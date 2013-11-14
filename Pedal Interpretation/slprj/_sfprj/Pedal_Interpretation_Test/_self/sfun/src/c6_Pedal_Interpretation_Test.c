/* Include files */

#include "Pedal_Interpretation_Test_sfun.h"
#include "c6_Pedal_Interpretation_Test.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "Pedal_Interpretation_Test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c6_IN_NO_ACTIVE_CHILD          (0)
#define c6_IN_TDataPre1                (3)
#define c6_IN_Init1                    (1)
#define c6_IN_Stabilise1               (2)
#define c6_IN_Precondition1            (1)
#define c6_IN_Stabilise2               (2)
#define c6_IN_wait                     (3)
#define c6_IN_Precondition2            (2)
#define c6_IN_Init2                    (1)
#define c6_IN_TDataPre2                (3)

/* Variable Declarations */

/* Variable Definitions */
static SFc6_Pedal_Interpretation_TestInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c6_Pedal_Interpretation_Test(void);
static void initialize_params_c6_Pedal_Interpretation_Test(void);
static void enable_c6_Pedal_Interpretation_Test(void);
static void disable_c6_Pedal_Interpretation_Test(void);
static void update_debugger_state_c6_Pedal_Interpretation_Test(void);
static const mxArray *get_sim_state_c6_Pedal_Interpretation_Test(void);
static void set_sim_state_c6_Pedal_Interpretation_Test(const mxArray *c6_st);
static void finalize_c6_Pedal_Interpretation_Test(void);
static void sf_c6_Pedal_Interpretation_Test(void);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static uint8_T c6_emlrt_marshallIn(const mxArray *c6_temporary, char *c6_name);
static real_T c6_b_emlrt_marshallIn(const mxArray *c6_temporary, char *c6_name);
static uint16_T c6_c_emlrt_marshallIn(const mxArray *c6_temporary, char *c6_name);
static const mxArray *c6_emlrt_marshallOut(uint8_T c6_u);
static const mxArray *c6_b_emlrt_marshallOut(real_T c6_u);
static const mxArray *c6_c_emlrt_marshallOut(uint16_T c6_u);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c6_Pedal_Interpretation_Test(void)
{
  real_T *c6_TDPre;
  c6_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c6_is_Precondition1 = 0U;
  chartInstance.c6_tp_Precondition1 = 0U;
  chartInstance.c6_tp_Init1 = 0U;
  chartInstance.c6_tp_Stabilise1 = 0U;
  chartInstance.c6_tp_TDataPre1 = 0U;
  chartInstance.c6_is_Precondition2 = 0U;
  chartInstance.c6_tp_Precondition2 = 0U;
  chartInstance.c6_tp_Init2 = 0U;
  chartInstance.c6_tp_Stabilise2 = 0U;
  chartInstance.c6_tp_TDataPre2 = 0U;
  chartInstance.c6_tp_wait = 0U;
  chartInstance.c6_is_active_c6_Pedal_Interpretation_Test = 0U;
  chartInstance.c6_is_c6_Pedal_Interpretation_Test = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c6_TDPre = 0.0;
  }
}

static void initialize_params_c6_Pedal_Interpretation_Test(void)
{
}

