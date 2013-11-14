function PSTID_callback(block)

% Callback processing function for mask parameter number of
% Triggered features identifiable with indeterminate delay
% in block PS (Preconditions Synchronization)

load_system('Simulink'); % Load Simulink library (background)
TID = [block '/TID'];
OA = [block '/OR - AND'];
NoTID = str2double(get_param(block,'NoTID')); % Get #TID features in mask
OldNoTID = length(find_system(TID, 'regexp', 'on','LookUnderMasks','all',...
                              'Name','TA AND')); % Get #TID features in model
if OldNoTID == 0 % Special case #1
    add_block('Simulink/Discrete/Memory',[TID '/Memory'],'Position',...
              [300 17 325 43],'Orientation','left','ShowName','off');
    add_line(TID,'AND/1','Memory/1','autorouting','on');
    Hold0Lines = get_param([TID '/Hold'],'LineHandles');
    delete_line(Hold0Lines.Outport(1));
    delete_line(Hold0Lines.Inport(1));
    delete_line(Hold0Lines.Inport(2));
    ConstLines = get_param([OA '/Default'],'LineHandles');
    delete_line(ConstLines.Outport(1));
    delete_block([OA '/Default']);
elseif OldNoTID == 1 % Special case #2
    ANDLines = get_param([TID '/AND'],'LineHandles');
    ORopLines = get_param([OA '/ORop'],'LineHandles');
    ANDopLines = get_param([OA '/ANDop'],'LineHandles');
    delete_line(ANDLines.Inport(2));
    delete_line(ORopLines.Inport(2));
    delete_line(ANDopLines.Inport(2));    
