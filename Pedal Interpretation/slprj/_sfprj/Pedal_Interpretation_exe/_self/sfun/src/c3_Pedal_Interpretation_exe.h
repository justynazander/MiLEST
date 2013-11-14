#ifndef __c3_Pedal_Interpretation_exe_h__
#define __c3_Pedal_Interpretation_exe_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  void *c3_testPointAddrMap[4];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint16_T c3_temporalCounter_i1;
  uint8_T c3_is_active_c3_Pedal_Interpretation_exe;
  uint8_T c3_is_c3_Pedal_Interpretation_exe;
  uint8_T c3_tp_TestCase1;
  uint8_T c3_tp_TestCase2;
  uint8_T c3_tp_TestCase3;
  uint8_T c3_tp_TestCase4;
  ChartInfoStruct chartInfo;
  rtwCAPI_ModelMappingInfo c3_testPointMappingInfo;
} SFc3_Pedal_Interpretation_exeInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c3_Pedal_Interpretation_exe_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_Pedal_Interpretation_exe_get_check_sum(mxArray *plhs[]);
extern void c3_Pedal_Interpretation_exe_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
