/*
* Copyright 2019-2020, Synopsys, Inc.
* All rights reserved.
*
* This source code is licensed under the BSD-3-Clause license found in
* the LICENSE file in the root directory of this source tree.
*
*/

#include "mli_config.h"
#include "mli_prv_lut.h"
#include "mli_prv_activation_lut.h"

using mli::krn::activation_lut;

/*
    *** Generated by lutfx.py ***
    arguments  = -t FX16 -o size/2 -s 180 -qi 3 -f 'sigm(x)'
    lut_size   = 180
    in_offset  = 90
    in_format  = Q4.3
    out_format = Q15
    out_error  = 0.000191 (6 lsb) (linear interpolation)
*/
static const int16_t sigmoid_lut_data_fx16[] = {
        +0,     +0,     +1,     +1,     +1,     +1,     +1,     +1,     +1,     +1,     +1,     +2,     +2,     +2,
        +2,     +3,     +3,     +4,     +4,     +5,     +5,     +6,     +7,     +8,     +9,     +10,    +11,    +12,
        +14,    +16,    +18,    +21,    +23,    +26,    +30,    +34,    +38,    +43,    +49,    +56,    +63,    +72,
        +81,    +92,    +104,   +118,   +133,   +151,   +171,   +194,   +219,   +248,   +281,   +318,   +360,   +407,
        +461,   +521,   +589,   +666,   +753,   +851,   +961,   +1084,  +1223,  +1379,  +1554,  +1750,  +1969,  +2213,
        +2486,  +2789,  +3124,  +3496,  +3906,  +4357,  +4851,  +5391,  +5978,  +6613,  +7297,  +8031,  +8813,  +9641,
        +10513, +11424, +12371, +13348, +14347, +15361, +16384, +17407, +18421, +19420, +20397, +21344, +22255, +23127,
        +23955, +24737, +25471, +26155, +26790, +27377, +27917, +28411, +28862, +29272, +29644, +29979, +30282, +30555,
        +30799, +31018, +31214, +31389, +31545, +31684, +31807, +31917, +32015, +32102, +32179, +32247, +32307, +32361,
        +32408, +32450, +32487, +32520, +32549, +32574, +32597, +32617, +32635, +32650, +32664, +32676, +32687, +32696,
        +32705, +32712, +32719, +32725, +32730, +32734, +32738, +32742, +32745, +32747, +32750, +32752, +32754, +32756,
        +32757, +32758, +32759, +32760, +32761, +32762, +32763, +32763, +32764, +32764, +32765, +32765, +32766, +32766,
        +32766, +32766, +32767, +32767, +32767, +32767, +32767, +32767, +32767, +32767, +32767, +32767};

const mli_lut sigmoid_lut_fx16 = {
        // Designated initializers in C++ is a C++20 feature
        /*.data =*/ (const void*)sigmoid_lut_data_fx16,
        /*.type =*/ MLI_EL_FX_16,
        /*.length =*/ sizeof(sigmoid_lut_data_fx16) / sizeof(sigmoid_lut_data_fx16[0]),
        /*.in_frac_bits =*/ 3,
        /*.out_frac_bits =*/ 15,
        /*.offset =*/ sizeof(sigmoid_lut_data_fx16) / (sizeof(sigmoid_lut_data_fx16[0]) * 2) /*center-aligned */
};