static void enable_c6_Pedal_Interpretation_Test(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c6_Pedal_Interpretation_Test(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void update_debugger_state_c6_Pedal_Interpretation_Test(void)
{
  uint32_T c6_prevAniVal;
  c6_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if (chartInstance.c6_is_active_c6_Pedal_Interpretation_Test == 1) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,2);
  }

  if (chartInstance.c6_is_Precondition1 == c6_IN_TDataPre1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
  }

  if (chartInstance.c6_is_Precondition1 == c6_IN_Init1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
  }

  if (chartInstance.c6_is_Precondition1 == c6_IN_Stabilise1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
  }

  if (chartInstance.c6_is_c6_Pedal_Interpretation_Test == c6_IN_Precondition1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
  }

  if (chartInstance.c6_is_Precondition2 == c6_IN_Stabilise2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
  }

  if (chartInstance.c6_is_c6_Pedal_Interpretation_Test == c6_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,8);
  }

  if (chartInstance.c6_is_c6_Pedal_Interpretation_Test == c6_IN_Precondition2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
  }

  if (chartInstance.c6_is_Precondition2 == c6_IN_Init2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
  }

  if (chartInstance.c6_is_Precondition2 == c6_IN_TDataPre2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,7);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
  }

  sf_debug_set_animation(c6_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c6_Pedal_Interpretation_Test(void)
{
  const mxArray *c6_st = NULL;
  const mxArray *c6_y = NULL;
  real_T *c6_TDPre;
  c6_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(15));
  sf_mex_setcell(c6_y, 0, c6_emlrt_marshallOut(chartInstance.c6_tp_TDataPre1));
  sf_mex_setcell(c6_y, 1, c6_emlrt_marshallOut(chartInstance.c6_tp_Init1));
  sf_mex_setcell(c6_y, 2, c6_emlrt_marshallOut(chartInstance.c6_tp_Stabilise1));
  sf_mex_setcell(c6_y, 3, c6_emlrt_marshallOut(chartInstance.c6_tp_Precondition1));
  sf_mex_setcell(c6_y, 4, c6_emlrt_marshallOut(chartInstance.c6_tp_Stabilise2));
  sf_mex_setcell(c6_y, 5, c6_emlrt_marshallOut(chartInstance.c6_tp_wait));
  sf_mex_setcell(c6_y, 6, c6_emlrt_marshallOut(chartInstance.c6_tp_Precondition2));
  sf_mex_setcell(c6_y, 7, c6_emlrt_marshallOut(chartInstance.c6_tp_Init2));
  sf_mex_setcell(c6_y, 8, c6_emlrt_marshallOut(chartInstance.c6_tp_TDataPre2));
  sf_mex_setcell(c6_y, 9, c6_emlrt_marshallOut
                 (chartInstance.c6_is_active_c6_Pedal_Interpretation_Test));
  sf_mex_setcell(c6_y, 10, c6_emlrt_marshallOut
                 (chartInstance.c6_is_c6_Pedal_Interpretation_Test));
  sf_mex_setcell(c6_y, 11, c6_emlrt_marshallOut
                 (chartInstance.c6_is_Precondition1));
  sf_mex_setcell(c6_y, 12, c6_emlrt_marshallOut
                 (chartInstance.c6_is_Precondition2));
  sf_mex_setcell(c6_y, 13, c6_b_emlrt_marshallOut(*c6_TDPre));
  sf_mex_setcell(c6_y, 14, c6_c_emlrt_marshallOut
                 (chartInstance.c6_temporalCounter_i1));
  sf_mex_assign(&c6_st, c6_y);
  return c6_st;
}

static void set_sim_state_c6_Pedal_Interpretation_Test(const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T *c6_TDPre;
  c6_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c6_u = sf_mex_dup(c6_st);
  chartInstance.c6_tp_TDataPre1 = c6_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c6_u, 0)), "tp_TDataPre1");
  chartInstance.c6_tp_Init1 = c6_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c6_u,
    1)), "tp_Init1");
  chartInstance.c6_tp_Stabilise1 = c6_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c6_u, 2)), "tp_Stabilise1");
  chartInstance.c6_tp_Precondition1 = c6_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c6_u, 3)), "tp_Precondition1");
  chartInstance.c6_tp_Stabilise2 = c6_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c6_u, 4)), "tp_Stabilise2");
  chartInstance.c6_tp_wait = c6_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c6_u,
    5)), "tp_wait");
  chartInstance.c6_tp_Precondition2 = c6_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c6_u, 6)), "tp_Precondition2");
  chartInstance.c6_tp_Init2 = c6_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c6_u,
    7)), "tp_Init2");
  chartInstance.c6_tp_TDataPre2 = c6_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c6_u, 8)), "tp_TDataPre2");
  chartInstance.c6_is_active_c6_Pedal_Interpretation_Test = c6_emlrt_marshallIn
    (sf_mex_dup(sf_mex_getcell(c6_u, 9)),
     "is_active_c6_Pedal_Interpretation_Test");
  chartInstance.c6_is_c6_Pedal_Interpretation_Test = c6_emlrt_marshallIn
    (sf_mex_dup(sf_mex_getcell(c6_u, 10)),
     "is_c6_Pedal_Interpretation_Test");
  chartInstance.c6_is_Precondition1 = c6_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c6_u, 11)), "is_Precondition1");
  chartInstance.c6_is_Precondition2 = c6_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c6_u, 12)), "is_Precondition2");
  *c6_TDPre = c6_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c6_u, 13)),
    "TDPre");
  chartInstance.c6_temporalCounter_i1 = c6_c_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c6_u, 14)), "temporalCounter_i1");
  sf_mex_destroy(&c6_u);
  update_debugger_state_c6_Pedal_Interpretation_Test();
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_Pedal_Interpretation_Test(void)
{
}

