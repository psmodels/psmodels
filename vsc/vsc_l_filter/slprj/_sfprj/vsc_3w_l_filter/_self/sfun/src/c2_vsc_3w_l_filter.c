/* Include files */

#include "vsc_3w_l_filter_sfun.h"
#include "c2_vsc_3w_l_filter.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "vsc_3w_l_filter_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[20] = { "R_s", "L_s", "C_dc", "di_sd",
  "di_sq", "dv_dc", "x", "nargin", "nargout", "eta_d", "eta_q", "v_sd", "v_sq",
  "i_dc", "omega", "params", "i_sd", "i_sq", "v_dc", "dx" };

/* Function Declarations */
static void initialize_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance);
static void initialize_params_c2_vsc_3w_l_filter
  (SFc2_vsc_3w_l_filterInstanceStruct *chartInstance);
static void enable_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance);
static void disable_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_vsc_3w_l_filter
  (SFc2_vsc_3w_l_filterInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_vsc_3w_l_filter
  (SFc2_vsc_3w_l_filterInstanceStruct *chartInstance);
static void set_sim_state_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct *
  chartInstance, const mxArray *c2_st);
static void finalize_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance);
static void sf_gateway_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance);
static void mdl_start_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance);
static void initSimStructsc2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_b_dx, const char_T *c2_identifier, real_T
  c2_y[3]);
static void c2_b_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_b_i_sq, const char_T *c2_identifier);
static real_T c2_d_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_vsc_3w_l_filter, const char_T
  *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_vsc_3w_l_filter(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_vsc_3w_l_filter = 0U;
}