end
% Set logical operators parameters
set_param([TID '/AND'],'Inputs',num2str(1+NoTID));
set_param([OA '/ORop'],'Inputs',num2str(1+NoTID));
set_param([OA '/ANDop'],'Inputs',num2str(1+NoTID));
% Add or remove model items
for i = 1:max(NoTID,OldNoTID)
    if OldNoTID > NoTID && i > NoTID && i <= OldNoTID % Remove
        % Add Hold block if necessary
        if NoTID == 0 && i == 1
            add_block([TID '/Hold1'],[TID '/Hold'],...
                      'Position',[290 114 335 156],'ShowName','off');
        end
        % Remove lines
        ORLines = get_param([TID '/OR ' num2str(i)],'LineHandles');
        HoldRANDLines = get_param([TID '/Hold R AND' num2str(i)],'LineHandles');
        RTIDLines = get_param([block '/R TID' num2str(i)],'LineHandles');
        TTIDLines = get_param([block '/T TID' num2str(i)],'LineHandles');
        ATIDLines = get_param([block '/A TID' num2str(i)],'LineHandles');
        HoldLines = get_param([TID '/Hold' num2str(i)],'LineHandles');
        OrLines = get_param([TID '/OR' num2str(i)],'LineHandles');
        RLines = get_param([OA '/R' num2str(i)],'LineHandles');
        ALines = get_param([TID '/A' num2str(i)],'LineHandles');
        TLines = get_param([TID '/T' num2str(i)],'LineHandles');
        AndLines = get_param([TID '/AND' num2str(i)],'LineHandles');
        delete_line(ORLines.Inport(1));
        delete_line(ORLines.Inport(2));
        delete_line(ORLines.Inport(3));
        delete_line(ORLines.Inport(4));
        delete_line(ORLines.Outport(1));
        delete_line(HoldRANDLines.Inport(2));
        delete_line(ATIDLines.Outport(1));
        delete_line(RTIDLines.Outport(1));
        delete_line(TTIDLines.Outport(1));
        delete_line(HoldLines.Outport(1));
        delete_line(HoldLines.Inport(2));
        delete_line(OrLines.Outport(1));
        delete_line(OrLines.Inport(1));
        delete_line(OrLines.Inport(2));
        delete_line(OrLines.Inport(3));
        delete_line(RLines.Outport(1));
        delete_line(ALines.Outport(1));
        delete_line(TLines.Outport(1));
        delete_line(AndLines.Inport(1));
        % Remove blocks
        delete_block([TID '/Mem' num2str(i)]);
        delete_block([TID '/OR ' num2str(i)]);
        delete_block([TID '/Hold R AND' num2str(i)]);
        delete_block([block '/A TID' num2str(i)]);
        delete_block([block '/R TID' num2str(i)]);
        delete_block([block '/T TID' num2str(i)]);
        delete_block([TID '/Hold' num2str(i)]);
        delete_block([TID '/OR' num2str(i)]);
        delete_block([TID '/TA AND' num2str(i)]);
        delete_block([TID '/T' num2str(i)]);
        delete_block([TID '/A' num2str(i)]);
        delete_block([TID '/AND' num2str(i)]);
        delete_block([OA '/R' num2str(i)]);
    elseif NoTID > OldNoTID && i > OldNoTID && i <= NoTID % Add
        % Add blocks
        Pos_Mem = [87 90 103 105];
        add_block('Simulink/Discrete/Memory',[TID '/Mem' num2str(i)],...
                  'Position',Pos_Mem + (i-1)*[0 100 0 100],...
                  'Orientation','up','ShowName','off');
        Pos_OR_ = [110 49 135 81];
        add_block('Simulink/Commonly Used Blocks/Logical Operator',...
                  [TID '/OR ' num2str(i)],'Position',Pos_OR_ + ...
                  (i-1)*[0 100 0 100],'Operator','OR','ShowName','off',...
                  'Inputs','4');
        Pos_HoldRAND = [155 54 200 96];
        if OldNoTID == 0 && i == 1
            add_block([TID '/Hold'],[TID '/Hold R AND' num2str(i)],...
                      'Position',Pos_HoldRAND + (i-1)*[0 100 0 100],...
                      'ShowName','off');
        else
            add_block([TID '/Hold1'],[TID '/Hold R AND' num2str(i)],...
                      'Position',Pos_HoldRAND + (i-1)*[0 100 0 100],...
                      'ShowName','off');
        end
        Pos_AND = [230 71 260 89];
        add_block('Simulink/Commonly Used Blocks/Logical Operator',...
                  [TID '/AND' num2str(i)],'Position',Pos_AND + (i-1)*...
                  [0 100 0 100],'ShowName','off','Operator','AND','Inputs','2');
        Pos_OR = [300 71 325 109];
        add_block('Simulink/Commonly Used Blocks/Logical Operator',...
                  [TID '/OR' num2str(i)],'Position',Pos_OR + (i-1)*...
                  [0 100 0 100],'ShowName','off','Operator','OR','Inputs','3');
        Pos_T = [15 118 45 132];
        add_block('Simulink/Ports & Subsystems/In1',[TID '/T' num2str(i)],...
                  'Position',Pos_T + (i-1)*[0 100 0 100],...
                  'NamePlacement','alternate');
        Pos_Hold = [350 104 395 146];
        if OldNoTID == 0 && i == 1
            add_block([TID '/Hold'],[TID '/Hold' num2str(i)],...
                  'Position',Pos_Hold + (i-1)*[0 100 0 100],'ShowName','off');
        else
            add_block([TID '/Hold1'],[TID '/Hold' num2str(i)],...
                  'Position',Pos_Hold + (i-1)*[0 100 0 100],'ShowName','off');
        end
        Pos_A = [15 138 45 152];
        add_block('Simulink/Ports & Subsystems/In1',[TID '/A' num2str(i)],...
                  'Position',Pos_A + (i-1)*[0 100 0 100]);
        Pos_TAAND = [300 117 325 153];
        add_block('Simulink/Commonly Used Blocks/Logical Operator',...
                  [TID '/TA AND' num2str(i)],'Position',Pos_TAAND + (i-1)*...
                  [0 100 0 100],'Inputs','2','ShowName','off','Operator','AND');
        Pos_R = [15 53 45 67];
        add_block('Simulink/Ports & Subsystems/In1',[OA '/R' num2str(i)],...
                  'Position',Pos_R + (i-1)*[0 30 0 30]);
        % Reorder 'R AND' port as the last one
        set_param([TID '/R AND'],'Port',num2str(2*i+2));
        % Reorder 'R OR' port as the penultimate one
        set_param([TID '/R OR'],'Port',num2str(2*i+1));
        Pos_RTID = [15 223 45 237];
        add_block('Simulink/Ports & Subsystems/In1',...
                  [block '/R TID' num2str(i)],...
                  'Position',Pos_RTID + (i-1)*[35 15 35 15]);
        Pos_TTID = [15 18 45 32];
        add_block('Simulink/Ports & Subsystems/In1',...
                  [block '/T TID' num2str(i)],...
                  'Position',Pos_TTID + (i-1)*[70 30 70 30]);
        Pos_ATID = [50 33 80 47];
        add_block('Simulink/Ports & Subsystems/In1',...
                  [block '/A TID' num2str(i)],...
                  'Position',Pos_ATID + (i-1)*[70 30 70 30]);
        % Add lines
        add_line(TID,'Memory/1',['OR ' num2str(i) '/1'],'autorouting','on');
        add_line(TID,'R AND/1',['OR ' num2str(i) '/2'],'autorouting','on');
        add_line(TID,'R OR/1',['OR ' num2str(i) '/3'],'autorouting','on');
        add_line(TID,['Mem' num2str(i) '/1'],['OR ' num2str(i) '/4'],...
                 'autorouting','on');
        add_line(TID,['T' num2str(i) '/1'],['Mem' num2str(i) '/1'],...
                 'autorouting','on');
        add_line(TID,['OR ' num2str(i) '/1'],['Hold R AND' num2str(i) '/1'],...
                 'autorouting','on');
        add_line(TID,'R AND/1',['Hold R AND' num2str(i) '/2'],...
                 'autorouting','on');
        add_line(block,['R TID' num2str(i) '/1'],['OR - AND/' num2str(i)],...
                 'autorouting','on');
        add_line(block,['T TID' num2str(i) '/1'],['TID/' num2str(2*i-1)],...
                 'autorouting','on');
        add_line(block,['A TID' num2str(i) '/1'],['TID/' num2str(2*i)],...
                 'autorouting','on');
        add_line(TID,'Memory/1',['OR' num2str(i) '/3'],'autorouting','on');
        add_line(TID,'R OR/1',['OR' num2str(i) '/2'],'autorouting','on');
        add_line(TID,['T' num2str(i) '/1'],['AND' num2str(i) '/2'],...
                 'autorouting','on');
        add_line(TID,['T' num2str(i) '/1'],['TA AND' num2str(i) '/1'],...
                 'autorouting','on');
        add_line(TID,['A' num2str(i) '/1'],['TA AND' num2str(i) '/2'],...
                 'autorouting','on');
        add_line(TID,['Hold' num2str(i) '/1'],['AND/' num2str(i)],...
                 'autorouting','on');
        add_line(TID,['OR' num2str(i) '/1'],['Hold' num2str(i) '/1'],...
                 'autorouting','on');
        add_line(TID,['TA AND' num2str(i) '/1'],['Hold' num2str(i) '/2'],...
                 'autorouting','on');
        add_line(TID,['Hold R AND' num2str(i) '/1'],['AND' num2str(i) '/1'],...
                 'autorouting','on');
        add_line(TID,['AND' num2str(i) '/1'],['OR' num2str(i) '/1'],...
                 'autorouting','on');
        add_line(OA,['R' num2str(i) '/1'],['ANDop/' num2str(i)],...
                 'autorouting','on');
        add_line(OA,['R' num2str(i) '/1'],['ORop/' num2str(i)],...
                 'autorouting','on');
        % Reorder ports
        set_param([block '/R TID' num2str(i)],'Port',num2str(3*i-2));
        set_param([block '/T TID' num2str(i)],'Port',num2str(3*i-1));
        set_param([block '/A TID' num2str(i)],'Port',num2str(3*i));
        % Remove Hold block if necessary
        if OldNoTID == 0 && i == 1
            delete_block([TID '/Hold']);
        end
    end
