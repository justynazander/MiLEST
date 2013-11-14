function PAS_callback(block)

% Callback processing function for mask parameter
% TI (Assertion feature is time-independent)
% in block Preconditions-Assertion Synchronization
%

load_system('Simulink'); % Load Simulink library (background)
AFT = get_param(block,'AFT'); % Get assertion feature type
if length(AFT) == 2 % TI
    TI = min('TI' == AFT(1:2)); % 1 if TI, 0 if TDD or TID
    TDD = 0;
    TID = 0;    
else % TDD or TID
    TI = 0;
    TDD = min('TD' == AFT(1:2)); % 1 if TDD, 0 if TID
    TID = min('TI' == AFT(1:2)); % 1 if TID, 0 if TDD
end
% Save old values for mask parameters visibility
VisParams = get_param(block,'MaskVisibilities');
% Detect old assertion type
if ~isempty(find_system(find_system(block,'SearchDepth',1,...
            'LookUnderMasks','all','FindAll','on','Name','R')))
    OldAFT = 1; % Assertion type was TID
elseif ~isempty(find_system(find_system(block,'SearchDepth',1,...
                'LookUnderMasks','all','FindAll','on','Name','T')))
    OldAFT = 2; % Assertion type was TDD
else
    OldAFT = 3; % Assertion type was TI
end
% Update model
if TI == 1 % Assertion feature is TI
    VisParams{2} = 'on'; % Set parameter AFD visible and enabled
    if OldAFT == 1 % Assertion type was TID
        RLines = get_param([block '/R'],'LineHandles');
        TLines = get_param([block '/T'],'LineHandles');
        delete_line(RLines.Outport(1));
        delete_line(TLines.Outport(1));
        delete_block([block '/R']);
        delete_block([block '/T']);
        add_line(block,'Bus Selector/1','Ra delay/1','autorouting','on');
        add_line(block,'Bus Selector/1','Ta delay/1','autorouting','on');
    elseif OldAFT == 2 % Assertion type was TDD
        TLines = get_param([block '/T'],'LineHandles');
        delete_line(TLines.Outport(1));
        delete_block([block '/T']);
        add_line(block,'Bus Selector/1','Ta delay/1','autorouting','on');
        add_line(block,'Bus Selector/1','Ra delay/1','autorouting','on');
    end
elseif TDD == 1 % Assertion feature is TDD
    VisParams{2} = 'on'; % Set parameter AFD visible and enabled
    if OldAFT == 1 % Assertion type was TID
        RLines = get_param([block '/R'],'LineHandles');
        delete_line(RLines.Outport(1));
        delete_block([block '/R']);
        add_line(block,'T/1','Ra delay/1','autorouting','on');
    elseif OldAFT == 3 % Assertion type was TI
        TaDelayLines = get_param([block '/Ta delay'],'LineHandles');
        RaDelayLines = get_param([block '/Ra delay'],'LineHandles');
        delete_line(TaDelayLines.Inport(1));
        delete_line(RaDelayLines.Inport(1));
        add_block('Simulink/Commonly Used Blocks/In1',[block '/T'],...
                  'Position',[15 183 45 197],'Port','2');
        add_line(block,'T/1','Ta delay/1','autorouting','on');
        add_line(block,'T/1','Ra delay/1','autorouting','on');
    end
elseif TID == 1 % Assertion feature is TID
    VisParams{2} = 'off'; % Set parameter AFD invisible and disabled
    if OldAFT == 2 % Assertion type was TDD
        RaDelayLines = get_param([block '/Ra delay'],'LineHandles');
        delete_line(RaDelayLines.Inport(1));
        add_block('Simulink/Commonly Used Blocks/In1',[block '/R'],...
                  'Position',[15 223 45 237],'Port','2');
        add_line(block,'R/1','Ra delay/1','autorouting','on');
    elseif OldAFT == 3 % Assertion type was TI
        TaDelayLines = get_param([block '/Ta delay'],'LineHandles');
        RaDelayLines = get_param([block '/Ra delay'],'LineHandles');
        delete_line(TaDelayLines.Inport(1));
        delete_line(RaDelayLines.Inport(1));
        add_block('Simulink/Commonly Used Blocks/In1',[block '/R'],...
                  'Position',[15 223 45 237],'Port','2');
        add_block('Simulink/Commonly Used Blocks/In1',[block '/T'],...
                  'Position',[15 183 45 197],'Port','3');
        add_line(block,'R/1','Ra delay/1','autorouting','on');
        add_line(block,'T/1','Ta delay/1','autorouting','on');
    end
end
% Set Visibility and Enable properties of mask parameters
set_param(block,'MaskVisibilities',VisParams);
set_param(block,'MaskEnables',VisParams);