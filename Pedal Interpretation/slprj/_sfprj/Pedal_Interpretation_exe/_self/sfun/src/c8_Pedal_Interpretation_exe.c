/* Include files */

#include "Pedal_Interpretation_exe_sfun.h"
#include "c8_Pedal_Interpretation_exe.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "Pedal_Interpretation_exe_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c8_IN_NO_ACTIVE_CHILD          (0)
#define c8_IN_TDataPre1                (3)
#define c8_IN_Init1                    (1)
#define c8_IN_Stabilise1               (2)
#define c8_IN_Precondition1            (1)
#define c8_IN_Stabilise6               (2)
#define c8_IN_wait                     (7)
#define c8_IN_Precondition2            (2)
#define c8_IN_Init2                    (1)
#define c8_IN_TDataPre2                (3)
#define c8_IN_Stabilise2               (2)
#define c8_IN_Precondition3            (3)
#define c8_IN_Init3                    (1)
#define c8_IN_TDataPre3                (3)
#define c8_IN_Stabilise3               (2)
#define c8_IN_Precondition4            (4)
#define c8_IN_Init4                    (1)
#define c8_IN_TDataPre4                (3)
#define c8_IN_Stabilise4               (2)
#define c8_IN_Precondition5            (5)
#define c8_IN_Init5                    (1)
#define c8_IN_TDataPre5                (3)
#define c8_IN_Stabilise5               (2)
#define c8_IN_Precondition6            (6)
#define c8_IN_Init6                    (1)
#define c8_IN_TDataPre6                (3)

/* Variable Declarations */

/* Variable Definitions */
static SFc8_Pedal_Interpretation_exeInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c8_Pedal_Interpretation_exe(void);
static void initialize_params_c8_Pedal_Interpretation_exe(void);
static void enable_c8_Pedal_Interpretation_exe(void);
static void disable_c8_Pedal_Interpretation_exe(void);
static void update_debugger_state_c8_Pedal_Interpretation_exe(void);
static const mxArray *get_sim_state_c8_Pedal_Interpretation_exe(void);
static void set_sim_state_c8_Pedal_Interpretation_exe(const mxArray *c8_st);
static void finalize_c8_Pedal_Interpretation_exe(void);
static void sf_c8_Pedal_Interpretation_exe(void);
static void c8_chartstep_c8_Pedal_Interpretation_exe(void);
static void c8_Precondition1(void);
static void c8_Precondition2(void);
static void c8_Precondition3(void);
static void c8_Precondition4(void);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c8_Pedal_Interpretation_exe(void)
{
  real_T *c8_TDPre;
  c8_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c8_is_Precondition1 = 0U;
  chartInstance.c8_tp_Precondition1 = 0U;
  chartInstance.c8_tp_Init1 = 0U;
  chartInstance.c8_tp_Stabilise1 = 0U;
  chartInstance.c8_tp_TDataPre1 = 0U;
  chartInstance.c8_is_Precondition2 = 0U;
  chartInstance.c8_tp_Precondition2 = 0U;
  chartInstance.c8_tp_Init2 = 0U;
  chartInstance.c8_tp_Stabilise2 = 0U;
  chartInstance.c8_tp_TDataPre2 = 0U;
  chartInstance.c8_is_Precondition3 = 0U;
  chartInstance.c8_tp_Precondition3 = 0U;
  chartInstance.c8_tp_Init3 = 0U;
  chartInstance.c8_tp_Stabilise3 = 0U;
  chartInstance.c8_tp_TDataPre3 = 0U;
  chartInstance.c8_is_Precondition4 = 0U;
  chartInstance.c8_tp_Precondition4 = 0U;
  chartInstance.c8_tp_Init4 = 0U;
  chartInstance.c8_tp_Stabilise4 = 0U;
  chartInstance.c8_tp_TDataPre4 = 0U;
  chartInstance.c8_is_Precondition5 = 0U;
  chartInstance.c8_tp_Precondition5 = 0U;
  chartInstance.c8_tp_Init5 = 0U;
  chartInstance.c8_tp_Stabilise5 = 0U;
  chartInstance.c8_tp_TDataPre5 = 0U;
  chartInstance.c8_is_Precondition6 = 0U;
  chartInstance.c8_tp_Precondition6 = 0U;
  chartInstance.c8_tp_Init6 = 0U;
  chartInstance.c8_tp_Stabilise6 = 0U;
  chartInstance.c8_tp_TDataPre6 = 0U;
  chartInstance.c8_tp_wait = 0U;
  chartInstance.c8_is_active_c8_Pedal_Interpretation_exe = 0U;
  chartInstance.c8_is_c8_Pedal_Interpretation_exe = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c8_TDPre = 0.0;
  }
}

