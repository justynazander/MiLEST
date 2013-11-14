#ifndef __c7_Pedal_Interpretation_exe_h__
#define __c7_Pedal_Interpretation_exe_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  void *c7_testPointAddrMap[6];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint16_T c7_temporalCounter_i1;
  uint8_T c7_is_Precondition1;
  uint8_T c7_is_active_c7_Pedal_Interpretation_exe;
  uint8_T c7_is_c7_Pedal_Interpretation_exe;
  uint8_T c7_tp_Init1;
  uint8_T c7_tp_Precondition1;
  uint8_T c7_tp_Stabilise1;
  uint8_T c7_tp_TDataPre1;
  uint8_T c7_tp_stop;
  uint8_T c7_tp_wait;
  ChartInfoStruct chartInfo;
  rtwCAPI_ModelMappingInfo c7_testPointMappingInfo;
} SFc7_Pedal_Interpretation_exeInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c7_Pedal_Interpretation_exe_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c7_Pedal_Interpretation_exe_get_check_sum(mxArray *plhs[]);
extern void c7_Pedal_Interpretation_exe_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