/*
    *** Generated by lutfx.py ***
    arguments  = -t FX16 -o size/2 -s 178 -qi 4 -f 'tanh(x)'
    lut_size   = 178
    in_offset  = 89
    in_format  = Q3.4
    out_format = Q15
    out_error  = 0.000377 (12 lsb) (linear interpolation)
*/
static const int16_t tanh_lut_data_fx16[] = {
        -32767, -32767, -32767, -32767, -32766, -32766, -32766, -32766, -32765, -32765, -32765, -32764, -32764, -32763,
        -32762, -32762, -32761, -32760, -32759, -32758, -32756, -32755, -32753, -32751, -32749, -32746, -32743, -32740,
        -32736, -32732, -32727, -32721, -32715, -32708, -32700, -32691, -32681, -32670, -32657, -32642, -32625, -32606,
        -32584, -32560, -32532, -32501, -32466, -32426, -32381, -32329, -32271, -32206, -32132, -32048, -31953, -31846,
        -31726, -31589, -31435, -31262, -31067, -30847, -30600, -30322, -30010, -29660, -29268, -28830, -28341, -27797,
        -27191, -26519, -25776, -24956, -24054, -23066, -21986, -20813, -19542, -18173, -16706, -15143, -13486, -11743,
        -9919,  -8025,  -6073,  -4075,  -2045,  +0,     +2045,  +4075,  +6073,  +8025,  +9919,  +11743, +13486, +15143,
        +16706, +18173, +19542, +20813, +21986, +23066, +24054, +24956, +25776, +26519, +27191, +27797, +28341, +28830,
        +29268, +29660, +30010, +30322, +30600, +30847, +31067, +31262, +31435, +31589, +31726, +31846, +31953, +32048,
        +32132, +32206, +32271, +32329, +32381, +32426, +32466, +32501, +32532, +32560, +32584, +32606, +32625, +32642,
        +32657, +32670, +32681, +32691, +32700, +32708, +32715, +32721, +32727, +32732, +32736, +32740, +32743, +32746,
        +32749, +32751, +32753, +32755, +32756, +32758, +32759, +32760, +32761, +32762, +32762, +32763, +32764, +32764,
        +32765, +32765, +32765, +32766, +32766, +32766, +32766, +32767, +32767, +32767};

const mli_lut tanh_lut_fx16 = {
        /*.data =*/ (const void*)tanh_lut_data_fx16,
        /*.type =*/ MLI_EL_FX_16,
        /*.length =*/ sizeof(tanh_lut_data_fx16) / sizeof(tanh_lut_data_fx16[0]),
        /*.in_frac_bits =*/ 4,
        /*.out_frac_bits =*/ 15,
        /*.offset =*/ sizeof(tanh_lut_data_fx16) / (sizeof(tanh_lut_data_fx16[0]) * 2) /*center-aligned */
};

/*
    *** Generated by lutfx.py ***
    arguments  = -t FX16 -o size-2 -s 181 -qi 4 -f 'expneg(x)'
    lut_size   = 181
    in_offset  = 179
    in_format  = Q3.4
    out_format = Q15
    out_error  = 0.000463 (15 lsb) (linear interpolation)
*/
static const int16_t expneg_lut_data_fx16[] = {
        +0,     +0,     +1,     +1,     +1,     +1,     +1,     +1,     +1,     +1,     +1,     +1,     +1,     +1,
        +1,     +1,     +1,     +1,     +1,     +1,     +2,     +2,     +2,     +2,     +2,     +2,     +2,     +2,
        +3,     +3,     +3,     +3,     +3,     +4,     +4,     +4,     +4,     +5,     +5,     +5,     +6,     +6,
        +6,     +7,     +7,     +8,     +8,     +9,     +9,     +10,    +10,    +11,    +12,    +12,    +13,    +14,
        +15,    +16,    +17,    +18,    +19,    +21,    +22,    +23,    +25,    +26,    +28,    +30,    +32,    +34,
        +36,    +38,    +41,    +43,    +46,    +49,    +52,    +56,    +59,    +63,    +67,    +72,    +76,    +81,
        +86,    +92,    +98,    +104,   +111,   +118,   +126,   +134,   +143,   +152,   +162,   +172,   +183,   +195,
        +207,   +221,   +235,   +250,   +266,   +283,   +302,   +321,   +342,   +364,   +387,   +412,   +439,   +467,
        +498,   +530,   +564,   +600,   +639,   +680,   +724,   +771,   +820,   +873,   +930,   +990,   +1053,  +1121,
        +1194,  +1271,  +1352,  +1440,  +1533,  +1631,  +1737,  +1849,  +1968,  +2095,  +2230,  +2374,  +2527,  +2690,
        +2863,  +3048,  +3244,  +3454,  +3676,  +3914,  +4166,  +4435,  +4721,  +5025,  +5349,  +5694,  +6061,  +6452,
        +6869,  +7312,  +7783,  +8285,  +8819,  +9388,  +9994,  +10638, +11324, +12055, +12832, +13660, +14541, +15479,
        +16477, +17539, +18671, +19875, +21157, +22521, +23974, +25520, +27166, +28918, +30783, +32767, +32767};

