/* Include files */

#include "Pedal_Interpretation_Test_sfun.h"
#include "c2_Pedal_Interpretation_Test.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "Pedal_Interpretation_Test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)
#define c2_IN_TestCase1                (1)
#define c2_IN_TestCase2                (2)
#define c2_IN_TestCase3                (3)
#define c2_IN_TestCase4                (4)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_Pedal_Interpretation_TestInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_Pedal_Interpretation_Test(void);
static void initialize_params_c2_Pedal_Interpretation_Test(void);
static void enable_c2_Pedal_Interpretation_Test(void);
static void disable_c2_Pedal_Interpretation_Test(void);
static void update_debugger_state_c2_Pedal_Interpretation_Test(void);
static const mxArray *get_sim_state_c2_Pedal_Interpretation_Test(void);
static void set_sim_state_c2_Pedal_Interpretation_Test(const mxArray *c2_st);
static void finalize_c2_Pedal_Interpretation_Test(void);
static void sf_c2_Pedal_Interpretation_Test(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static uint8_T c2_emlrt_marshallIn(const mxArray *c2_temporary, char *c2_name);
static real_T c2_b_emlrt_marshallIn(const mxArray *c2_temporary, char *c2_name);
static uint16_T c2_c_emlrt_marshallIn(const mxArray *c2_temporary, char *c2_name);
static const mxArray *c2_emlrt_marshallOut(uint8_T c2_u);
static const mxArray *c2_b_emlrt_marshallOut(real_T c2_u);
static const mxArray *c2_c_emlrt_marshallOut(uint16_T c2_u);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_Pedal_Interpretation_Test(void)
{
  real_T *c2_TestCase;
  real_T *c2_variant;
  c2_TestCase = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_variant = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_tp_TestCase1 = 0U;
  chartInstance.c2_tp_TestCase2 = 0U;
  chartInstance.c2_tp_TestCase3 = 0U;
  chartInstance.c2_tp_TestCase4 = 0U;
  chartInstance.c2_is_active_c2_Pedal_Interpretation_Test = 0U;
  chartInstance.c2_is_c2_Pedal_Interpretation_Test = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c2_TestCase = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 2) != 0)) {
    *c2_variant = 0.0;
  }
}

static void initialize_params_c2_Pedal_Interpretation_Test(void)
{
}

