function PS_init(block)

% Block initialization function for
% Preconditions Synchronization

% Retrieve delays from mask parameters
NoTI = str2double(get_param(block,'NoTI'));
if NoTI > 0
    TIdelays = str2num(get_param(block,'TIdel')); %#ok<ST2NM>
else
    TIdelays = 0;
end
NoTDD = str2double(get_param(block,'NoTDD'));
if NoTDD > 0
    TDDdelays = str2num(get_param(block,'TDDdel')); %#ok<ST2NM>
else
    TDDdelays = 0;
end

% Compute maximal delay
MaxDelay = max([TIdelays TDDdelays]);

% Set TI delays
for i = 1:NoTI
    Delay = MaxDelay - TIdelays(i);
    set_param([block '/TI/Delays' num2str(i)],'Delay',num2str(Delay));
end

% Set TDD delays
for i = 1:NoTDD
    Delay = MaxDelay - TDDdelays(i);
    set_param([block '/TDD/Delays' num2str(i)],'Delay',num2str(Delay));
end

% Set TID delays
set_param([block '/Max Delay A'],'Delay',num2str(MaxDelay));
set_param([block '/Max Delay T'],'Delay',num2str(MaxDelay));
set_param([block '/Max Delay R'],'Delay',num2str(MaxDelay));