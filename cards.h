#pragma once

#include "headers/rwsa_t_00.h"
#include "headers/rwsa_t_01.h"
#include "headers/rwsa_t_02.h"
#include "headers/rwsa_t_03.h"
#include "headers/rwsa_t_04.h"
#include "headers/rwsa_t_05.h"
#include "headers/rwsa_t_06.h"
#include "headers/rwsa_t_07.h"
#include "headers/rwsa_t_08.h"
#include "headers/rwsa_t_09.h"
#include "headers/rwsa_t_10.h"
#include "headers/rwsa_t_11.h"
#include "headers/rwsa_t_12.h"
#include "headers/rwsa_t_13.h"
#include "headers/rwsa_t_14.h"
#include "headers/rwsa_t_15.h"
#include "headers/rwsa_t_16.h"
#include "headers/rwsa_t_17.h"
#include "headers/rwsa_t_18.h"
#include "headers/rwsa_t_19.h"
#include "headers/rwsa_t_20.h"
#include "headers/rwsa_t_21.h"
#include "headers/rwsa_p_0a.h"
#include "headers/rwsa_p_02.h"
#include "headers/rwsa_p_03.h"
#include "headers/rwsa_p_04.h"
#include "headers/rwsa_p_05.h"
#include "headers/rwsa_p_06.h"
#include "headers/rwsa_p_07.h"
#include "headers/rwsa_p_08.h"
#include "headers/rwsa_p_09.h"
#include "headers/rwsa_p_10.h"
#include "headers/rwsa_p_j1.h"
#include "headers/rwsa_p_j2.h"
#include "headers/rwsa_p_qu.h"
#include "headers/rwsa_p_ki.h"
#include "headers/rwsa_w_0a.h"
#include "headers/rwsa_w_02.h"
#include "headers/rwsa_w_03.h"
#include "headers/rwsa_w_04.h"
#include "headers/rwsa_w_05.h"
#include "headers/rwsa_w_06.h"
#include "headers/rwsa_w_07.h"
#include "headers/rwsa_w_08.h"
#include "headers/rwsa_w_09.h"
#include "headers/rwsa_w_10.h"
#include "headers/rwsa_w_j1.h"
#include "headers/rwsa_w_j2.h"
#include "headers/rwsa_w_qu.h"
#include "headers/rwsa_w_ki.h"
#include "headers/rwsa_c_0a.h"
#include "headers/rwsa_c_02.h"
#include "headers/rwsa_c_03.h"
#include "headers/rwsa_c_04.h"
#include "headers/rwsa_c_05.h"
#include "headers/rwsa_c_06.h"
#include "headers/rwsa_c_07.h"
#include "headers/rwsa_c_08.h"
#include "headers/rwsa_c_09.h"
#include "headers/rwsa_c_10.h"
#include "headers/rwsa_c_j1.h"
#include "headers/rwsa_c_j2.h"
#include "headers/rwsa_c_qu.h"
#include "headers/rwsa_c_ki.h"
#include "headers/rwsa_s_0a.h"
#include "headers/rwsa_s_02.h"
#include "headers/rwsa_s_03.h"
#include "headers/rwsa_s_04.h"
#include "headers/rwsa_s_05.h"
#include "headers/rwsa_s_06.h"
#include "headers/rwsa_s_07.h"
#include "headers/rwsa_s_08.h"
#include "headers/rwsa_s_09.h"
#include "headers/rwsa_s_10.h"
#include "headers/rwsa_s_j1.h"
#include "headers/rwsa_s_j2.h"
#include "headers/rwsa_s_qu.h"
#include "headers/rwsa_s_ki.h"

