% Configuration file for softstarter model

% parameters for kickstart
u_kickstart = 300;
t_kickstart = 0;

% parameters for startup of engine
u_start = 100;
t_ramp_on = 10;
i_max = 18;
%i_max = 30;
%i_max = 500;

% parameters for running
t_on = 3;

% parameters for stopping engine
u_step = 50;
u_stop = 0;
t_ramp_off = 10;

% signal parameters
freq = 50;
u_nom = 400;
rel_load = 0.2;

%simulation parameters
stepsize = 1/50000;
t_hold = 2;
t_sim = t_kickstart + t_ramp_on + t_on + t_ramp_off + t_hold;

% run simulation
sim Softstarter;

% display results
subplot(2,1,1);
plot( L1.time, L1.signals.values, L2.time, L2.signals.values, L3.time, L3.signals.values );
ax1 = gca;
set( ax1, 'XGrid', 'on' );
title( 'voltage' );
legend( 'L1', 'L2', 'L3' );

subplot(2,1,2);
ax1 = gca;
ax2=axes('Position',get(ax1,'Position'),'YAxisLocation','right','Color','none','XColor','k','YColor','k');
p_rpm = line( rpm.time, rpm.signals.values, 'Parent', ax1, 'Color', 'r' );
p_ueff = line( u_eff.time, u_eff.signals.values, 'Parent', ax1, 'Color', 'b' );
p_ieff = line( i_eff.time, i_eff.signals.values, 'Parent', ax2, 'Color', 'g' );
p_torque = line( torque.time, torque.signals.values, 'Parent', ax2, 'Color', 'k' );

legend( [p_rpm p_ueff p_ieff p_torque],'speed','u_{eff}', 'i_{eff}', 'torque' );
ylimits = get( ax1, 'YLim' );
yinc = (ylimits(2) - ylimits(1))/5;
set( ax1, 'YTick', [ylimits(1):yinc:ylimits(2)] );
ylimits = get( ax2, 'YLim' );
yinc = (ylimits(2) - ylimits(1))/5;
set( ax2, 'YTick', [ylimits(1):yinc:ylimits(2)] );
grid;
