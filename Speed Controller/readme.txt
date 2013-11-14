Run the TestdataGen.m file will transform the TARGET into a new structure with the implemented Testdata block.

TestdataGen.m matches the TEST Layer;
TestdataReqG.m is related to the Requirement Layer;
Testdata_Preconditions_G.m is related to the Preconditions Layer;
TestdataFeature_G.m is to the Feature Layer

The target is defined in the TestdataGen.m as 'SOURCE' variable. 'SUTName' is related to its surfacial meaning and should also defined.

In the Feature Layer, we consider the situation under:
1. Detect Constant
2. Bound Precond
3. Detect Increase
4. Detect decrease
5. Detect true

All above can handle combination with each other and their own type.

Feature layer design rules
To get the signals component (i.e. Inputs and Outputs), we analyse the ‚Bus Selector’ in the VFs feature level at first. After taking out the output signals there, if it exists one Output signal, one ‘Bus Selector ‘ will be created in the TestData feature level and leave one Activate block in the feature level of target . The out ports of target ‘Bus Selector’ will match to the source  output signals. For each output signal we generate a Memory block to connect, which will be connected to the other function block later, e.g. Bound Precond. The Memory block’s name is after the matched Outputsignalsname of ‘Bus Selector’.
For 
1.	Each ‘Detect Constant’ exists in the source feature level, we generate a Constant block from the defined Library (‘MIL_TEST/Test Data’) and a Out  from the Simulink library. The signal will go from the Constant to the Out. The name of Out depends on the source ‘Detect Constant’s input signal name. The referenced value of the source  ‘Detect Constant’ is also translated to the Constant value;
2.	 Detect Increase and Detect decrease principle same as the Detect Constant, just generate ‘Generate limited increase’ and ‘Generate limited decrease’ blocks instead of ‘Detect Constant’;
3.	 ‘Detect true’ exists in the source feature level, we assume to generate a random constant for each input signal. Here we take the Constant block from the ‘MIL_TEST/Test data’ and set default value ‘zero’;
4.	Each ‘Bound Precond’ exists in the source feature level, we generate a ‘Bound Precond’ block but from the ‘MIL_Test/Test Data/..’. The source ‘Bound Precond’ related information e.g. input signal name, reference value will be recorded and translated to the target ‘Bound Precond’. If the input signal of it is actually the same Input signal to SUT, target ‘Bound Precond’ will be connected to a Constant, which is generated from the ‘MIL_TEST/Test Data’, which is named after Input signal’s name. Otherwise it will be connected to a matched  Memory block as mentioned above. For more than one ‘Bound Precond’ in the case of the source type connected to Output signals, we need generate a Bus Creator to summarize the signals to the Activate block.
5.	Each ‚Complete step detection’ exists in the source feature level, we generate a ‘Generate complete step’ block from the ‘MIL_Test/Test Data/..’. The Trigger signal to the new coming ‘Generate complete step’ block is according to VFs evaluation signal. And the output signal of it will be connected with the Outport block named after the signal to the ‘Complete step detection’s  ‘Step’ port.
6.	Each ‘CC active& no target’, we assume that a constant signal from ‘MIL_Test/Test Data/..’ to an Out port block named after the Input signal’s name to the ‘CC active& no target’. The source ‘CC active& no target’ referenced value will revalue to the constant signal. If Input signal’s name cannot be recognized, it maybe there is another block between the ‘Bus Selector’ and ‘CC active& no target’. In that case, the Input signal will be traced through them.
7.	Each ‘ Speed control active’ principle same as the ‘CC active& no target’;

Preconditions layer design rules
‘Preconditions’ number and name are according to the source ‘Activate’. If there is no signal from the ‘Preconditions’ to the out port, we generate a random signal, here assuming a Constant valued ‘zero’. And in this case we do not need a switch in front of the out port any more. The out ports of ‘ Initialisation & Stabilisation’ block match the Input signal to SUT, including the name and the number.

Requirement layer & Test layer design rules
1.	Detecting the SUT input signals names and number
2.	Generating ‘the test data generator’ from the library
3.	Setting the ‘Requirement’ blocks number according to the number of ‘Test info’ in the source.
4.	Setting the Output signals according to the SUT input signals names and number.