static void initialize_params_c2_vsc_3w_l_filter
  (SFc2_vsc_3w_l_filterInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_vsc_3w_l_filter
  (SFc2_vsc_3w_l_filterInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_vsc_3w_l_filter
  (SFc2_vsc_3w_l_filterInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  real_T c2_hoistedGlobal;
  const mxArray *c2_c_y = NULL;
  real_T c2_b_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  real_T c2_c_hoistedGlobal;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  const mxArray *c2_f_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(5, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", *chartInstance->c2_dx, 0, 0U, 1U, 0U,
    2, 1, 3), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = *chartInstance->c2_i_sd;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_b_hoistedGlobal = *chartInstance->c2_i_sq;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_c_hoistedGlobal = *chartInstance->c2_v_dc;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_active_c2_vsc_3w_l_filter;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_d_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct *
  chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[3];
  int32_T c2_i0;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("dx", c2_u, 0)),
                      "dx", c2_dv0);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    (*chartInstance->c2_dx)[c2_i0] = c2_dv0[c2_i0];
  }

  *chartInstance->c2_i_sd = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("i_sd", c2_u, 1)), "i_sd");
  *chartInstance->c2_i_sq = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("i_sq", c2_u, 2)), "i_sq");
  *chartInstance->c2_v_dc = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("v_dc", c2_u, 3)), "v_dc");
  chartInstance->c2_is_active_c2_vsc_3w_l_filter = c2_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c2_vsc_3w_l_filter",
       c2_u, 4)), "is_active_c2_vsc_3w_l_filter");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_vsc_3w_l_filter(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance)
{
  int32_T c2_i1;
  int32_T c2_i2;
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_b_eta_d;
  real_T c2_b_eta_q;
  real_T c2_b_v_sd;
  real_T c2_b_v_sq;
  real_T c2_b_i_dc;
  real_T c2_b_omega;
  int32_T c2_i3;
  int32_T c2_i4;
  real_T c2_b_params[3];
  uint32_T c2_debug_family_var_map[20];
  real_T c2_b_x[3];
  real_T c2_R_s;
  real_T c2_L_s;
  real_T c2_C_dc;
  real_T c2_di_sd;
  real_T c2_di_sq;
  real_T c2_dv_dc;
  real_T c2_c_x[9];
  real_T c2_nargin = 8.0;
  real_T c2_nargout = 4.0;
  real_T c2_b_i_sd;
  real_T c2_b_i_sq;
  real_T c2_b_v_dc;
  real_T c2_b_dx[3];
  int32_T c2_i5;
  real_T c2_B;
  real_T c2_y;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_A;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_d_y;
  real_T c2_b_B;
  real_T c2_e_y;
  real_T c2_f_y;
  real_T c2_g_y;
  real_T c2_b_A;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_y;
  real_T c2_c_B;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_k_y;
  int32_T c2_i6;
  int32_T c2_i7;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_x)[c2_i1], 7U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_params)[c2_i2], 6U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_omega, 5U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_i_dc, 4U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_v_sq, 3U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_v_sd, 2U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_eta_q, 1U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_eta_d, 0U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *chartInstance->c2_eta_d;
  c2_b_hoistedGlobal = *chartInstance->c2_eta_q;
  c2_c_hoistedGlobal = *chartInstance->c2_v_sd;
  c2_d_hoistedGlobal = *chartInstance->c2_v_sq;
  c2_e_hoistedGlobal = *chartInstance->c2_i_dc;
  c2_f_hoistedGlobal = *chartInstance->c2_omega;
  c2_b_eta_d = c2_hoistedGlobal;
  c2_b_eta_q = c2_b_hoistedGlobal;
  c2_b_v_sd = c2_c_hoistedGlobal;
  c2_b_v_sq = c2_d_hoistedGlobal;
  c2_b_i_dc = c2_e_hoistedGlobal;
  c2_b_omega = c2_f_hoistedGlobal;
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_b_params[c2_i3] = (*chartInstance->c2_params)[c2_i3];
  }

  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    c2_b_x[c2_i4] = (*chartInstance->c2_x)[c2_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 21U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_R_s, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_L_s, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_C_dc, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_di_sd, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_di_sq, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dv_dc, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_c_x, MAX_uint32_T, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_eta_d, 9U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_eta_q, 10U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_v_sd, 11U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_v_sq, 12U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_i_dc, 13U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_omega, 14U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_params, 15U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_x, 6U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_i_sd, 16U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_i_sq, 17U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_v_dc, 18U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_dx, 19U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_R_s = c2_b_params[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_L_s = c2_b_params[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_C_dc = c2_b_params[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  for (c2_i5 = 0; c2_i5 < 9; c2_i5++) {
    c2_c_x[c2_i5] = 0.0;
  }

  _SFD_SYMBOL_SWITCH(6U, 6U);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_b_i_sd = c2_c_x[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_b_i_sq = c2_c_x[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_b_v_dc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c2_b_v_dc, 0.1, -1, 2U,
             c2_b_v_dc < 0.1));
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_b_v_dc = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_B = c2_L_s;
  c2_y = c2_B;
  c2_b_y = c2_y;
  c2_c_y = 1.0 / c2_b_y;
  c2_A = 0.5 * c2_b_eta_d;
  c2_d_x = c2_A;
  c2_e_x = c2_d_x;
  c2_d_y = c2_e_x / 0.1;
  c2_di_sd = c2_c_y * (((c2_d_y + c2_L_s * c2_b_omega * c2_b_i_sq) - c2_R_s *
                        c2_b_i_sd) - c2_b_v_sd);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_b_B = c2_L_s;
  c2_e_y = c2_b_B;
  c2_f_y = c2_e_y;
  c2_g_y = 1.0 / c2_f_y;
  c2_b_A = 0.5 * c2_b_eta_q;
  c2_f_x = c2_b_A;
  c2_g_x = c2_f_x;
  c2_h_y = c2_g_x / 0.1;
  c2_di_sq = c2_g_y * (((c2_h_y - c2_L_s * c2_b_omega * c2_b_i_sd) - c2_R_s *
                        c2_b_i_sq) - c2_b_v_sq);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_c_B = c2_C_dc;
  c2_i_y = c2_c_B;
  c2_j_y = c2_i_y;
  c2_k_y = 1.0 / c2_j_y;
  c2_dv_dc = c2_k_y * (0.5 * ((c2_b_eta_d * c2_b_i_sd + c2_b_eta_q * c2_b_i_sq)
    - c2_b_i_dc));
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_b_dx[0] = c2_di_sd;
  c2_b_dx[1] = c2_di_sq;
  c2_b_dx[2] = c2_dv_dc;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -25);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c2_i_sd = c2_b_i_sd;
  *chartInstance->c2_i_sq = c2_b_i_sq;
  *chartInstance->c2_v_dc = c2_b_v_dc;
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    (*chartInstance->c2_dx)[c2_i6] = c2_b_dx[c2_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_vsc_3w_l_filterMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_i_sd, 8U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_i_sq, 9U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_v_dc, 10U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_dx)[c2_i7], 11U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }
}

static void mdl_start_c2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc2_vsc_3w_l_filter(SFc2_vsc_3w_l_filterInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i8;
  const mxArray *c2_y = NULL;
  real_T c2_u[3];
  SFc2_vsc_3w_l_filterInstanceStruct *chartInstance;
  chartInstance = (SFc2_vsc_3w_l_filterInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    c2_u[c2_i8] = (*(real_T (*)[3])c2_inData)[c2_i8];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_b_dx, const char_T *c2_identifier, real_T
  c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_dx), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_dx);
}

