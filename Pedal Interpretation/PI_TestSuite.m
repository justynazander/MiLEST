% for Test Suite
%__________________________________________________________________________
%______
% for Inputs 
% Create axes
axes1 = axes('ZTick',[-10 0 10 35 90 100],...
    'YTickLabel',{'car velocity','braking pedal','gas pedal',''},...
    'YTick',[0 1 2 3],...
    'YGrid','on',...
    'XGrid','on',...
    'Position',[0.1292 0.11 0.775 0.815],...
    'FontSize',14,...
    'FontName','Times New Roman');
% Uncomment the following line to preserve the Y-limits of the axes
% ylim([0 3]);
view([-17.5 48]);
hold('all');

% Create multiple lines using matrix input to plot3
plot3(PI_Inputs(1,1:11001),PI_Inputs(5,1:11001),PI_Inputs(2,1:11001),PI_Outputs(1,1:11001),PI_Inputs(6,1:11001),PI_Inputs(4,1:11001),PI_Inputs(1,1:11001),PI_Inputs(7,1:11001),PI_Inputs(3,1:11001),'Parent',axes1,'LineWidth',2); grid('on'); figure(gcf)

% Create xlabel
xlabel('time (seconds)','FontSize',14,'FontName','Times New Roman');

% Create zlabel
zlabel('values (units)','FontSize',14,'FontName','Times New Roman');

% Create title
title('Five test suites executed one after another.','FontSize',16,...
    'FontName','Times New Roman');



% for Outputs - torques
% Create axes
axes1 = axes('ZTick',[-8000 0 2300],...
    'YTickLabel',{'driving torque', 'braking torque'},...
    'YTick',[0 1 2],...
    'YGrid','on',...
    'XGrid','on',...
    'Position',[0.1292 0.11 0.775 0.815],...
    'FontSize',14,...
    'FontName','Times New Roman');
% Uncomment the following line to preserve the Y-limits of the axes
% ylim([0 2]);
view([-17.5 48]);
hold('all');

% Create multiple lines using matrix input to plot3
%plot3(PI_Outputs(1,1:11001),PI_Inputs(5,1:11001),PI_Outputs(3,1:11001),PI_Outputs(1,1:11001),PI_Inputs(6,1:11001),PI_Outputs(2,1:11001),PI_Outputs(1,1:11001),PI_Inputs(7,1:11001),PI_Outputs(4,1:11001),PI_Outputs(1,1:11001),PI_Inputs(8,1:11001),PI_Outputs(5,1:11001),'Parent',axes1,'LineWidth',2); grid('on'); figure(gcf)
plot3(PI_Outputs(1,1:11001),PI_Inputs(7,1:11001),PI_Outputs(4,1:11001),PI_Outputs(1,1:11001),PI_Inputs(8,1:11001),PI_Outputs(5,1:11001),'Parent',axes1,'LineWidth',2); grid('on'); figure(gcf)
% Create xlabel
xlabel('time (seconds)','FontSize',14,'FontName','Times New Roman');

% Create zlabel
zlabel('values (units)','FontSize',14,'FontName','Times New Roman');

% Create title
title('Results for execution of five test suites one after another.','FontSize',16,...
    'FontName','Times New Roman');


% for Outputs - flags
% Create axes
axes1 = axes('ZTick',[-1 0 1],...
    'YTickLabel',{'braking pedal flag','gas pedal flag'},...
    'YTick',[0 1 2],...
    'YGrid','on',...
    'XGrid','on',...
    'Position',[0.1292 0.11 0.775 0.815],...
    'FontSize',14,...
    'FontName','Times New Roman');
% Uncomment the following line to preserve the Y-limits of the axes
ylim([0 2]);
zlim([-1 2]);
view([-17.5 48]);
hold('all');