end
if NoTID == 0 % Special case #1
    MemoryLines = get_param([TID '/Memory'],'LineHandles');
    delete_line(MemoryLines.Inport(1));
    delete_block([TID '/Memory']);
    add_line(TID,'R AND/1','Hold/1','autorouting','on');
    add_line(TID,'R OR/1','Hold/2','autorouting','on');
    add_line(TID,'Hold/1','AND/1','autorouting','on');
    add_block('Simulink/Commonly Used Blocks/Constant',[OA '/Default'],...
              'Position',[110 140 140 170],'Value','1');
    add_line(OA,'Default/1','ORop/1','autorouting','on');
    add_line(OA,'Default/1','ANDop/1','autorouting','on');
elseif NoTID == 1 % Special case #2
    add_line(TID,'Hold1/1','AND/2','autorouting','on');
    add_line(OA,'R1/1','ORop/2','autorouting','on');
    add_line(OA,'R1/1','ANDop/2','autorouting','on');
else % Typical case
    % Set logical operators parameters
    set_param([TID '/AND'],'Inputs',num2str(NoTID));
    set_param([OA '/ORop'],'Inputs',num2str(NoTID));
    set_param([OA '/ANDop'],'Inputs',num2str(NoTID));
end
% Reset some block positions
set_param([TID '/AND'],'Position',[515 249 550 441]);
set_param([OA '/ANDop'],'Position',[250 184 280 276]);
set_param([OA '/ORop'],'Position',[250 24 280 116]);
set_param(OA,'Position',[340 222 425 358]);
set_param(TID,'Position',[665 16 765 304]);
