/* Include files */

#include "Pedal_Interpretation_Test_sfun.h"
#include "c2_Pedal_Interpretation_Test.h"
#include "c3_Pedal_Interpretation_Test.h"
#include "c6_Pedal_Interpretation_Test.h"
#include "c7_Pedal_Interpretation_Test.h"
#include "c8_Pedal_Interpretation_Test.h"
#include "c14_Pedal_Interpretation_Test.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _Pedal_Interpretation_TestMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Pedal_Interpretation_Test_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void Pedal_Interpretation_Test_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Pedal_Interpretation_Test_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_Pedal_Interpretation_Test_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Pedal_Interpretation_Test_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_Pedal_Interpretation_Test_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_Pedal_Interpretation_Test_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Pedal_Interpretation_Test_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_Pedal_Interpretation_Test_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Pedal_Interpretation_Test_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1729197010U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2748732506U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2528238476U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1207979084U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1919475174U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(449736639U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(73120655U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2382867791U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_Pedal_Interpretation_Test_get_check_sum(mxArray
            *plhs[]);
          sf_c2_Pedal_Interpretation_Test_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Pedal_Interpretation_Test_get_check_sum(mxArray
            *plhs[]);
          sf_c3_Pedal_Interpretation_Test_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_Pedal_Interpretation_Test_get_check_sum(mxArray
            *plhs[]);
          sf_c6_Pedal_Interpretation_Test_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_Pedal_Interpretation_Test_get_check_sum(mxArray
            *plhs[]);
          sf_c7_Pedal_Interpretation_Test_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Pedal_Interpretation_Test_get_check_sum(mxArray
            *plhs[]);
          sf_c8_Pedal_Interpretation_Test_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_Pedal_Interpretation_Test_get_check_sum(mxArray
            *plhs[]);
          sf_c14_Pedal_Interpretation_Test_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(197327120U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2950197879U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4213550391U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2745991157U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(849868539U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2477545632U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(634840569U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3881971385U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Pedal_Interpretation_Test_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern mxArray *sf_c2_Pedal_Interpretation_Test_get_autoinheritance_info
          (void);
        plhs[0] = sf_c2_Pedal_Interpretation_Test_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_Pedal_Interpretation_Test_get_autoinheritance_info
          (void);
        plhs[0] = sf_c3_Pedal_Interpretation_Test_get_autoinheritance_info();
        break;
      }

     case 6:
      {
        extern mxArray *sf_c6_Pedal_Interpretation_Test_get_autoinheritance_info
          (void);
        plhs[0] = sf_c6_Pedal_Interpretation_Test_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_Pedal_Interpretation_Test_get_autoinheritance_info
          (void);
        plhs[0] = sf_c7_Pedal_Interpretation_Test_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_Pedal_Interpretation_Test_get_autoinheritance_info
          (void);
        plhs[0] = sf_c8_Pedal_Interpretation_Test_get_autoinheritance_info();
        break;
      }

     case 14:
      {
        extern mxArray
          *sf_c14_Pedal_Interpretation_Test_get_autoinheritance_info(void);
        plhs[0] = sf_c14_Pedal_Interpretation_Test_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Pedal_Interpretation_Test_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern const mxArray
          *sf_c2_Pedal_Interpretation_Test_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Pedal_Interpretation_Test_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_Pedal_Interpretation_Test_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Pedal_Interpretation_Test_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_Pedal_Interpretation_Test_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_Pedal_Interpretation_Test_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_Pedal_Interpretation_Test_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_Pedal_Interpretation_Test_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_Pedal_Interpretation_Test_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_Pedal_Interpretation_Test_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_Pedal_Interpretation_Test_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_Pedal_Interpretation_Test_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void Pedal_Interpretation_Test_debug_initialize(void)
{
  _Pedal_Interpretation_TestMachineNumber_ = sf_debug_initialize_machine(
    "Pedal_Interpretation_Test","sfun",0,6,0,0,0);
  sf_debug_set_machine_event_thresholds(_Pedal_Interpretation_TestMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(_Pedal_Interpretation_TestMachineNumber_,
    0);
}

void Pedal_Interpretation_Test_register_exported_symbols(SimStruct* S)
{
}