% Create multiple lines using matrix input to plot3
plot3(PI_Outputs(1,1:11001),PI_Inputs(5,1:11001),PI_Outputs(3,1:11001),PI_Outputs(1,1:11001),PI_Inputs(6,1:11001),PI_Outputs(2,1:11001),'Parent',axes1,'LineWidth',2); grid('on'); figure(gcf)

% Create xlabel
xlabel('time (seconds)','FontSize',14,'FontName','Times New Roman');

% Create zlabel
zlabel('values (units)','FontSize',14,'FontName','Times New Roman');

% Create title
title('Results for execution of five test suites one after another.','FontSize',16,...
    'FontName','Times New Roman');

% for Test Case 4, variants combination 4
%__________________________________________________________________________
%______

% for Inputs 
% Create axes
axes1 = axes('ZTick',[-10 0 10 35 90 100],...
    'YTickLabel',{'car velocity','braking pedal','gas pedal',''},...
    'YTick',[0 1 2],...
    'YGrid','on',...
    'XGrid','on',...
    'Position',[0.1292 0.11 0.775 0.815],...
    'FontSize',14,...
    'FontName','Times New Roman');
% Uncomment the following line to preserve the Y-limits of the axes
% ylim([0 3]);
%ylim([0 3]);
view([-17.5 48]);
hold('all');

% Create multiple lines using matrix input to plot3
plot3(PI_Inputs(1,7601:8800),PI_Inputs(5,7601:8800),PI_Inputs(2,7601:8800), PI_Inputs(1,7601:8800),PI_Inputs(7,7601:8800),PI_Inputs(3,7601:8800), PI_Inputs(1,7601:8800),PI_Inputs(6,7601:8800),PI_Inputs(4,7601:8800),'Parent',axes1,'LineWidth',2); grid('on'); figure(gcf)

% -first - velocity at 2
% - prelast - accelr. at 0
%- last - braking pedal at 1

% Create xlabel
xlabel('time (seconds)','FontSize',14,'FontName','Times New Roman');

% Create zlabel
zlabel('values (units)','FontSize',14,'FontName','Times New Roman');

% Create title
title('All test steps in test case 4 for the 4th variants combination','FontSize',16,...
    'FontName','Times New Roman');


%__________________________________________________________________________
%______
% for Outputs 

% for Outputs - torques
% Create axes
axes1 = axes('ZTick',[-8000 0 2300],...
    'YTickLabel',{'driving torque', 'braking torque'},...
    'YTick',[0 1 2],...
    'YGrid','on',...
    'XGrid','on',...
    'Position',[0.1292 0.11 0.775 0.815],...
    'FontSize',14,...
    'FontName','Times New Roman');
% Uncomment the following line to preserve the Y-limits of the axes
ylim([0 2]);
view([-17.5 48]);
hold('all');

% Create multiple lines using matrix input to plot3
%plot3(PI_Outputs(1,1:11001),PI_Inputs(5,1:11001),PI_Outputs(3,1:11001),PI_Outputs(1,1:11001),PI_Inputs(6,1:11001),PI_Outputs(2,1:11001),PI_Outputs(1,1:11001),PI_Inputs(7,1:11001),PI_Outputs(4,1:11001),PI_Outputs(1,1:11001),PI_Inputs(8,1:11001),PI_Outputs(5,1:11001),'Parent',axes1,'LineWidth',2); grid('on'); figure(gcf)
plot3(PI_Outputs(1,7601:8800),PI_Inputs(5,7601:8800),PI_Outputs(4,7601:8800), PI_Outputs(1,7601:8800),PI_Inputs(6,7601:8800),PI_Outputs(5,7601:8800),'Parent',axes1,'LineWidth',2); grid('on'); figure(gcf)
% Create xlabel
xlabel('time (seconds)','FontSize',14,'FontName','Times New Roman');

% Create zlabel
zlabel('values (units)','FontSize',14,'FontName','Times New Roman');

