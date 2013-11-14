#ifndef __c8_Pedal_Interpretation_exe_h__
#define __c8_Pedal_Interpretation_exe_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  void *c8_testPointAddrMap[25];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint16_T c8_temporalCounter_i1;
  uint8_T c8_is_Precondition1;
  uint8_T c8_is_Precondition2;
  uint8_T c8_is_Precondition3;
  uint8_T c8_is_Precondition4;
  uint8_T c8_is_Precondition5;
  uint8_T c8_is_Precondition6;
  uint8_T c8_is_active_c8_Pedal_Interpretation_exe;
  uint8_T c8_is_c8_Pedal_Interpretation_exe;
  uint8_T c8_tp_Init1;
  uint8_T c8_tp_Init2;
  uint8_T c8_tp_Init3;
  uint8_T c8_tp_Init4;
  uint8_T c8_tp_Init5;
  uint8_T c8_tp_Init6;
  uint8_T c8_tp_Precondition1;
  uint8_T c8_tp_Precondition2;
  uint8_T c8_tp_Precondition3;
  uint8_T c8_tp_Precondition4;
  uint8_T c8_tp_Precondition5;
  uint8_T c8_tp_Precondition6;
  uint8_T c8_tp_Stabilise1;
  uint8_T c8_tp_Stabilise2;
  uint8_T c8_tp_Stabilise3;
  uint8_T c8_tp_Stabilise4;
  uint8_T c8_tp_Stabilise5;
  uint8_T c8_tp_Stabilise6;
  uint8_T c8_tp_TDataPre1;
  uint8_T c8_tp_TDataPre2;
  uint8_T c8_tp_TDataPre3;
  uint8_T c8_tp_TDataPre4;
  uint8_T c8_tp_TDataPre5;
  uint8_T c8_tp_TDataPre6;
  uint8_T c8_tp_wait;
  ChartInfoStruct chartInfo;
  rtwCAPI_ModelMappingInfo c8_testPointMappingInfo;
} SFc8_Pedal_Interpretation_exeInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c8_Pedal_Interpretation_exe_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c8_Pedal_Interpretation_exe_get_check_sum(mxArray *plhs[]);
extern void c8_Pedal_Interpretation_exe_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
