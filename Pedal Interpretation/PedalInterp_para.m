% Created:       25-Jul-97 Hoetzer
% Update:        04-Apr-03 Conrad
% Last Update:   23-Mar-06 Zander-Nowicka
%
%
% Skalare:
% --------
% Formelzeichen		  Wert		  Einheit	Erklärung
%=========================================================================
%%%%%%%%%%%%% Initialisierung Fahrzeugmodell
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

%%%%%%%%%%%%% Initialisierung Variablencodierung
% Bremspedal, Fahrpedal
NichtBetaetigt	= 0;		% []	
Betaetigt		= 1;		% []	
% Bedienhebel

%+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
% Vektoren/Busse:
% ----------------
% Formelzeichen	  Wert		  	  	    Einheit	    Erklärung
%=========================================================================

%%%%%%%%%%%%% Initialisierung Fahrzeugmodell

% Pedalinterpretation Kennlinien
load pedal

disp('>>> Parameters for ACC model loaded');

% changes 
% Simulation ->ConfigParameters->Data IO