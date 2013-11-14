#ifndef __c14_Pedal_Interpretation_Test_h__
#define __c14_Pedal_Interpretation_Test_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  void *c14_testPointAddrMap[9];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c14_is_Precondition1;
  uint8_T c14_is_Precondition2;
  uint8_T c14_is_active_c14_Pedal_Interpretation_Test;
  uint8_T c14_is_c14_Pedal_Interpretation_Test;
  uint8_T c14_temporalCounter_i1;
  uint8_T c14_tp_Init1;
  uint8_T c14_tp_Init2;
  uint8_T c14_tp_Precondition1;
  uint8_T c14_tp_Precondition2;
  uint8_T c14_tp_Stabilise1;
  uint8_T c14_tp_Stabilise2;
  uint8_T c14_tp_TDataPre1;
  uint8_T c14_tp_TDataPre2;
  uint8_T c14_tp_wait;
  ChartInfoStruct chartInfo;
  rtwCAPI_ModelMappingInfo c14_testPointMappingInfo;
} SFc14_Pedal_Interpretation_TestInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c14_Pedal_Interpretation_Test_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c14_Pedal_Interpretation_Test_get_check_sum(mxArray *plhs[]);
extern void c14_Pedal_Interpretation_Test_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
