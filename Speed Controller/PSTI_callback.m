function PSTI_callback(block)

% Callback processing function for mask parameter number of 
% Time-independent features identifiable with or without
% a delay in block PS (Preconditions Synchronization)

load_system('Simulink'); % Load Simulink library (background)
TI = [block '/TI'];
NoTI = str2double(get_param(block,'NoTI')); % Get #TI features in mask
OldNoTI = length(find_system(TI, 'regexp', 'on','LookUnderMasks','all',...
                             'Name','Delays')); % Get# TI features in model
set_param([TI '/AND'],'Inputs',num2str(1+NoTI)); % Set AND parameters
TIdelays = str2num(get_param(block,'TIdel')); %#ok<ST2NM> % TI delays
if OldNoTI == 0 % Special case
    OneLines = get_param([TI '/One'],'LineHandles');
    delete_line(OneLines.Outport(1));
    delete_block([TI '/One']);
    TIdelays = [];
end
% Add or remove model items
for i = 1:max(NoTI,OldNoTI)
    if OldNoTI > NoTI && i > NoTI && i <= OldNoTI % Remove
        % Remove Lines
        ATILines = get_param([block '/A TI' num2str(i)],'LineHandles');
        DLines = get_param([TI '/Delays' num2str(i)],'LineHandles');
        delete_line(ATILines.Outport(1));
        delete_line(DLines.Inport(1));
        delete_line(DLines.Outport(1));
        % Remove blocks
        delete_block([block '/A TI' num2str(i)]);
        delete_block([TI '/Delays' num2str(i)]);
        delete_block([TI '/A' num2str(i)]);
        % Remove delays from mask parameter
        TIdelays = TIdelays(1:NoTI);
    elseif NoTI > OldNoTI && i > OldNoTI && i <= NoTI % Add
        % Add blocks
        Pos_A = [15 23 45 37];
        add_block('Simulink/Ports & Subsystems/In1',[TI '/A' num2str(i)],...
                  'Position',Pos_A + (i-1)*[0 40 0 40]);
        Pos_D = [80 19 110 41];
        add_block([block '/Max Delay R'],[TI '/Delays' num2str(i)],...
                  'Position',Pos_D + (i-1)*[0 40 0 40],'ShowName','off');
        Pos_ATI = [15 368 45 382];
        add_block('Simulink/Ports & Subsystems/In1',...
                  [block '/A TI' num2str(i)],...
                  'Position',Pos_ATI + (i-1)*[35 15 35 15]);
        % Add lines
        add_line(TI,['A' num2str(i) '/1'],['Delays' num2str(i) '/1'],...
                 'autorouting','on');
        add_line(TI,['Delays' num2str(i) '/1'],['AND/' num2str(i)],...
                 'autorouting','on');
        add_line(block,['A TI' num2str(i) '/1'],['TI/' num2str(i)],...
                 'autorouting','on');
        % Add delays to mask parameter
        TIdelays(NoTI) = 0; % Add zeros
    end
end
if NoTI == 0 % Special case
    add_block('Simulink/Commonly Used Blocks/Constant',[TI '/One'],...
              'Position',[80 173 105 207],'Value','1');
    add_line(TI,'One/1','AND/1');
else % Typical case
    set_param([TI '/AND'],'Inputs',num2str(NoTI)); % Set AND parameters
end
% Set Visibility properties of mask parameters
VisParams = get_param(block,'MaskVisibilities');
if NoTI == 0
    VisParams{4} = 'off';
else
    VisParams{4} = 'on';
end
set_param(block,'MaskVisibilities',VisParams);
set_param(block,'TIdel',['[' num2str(TIdelays) ']']); % Set param TIdelays
% Reset some block positions
set_param([TI '/AND'],'Position',[170 108 205 272]);
set_param(TI,'Position',[665 364 765 506]);