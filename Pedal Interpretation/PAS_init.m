function PAS_init(block)

% Block initialization function for
% Preconditions-Assertion Synchronization

PS = find_system(get_param(get_param(block,'Parent'),'Parent'),...
                 'regexp','on','Name','PS');
PS = PS{1};

% Retrieve preconditions delays from mask parameters
NoTI = str2double(get_param(PS,'NoTI'));
if NoTI > 0
    TIdelays = str2num(get_param(PS,'TIdel')); %#ok<ST2NM>
else
    TIdelays = 0;
end
NoTDD = str2double(get_param(PS,'NoTDD'));
if NoTDD > 0
    TDDdelays = str2num(get_param(PS,'TDDdel')); %#ok<ST2NM>
else
    TDDdelays = 0;
end

% Compute maximal delay of the preconditions
PrecondMaxDelay = max([TIdelays TDDdelays]);

% Detect if assertion type is TID
if ~isempty(find_system(find_system(block,'SearchDepth',1,...
                        'LookUnderMasks','all','FindAll','on','Name','R')))
    AssDelay = 0; % Assertion type is TID
else
    AssDelay = str2double(get_param(block,'AFD')); % Assertion is TDD or TI
end

% Compute maximal delay
MaxDelay = max([PrecondMaxDelay AssDelay]);

% Update delays
set_param([block '/Rp delay'],'Delay',num2str(MaxDelay - PrecondMaxDelay));
set_param([block '/Tp delay'],'Delay',num2str(MaxDelay - PrecondMaxDelay));
set_param([block '/A delay'], 'Delay',num2str(MaxDelay - PrecondMaxDelay));
set_param([block '/Ra delay'],'Delay',num2str(MaxDelay - AssDelay));
set_param([block '/Ta delay'],'Delay',num2str(MaxDelay - AssDelay));
set_param([block '/V delay'], 'Delay',num2str(MaxDelay - AssDelay));
set_param([block '/Delay bus signals/ELL delay'], 'Delay',num2str(MaxDelay - AssDelay));
set_param([block '/Delay bus signals/EUL delay'], 'Delay',num2str(MaxDelay - AssDelay));
set_param([block '/Delay bus signals/AD delay'], 'Delay',num2str(MaxDelay - AssDelay));
set_param([block '/none - pass - fail/Max Delay'],'Value',num2str(MaxDelay));

%  Update delay computation parameters
set_param([block '/none - pass - fail/Compute delay/SimStepSize'],...
          'Value',num2str(get_param(bdroot,'FixedStep')));
set_param([block '/none - pass - fail/Compute delay1/SimStepSize'],...
          'Value',num2str(get_param(bdroot,'FixedStep')));
set_param([block '/none - pass - fail/Compute delay2/SimStepSize'],...
          'Value',num2str(get_param(bdroot,'FixedStep')));