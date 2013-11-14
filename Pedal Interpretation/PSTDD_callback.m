function PSTDD_callback(block)

% Callback processing function for mask parameter number of
% triggered features identifiable with determinate delay or
% without a delay in block PS (Preconditions Synchronization)

load_system('Simulink'); % Load Simulink library (background)
TDD = [block '/TDD'];
NoTDD = str2double(get_param(block,'NoTDD')); % Get # TDD features in mask
OldNoTDD = length(find_system(TDD, 'regexp', 'on','LookUnderMasks','all',...
                              'Name','Delays')); % Get # TDD features in model
set_param([TDD '/AND'],'Inputs',num2str(1+NoTDD)); % Set AND parameters
TDDdelays = str2num(get_param(block,'TDDdel')); %#ok<ST2NM> % TDD delays
if OldNoTDD == 0 % Special case
    OneLines = get_param([TDD '/One'],'LineHandles');
    delete_line(OneLines.Outport(1));
    delete_block([TDD '/One']);
    TDDdelays = [];
end
% Add or remove model items
for i = 1:max(NoTDD,OldNoTDD)
    if OldNoTDD > NoTDD && i > NoTDD && i <= OldNoTDD % Remove
        % Remove Lines
        ATDDLines = get_param([block '/A TDD' num2str(i)],'LineHandles');
        TTDDLines = get_param([block '/T TDD' num2str(i)],'LineHandles');
        DLines = get_param([TDD '/Delays' num2str(i)],'LineHandles');
        ALines = get_param([TDD '/A' num2str(i)],'LineHandles');
        TLines = get_param([TDD '/T' num2str(i)],'LineHandles');
        delete_line(ATDDLines.Outport(1));
        delete_line(TTDDLines.Outport(1));
        delete_line(DLines.Inport(1));
        delete_line(DLines.Outport(1));
        delete_line(ALines.Outport(1));
        delete_line(TLines.Outport(1));
        % Remove blocks
        delete_block([block '/A TDD' num2str(i)]);
        delete_block([block '/T TDD' num2str(i)]);
        delete_block([TDD '/Delays' num2str(i)]);
        delete_block([TDD '/TA AND' num2str(i)]);
        delete_block([TDD '/A' num2str(i)]);
        delete_block([TDD '/T' num2str(i)]);
        % Remove delays from mask parameter
        TDDdelays = TDDdelays(1:NoTDD);
    elseif NoTDD > OldNoTDD && i > OldNoTDD && i <= NoTDD % Add
        % Add blocks
        Pos_T = [15 23 45 37];
        add_block('Simulink/Ports & Subsystems/In1',[TDD '/T' num2str(i)],...
                  'Position',Pos_T + (i-1)*[0 70 0 70]);
        Pos_A = [15 53 45 67];
        add_block('Simulink/Ports & Subsystems/In1',[TDD '/A' num2str(i)],...
                  'Position',Pos_A + (i-1)*[0 70 0 70]);
        Pos_D = [130 34 160 56];
        add_block([block '/Max Delay R'],[TDD '/Delays' num2str(i)],...
                  'Position',Pos_D + (i-1)*[0 70 0 70],'ShowName','off');
        Pos_TAAND = [75 15 105 75];
        add_block('Simulink/Commonly Used Blocks/Logical Operator',...
                  [TDD '/TA AND' num2str(i)],'Position',Pos_TAAND + ...
                  (i-1)*[0 70 0 70],'Inputs','2',...
                  'ShowName','off','Operator','AND');
        Pos_TTDD = [15 528 45 542];
        add_block('Simulink/Ports & Subsystems/In1',...
                  [block '/T TDD' num2str(i)],...
                  'Position',Pos_TTDD + (i-1)*[70 30 70 30]);
        Pos_ATDD = [50 543 80 557];
        add_block('Simulink/Ports & Subsystems/In1',...
                  [block '/A TDD' num2str(i)],...
                  'Position',Pos_ATDD + (i-1)*[70 30 70 30]);
        % Add lines
        add_line(TDD,['A' num2str(i) '/1'],['TA AND' num2str(i) '/2'],...
                 'autorouting','on');
        add_line(TDD,['TA AND' num2str(i) '/1'],['Delays' num2str(i) '/1'],...
                 'autorouting','on');
        add_line(TDD,['T' num2str(i) '/1'],['TA AND' num2str(i) '/1'],...
                 'autorouting','on');
        add_line(TDD,['Delays' num2str(i) '/1'],['AND/' num2str(i)],...
                 'autorouting','on');
        add_line(block,['T TDD' num2str(i) '/1'],['TDD/' num2str(2*i-1)],...
                 'autorouting','on');
        add_line(block,['A TDD' num2str(i) '/1'],['TDD/' num2str(2*i)],...
                 'autorouting','on');
        % Add delays to mask parameter
        TDDdelays(NoTDD) = 0; % Add zeros
    end
end
if NoTDD == 0 % Special case
    add_block('Simulink/Commonly Used Blocks/Constant',[TDD '/One'],...
              'Position',[85 275 115 305],'Value','1');
    add_line(TDD,'One/1','AND/1','autorouting','on');
    set_param([TDD '/AND'],'Inputs','2'); % Set AND parameters
    add_line(TDD,'One/1','AND/2','autorouting','on');
else % Typical case
    set_param([TDD '/AND'],'Inputs',num2str(NoTDD)); % Set AND parameters
end
% Set Visibility properties of mask parameters
VisParams = get_param(block,'MaskVisibilities');
if NoTDD == 0
    VisParams{5} = 'off';
else
    VisParams{5} = 'on';
end
set_param(block,'MaskVisibilities',VisParams);
set_param(block,'TDDdel',['[' num2str(TDDdelays) ']']); % Set param TDDdel
% Reset some block positions
set_param([TDD '/AND'],'Position',[245 208 280 372]);
set_param(TDD,'Position',[665 524 765 801]);