static void initialize_params_c8_Pedal_Interpretation_exe(void)
{
}

static void enable_c8_Pedal_Interpretation_exe(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c8_Pedal_Interpretation_exe(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void update_debugger_state_c8_Pedal_Interpretation_exe(void)
{
  uint32_T c8_prevAniVal;
  c8_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if (chartInstance.c8_is_active_c8_Pedal_Interpretation_exe == 1) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,4);
  }

  if (chartInstance.c8_is_Precondition1 == c8_IN_TDataPre1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
  }

  if (chartInstance.c8_is_Precondition1 == c8_IN_Init1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
  }

  if (chartInstance.c8_is_Precondition1 == c8_IN_Stabilise1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
  }

  if (chartInstance.c8_is_c8_Pedal_Interpretation_exe == c8_IN_Precondition1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
  }

  if (chartInstance.c8_is_Precondition6 == c8_IN_Stabilise6) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,22);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,22);
  }

  if (chartInstance.c8_is_c8_Pedal_Interpretation_exe == c8_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,24);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,24);
  }

  if (chartInstance.c8_is_c8_Pedal_Interpretation_exe == c8_IN_Precondition2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
  }

  if (chartInstance.c8_is_Precondition2 == c8_IN_Init2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
  }

  if (chartInstance.c8_is_Precondition2 == c8_IN_TDataPre2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,7);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
  }

  if (chartInstance.c8_is_Precondition2 == c8_IN_Stabilise2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
  }

  if (chartInstance.c8_is_c8_Pedal_Interpretation_exe == c8_IN_Precondition3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,8);
  }

  if (chartInstance.c8_is_Precondition3 == c8_IN_Init3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,9);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,9);
  }

  if (chartInstance.c8_is_Precondition3 == c8_IN_TDataPre3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
  }

  if (chartInstance.c8_is_Precondition3 == c8_IN_Stabilise3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,10);
  }

  if (chartInstance.c8_is_c8_Pedal_Interpretation_exe == c8_IN_Precondition4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
  }

  if (chartInstance.c8_is_Precondition4 == c8_IN_Init4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
  }

  if (chartInstance.c8_is_Precondition4 == c8_IN_TDataPre4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,15);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,15);
  }

  if (chartInstance.c8_is_Precondition4 == c8_IN_Stabilise4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,14);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,14);
  }

  if (chartInstance.c8_is_c8_Pedal_Interpretation_exe == c8_IN_Precondition5) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,16);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,16);
  }

  if (chartInstance.c8_is_Precondition5 == c8_IN_Init5) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,17);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,17);
  }

  if (chartInstance.c8_is_Precondition5 == c8_IN_TDataPre5) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,19);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,19);
  }

  if (chartInstance.c8_is_Precondition5 == c8_IN_Stabilise5) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,18);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,18);
  }

  if (chartInstance.c8_is_c8_Pedal_Interpretation_exe == c8_IN_Precondition6) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,20);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,20);
  }

  if (chartInstance.c8_is_Precondition6 == c8_IN_Init6) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,21);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,21);
  }

  if (chartInstance.c8_is_Precondition6 == c8_IN_TDataPre6) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,23);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,23);
  }

  sf_debug_set_animation(c8_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c8_Pedal_Interpretation_exe(void)
{
  return NULL;
}

static void set_sim_state_c8_Pedal_Interpretation_exe(const mxArray *c8_st)
{
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_Pedal_Interpretation_exe(void)
{
}

static void sf_c8_Pedal_Interpretation_exe(void)
{
  uint8_T c8_previousEvent;
  uint8_T *c8_Activate;
  real_T *c8_TDPre;
  uint8_T *c8_Activate1;
  uint8_T *c8_Activate2;
  uint8_T *c8_Activate3;
  uint8_T *c8_Activate4;
  c8_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c8_Activate3 = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c8_Activate = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c8_Activate2 = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c8_Activate1 = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c8_Activate4 = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 4);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,4);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_Activate, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_Activate1, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_Activate2, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_Activate3, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_Activate4, 5U);
  c8_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c8_chartstep_c8_Pedal_Interpretation_exe();
  _sfEvent_ = c8_previousEvent;
  sf_debug_check_for_state_inconsistency(_Pedal_Interpretation_exeMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void c8_chartstep_c8_Pedal_Interpretation_exe(void)
{
  real_T *c8_TDPre;
  c8_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,4);
  if (chartInstance.c8_temporalCounter_i1 < 1023) {
    chartInstance.c8_temporalCounter_i1 = (uint16_T)
      (chartInstance.c8_temporalCounter_i1 + 1);
  }

  if (chartInstance.c8_is_active_c8_Pedal_Interpretation_exe == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,4);
    chartInstance.c8_is_active_c8_Pedal_Interpretation_exe = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
    chartInstance.c8_is_c8_Pedal_Interpretation_exe = (uint8_T)c8_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,24);
    chartInstance.c8_temporalCounter_i1 = 0U;
    chartInstance.c8_tp_wait = 1U;
    *c8_TDPre = 7.0;
    _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
  } else {
    switch (chartInstance.c8_is_c8_Pedal_Interpretation_exe) {
     case c8_IN_Precondition1:
      CV_CHART_EVAL(4,0,1);
      c8_Precondition1();
      break;

     case c8_IN_Precondition2:
      CV_CHART_EVAL(4,0,2);
      c8_Precondition2();
      break;

     case c8_IN_Precondition3:
      CV_CHART_EVAL(4,0,3);
      c8_Precondition3();
      break;

     case c8_IN_Precondition4:
      CV_CHART_EVAL(4,0,4);
      c8_Precondition4();
      break;

     case c8_IN_Precondition5:
      CV_CHART_EVAL(4,0,5);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,16);
      switch (chartInstance.c8_is_Precondition5) {
       case c8_IN_Init5:
        CV_STATE_EVAL(16,0,1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,17);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,14);
        if (CV_TRANSITION_EVAL(14U, (_SFD_CCP_CALL(14,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(14,1,
               ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,14);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,17);
          chartInstance.c8_tp_Init5 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,17);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,17);
          chartInstance.c8_is_Precondition5 = (uint8_T)c8_IN_TDataPre5;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,19);
          chartInstance.c8_temporalCounter_i1 = 0U;
          chartInstance.c8_tp_TDataPre5 = 1U;
          *c8_TDPre = 5.0;
          _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,17);
        break;

       case c8_IN_Stabilise5:
        CV_STATE_EVAL(16,0,2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,18);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,15);
        if (CV_TRANSITION_EVAL(15U, (_SFD_CCP_CALL(15,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(15,1,
               ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,15);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,18);
          chartInstance.c8_tp_Stabilise5 = 0U;
          chartInstance.c8_is_Precondition5 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,18);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,18);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,16);
          chartInstance.c8_tp_Precondition5 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,16);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,16);
          chartInstance.c8_is_c8_Pedal_Interpretation_exe = (uint8_T)
            c8_IN_Precondition6;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,20);
          chartInstance.c8_tp_Precondition6 = 1U;
          chartInstance.c8_is_Precondition6 = (uint8_T)c8_IN_Init6;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,21);
          chartInstance.c8_temporalCounter_i1 = 0U;
          chartInstance.c8_tp_Init6 = 1U;
          *c8_TDPre = 6.0;
          _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,18);
        break;

       case c8_IN_TDataPre5:
        CV_STATE_EVAL(16,0,3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,19);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,16);
        if (CV_TRANSITION_EVAL(16U, (_SFD_CCP_CALL(16,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(16,1,
               ((chartInstance.c8_temporalCounter_i1 >= 100)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,16);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,19);
          chartInstance.c8_tp_TDataPre5 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,19);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,19);
          chartInstance.c8_is_Precondition5 = (uint8_T)c8_IN_Stabilise5;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,18);
          chartInstance.c8_temporalCounter_i1 = 0U;
          chartInstance.c8_tp_Stabilise5 = 1U;
          *c8_TDPre = 5.0;
          _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,19);
        break;

       default:
        CV_STATE_EVAL(16,0,0);
        chartInstance.c8_is_Precondition5 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,17);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,16);
      break;

     case c8_IN_Precondition6:
      CV_CHART_EVAL(4,0,6);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,20);
      switch (chartInstance.c8_is_Precondition6) {
       case c8_IN_Init6:
        CV_STATE_EVAL(20,0,1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,21);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,17);
        if (CV_TRANSITION_EVAL(17U, (_SFD_CCP_CALL(17,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(17,1,
               ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,17);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,21);
          chartInstance.c8_tp_Init6 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,21);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,21);
          chartInstance.c8_is_Precondition6 = (uint8_T)c8_IN_TDataPre6;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,23);
          chartInstance.c8_temporalCounter_i1 = 0U;
          chartInstance.c8_tp_TDataPre6 = 1U;
          *c8_TDPre = 6.0;
          _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,21);
        break;

       case c8_IN_Stabilise6:
        CV_STATE_EVAL(20,0,2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,22);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,18);
        if (CV_TRANSITION_EVAL(18U, (_SFD_CCP_CALL(18,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(18,1,
               ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,18);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,22);
          chartInstance.c8_tp_Stabilise6 = 0U;
          chartInstance.c8_is_Precondition6 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,22);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,22);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,20);
          chartInstance.c8_tp_Precondition6 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,20);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,20);
          chartInstance.c8_is_c8_Pedal_Interpretation_exe = (uint8_T)c8_IN_wait;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,24);
          chartInstance.c8_temporalCounter_i1 = 0U;
          chartInstance.c8_tp_wait = 1U;
          *c8_TDPre = 7.0;
          _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,22);
        break;

       case c8_IN_TDataPre6:
        CV_STATE_EVAL(20,0,3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,23);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,19);
        if (CV_TRANSITION_EVAL(19U, (_SFD_CCP_CALL(19,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(19,1,
               ((chartInstance.c8_temporalCounter_i1 >= 100)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,19);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,23);
          chartInstance.c8_tp_TDataPre6 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,23);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,23);
          chartInstance.c8_is_Precondition6 = (uint8_T)c8_IN_Stabilise6;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,22);
          chartInstance.c8_temporalCounter_i1 = 0U;
          chartInstance.c8_tp_Stabilise6 = 1U;
          *c8_TDPre = 6.0;
          _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,23);
        break;

       default:
        CV_STATE_EVAL(20,0,0);
        chartInstance.c8_is_Precondition6 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,21);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,20);
      break;

     case c8_IN_wait:
      CV_CHART_EVAL(4,0,7);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,24);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,20);
      if (CV_TRANSITION_EVAL(20U, (_SFD_CCP_CALL(20,0,((1)!=0)) != 0) &&
                             (_SFD_CCP_CALL(20,1,
             ((chartInstance.c8_temporalCounter_i1 >= 1000)!=0))
            != 0)) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,20);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,24);
        chartInstance.c8_tp_wait = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,24);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,24);
        chartInstance.c8_is_c8_Pedal_Interpretation_exe = (uint8_T)
          c8_IN_Precondition1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
        chartInstance.c8_tp_Precondition1 = 1U;
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,1);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
        chartInstance.c8_is_Precondition1 = (uint8_T)c8_IN_Init1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
        chartInstance.c8_temporalCounter_i1 = 0U;
        chartInstance.c8_tp_Init1 = 1U;
        *c8_TDPre = 1.0;
        _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,24);
      break;

     default:
      CV_CHART_EVAL(4,0,0);
      chartInstance.c8_is_c8_Pedal_Interpretation_exe = (uint8_T)
        c8_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
}

