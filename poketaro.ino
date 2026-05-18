#include <M5Unified.h>
#include "cards.h"

int currentCard = 0;
int deck[CARD_COUNT];

void shuffleDeck() {
  // Fisher-Yates shuffle
  for (int i = 0; i < CARD_COUNT; i++) deck[i] = i;
  for (int i = CARD_COUNT - 1; i > 0; i--) {
    int j = random(i + 1);
    int tmp = deck[i];
    deck[i] = deck[j];
    deck[j] = tmp;
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

void setup() {
  M5.begin();
  randomSeed(esp_random());
  shuffleDeck();
  showCard(currentCard);
}

void loop() {
  M5.delay(1);
  M5.update();

  if (M5.BtnA.wasClicked()) {
    currentCard = (currentCard + 1) % CARD_COUNT;
    showCard(currentCard);
  }

  if (M5.BtnB.wasClicked()) {
    currentCard = 0;
    shuffleDeck();
    showCard(currentCard);
  }
}