const mli_lut expneg_lut_fx16 = {
        /*.data =*/ (const void*)expneg_lut_data_fx16,
        /*.type =*/ MLI_EL_FX_16,
        /*.length =*/ sizeof(expneg_lut_data_fx16) / sizeof(expneg_lut_data_fx16[0]),
        /*.in_frac_bits =*/ 4,
        /*.out_frac_bits =*/ 15,
        /*.offset =*/ sizeof(expneg_lut_data_fx16) / sizeof(expneg_lut_data_fx16[0]) - 2 /*right-minus-one-aligned */
};

/*
    *** Generated by lutfx.py ***
    arguments  = -t FX16 -o -32 -s 95 -qi 0 -qo 17 -f 'invsqrt(x)'
    lut_size   = 95
    in_offset  = -32
    in_format  = Q7.0
    out_format = Q17
    out_error  = 0.000017 (2 lsb) (linear interpolation)
*/
static const int16_t invsqrt_lut_data_fx16[] = {
    +23170, +22817, +22479, +22155, +21845, +21548, +21263, +20988,
    +20724, +20470, +20225, +19988, +19760, +19539, +19326, +19119,
    +18919, +18725, +18536, +18354, +18176, +18004, +17837, +17674,
    +17515, +17361, +17211, +17064, +16921, +16782, +16646, +16514,
    +16384, +16257, +16134, +16013, +15895, +15779, +15666, +15555,
    +15447, +15341, +15237, +15135, +15035, +14937, +14841, +14747,
    +14654, +14564, +14474, +14387, +14301, +14217, +14134, +14052,
    +13972, +13894, +13816, +13740, +13665, +13592, +13519, +13448,
    +13377, +13308, +13240, +13173, +13107, +13042, +12978, +12915,
    +12853, +12791, +12731, +12671, +12612, +12554, +12497, +12441,
    +12385, +12330, +12276, +12223, +12170, +12118, +12066, +12015,
    +11965, +11916, +11867, +11818, +11771, +11723, +11677
};

const mli_lut invsqrt_lut_fx16 = {
        /*.data =*/ (const void*)invsqrt_lut_data_fx16,
        /*.type =*/ MLI_EL_FX_16,
        /*.length =*/ sizeof(invsqrt_lut_data_fx16) / sizeof(invsqrt_lut_data_fx16[0]),
        /*.in_frac_bits =*/ 0,
        /*.out_frac_bits =*/ 17,
        /*.offset =*/ -32
};
#ifdef __cplusplus
extern "C" {
#endif

#pragma MLI_CODE_SECTION_START(".mli_lib")

void mli_prv_activation_lut_fx8(
        const mli_tensor *in,
        const mli_tensor *out,
        const mli_lut *lut,
        int in_frac_bits) {
    activation_lut<int8_t, /* convert = */ false>(in, out, lut, in_frac_bits);
}

void mli_prv_activation_lut_fx16(
        const mli_tensor *in,
        const mli_tensor *out,
        const mli_lut *lut,
        int in_frac_bits) {
    activation_lut<int16_t, /* convert = */ false>(in, out, lut, in_frac_bits);
}

void mli_prv_activation_lut_sa8(
        const mli_tensor *in,
        const mli_tensor *out,
        const mli_lut *lut,
        struct s8asym_quant_params *in_params,
        struct s8asym_quant_params *out_params) {
    activation_lut<int8_t, /* convert = */ true>(in, out, lut, 0 /*Unused*/, in_params, out_params);
}

#pragma MLI_CODE_SECTION_END()

#ifdef __cplusplus
}
#endif
