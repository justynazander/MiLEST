function [] = GenLogdata_tc(source)
% automatically set the SUT input signals 'DataLogging (on)' in all
% requirements
% assist function for the input coverage calculation

load_system(source);
sys = [source '/Validation Functions'];
c = find_system(sys, 'regexp', 'on','LookUnderMasks','all','Name','Test Info');
ReqNr = length(c);
lb = length('Test Info')+1;
lg = length([source '/Validation Functions'])+2;
for i = 1:ReqNr
    if i == 1
        m=char(c{1});% the whole path and name of block
    else
        m = c{i};
    end
    l1 = length(m)-lb;
    m1 = m(lg:l1); % requirement name      
    input_s = find_system([source '/TestData 1/' m1],'SearchDepth',1,'Blocktype','Outport');
    for k = 1:length(input_s)
        input_n = get_param(input_s{k},'Name');
        if strcmp(input_n, 'Activate') == 0
            l = get_param(input_s{k},'Linehandles');
            in = l.Inport;
            q = get_param(in,'SrcPortHandle');
            set_param(q,'DataLogging','on');
            set_param(q,'DataLoggingNameMode','Custom');
            set_param(q,'DataLoggingName',input_n);
        end
    end
end