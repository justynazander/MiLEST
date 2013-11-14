% Created:       25-Jul-97 Hoetzer
% Last Update:   29-Jan-07 Marrero
%
% Initialisierungsdatei Fahrzeugmodell fzgmod.m und Geschwindigkeitsregler vregler.m
%
% Skalare:
% --------
% Formelzeichen		  Wert		  Einheit	Erklärung
%=========================================================================
%%%%%%%%%%%%% Initialisierung Fahrzeugmodell
m_Fzg			= 1400;		% [kg]		Fahrzeugmasse
rho			    = 1.202;	% [kg/m^3]	Dichte Luft
cw			    = 0.32;		% [-]		cw-Wert
A			    = 1.9;		% [m^2]		Angestr. Querschnittsfläche
r_dyn			= 0.28;		% [m]		Dynamischer Rollradius
f_r			    = 0.015;	% [-]		Rollwiderstandsbeiwert
t_sch			= 0.2;		% [s]		Schaltdauer		
n_mot0			= 1000;		% [1/min]	Leerlaufdrehzahl
g			    = 9.81;		% [m/s^2]	Fallbeschleunigung
i_d			    = 3.42;		% [-]		Uebersetzung Differential
v_Fzg_ms0		= 0;		% [m/s]		Anfangsgeschwindigkeit
n_mot_min_wert	= 1000;		% [1/min]	Motordrehzahl
n_mot_max_wert	= 6000;		% [1/min]	Motordrehzahl
M_Br_max		= 4000;		% [Nm]		Maximales Bremsmoment
T_max_Brake		= 4000;		% [Nm]		Maximales Bremsmoment
M_Abtr_max		= 2000;		% [N]		Maximale Abtriebskraft
M_Abtr_min		= -2000;	% [N]		Maximale Abtriebskraft
a_Fzg_max		= 2;		% [m/s^2]	Maximal zul. Beschleunigung
a_Fzg_min		= -2;		% [m/s^2]	Minimal zul. Beschleunigung
gang0			= 1;		% []		Anfangsgang
gang_vec		= [1 2 3 4];% []		Alle Gänge
lambda_gang		= [1.3 1.25  1.17  1.05];
					        % []		Massezuschlagsfaktor
speicher		= 100000;	% []		Speicherplatz

ped_min         = 5;        % [%]       Minimaler Pedalweg  

%%%%%%%%%%%%% Initialisierung Geschwindigkeitsregler
p_anteil		= 100;		% [sN/m]	P-Anteil Geschwindigkeitsregler
i_anteil		= 5;		% [N/m]		I-Anteil Geschwindigkeitsregler

%%%%%%%%%%%%% Initialisierung Abstandsregler

%%%%%%%%%%%%% Initialisierung Variablencodierung
% SystemStatus
passiv			= 0;		% []	
ueberdrueckt	= 1;		% []	
aktiv			= 2;		% []	
% Bremspedal, Fahrpedal
NichtBetaetigt	= 0;		% []	
Betaetigt		= 1;		% []	
% Bedienhebel
MittelStellung	= 0;		% []
SetzenBesch		= 1;		% []
SetzenVerz		= 2;		% []
WiederAufnahme	= 3;		% []
Aus			    = 4;		% []
% v_Soll
v_Min           = 40;       %[km/h]
v_Max           = 160;      %[km/h]
v_Diff          = 10;       %[km/h]
v_Init          = 0;        %[km/h]
% Ziel
NichtErkannt    = 0;        %[]
Erkannt         = 1;        %[]

%+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
% Vektoren/Busse:
% ----------------
% Formelzeichen	  Wert		  	  	    Einheit	    Erklärung
%=========================================================================

%%%%%%%%%%%%% Initialisierung Fahrzeugmodell
gang		= [1 2 3 4];			    % [-]		Gangvektor
i_g		    = [3.91 2.17 1.37 1.00];	% [-]		Getriebeübersetzung		  
n_mot_max	= 1000:500:6500;		    % [1/min]	Motordrehzahl
M_mot_max	= [130 149 163 170 168 166 162 158 150 139 123 80];
						                % [Nm]		Maximales Motormoment
n_mot_min	= [1000 6500];			    % [1/min]	Motordrehzahl
M_mot_min	= [0 -40];			        % [Nm]		Minimales Motormoment


%%%%%%%%%%%%% Initialisierung Umgebungsmodell
d_init      = 150;  %[m]  Anfangsabstand des vorausfahrenden Fahrzeugs 

%*************
delta_t = 0.04 ;    %[s]  Schrittweite (CTE-Variable)   

% Drosselklappenkennfeld erzeugt mit drossel.m
% save drossel n_Mot_vec M_Mot_vec Drossel_mat
% mesh(n_Mot_vec, M_Mot_vec, Drossel_mat');
load drossel

% Pedalinterpretation Kennlinien
%load pedal

%disp('>>> Parameters for ACC model loaded');