static void enable_c2_Pedal_Interpretation_Test(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c2_Pedal_Interpretation_Test(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void update_debugger_state_c2_Pedal_Interpretation_Test(void)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if (chartInstance.c2_is_active_c2_Pedal_Interpretation_Test == 1) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,0);
  }

  if (chartInstance.c2_is_c2_Pedal_Interpretation_Test == c2_IN_TestCase1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
  }

  if (chartInstance.c2_is_c2_Pedal_Interpretation_Test == c2_IN_TestCase2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
  }

  if (chartInstance.c2_is_c2_Pedal_Interpretation_Test == c2_IN_TestCase3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
  }

  if (chartInstance.c2_is_c2_Pedal_Interpretation_Test == c2_IN_TestCase4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
  }

  sf_debug_set_animation(c2_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_Pedal_Interpretation_Test(void)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T *c2_TestCase;
  real_T *c2_variant;
  c2_TestCase = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_variant = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(9));
  sf_mex_setcell(c2_y, 0, c2_emlrt_marshallOut(chartInstance.c2_tp_TestCase1));
  sf_mex_setcell(c2_y, 1, c2_emlrt_marshallOut(chartInstance.c2_tp_TestCase2));
  sf_mex_setcell(c2_y, 2, c2_emlrt_marshallOut(chartInstance.c2_tp_TestCase3));
  sf_mex_setcell(c2_y, 3, c2_emlrt_marshallOut(chartInstance.c2_tp_TestCase4));
  sf_mex_setcell(c2_y, 4, c2_emlrt_marshallOut
                 (chartInstance.c2_is_active_c2_Pedal_Interpretation_Test));
  sf_mex_setcell(c2_y, 5, c2_emlrt_marshallOut
                 (chartInstance.c2_is_c2_Pedal_Interpretation_Test));
  sf_mex_setcell(c2_y, 6, c2_b_emlrt_marshallOut(*c2_TestCase));
  sf_mex_setcell(c2_y, 7, c2_b_emlrt_marshallOut(*c2_variant));
  sf_mex_setcell(c2_y, 8, c2_c_emlrt_marshallOut
                 (chartInstance.c2_temporalCounter_i1));
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_Pedal_Interpretation_Test(const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_TestCase;
  real_T *c2_variant;
  c2_TestCase = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_variant = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_u = sf_mex_dup(c2_st);
  chartInstance.c2_tp_TestCase1 = c2_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "tp_TestCase1");
  chartInstance.c2_tp_TestCase2 = c2_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c2_u, 1)), "tp_TestCase2");
  chartInstance.c2_tp_TestCase3 = c2_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c2_u, 2)), "tp_TestCase3");
  chartInstance.c2_tp_TestCase4 = c2_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c2_u, 3)), "tp_TestCase4");
  chartInstance.c2_is_active_c2_Pedal_Interpretation_Test = c2_emlrt_marshallIn
    (sf_mex_dup(sf_mex_getcell(c2_u, 4)),
     "is_active_c2_Pedal_Interpretation_Test");
  chartInstance.c2_is_c2_Pedal_Interpretation_Test = c2_emlrt_marshallIn
    (sf_mex_dup(sf_mex_getcell(c2_u, 5)),
     "is_c2_Pedal_Interpretation_Test");
  *c2_TestCase = c2_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c2_u, 6)),
    "TestCase");
  *c2_variant = c2_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c2_u, 7)),
    "variant");
  chartInstance.c2_temporalCounter_i1 = c2_c_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c2_u, 8)), "temporalCounter_i1");
  sf_mex_destroy(&c2_u);
  update_debugger_state_c2_Pedal_Interpretation_Test();
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Pedal_Interpretation_Test(void)
{
}

