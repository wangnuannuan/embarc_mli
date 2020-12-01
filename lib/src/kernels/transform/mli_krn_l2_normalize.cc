/*
* Copyright 2020, Synopsys, Inc.
* All rights reserved.
*
* This source code is licensed under the BSD-3-Clause license found in
* the LICENSE file in the root directory of this source tree.
*
*/

#include "mli_check.h"
#include "mli_krn_l2_normalize.h"

using mli::krn::mli_krn_l2_normalize_run;
#ifdef __cplusplus
extern "C" {
#endif

#pragma MLI_CODE_SECTION_START(".mli_lib")

mli_status mli_krn_l2_normalize_fx16(const mli_tensor *in, 
        const mli_tensor *epsilon, 
        const mli_l2_normalize_cfg *cfg, 
        mli_tensor *out) {

    mli_status ret = MLI_CHECK_STATUS(mli_chk_l2_normalize_fx16(in, cfg, out), __func__);
    if (ret != MLI_STATUS_OK) return ret;

    return mli_krn_l2_normalize_run<int16_t>(in, epsilon, cfg, out);
}

mli_status mli_krn_l2_normalize_sa8(const mli_tensor *in, 
        const mli_tensor *epsilon, 
        const mli_l2_normalize_cfg *cfg, 
        mli_tensor *out) {

    mli_status ret = MLI_CHECK_STATUS(mli_chk_l2_normalize_sa8(in, cfg, out), __func__);
    if (ret != MLI_STATUS_OK) return ret;

    return mli_krn_l2_normalize_run<int8_t, true>(in, epsilon, cfg, out);
}

#pragma MLI_CODE_SECTION_END()

#ifdef __cplusplus
}
#endif