static void c2_b_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3])
{
  real_T c2_dv1[3];
  int32_T c2_i9;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    c2_y[c2_i9] = c2_dv1[c2_i9];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_dx;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i10;
  SFc2_vsc_3w_l_filterInstanceStruct *chartInstance;
  chartInstance = (SFc2_vsc_3w_l_filterInstanceStruct *)chartInstanceVoid;
  c2_b_dx = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_dx), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_dx);
  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    (*(real_T (*)[3])c2_outData)[c2_i10] = c2_y[c2_i10];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vsc_3w_l_filterInstanceStruct *chartInstance;
  chartInstance = (SFc2_vsc_3w_l_filterInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_b_i_sq, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i_sq), &c2_thisId);
  sf_mex_destroy(&c2_b_i_sq);
  return c2_y;
}

static real_T c2_d_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_i_sq;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_vsc_3w_l_filterInstanceStruct *chartInstance;
  chartInstance = (SFc2_vsc_3w_l_filterInstanceStruct *)chartInstanceVoid;
  c2_b_i_sq = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i_sq), &c2_thisId);
  sf_mex_destroy(&c2_b_i_sq);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i11;
  const mxArray *c2_y = NULL;
  real_T c2_u[3];
  SFc2_vsc_3w_l_filterInstanceStruct *chartInstance;
  chartInstance = (SFc2_vsc_3w_l_filterInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    c2_u[c2_i11] = (*(real_T (*)[3])c2_inData)[c2_i11];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i12;
  int32_T c2_i13;
  const mxArray *c2_y = NULL;
  int32_T c2_i14;
  real_T c2_u[9];
  SFc2_vsc_3w_l_filterInstanceStruct *chartInstance;
  chartInstance = (SFc2_vsc_3w_l_filterInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i12 = 0;
  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
      c2_u[c2_i14 + c2_i12] = (*(real_T (*)[9])c2_inData)[c2_i14 + c2_i12];
    }

    c2_i12 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_vsc_3w_l_filter_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_vsc_3w_l_filterInstanceStruct *chartInstance;
  chartInstance = (SFc2_vsc_3w_l_filterInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i15;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i15, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i15;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_vsc_3w_l_filterInstanceStruct *chartInstance;
  chartInstance = (SFc2_vsc_3w_l_filterInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_vsc_3w_l_filter, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_vsc_3w_l_filter), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_vsc_3w_l_filter);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_vsc_3w_l_filterInstanceStruct
  *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_eta_d = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_eta_q = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_i_sd = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_i_sq = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_v_dc = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_v_sd = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_v_sq = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_i_dc = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_omega = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_params = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c2_dx = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_x = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_vsc_3w_l_filter_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(881385620U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2992732365U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(634236116U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(602573100U);
}

mxArray* sf_c2_vsc_3w_l_filter_get_post_codegen_info(void);
mxArray *sf_c2_vsc_3w_l_filter_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("eQmPWzIbRK1lnBTqWNqy4F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_vsc_3w_l_filter_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_vsc_3w_l_filter_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_vsc_3w_l_filter_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_vsc_3w_l_filter_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_vsc_3w_l_filter_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c2_vsc_3w_l_filter(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"dx\",},{M[1],M[10],T\"i_sd\",},{M[1],M[11],T\"i_sq\",},{M[1],M[12],T\"v_dc\",},{M[8],M[0],T\"is_active_c2_vsc_3w_l_filter\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_vsc_3w_l_filter_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_vsc_3w_l_filterInstanceStruct *chartInstance =
      (SFc2_vsc_3w_l_filterInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _vsc_3w_l_filterMachineNumber_,
           2,
           1,
           1,
           0,
           12,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_vsc_3w_l_filterMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_vsc_3w_l_filterMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _vsc_3w_l_filterMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"eta_d");
          _SFD_SET_DATA_PROPS(1,1,1,0,"eta_q");
          _SFD_SET_DATA_PROPS(2,1,1,0,"v_sd");
          _SFD_SET_DATA_PROPS(3,1,1,0,"v_sq");
          _SFD_SET_DATA_PROPS(4,1,1,0,"i_dc");
          _SFD_SET_DATA_PROPS(5,1,1,0,"omega");
          _SFD_SET_DATA_PROPS(6,1,1,0,"params");
          _SFD_SET_DATA_PROPS(7,1,1,0,"x");
          _SFD_SET_DATA_PROPS(8,2,0,1,"i_sd");
          _SFD_SET_DATA_PROPS(9,2,0,1,"i_sq");
          _SFD_SET_DATA_PROPS(10,2,0,1,"v_dc");
          _SFD_SET_DATA_PROPS(11,2,0,1,"dx");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,558);
        _SFD_CV_INIT_EML_IF(0,1,0,246,257,-1,277);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,249,257,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _vsc_3w_l_filterMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_vsc_3w_l_filterInstanceStruct *chartInstance =
      (SFc2_vsc_3w_l_filterInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c2_eta_d);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c2_eta_q);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c2_i_sd);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c2_i_sq);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)chartInstance->c2_v_dc);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c2_v_sd);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c2_v_sq);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c2_i_dc);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c2_omega);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c2_params);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)chartInstance->c2_dx);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c2_x);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sRf4hveem7RSsbwxtBj5fU";
}

