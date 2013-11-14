function [] = Requirements_Coverage_callback(block,signal)

% Callback processing function for mask parameter
% - number of <Requirement name> used in the System
set_param(block, 'LinkStatus', 'none');
load_system('Simulink'); % Load Simulink library (background)
load_system('MIL_Test');
if signal < 0 
No = get_param(block,'So'); % Get # of VF-s
else
    No = signal;
end
%System_Name = get_param(block,'Parent');
%Source = [System_Name '/Validation Functions'];
%Bus_VFs = find_system(Source, 'SearchDepth',1,'regexp', 'on','LookUnderMasks','all','Name',sprintf('Bus\nSelector'));
Bus_D = [block sprintf('/Bus\nSelector')];
Bus_C_D = [block '/Sum'];
if strcmp(No,'on') == 1 % adjust the number of signal to the present Eval signal's number
    
    %LineNr_S = length(get_param(Bus_VFs, 'outport')); % 'Local verdicts'in VFs signal numbers
    LineNr_D = length(get_param(Bus_D, 'outport'));
    Sig = get_param(Bus_D, 'OutputSignals');
    SigC = get_param(Bus_C_D, 'Inputs');
    In_Bus_D = get_param(Bus_D, 'InputSignals');
    v1 = In_Bus_D{2}; 
    v1=v1{2}; %Input signal to Bus Selector in Requirements_Coverage
    LineNr_S = length(v1);
    % Present signal number more than default/previous signal number
    if LineNr_S > LineNr_D
        for i = (LineNr_D+1):LineNr_S
            Sig_N = strcat(Sig,',Local Verdicts.',v1{i});
            Sig_C = strcat(SigC,'+');
            SigC = Sig_C;
            Sig = Sig_N;
            add_block([block '/Max to date'],[block '/Max to date' num2str(i-1)]);
            if i-2 > 0
                fix_pos([block '/Max to date' num2str(i-2)],[block '/Max to date' num2str(i-1)],0,20);
            else
                fix_pos([block '/Max to date'],[block '/Max to date' num2str(i-1)],0,20);
            end
            add_block([block sprintf('/verdict is \nnot none')],[block sprintf('/verdict is \nnot none') num2str(i-1)]);
            if i-1 > 0
                fix_pos([block sprintf('/verdict is \nnot none') num2str(i-2)],[block sprintf('/verdict is \nnot none') num2str(i-1)],0,10);
            else
                fix_pos([block sprintf('/verdict is \nnot none')],[block sprintf('/verdict is \nnot none') num2str(i-1)],0,10);
            end
            set_param(Bus_D,'OutputSignals',Sig_N);
            set_param(Bus_C_D,'Inputs',Sig_C);
            add_line(block,[sprintf('Bus\nSelector') '/' num2str(i)],[sprintf('verdict is \nnot none') num2str(i-1) '/' num2str(1)],'autorouting','on');
            add_line(block,[sprintf('verdict is \nnot none') num2str(i-1) '/' num2str(1)],['Max to date' num2str(i-1) '/' num2str(1)],'autorouting','on');
            add_line(block,['Max to date' num2str(i-1) '/' num2str(1)],['Sum' '/' num2str(i)],'autorouting','on');
        end
    % Present signal number little than default/previous signal number
    else
        for i = LineNr_D:-1:(LineNr_S+1)
            
            delete_line(block,[sprintf('Bus\nSelector') '/' num2str(i)],[sprintf('verdict is \nnot none') num2str(i-1) '/' num2str(1)]);
            delete_line(block,[sprintf('verdict is \nnot none') num2str(i-1) '/' num2str(1)],['Max to date' num2str(i-1) '/' num2str(1)]);
            delete_line(block,['Max to date' num2str(i-1) '/' num2str(1)],['Sum' '/' num2str(i)]);
            delete_block([block sprintf('/verdict is \nnot none') num2str(i-1)]);
            delete_block([block '/Max to date' num2str(i-1)]);
            Sig_N = strrep(Sig,[',Local Verdicts.Local verdict (signal ' num2str(i) ')'],'');
            Sig_C = SigC(1:(length(SigC)-1));
            SigC = Sig_C;
            Sig = Sig_N;
            set_param(Bus_D,'OutputSignals',Sig_N);
            set_param(Bus_C_D,'Inputs',Sig_C);
        end
    end
end