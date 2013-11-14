/* Include files */

#include "Pedal_Interpretation_exe_sfun.h"
#include "c7_Pedal_Interpretation_exe.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "Pedal_Interpretation_exe_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c7_IN_NO_ACTIVE_CHILD          (0)
#define c7_IN_TDataPre1                (3)
#define c7_IN_Init1                    (1)
#define c7_IN_Stabilise1               (2)
#define c7_IN_Precondition1            (1)
#define c7_IN_stop                     (2)
#define c7_IN_wait                     (3)

/* Variable Declarations */

/* Variable Definitions */
static SFc7_Pedal_Interpretation_exeInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c7_Pedal_Interpretation_exe(void);
static void initialize_params_c7_Pedal_Interpretation_exe(void);
static void enable_c7_Pedal_Interpretation_exe(void);
static void disable_c7_Pedal_Interpretation_exe(void);
static void update_debugger_state_c7_Pedal_Interpretation_exe(void);
static const mxArray *get_sim_state_c7_Pedal_Interpretation_exe(void);
static void set_sim_state_c7_Pedal_Interpretation_exe(const mxArray *c7_st);
static void finalize_c7_Pedal_Interpretation_exe(void);
static void sf_c7_Pedal_Interpretation_exe(void);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c7_Pedal_Interpretation_exe(void)
{
  real_T *c7_TDPre;
  c7_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c7_is_Precondition1 = 0U;
  chartInstance.c7_tp_Precondition1 = 0U;
  chartInstance.c7_tp_Init1 = 0U;
  chartInstance.c7_tp_Stabilise1 = 0U;
  chartInstance.c7_tp_TDataPre1 = 0U;
  chartInstance.c7_tp_stop = 0U;
  chartInstance.c7_tp_wait = 0U;
  chartInstance.c7_is_active_c7_Pedal_Interpretation_exe = 0U;
  chartInstance.c7_is_c7_Pedal_Interpretation_exe = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c7_TDPre = 0.0;
  }
}

static void initialize_params_c7_Pedal_Interpretation_exe(void)
{
}