static void sf_opaque_initialize_c2_vsc_3w_l_filter(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_vsc_3w_l_filterInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_vsc_3w_l_filter((SFc2_vsc_3w_l_filterInstanceStruct*)
    chartInstanceVar);
  initialize_c2_vsc_3w_l_filter((SFc2_vsc_3w_l_filterInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_vsc_3w_l_filter(void *chartInstanceVar)
{
  enable_c2_vsc_3w_l_filter((SFc2_vsc_3w_l_filterInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_vsc_3w_l_filter(void *chartInstanceVar)
{
  disable_c2_vsc_3w_l_filter((SFc2_vsc_3w_l_filterInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_vsc_3w_l_filter(void *chartInstanceVar)
{
  sf_gateway_c2_vsc_3w_l_filter((SFc2_vsc_3w_l_filterInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_vsc_3w_l_filter(SimStruct* S)
{
  return get_sim_state_c2_vsc_3w_l_filter((SFc2_vsc_3w_l_filterInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_vsc_3w_l_filter(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_vsc_3w_l_filter((SFc2_vsc_3w_l_filterInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_vsc_3w_l_filter(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_vsc_3w_l_filterInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_vsc_3w_l_filter_optimization_info();
    }

    finalize_c2_vsc_3w_l_filter((SFc2_vsc_3w_l_filterInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_vsc_3w_l_filter((SFc2_vsc_3w_l_filterInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_vsc_3w_l_filter(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_vsc_3w_l_filter((SFc2_vsc_3w_l_filterInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_vsc_3w_l_filter(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_vsc_3w_l_filter_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1910624515U));
  ssSetChecksum1(S,(3303931272U));
  ssSetChecksum2(S,(4032562640U));
  ssSetChecksum3(S,(1842710367U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_vsc_3w_l_filter(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_vsc_3w_l_filter(SimStruct *S)
{
  SFc2_vsc_3w_l_filterInstanceStruct *chartInstance;
  chartInstance = (SFc2_vsc_3w_l_filterInstanceStruct *)utMalloc(sizeof
    (SFc2_vsc_3w_l_filterInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_vsc_3w_l_filterInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_vsc_3w_l_filter;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_vsc_3w_l_filter;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_vsc_3w_l_filter;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_vsc_3w_l_filter;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_vsc_3w_l_filter;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_vsc_3w_l_filter;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_vsc_3w_l_filter;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_vsc_3w_l_filter;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_vsc_3w_l_filter;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_vsc_3w_l_filter;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_vsc_3w_l_filter;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_vsc_3w_l_filter(chartInstance);
}

void c2_vsc_3w_l_filter_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_vsc_3w_l_filter(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_vsc_3w_l_filter(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_vsc_3w_l_filter(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_vsc_3w_l_filter_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