static void sf_c6_Pedal_Interpretation_Test(void)
{
  uint8_T c6_previousEvent;
  real_T *c6_TDPre;
  real_T *c6_Activate;
  c6_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c6_Activate = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,2);
  _SFD_DATA_RANGE_CHECK(*c6_Activate, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_TDPre, 1U);
  c6_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  if (chartInstance.c6_temporalCounter_i1 < 511) {
    chartInstance.c6_temporalCounter_i1 = (uint16_T)
      (chartInstance.c6_temporalCounter_i1 + 1);
  }

  if (chartInstance.c6_is_active_c6_Pedal_Interpretation_Test == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,2);
    chartInstance.c6_is_active_c6_Pedal_Interpretation_Test = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
    chartInstance.c6_is_c6_Pedal_Interpretation_Test = (uint8_T)c6_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
    chartInstance.c6_temporalCounter_i1 = 0U;
    chartInstance.c6_tp_wait = 1U;
    *c6_TDPre = 3.0;
    _SFD_DATA_RANGE_CHECK(*c6_TDPre, 1U);
  } else {
    switch (chartInstance.c6_is_c6_Pedal_Interpretation_Test) {
     case c6_IN_Precondition1:
      CV_CHART_EVAL(2,0,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,0);
      switch (chartInstance.c6_is_Precondition1) {
       case c6_IN_Init1:
        CV_STATE_EVAL(0,0,1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,1);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,2);
        if (CV_TRANSITION_EVAL(2U, (_SFD_CCP_CALL(2,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(2,1,
               ((chartInstance.c6_temporalCounter_i1 >= 50)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
          chartInstance.c6_tp_Init1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
          chartInstance.c6_is_Precondition1 = (uint8_T)c6_IN_TDataPre1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
          chartInstance.c6_temporalCounter_i1 = 0U;
          chartInstance.c6_tp_TDataPre1 = 1U;
          *c6_TDPre = 1.0;
          _SFD_DATA_RANGE_CHECK(*c6_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
        break;

       case c6_IN_Stabilise1:
        CV_STATE_EVAL(0,0,2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,3);
        if (CV_TRANSITION_EVAL(3U, (_SFD_CCP_CALL(3,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(3,1,
               ((chartInstance.c6_temporalCounter_i1 >= 50)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,2);
          chartInstance.c6_tp_Stabilise1 = 0U;
          chartInstance.c6_is_Precondition1 = (uint8_T)c6_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,0);
          chartInstance.c6_tp_Precondition1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
          chartInstance.c6_is_c6_Pedal_Interpretation_Test = (uint8_T)
            c6_IN_Precondition2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
          chartInstance.c6_tp_Precondition2 = 1U;
          chartInstance.c6_is_Precondition2 = (uint8_T)c6_IN_Init2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
          chartInstance.c6_temporalCounter_i1 = 0U;
          chartInstance.c6_tp_Init2 = 1U;
          *c6_TDPre = 2.0;
          _SFD_DATA_RANGE_CHECK(*c6_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
        break;

       case c6_IN_TDataPre1:
        CV_STATE_EVAL(0,0,3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,3);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,4);
        if (CV_TRANSITION_EVAL(4U, (_SFD_CCP_CALL(4,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(4,1,
               ((chartInstance.c6_temporalCounter_i1 >= 100)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,4);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,3);
          chartInstance.c6_tp_TDataPre1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
          chartInstance.c6_is_Precondition1 = (uint8_T)c6_IN_Stabilise1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
          chartInstance.c6_temporalCounter_i1 = 0U;
          chartInstance.c6_tp_Stabilise1 = 1U;
          *c6_TDPre = 1.0;
          _SFD_DATA_RANGE_CHECK(*c6_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
        break;

       default:
        CV_STATE_EVAL(0,0,0);
        chartInstance.c6_is_Precondition1 = (uint8_T)c6_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
      break;

     case c6_IN_Precondition2:
      CV_CHART_EVAL(2,0,2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,4);
      switch (chartInstance.c6_is_Precondition2) {
       case c6_IN_Init2:
        CV_STATE_EVAL(4,0,1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,5);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,5);
        if (CV_TRANSITION_EVAL(5U, (_SFD_CCP_CALL(5,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(5,1,
               ((chartInstance.c6_temporalCounter_i1 >= 50)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,5);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,5);
          chartInstance.c6_tp_Init2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
          chartInstance.c6_is_Precondition2 = (uint8_T)c6_IN_TDataPre2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,7);
          chartInstance.c6_temporalCounter_i1 = 0U;
          chartInstance.c6_tp_TDataPre2 = 1U;
          *c6_TDPre = 2.0;
          _SFD_DATA_RANGE_CHECK(*c6_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
        break;

       case c6_IN_Stabilise2:
        CV_STATE_EVAL(4,0,2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,6);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,6);
        if (CV_TRANSITION_EVAL(6U, (_SFD_CCP_CALL(6,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(6,1,
               ((chartInstance.c6_temporalCounter_i1 >= 50)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,6);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
          chartInstance.c6_tp_Stabilise2 = 0U;
          chartInstance.c6_is_Precondition2 = (uint8_T)c6_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,4);
          chartInstance.c6_tp_Precondition2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
          chartInstance.c6_is_c6_Pedal_Interpretation_Test = (uint8_T)c6_IN_wait;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
          chartInstance.c6_temporalCounter_i1 = 0U;
          chartInstance.c6_tp_wait = 1U;
          *c6_TDPre = 3.0;
          _SFD_DATA_RANGE_CHECK(*c6_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
        break;

       case c6_IN_TDataPre2:
        CV_STATE_EVAL(4,0,3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,7);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,7);
        if (CV_TRANSITION_EVAL(7U, (_SFD_CCP_CALL(7,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(7,1,
               ((chartInstance.c6_temporalCounter_i1 >= 100)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,7);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,7);
          chartInstance.c6_tp_TDataPre2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
          chartInstance.c6_is_Precondition2 = (uint8_T)c6_IN_Stabilise2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
          chartInstance.c6_temporalCounter_i1 = 0U;
          chartInstance.c6_tp_Stabilise2 = 1U;
          *c6_TDPre = 2.0;
          _SFD_DATA_RANGE_CHECK(*c6_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
        break;

       default:
        CV_STATE_EVAL(4,0,0);
        chartInstance.c6_is_Precondition2 = (uint8_T)c6_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
      break;

     case c6_IN_wait:
      CV_CHART_EVAL(2,0,3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,8);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,8);
      if (CV_TRANSITION_EVAL(8U, (_SFD_CCP_CALL(8,0,((1)!=0)) != 0) &&
                             (_SFD_CCP_CALL(8,1,
             ((chartInstance.c6_temporalCounter_i1 >= 400)!=0))
            != 0)) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,8);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,8);
        chartInstance.c6_tp_wait = 0U;
        chartInstance.c6_is_c6_Pedal_Interpretation_Test = (uint8_T)
          c6_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,8);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
        chartInstance.c6_is_c6_Pedal_Interpretation_Test = (uint8_T)
          c6_IN_Precondition1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
        chartInstance.c6_tp_Precondition1 = 1U;
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,1);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
        chartInstance.c6_is_Precondition1 = (uint8_T)c6_IN_Init1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
        chartInstance.c6_temporalCounter_i1 = 0U;
        chartInstance.c6_tp_Init1 = 1U;
        *c6_TDPre = 1.0;
        _SFD_DATA_RANGE_CHECK(*c6_TDPre, 1U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
      break;

     default:
      CV_CHART_EVAL(2,0,0);
      chartInstance.c6_is_c6_Pedal_Interpretation_Test = (uint8_T)
        c6_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
  _sfEvent_ = c6_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_Pedal_Interpretation_TestMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

const mxArray *sf_c6_Pedal_Interpretation_Test_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c6_nameCaptureInfo;
}

static uint8_T c6_emlrt_marshallIn(const mxArray *c6_temporary, char *c6_name)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_name, sf_mex_dup(c6_temporary), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_temporary);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(const mxArray *c6_temporary, char *c6_name)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_name, sf_mex_dup(c6_temporary), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_temporary);
  return c6_y;
}

static uint16_T c6_c_emlrt_marshallIn(const mxArray *c6_temporary, char *c6_name)
{
  uint16_T c6_y;
  uint16_T c6_u1;
  sf_mex_import(c6_name, sf_mex_dup(c6_temporary), &c6_u1, 1, 5, 0U, 0, 0U, 0);
  c6_y = c6_u1;
  sf_mex_destroy(&c6_temporary);
  return c6_y;
}

static const mxArray *c6_emlrt_marshallOut(uint8_T c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 3, 0U, 0U, 0U, 0));
  return c6_y;
}

static const mxArray *c6_b_emlrt_marshallOut(real_T c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0));
  return c6_y;
}

static const mxArray *c6_c_emlrt_marshallOut(uint16_T c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 5, 0U, 0U, 0U, 0));
  return c6_y;
}

static void init_test_point_addr_map(void)
{
  chartInstance.c6_testPointAddrMap[0] = &chartInstance.c6_tp_Precondition1;
  chartInstance.c6_testPointAddrMap[1] = &chartInstance.c6_tp_Init1;
  chartInstance.c6_testPointAddrMap[2] = &chartInstance.c6_tp_Stabilise1;
  chartInstance.c6_testPointAddrMap[3] = &chartInstance.c6_tp_TDataPre1;
  chartInstance.c6_testPointAddrMap[4] = &chartInstance.c6_tp_Precondition2;
  chartInstance.c6_testPointAddrMap[5] = &chartInstance.c6_tp_Init2;
  chartInstance.c6_testPointAddrMap[6] = &chartInstance.c6_tp_Stabilise2;
  chartInstance.c6_testPointAddrMap[7] = &chartInstance.c6_tp_TDataPre2;
  chartInstance.c6_testPointAddrMap[8] = &chartInstance.c6_tp_wait;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c6_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c6_testPointMappingInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c6_Pedal_Interpretation_Test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1582014190U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(116499994U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(28444696U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3319849912U);
}

mxArray *sf_c6_Pedal_Interpretation_Test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2952758515U);
    pr[1] = (double)(2529961958U);
    pr[2] = (double)(1756593623U);
    pr[3] = (double)(2848708843U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Pedal_Interpretation_TestMachineNumber_,
           6,
           9,
           9,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance.chartNumber),
           &(chartInstance.instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_Pedal_Interpretation_TestMachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Pedal_Interpretation_TestMachineNumber_,chartInstance.chartNumber,
             1);
          sf_debug_set_chart_event_thresholds
            (_Pedal_Interpretation_TestMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Activate",0,NULL);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"TDPre",0,
                              NULL);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,1,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,4);
          _SFD_CH_SUBSTATE_INDEX(2,8);
          _SFD_ST_SUBSTATE_COUNT(0,3);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,3);
          _SFD_ST_SUBSTATE_INDEX(4,0,5);
          _SFD_ST_SUBSTATE_INDEX(4,1,6);
          _SFD_ST_SUBSTATE_INDEX(4,2,7);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(2,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(6,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(3,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(4,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(8,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(5,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(7,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(2,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(8,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(7,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          _SFD_TRANS_COV_MAPS(7,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c6_Activate;
          real_T *c6_TDPre;
          c6_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c6_Activate = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_Activate);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_TDPre);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration
      (_Pedal_Interpretation_TestMachineNumber_,chartInstance.chartNumber,
       chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c6_Pedal_Interpretation_Test(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c6_Pedal_Interpretation_Test();
  initialize_c6_Pedal_Interpretation_Test();
}

static void sf_opaque_enable_c6_Pedal_Interpretation_Test(void *chartInstanceVar)
{
  enable_c6_Pedal_Interpretation_Test();
}

static void sf_opaque_disable_c6_Pedal_Interpretation_Test(void
  *chartInstanceVar)
{
  disable_c6_Pedal_Interpretation_Test();
}

static void sf_opaque_gateway_c6_Pedal_Interpretation_Test(void
  *chartInstanceVar)
{
  sf_c6_Pedal_Interpretation_Test();
}

static mxArray* sf_opaque_get_sim_state_c6_Pedal_Interpretation_Test(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c6_Pedal_Interpretation_Test();
  return st;
}

static void sf_opaque_set_sim_state_c6_Pedal_Interpretation_Test(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c6_Pedal_Interpretation_Test(sf_mex_dup(st));
}

static void sf_opaque_terminate_c6_Pedal_Interpretation_Test(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c6_Pedal_Interpretation_Test();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_Pedal_Interpretation_Test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_Pedal_Interpretation_Test();
  }
}

static void mdlSetWorkWidths_c6_Pedal_Interpretation_Test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Pedal_Interpretation_Test",
      "Pedal_Interpretation_Test",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("Pedal_Interpretation_Test",
                "Pedal_Interpretation_Test",6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "Pedal_Interpretation_Test","Pedal_Interpretation_Test",6,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Pedal_Interpretation_Test",
        "Pedal_Interpretation_Test",6,1);
      sf_mark_chart_reusable_outputs(S,"Pedal_Interpretation_Test",
        "Pedal_Interpretation_Test",6,1);
    }

    sf_set_rtw_dwork_info(S,"Pedal_Interpretation_Test",
                          "Pedal_Interpretation_Test",6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(853900340U));
  ssSetChecksum1(S,(3206552671U));
  ssSetChecksum2(S,(2039073706U));
  ssSetChecksum3(S,(1489251310U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_Pedal_Interpretation_Test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Pedal_Interpretation_Test",
      "Pedal_Interpretation_Test",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c6_Pedal_Interpretation_Test(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_Pedal_Interpretation_Test;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c6_Pedal_Interpretation_Test;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c6_Pedal_Interpretation_Test;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c6_Pedal_Interpretation_Test;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c6_Pedal_Interpretation_Test;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_Pedal_Interpretation_Test;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_Pedal_Interpretation_Test;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c6_Pedal_Interpretation_Test;
  chartInstance.chartInfo.mdlStart = mdlStart_c6_Pedal_Interpretation_Test;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_Pedal_Interpretation_Test;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
    init_dsm_address_info();
  }

  chart_debug_initialization(S,1);
}

void c6_Pedal_Interpretation_Test_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_Pedal_Interpretation_Test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_Pedal_Interpretation_Test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_Pedal_Interpretation_Test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_Pedal_Interpretation_Test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/Precondition1", "Precondition1", 0, 0, 0, 0, 0 },

  { 1, 0, "StateflowChart/Precondition1.Init1", "Init1", 0, 0, 0, 0, 0 },

  { 2, 0, "StateflowChart/Precondition1.Stabilise1", "Stabilise1", 0, 0, 0, 0, 0
  },

  { 3, 0, "StateflowChart/Precondition1.TDataPre1", "TDataPre1", 0, 0, 0, 0, 0 },

  { 4, 0, "StateflowChart/Precondition2", "Precondition2", 0, 0, 0, 0, 0 },

  { 5, 0, "StateflowChart/Precondition2.Init2", "Init2", 0, 0, 0, 0, 0 },

  { 6, 0, "StateflowChart/Precondition2.Stabilise2", "Stabilise2", 0, 0, 0, 0, 0
  },

  { 7, 0, "StateflowChart/Precondition2.TDataPre2", "TDataPre2", 0, 0, 0, 0, 0 },

  { 8, 0, "StateflowChart/wait", "wait", 0, 0, 0, 0, 0 } };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    9                                  /* Num Block IO signals */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float"
};

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  init_test_point_addr_map();
  testPointMappingInfo = get_test_point_mapping_info();
  testPointAddrMap = get_test_point_address_map();
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}