static void enable_c7_Pedal_Interpretation_exe(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c7_Pedal_Interpretation_exe(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void update_debugger_state_c7_Pedal_Interpretation_exe(void)
{
  uint32_T c7_prevAniVal;
  c7_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if (chartInstance.c7_is_active_c7_Pedal_Interpretation_exe == 1) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,3);
  }

  if (chartInstance.c7_is_Precondition1 == c7_IN_TDataPre1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
  }

  if (chartInstance.c7_is_Precondition1 == c7_IN_Init1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
  }

  if (chartInstance.c7_is_Precondition1 == c7_IN_Stabilise1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
  }

  if (chartInstance.c7_is_c7_Pedal_Interpretation_exe == c7_IN_Precondition1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
  }

  if (chartInstance.c7_is_c7_Pedal_Interpretation_exe == c7_IN_stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
  }

  if (chartInstance.c7_is_c7_Pedal_Interpretation_exe == c7_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
  }

  sf_debug_set_animation(c7_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c7_Pedal_Interpretation_exe(void)
{
  return NULL;
}

static void set_sim_state_c7_Pedal_Interpretation_exe(const mxArray *c7_st)
{
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_Pedal_Interpretation_exe(void)
{
}

static void sf_c7_Pedal_Interpretation_exe(void)
{
  uint8_T c7_previousEvent;
  real_T *c7_TDPre;
  real_T *c7_Activate;
  c7_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c7_Activate = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,3);
  _SFD_DATA_RANGE_CHECK(*c7_Activate, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_TDPre, 1U);
  c7_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,3);
  if (chartInstance.c7_temporalCounter_i1 < 1023) {
    chartInstance.c7_temporalCounter_i1 = (uint16_T)
      (chartInstance.c7_temporalCounter_i1 + 1);
  }

  if (chartInstance.c7_is_active_c7_Pedal_Interpretation_exe == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,3);
    chartInstance.c7_is_active_c7_Pedal_Interpretation_exe = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
    chartInstance.c7_is_c7_Pedal_Interpretation_exe = (uint8_T)c7_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
    chartInstance.c7_temporalCounter_i1 = 0U;
    chartInstance.c7_tp_wait = 1U;
    *c7_TDPre = 2.0;
    _SFD_DATA_RANGE_CHECK(*c7_TDPre, 1U);
  } else {
    switch (chartInstance.c7_is_c7_Pedal_Interpretation_exe) {
     case c7_IN_Precondition1:
      CV_CHART_EVAL(3,0,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,0);
      switch (chartInstance.c7_is_Precondition1) {
       case c7_IN_Init1:
        CV_STATE_EVAL(0,0,1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,1);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,2);
        if (CV_TRANSITION_EVAL(2U, (_SFD_CCP_CALL(2,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(2,1,
               ((chartInstance.c7_temporalCounter_i1 >= 50)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
          chartInstance.c7_tp_Init1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
          chartInstance.c7_is_Precondition1 = (uint8_T)c7_IN_TDataPre1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
          chartInstance.c7_temporalCounter_i1 = 0U;
          chartInstance.c7_tp_TDataPre1 = 1U;
          *c7_TDPre = 1.0;
          _SFD_DATA_RANGE_CHECK(*c7_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
        break;

       case c7_IN_Stabilise1:
        CV_STATE_EVAL(0,0,2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,3);
        if (CV_TRANSITION_EVAL(3U, (_SFD_CCP_CALL(3,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(3,1,
               ((chartInstance.c7_temporalCounter_i1 >= 50)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,2);
          chartInstance.c7_tp_Stabilise1 = 0U;
          chartInstance.c7_is_Precondition1 = (uint8_T)c7_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,0);
          chartInstance.c7_tp_Precondition1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
          chartInstance.c7_is_c7_Pedal_Interpretation_exe = (uint8_T)c7_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
          chartInstance.c7_tp_stop = 1U;
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
        break;

       case c7_IN_TDataPre1:
        CV_STATE_EVAL(0,0,3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,3);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,4);
        if (CV_TRANSITION_EVAL(4U, (_SFD_CCP_CALL(4,0,((1)!=0)) != 0) &&
                               (_SFD_CCP_CALL(4,1,
               ((chartInstance.c7_temporalCounter_i1 >= 100)!=0))
              != 0)) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,4);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,3);
          chartInstance.c7_tp_TDataPre1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
          chartInstance.c7_is_Precondition1 = (uint8_T)c7_IN_Stabilise1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
          chartInstance.c7_temporalCounter_i1 = 0U;
          chartInstance.c7_tp_Stabilise1 = 1U;
          *c7_TDPre = 1.0;
          _SFD_DATA_RANGE_CHECK(*c7_TDPre, 1U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
        break;

       default:
        CV_STATE_EVAL(0,0,0);
        chartInstance.c7_is_Precondition1 = (uint8_T)c7_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
      break;

     case c7_IN_stop:
      CV_CHART_EVAL(3,0,2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,5);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,5);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,4);
      chartInstance.c7_tp_stop = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
      chartInstance.c7_is_c7_Pedal_Interpretation_exe = (uint8_T)
        c7_IN_Precondition1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
      chartInstance.c7_tp_Precondition1 = 1U;
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
      chartInstance.c7_is_Precondition1 = (uint8_T)c7_IN_Init1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
      chartInstance.c7_temporalCounter_i1 = 0U;
      chartInstance.c7_tp_Init1 = 1U;
      *c7_TDPre = 1.0;
      _SFD_DATA_RANGE_CHECK(*c7_TDPre, 1U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
      break;

     case c7_IN_wait:
      CV_CHART_EVAL(3,0,3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,5);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,6);
      if (CV_TRANSITION_EVAL(6U, (_SFD_CCP_CALL(6,0,((1)!=0)) != 0) &&
                             (_SFD_CCP_CALL(6,1,
             ((chartInstance.c7_temporalCounter_i1 >= 800)!=0))
            != 0)) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,6);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,5);
        chartInstance.c7_tp_wait = 0U;
        chartInstance.c7_is_c7_Pedal_Interpretation_exe = (uint8_T)
          c7_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
        chartInstance.c7_is_c7_Pedal_Interpretation_exe = (uint8_T)
          c7_IN_Precondition1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
        chartInstance.c7_tp_Precondition1 = 1U;
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,1);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
        chartInstance.c7_is_Precondition1 = (uint8_T)c7_IN_Init1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
        chartInstance.c7_temporalCounter_i1 = 0U;
        chartInstance.c7_tp_Init1 = 1U;
        *c7_TDPre = 1.0;
        _SFD_DATA_RANGE_CHECK(*c7_TDPre, 1U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
      break;

     default:
      CV_CHART_EVAL(3,0,0);
      chartInstance.c7_is_c7_Pedal_Interpretation_exe = (uint8_T)
        c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
  _sfEvent_ = c7_previousEvent;
  sf_debug_check_for_state_inconsistency(_Pedal_Interpretation_exeMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

const mxArray *sf_c7_Pedal_Interpretation_exe_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c7_nameCaptureInfo;
}

static void init_test_point_addr_map(void)
{
  chartInstance.c7_testPointAddrMap[0] = &chartInstance.c7_tp_Precondition1;
  chartInstance.c7_testPointAddrMap[1] = &chartInstance.c7_tp_Init1;
  chartInstance.c7_testPointAddrMap[2] = &chartInstance.c7_tp_Stabilise1;
  chartInstance.c7_testPointAddrMap[3] = &chartInstance.c7_tp_TDataPre1;
  chartInstance.c7_testPointAddrMap[4] = &chartInstance.c7_tp_stop;
  chartInstance.c7_testPointAddrMap[5] = &chartInstance.c7_tp_wait;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c7_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c7_testPointMappingInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c7_Pedal_Interpretation_exe_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3648064069U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2862302131U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(298490502U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3606216232U);
}

mxArray *sf_c7_Pedal_Interpretation_exe_get_autoinheritance_info(void)
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
          (_Pedal_Interpretation_exeMachineNumber_,
           7,
           6,
           7,
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
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,4);
          _SFD_CH_SUBSTATE_INDEX(2,5);
          _SFD_ST_SUBSTATE_COUNT(0,3);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
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
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 14, 15 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(2,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

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

          _SFD_CV_INIT_TRANS(6,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
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

        _SFD_TRANS_COV_WTS(5,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              0,NULL,NULL,
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

        _SFD_TRANS_COV_WTS(6,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c7_Activate;
          real_T *c7_TDPre;
          c7_TDPre = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c7_Activate = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_Activate);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_TDPre);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration
      (_Pedal_Interpretation_exeMachineNumber_,chartInstance.chartNumber,
       chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c7_Pedal_Interpretation_exe(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c7_Pedal_Interpretation_exe();
  initialize_c7_Pedal_Interpretation_exe();
}

static void sf_opaque_enable_c7_Pedal_Interpretation_exe(void *chartInstanceVar)
{
  enable_c7_Pedal_Interpretation_exe();
}

static void sf_opaque_disable_c7_Pedal_Interpretation_exe(void *chartInstanceVar)
{
  disable_c7_Pedal_Interpretation_exe();
}

static void sf_opaque_gateway_c7_Pedal_Interpretation_exe(void *chartInstanceVar)
{
  sf_c7_Pedal_Interpretation_exe();
}

static mxArray* sf_opaque_get_sim_state_c7_Pedal_Interpretation_exe(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c7_Pedal_Interpretation_exe();
  return st;
}

static void sf_opaque_set_sim_state_c7_Pedal_Interpretation_exe(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c7_Pedal_Interpretation_exe(sf_mex_dup(st));
}

static void sf_opaque_terminate_c7_Pedal_Interpretation_exe(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c7_Pedal_Interpretation_exe();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_Pedal_Interpretation_exe(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_Pedal_Interpretation_exe();
  }
}

static void mdlSetWorkWidths_c7_Pedal_Interpretation_exe(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Pedal_Interpretation_exe",
      "Pedal_Interpretation_exe",7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("Pedal_Interpretation_exe",
                "Pedal_Interpretation_exe",7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Pedal_Interpretation_exe",
      "Pedal_Interpretation_exe",7,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Pedal_Interpretation_exe",
        "Pedal_Interpretation_exe",7,1);
      sf_mark_chart_reusable_outputs(S,"Pedal_Interpretation_exe",
        "Pedal_Interpretation_exe",7,1);
    }

    sf_set_rtw_dwork_info(S,"Pedal_Interpretation_exe",
                          "Pedal_Interpretation_exe",7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3486000574U));
  ssSetChecksum1(S,(3964249948U));
  ssSetChecksum2(S,(354999986U));
  ssSetChecksum3(S,(2713834233U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_Pedal_Interpretation_exe(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Pedal_Interpretation_exe",
      "Pedal_Interpretation_exe",7);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c7_Pedal_Interpretation_exe(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_Pedal_Interpretation_exe;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c7_Pedal_Interpretation_exe;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c7_Pedal_Interpretation_exe;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c7_Pedal_Interpretation_exe;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c7_Pedal_Interpretation_exe;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_Pedal_Interpretation_exe;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_Pedal_Interpretation_exe;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c7_Pedal_Interpretation_exe;
  chartInstance.chartInfo.mdlStart = mdlStart_c7_Pedal_Interpretation_exe;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_Pedal_Interpretation_exe;
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

void c7_Pedal_Interpretation_exe_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_Pedal_Interpretation_exe(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_Pedal_Interpretation_exe(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_Pedal_Interpretation_exe(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_Pedal_Interpretation_exe_method_dispatcher.\n"
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

  { 4, 0, "StateflowChart/stop", "stop", 0, 0, 0, 0, 0 },

  { 5, 0, "StateflowChart/wait", "wait", 0, 0, 0, 0, 0 } };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    6                                  /* Num Block IO signals */
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
