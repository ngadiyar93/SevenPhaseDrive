clc; clear; close all;
clc;
dir = pwd; % Get the present working directory
addpath(genpath(dir)); % using genpath() adds all the subfolders

%% Simulation time
T_end = 1; % End time
Ts = 1/25000; % Sampling time
T_sim = Ts/200; %Simulation time

%% Command generation
% dq currents
Id_step = 0;
Id_ref1 = 0;
Id_ref2 = 0;

Iq_step = 0;
Iq_ref1 = 0;
Iq_ref2 = 0;

% 3rd harmonic currents
Id3_step = 0;
Id3_ref1 = 0;
Id3_ref2 = 0;

Iq3_step = 0;
Iq3_ref1 = 0;
Iq3_ref2 = 140;

% 5th harmonic currents
Id5_step = 0.0;
Id5_ref1 = 0;
Id5_ref2 = 0;

Iq5_step = 0;
Iq5_ref1 = 0;
Iq5_ref2 = 0;

%% DC Bus
VDC = 250;

%% Frequencies
f_b = 1000; % Current controller bandwidth in Hz.
fe = 0; % Fundamental freq
Fsw = 60e3; % Switching freq

%% Circuit parameters
R = 24e-3;
L1 = 50e-6; L3 = 0;
L2 = 0; L4 = 0;
A = [L1 L3; L3 L1];
B = [L2 L4; L4 L2];
Lmat = [A B B; B A B; B B A];

L_ind1 = L1;
L_ind2 = L1;
L_ind3 = L1;
L_ind4 = L1;
L_ind5 = L1;
L_ind6 = L1;
L_ind7 = L1;

R1 = R;
R2 = R;
R3 = R;
R4 = R;
R5 = R;
R6 = R;
R7 = R;

L = L1 + L2;
M = L3 - L4;

Rxy = R; % equivalent xy resistance [Ohms]
Lxy = L - M; % equivalent xy inductance [H]
Rx = Rxy; Ry = Rxy;
Lx = Lxy; Ly = Lxy;

Rdq = R; % equivalent dq resistance [Ohms]
Ldq = L + M; % equivalent dq inductance [H]
Rd = Rdq; Rq = Rdq;
Ld = Ldq; Lq = Ldq;

%% Current controller parameters
% Fundamental PI controllers:
Kpd1 = 2*pi*f_b*Ld; % [Ohms]
Kid1 = 2*pi*f_b*Rd; % [Ohms s]
Kpq1 = 2*pi*f_b*Lq; % [Ohms]
Kiq1 = 2*pi*f_b*Rq; % [Ohms s]

% Third harmonic PI controllers:
Kpd3 = 2*pi*f_b*Ld; % [Ohms]
Kid3 = 2*pi*f_b*Rd; % [Ohms s]
Kpq3 = 2*pi*f_b*Lq; % [Ohms]
Kiq3 = 2*pi*f_b*Rq; % [Ohms s]

% Fifth harmonic PI controllers:
Kpd5 = 2*pi*f_b*Ld; % [Ohms]
Kid5 = 2*pi*f_b*Rd; % [Ohms s]
Kpq5 = 2*pi*f_b*Lq; % [Ohms]
Kiq5 = 2*pi*f_b*Rq; % [Ohms s]

%% Other parameters
m = 7;
Cm = 2/m; % Clarke Transformation constant
Tsw = 1/Fsw; % Switching time
PWM_INVERTER = 1; % Enable the inverter
K_dec_ax = 1;

%% Run the simulation
output = sim('multiPhaseAFPM');

figure()
subplot(3,1,1)
plot(output.simout.i_sv.id1_ref, 'linewidth', 1.5);
hold on
plot(output.simout.i_sv.iq1_ref, 'linewidth', 1.5);
plot(output.simout.i_sv.id1,'--', 'linewidth', 1.5);
plot(output.simout.i_sv.iq1,'--', 'linewidth', 1.5);
xlabel('Simulation time [s]')
ylabel('Amplitude [A]')
legend('I_dref', 'I_qref', 'I_d', 'I_q')
grid on

subplot(3,1,2)
plot(output.simout.i_sv.id3_ref, 'linewidth', 1.5);
hold on
plot(output.simout.i_sv.iq3_ref, 'linewidth', 1.5);
plot(output.simout.i_sv.id3,'--', 'linewidth', 1.5);
plot(output.simout.i_sv.iq3,'--', 'linewidth', 1.5);
xlabel('Simulation time [s]')
ylabel('Amplitude [A]')
legend('I_d3ref', 'I_q3ref', 'I_d3', 'I_q3')
grid on

subplot(3,1,3)
plot(output.simout.i_sv.id5_ref, 'linewidth', 1.5);
hold on
plot(output.simout.i_sv.iq5_ref, 'linewidth', 1.5);
plot(output.simout.i_sv.id5,'--', 'linewidth', 1.5);
plot(output.simout.i_sv.iq5,'--', 'linewidth', 1.5);
xlabel('Simulation time [s]')
ylabel('Amplitude [A]')
legend('I_d5ref', 'I_q5ref', 'I_d5', 'I_q5')
grid on

% % Acquire simulation data
% plotIdRef = output.OutputData.signals(1).values(:,1);
% plotId = output.OutputData.signals(1).values(:,2);
% plotIqRef = output.OutputData.signals(2).values(:,1);
% plotIq = output.OutputData.signals(2).values(:,2);
% plotIa = output.OutputData.signals(3).values(:,1);
% plotIb = output.OutputData.signals(3).values(:,2);
% plotIc = output.OutputData.signals(3).values(:,3);
% time = output.OutputData.time;

% %% Make plots
% figure()
% plot(time, plotIdRef);
% hold on
% plot(time, plotId);
% xlabel('Time[s]')
% ylabel('I_d [A]');
% legend('reference', 'actual');
% xlim([0,0.6]);
% 
% 
% figure()
% plot(time, plotIqRef);
% hold on
% plot(time, plotIq);
% xlabel('Time[s]')
% ylabel('I_q [A]');
% legend('reference', 'actual');
% xlim([0,0.4]);
% 
% figure()
% plot(time, plotIa);
% hold on
% plot(time, plotIb);
% plot(time, plotIc);
% xlabel('Time[s]')
% ylabel('Three phase currents [A]');
% legend('I_a', 'I_b', 'I_c');
% xlim([0.16,0.4]);
% grid on

%% Build CurrentControl
model='CurrentControl';
slbuild(model);
%Open file explorer to correct location
winopen(['.\' model '_ert_rtw/']);