% Create title
title('Results for execution of test case 4 for the 4th variants combination.','FontSize',16,...
    'FontName','Times New Roman');


% for Outputs - flags
% Create axes
axes1 = axes('ZTick',[-1 0 1],...
    'YTickLabel',{'braking pedal flag','gas pedal flag'},...
    'YTick',[0 1 2],...
    'YGrid','on',...
    'XGrid','on',...
    'Position',[0.1292 0.11 0.775 0.815],...
    'FontSize',14,...
    'FontName','Times New Roman');
% Uncomment the following line to preserve the Y-limits of the axes
ylim([0 2]);

view([-17.5 48]);
hold('all');

% Create multiple lines using matrix input to plot3
plot3(PI_Outputs(1,7601:8800),PI_Inputs(5,7601:8800),PI_Outputs(3,7601:8800), PI_Outputs(1,7601:8800),PI_Inputs(6,7601:8800),PI_Outputs(2,7601:8800),'Parent',axes1,'LineWidth',2); grid('on'); figure(gcf)

% Create xlabel
xlabel('time (seconds)','FontSize',14,'FontName','Times New Roman');

% Create zlabel
zlabel('values (units)','FontSize',14,'FontName','Times New Roman');

% Create title
title('Results for execution of test case 4 for the 4th variants combination.','FontSize',16,...
    'FontName','Times New Roman');



% for VERDICT
% Create axes
axes1 = axes('ZTick',[-1 0 1 2],...
    'YTickLabel',{'local verdict'},...
    'YTick',[0 1 2],...
    'YGrid','on',...
    'XGrid','on',...
    'Position',[0.1292 0.11 0.775 0.815],...
    'FontSize',14,...
    'FontName','Times New Roman');
% Uncomment the following line to preserve the Y-limits of the axes
ylim([0 2]);
zlim([-1 2]);

view([-17.5 48]);
hold('all');

% Create multiple lines using matrix input to plot3
plot3(PI_Verdicts(1,7601:8800), PI_Inputs(6,7601:8800), PI_Verdicts(8,7601:8800),'Parent',axes1,'LineWidth',2); grid('on'); figure(gcf)

% Create xlabel
xlabel('time (seconds)','FontSize',14,'FontName','Times New Roman');

% Create zlabel
zlabel('values (units)','FontSize',14,'FontName','Times New Roman');

% Create title
title('Local verdict for VF: IF v is constant AND gas pedal increases AND driving torque is non-negative THEN driving torque increases.','FontSize',16,...
    'FontName','Times New Roman');

% _________________________________________________________________________
% ____________________ACC 


axes1 = axes('ZTick',[-1 0 1 2],...
    'YTickLabel',{'inputs, outputs, overall verdict'},...
    'YTick',[0 1 2],...
    'YGrid','on',...
    'XGrid','on',...
    'Position',[0.1292 0.11 0.775 0.815],...
    'FontSize',14,...
    'FontName','Times New Roman');
% Uncomment the following line to preserve the Y-limits of the axes
ylim([0 2]);
zlim([-1 2]);

view([-17.5 48]);
hold('all');

% Create multiple lines using matrix input to plot3
plot3(ACCoutput.time(1:6001,1), ACCoutput.time(1:6001,2), ACCinput.signals.values(1:6001,1), ACCoutput.time(1:6001,1), ACCoutput.time(1:6001,2), ACCinput.signals.values(1:6001,2), ACCoutput.time(1:6001,1), ACCoutput.time(1:6001,2), ACCoutput.signals.values(1:6001,1), ACCoutput.time(1:6001,1), ACCoutput.time(1:6001,2), ACCinput.signals.values(1:6001,4))

% Create xlabel
xlabel('time (seconds)','FontSize',14,'FontName','Times New Roman');

% Create zlabel
zlabel('values (units)','FontSize',14,'FontName','Times New Roman');

% Create title
title('ACC.','FontSize',16,...
    'FontName','Times New Roman');


