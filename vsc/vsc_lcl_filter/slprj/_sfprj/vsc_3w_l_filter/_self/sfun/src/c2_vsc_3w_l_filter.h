#ifndef __c2_vsc_3w_l_filter_h__
#define __c2_vsc_3w_l_filter_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_vsc_3w_l_filterInstanceStruct
#define typedef_SFc2_vsc_3w_l_filterInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_vsc_3w_l_filter;
  void *c2_fEmlrtCtx;
  real_T *c2_eta_d;
  real_T *c2_eta_q;
  real_T *c2_i_sd;
  real_T *c2_i_sq;
  real_T *c2_v_dc;
  real_T *c2_v_sd;
  real_T *c2_v_sq;
  real_T *c2_i_dc;
  real_T *c2_omega;
  real_T (*c2_params)[3];
  real_T (*c2_dx)[3];
  real_T (*c2_x)[3];
} SFc2_vsc_3w_l_filterInstanceStruct;

#endif                                 /*typedef_SFc2_vsc_3w_l_filterInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_vsc_3w_l_filter_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_vsc_3w_l_filter_get_check_sum(mxArray *plhs[]);
extern void c2_vsc_3w_l_filter_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