static void sf_c2_Pedal_Interpretation_Test(void)
{
  uint8_T c2_previousEvent;
  real_T *c2_TestCase;
  real_T *c2_variant;
  c2_TestCase = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_variant = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c2_TestCase, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_variant, 1U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  if (chartInstance.c2_temporalCounter_i1 < 2047) {
    chartInstance.c2_temporalCounter_i1 = (uint16_T)
      (chartInstance.c2_temporalCounter_i1 + 1);
  }

  if (chartInstance.c2_is_active_c2_Pedal_Interpretation_Test == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,0);
    chartInstance.c2_is_active_c2_Pedal_Interpretation_Test = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
    *c2_variant = 1.0;
    _SFD_DATA_RANGE_CHECK(*c2_variant, 1U);
    chartInstance.c2_is_c2_Pedal_Interpretation_Test = (uint8_T)c2_IN_TestCase1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
    chartInstance.c2_temporalCounter_i1 = 0U;
    chartInstance.c2_tp_TestCase1 = 1U;
    *c2_TestCase = 1.0;
    _SFD_DATA_RANGE_CHECK(*c2_TestCase, 0U);
  } else {
    switch (chartInstance.c2_is_c2_Pedal_Interpretation_Test) {
     case c2_IN_TestCase1:
      CV_CHART_EVAL(0,0,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,0);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,1);
      if (CV_TRANSITION_EVAL(1U, (_SFD_CCP_CALL(1,0,((1)!=0)) != 0) &&
                             (_SFD_CCP_CALL(1,1,
             ((chartInstance.c2_temporalCounter_i1 >= 400)!=0))
            != 0)) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,0);
        chartInstance.c2_tp_TestCase1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
        chartInstance.c2_is_c2_Pedal_Interpretation_Test = (uint8_T)
          c2_IN_TestCase2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
        chartInstance.c2_temporalCounter_i1 = 0U;
        chartInstance.c2_tp_TestCase2 = 1U;
        *c2_TestCase = 2.0;
        _SFD_DATA_RANGE_CHECK(*c2_TestCase, 0U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
      break;

     case c2_IN_TestCase2:
      CV_CHART_EVAL(0,0,2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,2);
      if (CV_TRANSITION_EVAL(2U, (_SFD_CCP_CALL(2,0,((1)!=0)) != 0) &&
                             (_SFD_CCP_CALL(2,1,
             ((chartInstance.c2_temporalCounter_i1 >= 400)!=0))
            != 0)) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
        chartInstance.c2_tp_TestCase2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
        chartInstance.c2_is_c2_Pedal_Interpretation_Test = (uint8_T)
          c2_IN_TestCase3;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
        chartInstance.c2_temporalCounter_i1 = 0U;
        chartInstance.c2_tp_TestCase3 = 1U;
        *c2_TestCase = 3.0;
        _SFD_DATA_RANGE_CHECK(*c2_TestCase, 0U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
      break;

     case c2_IN_TestCase3:
      CV_CHART_EVAL(0,0,3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,3);
      if (CV_TRANSITION_EVAL(3U, (_SFD_CCP_CALL(3,0,((1)!=0)) != 0) &&
                             (_SFD_CCP_CALL(3,1,
             ((chartInstance.c2_temporalCounter_i1 >= 200)!=0))
            != 0)) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,2);
        chartInstance.c2_tp_TestCase3 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
        chartInstance.c2_is_c2_Pedal_Interpretation_Test = (uint8_T)
          c2_IN_TestCase4;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
        chartInstance.c2_temporalCounter_i1 = 0U;
        chartInstance.c2_tp_TestCase4 = 1U;
        *c2_TestCase = 4.0;
        _SFD_DATA_RANGE_CHECK(*c2_TestCase, 0U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
      break;

     case c2_IN_TestCase4:
      CV_CHART_EVAL(0,0,4);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,4);
      if (CV_TRANSITION_EVAL(4U, (_SFD_CCP_CALL(4,0,((1)!=0)) != 0) &&
                             (_SFD_CCP_CALL(4,1,
             ((chartInstance.c2_temporalCounter_i1 >= 1200)!=0))
            != 0)) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,4);
        *c2_variant = *c2_variant + 1.0;
        _SFD_DATA_RANGE_CHECK(*c2_variant, 1U);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,3);
        chartInstance.c2_tp_TestCase4 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
        chartInstance.c2_is_c2_Pedal_Interpretation_Test = (uint8_T)
          c2_IN_TestCase1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
        chartInstance.c2_temporalCounter_i1 = 0U;
        chartInstance.c2_tp_TestCase1 = 1U;
        *c2_TestCase = 1.0;
        _SFD_DATA_RANGE_CHECK(*c2_TestCase, 0U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
      break;

     default:
      CV_CHART_EVAL(0,0,0);
      chartInstance.c2_is_c2_Pedal_Interpretation_Test = (uint8_T)
        c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_Pedal_Interpretation_TestMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

const mxArray *sf_c2_Pedal_Interpretation_Test_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c2_nameCaptureInfo;
}

static uint8_T c2_emlrt_marshallIn(const mxArray *c2_temporary, char *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_temporary), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_temporary);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(const mxArray *c2_temporary, char *c2_name)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_name, sf_mex_dup(c2_temporary), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_temporary);
  return c2_y;
}

static uint16_T c2_c_emlrt_marshallIn(const mxArray *c2_temporary, char *c2_name)
{
  uint16_T c2_y;
  uint16_T c2_u1;
  sf_mex_import(c2_name, sf_mex_dup(c2_temporary), &c2_u1, 1, 5, 0U, 0, 0U, 0);
  c2_y = c2_u1;
  sf_mex_destroy(&c2_temporary);
  return c2_y;
}

static const mxArray *c2_emlrt_marshallOut(uint8_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0));
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(real_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  return c2_y;
}

static const mxArray *c2_c_emlrt_marshallOut(uint16_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 5, 0U, 0U, 0U, 0));
  return c2_y;
}

static void init_test_point_addr_map(void)
{
  chartInstance.c2_testPointAddrMap[0] = &chartInstance.c2_tp_TestCase1;
  chartInstance.c2_testPointAddrMap[1] = &chartInstance.c2_tp_TestCase2;
  chartInstance.c2_testPointAddrMap[2] = &chartInstance.c2_tp_TestCase3;
  chartInstance.c2_testPointAddrMap[3] = &chartInstance.c2_tp_TestCase4;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c2_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c2_testPointMappingInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c2_Pedal_Interpretation_Test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4084558967U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1543603310U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3852545659U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1454777746U);
}