static void c8_Precondition1(void)
{
  real_T *c8_TDPre;
  c8_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,0);
  switch (chartInstance.c8_is_Precondition1) {
   case c8_IN_Init1:
    CV_STATE_EVAL(0,0,1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,2);
    if (CV_TRANSITION_EVAL(2U, (_SFD_CCP_CALL(2,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(2,1,
           ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
      chartInstance.c8_tp_Init1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
      chartInstance.c8_is_Precondition1 = (uint8_T)c8_IN_TDataPre1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_TDataPre1 = 1U;
      *c8_TDPre = 1.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
    break;

   case c8_IN_Stabilise1:
    CV_STATE_EVAL(0,0,2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,3);
    if (CV_TRANSITION_EVAL(3U, (_SFD_CCP_CALL(3,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(3,1,
           ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,2);
      chartInstance.c8_tp_Stabilise1 = 0U;
      chartInstance.c8_is_Precondition1 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,0);
      chartInstance.c8_tp_Precondition1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
      chartInstance.c8_is_c8_Pedal_Interpretation_exe = (uint8_T)
        c8_IN_Precondition2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
      chartInstance.c8_tp_Precondition2 = 1U;
      chartInstance.c8_is_Precondition2 = (uint8_T)c8_IN_Init2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_Init2 = 1U;
      *c8_TDPre = 2.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
    break;

   case c8_IN_TDataPre1:
    CV_STATE_EVAL(0,0,3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,4);
    if (CV_TRANSITION_EVAL(4U, (_SFD_CCP_CALL(4,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(4,1,
           ((chartInstance.c8_temporalCounter_i1 >= 100)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,4);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,3);
      chartInstance.c8_tp_TDataPre1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
      chartInstance.c8_is_Precondition1 = (uint8_T)c8_IN_Stabilise1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_Stabilise1 = 1U;
      *c8_TDPre = 1.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
    break;

   default:
    CV_STATE_EVAL(0,0,0);
    chartInstance.c8_is_Precondition1 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void c8_Precondition2(void)
{
  real_T *c8_TDPre;
  c8_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,4);
  switch (chartInstance.c8_is_Precondition2) {
   case c8_IN_Init2:
    CV_STATE_EVAL(4,0,1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,5);
    if (CV_TRANSITION_EVAL(5U, (_SFD_CCP_CALL(5,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(5,1,
           ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,5);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,5);
      chartInstance.c8_tp_Init2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
      chartInstance.c8_is_Precondition2 = (uint8_T)c8_IN_TDataPre2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,7);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_TDataPre2 = 1U;
      *c8_TDPre = 2.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
    break;

   case c8_IN_Stabilise2:
    CV_STATE_EVAL(4,0,2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,6);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,6);
    if (CV_TRANSITION_EVAL(6U, (_SFD_CCP_CALL(6,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(6,1,
           ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,6);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
      chartInstance.c8_tp_Stabilise2 = 0U;
      chartInstance.c8_is_Precondition2 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,4);
      chartInstance.c8_tp_Precondition2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
      chartInstance.c8_is_c8_Pedal_Interpretation_exe = (uint8_T)
        c8_IN_Precondition3;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
      chartInstance.c8_tp_Precondition3 = 1U;
      chartInstance.c8_is_Precondition3 = (uint8_T)c8_IN_Init3;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,9);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_Init3 = 1U;
      *c8_TDPre = 3.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
    break;

   case c8_IN_TDataPre2:
    CV_STATE_EVAL(4,0,3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,7);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,7);
    if (CV_TRANSITION_EVAL(7U, (_SFD_CCP_CALL(7,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(7,1,
           ((chartInstance.c8_temporalCounter_i1 >= 100)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,7);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,7);
      chartInstance.c8_tp_TDataPre2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
      chartInstance.c8_is_Precondition2 = (uint8_T)c8_IN_Stabilise2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_Stabilise2 = 1U;
      *c8_TDPre = 2.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
    break;

   default:
    CV_STATE_EVAL(4,0,0);
    chartInstance.c8_is_Precondition2 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
}

static void c8_Precondition3(void)
{
  real_T *c8_TDPre;
  c8_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,8);
  switch (chartInstance.c8_is_Precondition3) {
   case c8_IN_Init3:
    CV_STATE_EVAL(8,0,1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,9);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,8);
    if (CV_TRANSITION_EVAL(8U, (_SFD_CCP_CALL(8,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(8,1,
           ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,8);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,9);
      chartInstance.c8_tp_Init3 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,9);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
      chartInstance.c8_is_Precondition3 = (uint8_T)c8_IN_TDataPre3;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_TDataPre3 = 1U;
      *c8_TDPre = 3.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
    break;

   case c8_IN_Stabilise3:
    CV_STATE_EVAL(8,0,2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,10);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,9);
    if (CV_TRANSITION_EVAL(9U, (_SFD_CCP_CALL(9,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(9,1,
           ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,9);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,10);
      chartInstance.c8_tp_Stabilise3 = 0U;
      chartInstance.c8_is_Precondition3 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,10);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,8);
      chartInstance.c8_tp_Precondition3 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,8);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
      chartInstance.c8_is_c8_Pedal_Interpretation_exe = (uint8_T)
        c8_IN_Precondition4;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
      chartInstance.c8_tp_Precondition4 = 1U;
      chartInstance.c8_is_Precondition4 = (uint8_T)c8_IN_Init4;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_Init4 = 1U;
      *c8_TDPre = 4.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
    break;

   case c8_IN_TDataPre3:
    CV_STATE_EVAL(8,0,3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,11);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,10);
    if (CV_TRANSITION_EVAL(10U, (_SFD_CCP_CALL(10,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(10,1,
           ((chartInstance.c8_temporalCounter_i1 >= 100)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,10);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,11);
      chartInstance.c8_tp_TDataPre3 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
      chartInstance.c8_is_Precondition3 = (uint8_T)c8_IN_Stabilise3;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_Stabilise3 = 1U;
      *c8_TDPre = 3.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
    break;

   default:
    CV_STATE_EVAL(8,0,0);
    chartInstance.c8_is_Precondition3 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,9);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
}

static void c8_Precondition4(void)
{
  real_T *c8_TDPre;
  c8_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,12);
  switch (chartInstance.c8_is_Precondition4) {
   case c8_IN_Init4:
    CV_STATE_EVAL(12,0,1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,13);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,11);
    if (CV_TRANSITION_EVAL(11U, (_SFD_CCP_CALL(11,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(11,1,
           ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,11);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,13);
      chartInstance.c8_tp_Init4 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
      chartInstance.c8_is_Precondition4 = (uint8_T)c8_IN_TDataPre4;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,15);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_TDataPre4 = 1U;
      *c8_TDPre = 4.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
    break;

   case c8_IN_Stabilise4:
    CV_STATE_EVAL(12,0,2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,14);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,12);
    if (CV_TRANSITION_EVAL(12U, (_SFD_CCP_CALL(12,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(12,1,
           ((chartInstance.c8_temporalCounter_i1 >= 50)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,12);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,14);
      chartInstance.c8_tp_Stabilise4 = 0U;
      chartInstance.c8_is_Precondition4 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,14);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,14);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
      chartInstance.c8_tp_Precondition4 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
      chartInstance.c8_is_c8_Pedal_Interpretation_exe = (uint8_T)
        c8_IN_Precondition5;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,16);
      chartInstance.c8_tp_Precondition5 = 1U;
      chartInstance.c8_is_Precondition5 = (uint8_T)c8_IN_Init5;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,17);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_Init5 = 1U;
      *c8_TDPre = 5.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,14);
    break;

   case c8_IN_TDataPre4:
    CV_STATE_EVAL(12,0,3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,15);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,13);
    if (CV_TRANSITION_EVAL(13U, (_SFD_CCP_CALL(13,0,((1)!=0)) != 0) &&
                           (_SFD_CCP_CALL(13,1,
           ((chartInstance.c8_temporalCounter_i1 >= 100)!=0))
          != 0)) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,13);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,15);
      chartInstance.c8_tp_TDataPre4 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,15);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,15);
      chartInstance.c8_is_Precondition4 = (uint8_T)c8_IN_Stabilise4;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,14);
      chartInstance.c8_temporalCounter_i1 = 0U;
      chartInstance.c8_tp_Stabilise4 = 1U;
      *c8_TDPre = 4.0;
      _SFD_DATA_RANGE_CHECK(*c8_TDPre, 1U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,15);
    break;

   default:
    CV_STATE_EVAL(12,0,0);
    chartInstance.c8_is_Precondition4 = (uint8_T)c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

const mxArray *sf_c8_Pedal_Interpretation_exe_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c8_nameCaptureInfo;
}

static void init_test_point_addr_map(void)
{
  chartInstance.c8_testPointAddrMap[0] = &chartInstance.c8_tp_Precondition1;
  chartInstance.c8_testPointAddrMap[1] = &chartInstance.c8_tp_Init1;
  chartInstance.c8_testPointAddrMap[2] = &chartInstance.c8_tp_Stabilise1;
  chartInstance.c8_testPointAddrMap[3] = &chartInstance.c8_tp_TDataPre1;
  chartInstance.c8_testPointAddrMap[4] = &chartInstance.c8_tp_Precondition2;
  chartInstance.c8_testPointAddrMap[5] = &chartInstance.c8_tp_Init2;
  chartInstance.c8_testPointAddrMap[6] = &chartInstance.c8_tp_Stabilise2;
  chartInstance.c8_testPointAddrMap[7] = &chartInstance.c8_tp_TDataPre2;
  chartInstance.c8_testPointAddrMap[8] = &chartInstance.c8_tp_Precondition3;
  chartInstance.c8_testPointAddrMap[9] = &chartInstance.c8_tp_Init3;
  chartInstance.c8_testPointAddrMap[10] = &chartInstance.c8_tp_Stabilise3;
  chartInstance.c8_testPointAddrMap[11] = &chartInstance.c8_tp_TDataPre3;
  chartInstance.c8_testPointAddrMap[12] = &chartInstance.c8_tp_Precondition4;
  chartInstance.c8_testPointAddrMap[13] = &chartInstance.c8_tp_Init4;
  chartInstance.c8_testPointAddrMap[14] = &chartInstance.c8_tp_Stabilise4;
  chartInstance.c8_testPointAddrMap[15] = &chartInstance.c8_tp_TDataPre4;
  chartInstance.c8_testPointAddrMap[16] = &chartInstance.c8_tp_Precondition5;
  chartInstance.c8_testPointAddrMap[17] = &chartInstance.c8_tp_Init5;
  chartInstance.c8_testPointAddrMap[18] = &chartInstance.c8_tp_Stabilise5;
  chartInstance.c8_testPointAddrMap[19] = &chartInstance.c8_tp_TDataPre5;
  chartInstance.c8_testPointAddrMap[20] = &chartInstance.c8_tp_Precondition6;
  chartInstance.c8_testPointAddrMap[21] = &chartInstance.c8_tp_Init6;
  chartInstance.c8_testPointAddrMap[22] = &chartInstance.c8_tp_Stabilise6;
  chartInstance.c8_testPointAddrMap[23] = &chartInstance.c8_tp_TDataPre6;
  chartInstance.c8_testPointAddrMap[24] = &chartInstance.c8_tp_wait;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c8_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c8_testPointMappingInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c8_Pedal_Interpretation_exe_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3334991046U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3595301368U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3057833255U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3013732514U);
}

mxArray *sf_c8_Pedal_Interpretation_exe_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3803278118U);
    pr[1] = (double)(1615035405U);
    pr[2] = (double)(3085795291U);
    pr[3] = (double)(991962313U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
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
          (_Pedal_Interpretation_exeMachineNumber_,
           8,
           25,
           21,
           6,
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
          init_script_number_translation(_Pedal_Interpretation_exeMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Pedal_Interpretation_exeMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_Pedal_Interpretation_exeMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"Activate",
                              0,NULL);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"TDPre",0,
                              NULL);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "Activate1",0,NULL);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "Activate2",0,NULL);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "Activate3",0,NULL);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "Activate4",0,NULL);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,1,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,0);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(23,0,0);
          _SFD_STATE_INFO(24,0,0);
          _SFD_CH_SUBSTATE_COUNT(7);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,4);
          _SFD_CH_SUBSTATE_INDEX(2,8);
          _SFD_CH_SUBSTATE_INDEX(3,12);
          _SFD_CH_SUBSTATE_INDEX(4,16);
          _SFD_CH_SUBSTATE_INDEX(5,20);
          _SFD_CH_SUBSTATE_INDEX(6,24);
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
          _SFD_ST_SUBSTATE_COUNT(8,3);
          _SFD_ST_SUBSTATE_INDEX(8,0,9);
          _SFD_ST_SUBSTATE_INDEX(8,1,10);
          _SFD_ST_SUBSTATE_INDEX(8,2,11);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,3);
          _SFD_ST_SUBSTATE_INDEX(12,0,13);
          _SFD_ST_SUBSTATE_INDEX(12,1,14);
          _SFD_ST_SUBSTATE_INDEX(12,2,15);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,3);
          _SFD_ST_SUBSTATE_INDEX(16,0,17);
          _SFD_ST_SUBSTATE_INDEX(16,1,18);
          _SFD_ST_SUBSTATE_INDEX(16,2,19);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(20,3);
          _SFD_ST_SUBSTATE_INDEX(20,0,21);
          _SFD_ST_SUBSTATE_INDEX(20,1,22);
          _SFD_ST_SUBSTATE_INDEX(20,2,23);
          _SFD_ST_SUBSTATE_COUNT(21,0);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(23,0);
          _SFD_ST_SUBSTATE_COUNT(24,0);
        }

        _SFD_CV_INIT_CHART(7,1,0,0);

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
          _SFD_CV_INIT_STATE(8,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(23,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(24,0,0,0,0,0,NULL,NULL);
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

          _SFD_CV_INIT_TRANS(18,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(15,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
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
          static unsigned int sStartGuardMap[] = { 12, 0 };

          static unsigned int sEndGuardMap[] = { 16, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(20,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
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

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(3,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(8,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(10,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
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

          _SFD_CV_INIT_TRANS(11,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(13,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(9,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(14,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(16,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(12,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(17,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(19,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
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

        _SFD_TRANS_COV_WTS(18,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(18,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(15,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(15,
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

        _SFD_TRANS_COV_WTS(20,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 12, 0 };

          static unsigned int sEndGuardMap[] = { 16, 17 };

          _SFD_TRANS_COV_MAPS(20,
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

        _SFD_TRANS_COV_WTS(8,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(10,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          _SFD_TRANS_COV_MAPS(10,
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

        _SFD_TRANS_COV_WTS(11,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(11,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(13,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          _SFD_TRANS_COV_MAPS(13,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(14,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(14,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(16,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          _SFD_TRANS_COV_MAPS(16,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(12,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(12,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(17,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          _SFD_TRANS_COV_MAPS(17,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(19,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          _SFD_TRANS_COV_MAPS(19,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          uint8_T *c8_Activate;
          real_T *c8_TDPre;
          uint8_T *c8_Activate1;
          uint8_T *c8_Activate2;
          uint8_T *c8_Activate3;
          uint8_T *c8_Activate4;
          c8_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c8_Activate3 = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c8_Activate = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c8_Activate2 = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c8_Activate1 = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c8_Activate4 = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 4);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_Activate);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_TDPre);
          _SFD_SET_DATA_VALUE_PTR(2U, c8_Activate1);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_Activate2);
          _SFD_SET_DATA_VALUE_PTR(4U, c8_Activate3);
          _SFD_SET_DATA_VALUE_PTR(5U, c8_Activate4);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration
      (_Pedal_Interpretation_exeMachineNumber_,chartInstance.chartNumber,
       chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c8_Pedal_Interpretation_exe(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c8_Pedal_Interpretation_exe();
  initialize_c8_Pedal_Interpretation_exe();
}

static void sf_opaque_enable_c8_Pedal_Interpretation_exe(void *chartInstanceVar)
{
  enable_c8_Pedal_Interpretation_exe();
}

static void sf_opaque_disable_c8_Pedal_Interpretation_exe(void *chartInstanceVar)
{
  disable_c8_Pedal_Interpretation_exe();
}

static void sf_opaque_gateway_c8_Pedal_Interpretation_exe(void *chartInstanceVar)
{
  sf_c8_Pedal_Interpretation_exe();
}

static mxArray* sf_opaque_get_sim_state_c8_Pedal_Interpretation_exe(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c8_Pedal_Interpretation_exe();
  return st;
}

static void sf_opaque_set_sim_state_c8_Pedal_Interpretation_exe(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c8_Pedal_Interpretation_exe(sf_mex_dup(st));
}

static void sf_opaque_terminate_c8_Pedal_Interpretation_exe(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c8_Pedal_Interpretation_exe();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_Pedal_Interpretation_exe(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_Pedal_Interpretation_exe();
  }
}

static void mdlSetWorkWidths_c8_Pedal_Interpretation_exe(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Pedal_Interpretation_exe",
      "Pedal_Interpretation_exe",8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("Pedal_Interpretation_exe",
                "Pedal_Interpretation_exe",8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Pedal_Interpretation_exe",
      "Pedal_Interpretation_exe",8,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Pedal_Interpretation_exe",
        "Pedal_Interpretation_exe",8,5);
      sf_mark_chart_reusable_outputs(S,"Pedal_Interpretation_exe",
        "Pedal_Interpretation_exe",8,1);
    }

    sf_set_rtw_dwork_info(S,"Pedal_Interpretation_exe",
                          "Pedal_Interpretation_exe",8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3983199132U));
  ssSetChecksum1(S,(3712116634U));
  ssSetChecksum2(S,(1133718442U));
  ssSetChecksum3(S,(1866300385U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_Pedal_Interpretation_exe(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Pedal_Interpretation_exe",
      "Pedal_Interpretation_exe",8);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c8_Pedal_Interpretation_exe(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_Pedal_Interpretation_exe;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c8_Pedal_Interpretation_exe;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c8_Pedal_Interpretation_exe;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c8_Pedal_Interpretation_exe;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c8_Pedal_Interpretation_exe;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_Pedal_Interpretation_exe;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_Pedal_Interpretation_exe;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c8_Pedal_Interpretation_exe;
  chartInstance.chartInfo.mdlStart = mdlStart_c8_Pedal_Interpretation_exe;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_Pedal_Interpretation_exe;
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

void c8_Pedal_Interpretation_exe_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_Pedal_Interpretation_exe(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_Pedal_Interpretation_exe(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_Pedal_Interpretation_exe(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_Pedal_Interpretation_exe_method_dispatcher.\n"
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

  { 8, 0, "StateflowChart/Precondition3", "Precondition3", 0, 0, 0, 0, 0 },

  { 9, 0, "StateflowChart/Precondition3.Init3", "Init3", 0, 0, 0, 0, 0 },

  { 10, 0, "StateflowChart/Precondition3.Stabilise3", "Stabilise3", 0, 0, 0, 0,
    0 },

  { 11, 0, "StateflowChart/Precondition3.TDataPre3", "TDataPre3", 0, 0, 0, 0, 0
  },

  { 12, 0, "StateflowChart/Precondition4", "Precondition4", 0, 0, 0, 0, 0 },

  { 13, 0, "StateflowChart/Precondition4.Init4", "Init4", 0, 0, 0, 0, 0 },

  { 14, 0, "StateflowChart/Precondition4.Stabilise4", "Stabilise4", 0, 0, 0, 0,
    0 },

  { 15, 0, "StateflowChart/Precondition4.TDataPre4", "TDataPre4", 0, 0, 0, 0, 0
  },

  { 16, 0, "StateflowChart/Precondition5", "Precondition5", 0, 0, 0, 0, 0 },

  { 17, 0, "StateflowChart/Precondition5.Init5", "Init5", 0, 0, 0, 0, 0 },

  { 18, 0, "StateflowChart/Precondition5.Stabilise5", "Stabilise5", 0, 0, 0, 0,
    0 },

  { 19, 0, "StateflowChart/Precondition5.TDataPre5", "TDataPre5", 0, 0, 0, 0, 0
  },

  { 20, 0, "StateflowChart/Precondition6", "Precondition6", 0, 0, 0, 0, 0 },

  { 21, 0, "StateflowChart/Precondition6.Init6", "Init6", 0, 0, 0, 0, 0 },

  { 22, 0, "StateflowChart/Precondition6.Stabilise6", "Stabilise6", 0, 0, 0, 0,
    0 },

  { 23, 0, "StateflowChart/Precondition6.TDataPre6", "TDataPre6", 0, 0, 0, 0, 0
  },

  { 24, 0, "StateflowChart/wait", "wait", 0, 0, 0, 0, 0 } };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    25                                 /* Num Block IO signals */
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
