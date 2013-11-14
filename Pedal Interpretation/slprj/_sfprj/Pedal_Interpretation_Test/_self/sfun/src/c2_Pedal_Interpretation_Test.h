#ifndef __c2_Pedal_Interpretation_Test_h__
#define __c2_Pedal_Interpretation_Test_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  void *c2_testPointAddrMap[4];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint16_T c2_temporalCounter_i1;
  uint8_T c2_is_active_c2_Pedal_Interpretation_Test;
  uint8_T c2_is_c2_Pedal_Interpretation_Test;
  uint8_T c2_tp_TestCase1;
  uint8_T c2_tp_TestCase2;
  uint8_T c2_tp_TestCase3;
  uint8_T c2_tp_TestCase4;
  ChartInfoStruct chartInfo;
  rtwCAPI_ModelMappingInfo c2_testPointMappingInfo;
} SFc2_Pedal_Interpretation_TestInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c2_Pedal_Interpretation_Test_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_Pedal_Interpretation_Test_get_check_sum(mxArray *plhs[]);
extern void c2_Pedal_Interpretation_Test_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
