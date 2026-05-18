#include <M5Unified.h>
#include <esp_sleep.h>
#include <WiFi.h>
#include <math.h>
#include "cards.h"

// --- State machine ---
enum State {
  STATE_NEEDS_SHUFFLE,
  STATE_READY,
  STATE_DRAWING
};
State state = STATE_NEEDS_SHUFFLE;

int currentCard = 0;
int deck[CARD_COUNT];

// --- Continuously-stirred entropy pool ---
uint32_t entropyPool = 0;

// --- Shuffle gesture detection ---
float shuffleEnergy = 0.0f;
const float SHUFFLE_THRESHOLD = 6.0f;
const float ENERGY_DECAY = 0.98f;
float lastAccelMag = 0.0f;

// --- Timing ---
unsigned long lastActivity = 0;
unsigned long lastImuSample = 0;
unsigned long lastBarUpdate = 0;
const unsigned long IDLE_TIMEOUT_MS = 30UL * 1000UL;
const unsigned long IMU_INTERVAL_MS = 10;
const unsigned long BAR_REDRAW_MS = 50;

#define BTNA_PIN GPIO_NUM_11

// --- Card display ---
void shuffleDeck() {
  randomSeed(entropyPool ^ micros() ^ esp_random());
  for (int i = 0; i < CARD_COUNT; i++) deck[i] = i;
  for (int i = CARD_COUNT - 1; i > 0; i--) {
    int j = random(i + 1);
    int tmp = deck[i]; deck[i] = deck[j]; deck[j] = tmp;
  }
}

void showCard(int index) {
  M5.Display.drawJpg( card_data[deck[index]]
                    , card_lens[deck[index]]
                    , 0, 0
                    , M5.Display.width()
                    , M5.Display.height()
                    , 0, 0, 0, 0
                    , datum_t::middle_center
                    );
}

// --- Prompt screens ---
void drawShuffleScreen() {
  int w = M5.Display.width();
  int h = M5.Display.height();
  M5.Display.fillScreen(TFT_BLACK);
  M5.Display.setTextColor(TFT_WHITE);
  M5.Display.setTextDatum(middle_center);
  M5.Display.setFont(&fonts::FreeSerifItalic9pt7b);
  M5.Display.drawString("shake the deck", w/2, h/2 - 12);
  M5.Display.drawRect(30, h - 24, w - 60, 8, TFT_DARKGREY);
}

void updateShuffleBar() {
  int w = M5.Display.width();
  int h = M5.Display.height();
  int maxBarW = w - 62;
  int barW = (int)((shuffleEnergy / SHUFFLE_THRESHOLD) * maxBarW);
  if (barW > maxBarW) barW = maxBarW;
  if (barW < 0) barW = 0;
  M5.Display.fillRect(31, h - 23, barW, 6, TFT_WHITE);
  M5.Display.fillRect(31 + barW, h - 23, maxBarW - barW, 6, TFT_BLACK);
}

void drawReadyScreen() {
  int w = M5.Display.width();
  int h = M5.Display.height();
  M5.Display.fillScreen(TFT_BLACK);
  M5.Display.setTextColor(TFT_WHITE);
  M5.Display.setTextDatum(middle_center);
  M5.Display.setFont(&fonts::FreeSerifItalic9pt7b);
  M5.Display.drawString("press A to draw", w/2, h/2);
}

// --- IMU sampling: entropy + motion energy ---
void sampleImu() {
  if (!M5.Imu.isEnabled()) return;
  M5.Imu.update();
  auto d = M5.Imu.getImuData();

  uint32_t bits = 0;
  bits ^= ((uint32_t)(d.accel.x * 1e6f) & 0xFF);
  bits ^= ((uint32_t)(d.accel.y * 1e6f) & 0xFF) << 8;
  bits ^= ((uint32_t)(d.accel.z * 1e6f) & 0xFF) << 16;
  bits ^= ((uint32_t)(d.gyro.x  * 1e6f) & 0xFF) << 24;
  entropyPool ^= bits;
  entropyPool = (entropyPool << 7) | (entropyPool >> 25);

  float mag = sqrtf(d.accel.x*d.accel.x +
                    d.accel.y*d.accel.y +
                    d.accel.z*d.accel.z);
  float delta = fabsf(mag - lastAccelMag);
  lastAccelMag = mag;

  shuffleEnergy = shuffleEnergy * ENERGY_DECAY + delta;
}

// --- Sleep ---
void sleepNow() {
  M5.Display.sleep();
  M5.Display.setBrightness(0);
  esp_sleep_enable_ext1_wakeup(1ULL << BTNA_PIN, ESP_EXT1_WAKEUP_ANY_LOW);
  esp_deep_sleep_start();
}

// --- Setup / Loop ---
void setup() {
  auto cfg = M5.config();
  cfg.internal_imu  = true;
  cfg.internal_mic  = false;
  cfg.internal_spk  = false;
  cfg.internal_rtc  = false;
  M5.begin(cfg);

  WiFi.mode(WIFI_OFF);
  btStop();
  setCpuFrequencyMhz(80);

  entropyPool = esp_random();

  if (M5.Imu.isEnabled()) {
    M5.Imu.update();
    auto d = M5.Imu.getImuData();
    lastAccelMag = sqrtf(d.accel.x*d.accel.x +
                         d.accel.y*d.accel.y +
                         d.accel.z*d.accel.z);
  }

  drawShuffleScreen();
  lastActivity = millis();
}

void loop() {
  M5.delay(1);
  M5.update();

  if (millis() - lastImuSample >= IMU_INTERVAL_MS) {
    sampleImu();
    lastImuSample = millis();
  }

  bool active = false;

  if (state == STATE_NEEDS_SHUFFLE) {
    if (millis() - lastBarUpdate > BAR_REDRAW_MS) {
      updateShuffleBar();
      lastBarUpdate = millis();
    }
    if (shuffleEnergy >= SHUFFLE_THRESHOLD) {
      state = STATE_READY;
      drawReadyScreen();
      active = true;
    }
    if (shuffleEnergy > 0.5f) active = true;
  }
  else if (state == STATE_READY) {
    // The deck is loaded. Wait for the user — no fallback, no decay-out.
    if (M5.BtnA.wasClicked()) {
      shuffleDeck();
      currentCard = 0;
      showCard(currentCard);
      shuffleEnergy = 0.0f;
      state = STATE_DRAWING;
      active = true;
    }
  }
  else if (state == STATE_DRAWING) {
    if (M5.BtnA.wasClicked()) {
      currentCard = (currentCard + 1) % CARD_COUNT;
      showCard(currentCard);
      active = true;
    }
    if (M5.BtnB.wasClicked()) {
      shuffleEnergy = 0.0f;
      state = STATE_NEEDS_SHUFFLE;
      drawShuffleScreen();
      active = true;
    }
  }

  if (active) lastActivity = millis();
  if (millis() - lastActivity > IDLE_TIMEOUT_MS) sleepNow();
}