mxArray *sf_c2_Pedal_Interpretation_Test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3411058080U);
    pr[1] = (double)(535328882U);
    pr[2] = (double)(1550693531U);
    pr[3] = (double)(211155546U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
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
           2,
           4,
           5,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "TestCase",0,NULL);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"variant",
                              0,NULL);
          _SFD_STATE_INFO(0,1,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
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

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(1,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(2,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(3,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 12, 0 };

          static unsigned int sEndGuardMap[] = { 16, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(4,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 11, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,2,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 12, 0 };

          static unsigned int sEndGuardMap[] = { 16, 17 };

          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c2_TestCase;
          real_T *c2_variant;
          c2_TestCase = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c2_variant = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_TestCase);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_variant);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration
      (_Pedal_Interpretation_TestMachineNumber_,chartInstance.chartNumber,
       chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_Pedal_Interpretation_Test(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_Pedal_Interpretation_Test();
  initialize_c2_Pedal_Interpretation_Test();
}

static void sf_opaque_enable_c2_Pedal_Interpretation_Test(void *chartInstanceVar)
{
  enable_c2_Pedal_Interpretation_Test();
}

static void sf_opaque_disable_c2_Pedal_Interpretation_Test(void
  *chartInstanceVar)
{
  disable_c2_Pedal_Interpretation_Test();
}

static void sf_opaque_gateway_c2_Pedal_Interpretation_Test(void
  *chartInstanceVar)
{
  sf_c2_Pedal_Interpretation_Test();
}

static mxArray* sf_opaque_get_sim_state_c2_Pedal_Interpretation_Test(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_Pedal_Interpretation_Test();
  return st;
}

static void sf_opaque_set_sim_state_c2_Pedal_Interpretation_Test(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c2_Pedal_Interpretation_Test(sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_Pedal_Interpretation_Test(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c2_Pedal_Interpretation_Test();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Pedal_Interpretation_Test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Pedal_Interpretation_Test();
  }
}

static void mdlSetWorkWidths_c2_Pedal_Interpretation_Test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Pedal_Interpretation_Test",
      "Pedal_Interpretation_Test",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("Pedal_Interpretation_Test",
                "Pedal_Interpretation_Test",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "Pedal_Interpretation_Test","Pedal_Interpretation_Test",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,"Pedal_Interpretation_Test",
        "Pedal_Interpretation_Test",2,2);
    }

    sf_set_rtw_dwork_info(S,"Pedal_Interpretation_Test",
                          "Pedal_Interpretation_Test",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2404968286U));
  ssSetChecksum1(S,(2595878953U));
  ssSetChecksum2(S,(1527109714U));
  ssSetChecksum3(S,(514011915U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_Pedal_Interpretation_Test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Pedal_Interpretation_Test",
      "Pedal_Interpretation_Test",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_Pedal_Interpretation_Test(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Pedal_Interpretation_Test;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_Pedal_Interpretation_Test;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_Pedal_Interpretation_Test;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c2_Pedal_Interpretation_Test;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_Pedal_Interpretation_Test;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_Pedal_Interpretation_Test;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_Pedal_Interpretation_Test;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_Pedal_Interpretation_Test;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_Pedal_Interpretation_Test;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Pedal_Interpretation_Test;
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

void c2_Pedal_Interpretation_Test_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Pedal_Interpretation_Test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Pedal_Interpretation_Test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Pedal_Interpretation_Test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Pedal_Interpretation_Test_method_dispatcher.\n"
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
  { 0, 0, "StateflowChart/TestCase1", "TestCase1", 0, 0, 0, 0, 0 },

  { 1, 0, "StateflowChart/TestCase2", "TestCase2", 0, 0, 0, 0, 0 },

  { 2, 0, "StateflowChart/TestCase3", "TestCase3", 0, 0, 0, 0, 0 },

  { 3, 0, "StateflowChart/TestCase4", "TestCase4", 0, 0, 0, 0, 0 } };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    4                                  /* Num Block IO signals */
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