const uint8_t* card_data[] = {
    rwsa_t_00,
    rwsa_t_01,
    rwsa_t_02,
    rwsa_t_03,
    rwsa_t_04,
    rwsa_t_05,
    rwsa_t_06,
    rwsa_t_07,
    rwsa_t_08,
    rwsa_t_09,
    rwsa_t_10,
    rwsa_t_11,
    rwsa_t_12,
    rwsa_t_13,
    rwsa_t_14,
    rwsa_t_15,
    rwsa_t_16,
    rwsa_t_17,
    rwsa_t_18,
    rwsa_t_19,
    rwsa_t_20,
    rwsa_t_21,
    rwsa_p_0a,
    rwsa_p_02,
    rwsa_p_03,
    rwsa_p_04,
    rwsa_p_05,
    rwsa_p_06,
    rwsa_p_07,
    rwsa_p_08,
    rwsa_p_09,
    rwsa_p_10,
    rwsa_p_j1,
    rwsa_p_j2,
    rwsa_p_qu,
    rwsa_p_ki,
    rwsa_w_0a,
    rwsa_w_02,
    rwsa_w_03,
    rwsa_w_04,
    rwsa_w_05,
    rwsa_w_06,
    rwsa_w_07,
    rwsa_w_08,
    rwsa_w_09,
    rwsa_w_10,
    rwsa_w_j1,
    rwsa_w_j2,
    rwsa_w_qu,
    rwsa_w_ki,
    rwsa_c_0a,
    rwsa_c_02,
    rwsa_c_03,
    rwsa_c_04,
    rwsa_c_05,
    rwsa_c_06,
    rwsa_c_07,
    rwsa_c_08,
    rwsa_c_09,
    rwsa_c_10,
    rwsa_c_j1,
    rwsa_c_j2,
    rwsa_c_qu,
    rwsa_c_ki,
    rwsa_s_0a,
    rwsa_s_02,
    rwsa_s_03,
    rwsa_s_04,
    rwsa_s_05,
    rwsa_s_06,
    rwsa_s_07,
    rwsa_s_08,
    rwsa_s_09,
    rwsa_s_10,
    rwsa_s_j1,
    rwsa_s_j2,
    rwsa_s_qu,
    rwsa_s_ki,
};

const unsigned int card_lens[] = {
    rwsa_t_00_len,
    rwsa_t_01_len,
    rwsa_t_02_len,
    rwsa_t_03_len,
    rwsa_t_04_len,
    rwsa_t_05_len,
    rwsa_t_06_len,
    rwsa_t_07_len,
    rwsa_t_08_len,
    rwsa_t_09_len,
    rwsa_t_10_len,
    rwsa_t_11_len,
    rwsa_t_12_len,
    rwsa_t_13_len,
    rwsa_t_14_len,
    rwsa_t_15_len,
    rwsa_t_16_len,
    rwsa_t_17_len,
    rwsa_t_18_len,
    rwsa_t_19_len,
    rwsa_t_20_len,
    rwsa_t_21_len,
    rwsa_p_0a_len,
    rwsa_p_02_len,
    rwsa_p_03_len,
    rwsa_p_04_len,
    rwsa_p_05_len,
    rwsa_p_06_len,
    rwsa_p_07_len,
    rwsa_p_08_len,
    rwsa_p_09_len,
    rwsa_p_10_len,
    rwsa_p_j1_len,
    rwsa_p_j2_len,
    rwsa_p_qu_len,
    rwsa_p_ki_len,
    rwsa_w_0a_len,
    rwsa_w_02_len,
    rwsa_w_03_len,
    rwsa_w_04_len,
    rwsa_w_05_len,
    rwsa_w_06_len,
    rwsa_w_07_len,
    rwsa_w_08_len,
    rwsa_w_09_len,
    rwsa_w_10_len,
    rwsa_w_j1_len,
    rwsa_w_j2_len,
    rwsa_w_qu_len,
    rwsa_w_ki_len,
    rwsa_c_0a_len,
    rwsa_c_02_len,
    rwsa_c_03_len,
    rwsa_c_04_len,
    rwsa_c_05_len,
    rwsa_c_06_len,
    rwsa_c_07_len,
    rwsa_c_08_len,
    rwsa_c_09_len,
    rwsa_c_10_len,
    rwsa_c_j1_len,
    rwsa_c_j2_len,
    rwsa_c_qu_len,
    rwsa_c_ki_len,
    rwsa_s_0a_len,
    rwsa_s_02_len,
    rwsa_s_03_len,
    rwsa_s_04_len,
    rwsa_s_05_len,
    rwsa_s_06_len,
    rwsa_s_07_len,
    rwsa_s_08_len,
    rwsa_s_09_len,
    rwsa_s_10_len,
    rwsa_s_j1_len,
    rwsa_s_j2_len,
    rwsa_s_qu_len,
    rwsa_s_ki_len,
};

const int CARD_COUNT = 78;
