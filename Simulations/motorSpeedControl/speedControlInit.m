clear all;
close all;
clc;
dir = pwd; % Get the present working directory
addpath(genpath(dir)); % using genpath() adds all the subfolders
%% Simulation time
T_end = 0.5; % End time
mask_Ts = 1/10000; % Sample time for the controller

%% Motor and drive parameters
mask_Kt = 0.126; %Torque constant in Nm/A_pk
mask_R_s = 45e-3; %Resistance phase to neutral [Ohms]
mask_Ld = 52.9e-6; % d-axis inductance [H]
mask_Lq = 52.9e-6; % q-axis inductance [H]
mask_p = 8; %Pole pairs
mask_lambda_pm = mask_Kt/((3/2)*mask_p); % Flux linkage due to PM
mask_Kv = 0.126; % Voltage constant in V(l-l pk)/rad/s

%% Simulation parameters
I_dref = 0;
RPM = 1500; % Reference speed in RPM
omega_ref = (2*pi/60)*(RPM);
millPower = 5600; % Power rating of mill spindle in Watts
mask_f = (2*mask_p)*RPM/120;
mask_Vrms = (mask_Kv*omega_ref)/(sqrt(6));

%% Current control parameters
f_ib = 750; % Current controller bandwidth Hz
omega_ib = f_ib*2*pi; % Current controller bandwidth [rad/s]
mask_Kpd = omega_ib*mask_Ld; % K_p for d axis
mask_Kpq = omega_ib*mask_Lq; % K_p for q axis
mask_Kid = omega_ib*mask_R_s; % K_i for d axis
mask_Kiq = omega_ib*mask_R_s;% K_i for q axis
F_sw = 50000; % Switching freq
mask_Tsw = 1/F_sw; % Switching time
PWM_INVERTER = 1; % Enable the inverter
T_sim = 1/(F_sw*100);

%% Speed control parameters
f_sb = f_ib/4; % Speed controller bandwidth Hz
omega_sb = f_sb*2*pi; % Speed controller bandwidth [rad/s]
Iq_max = 200;
J = 0.008; % Moment of inertia [kg m^2] of the rotor + shaft + PM
B = 0.00000001;
mask_Kps=omega_sb*J; %Proportional Gain for the Speed Controller
mask_Kis=omega_sb*B; %Integral Gain for the Speed Controller
mask_Kaw = mask_Kis/mask_Kps;
F_sw = 60000; % Switching freq
f_w = 50; % LPF for speed command

%% Buck converter
mask_VDC = 250;

% Run the simulation
output = sim('discreteMill');
save('SimDataDiscrete.mat');

%% Acquire simulation data
% Motor Line currents
I_abc2(:,1) = output.I_3.signals.values(:,1);
I_abc2(:,2) = output.I_3.signals.values(:,2);
I_abc2(:,3) = output.I_3.signals.values(:,3);

% Line-line voltages
V_abc2(:,1) = output.V_3.signals.values(:,1);
V_abc2(:,2) = output.V_3.signals.values(:,2);
V_abc2(:,3) = output.V_3.signals.values(:,3);

% Torque
T_2 = output.T_3.signals.values(:,1);

% Simulation time
time = output.tout;
f_1 = 2*mask_p*RPM/120;

%% Make plots
figure()
plot(time, I_abc2(:,1));
hold on
plot(time, I_abc2(:,2));
plot(time, I_abc2(:,3));
ylabel('Current [A]');
xlabel('Time [s]');
xlim([T_end-2/f_1,T_end]);

figure()
plot(time, V_abc2(:,1));
hold on
plot(time, V_abc2(:,2));
plot(time, V_abc2(:,3));
ylabel('Voltage [V]');
xlim([T_end-2/f_1,T_end]);
xlabel('Time [s]');
xlim([T_end-2/f_1,T_end]);

figure()
plot(time, T_2);
hold on
plot(time, output.torqueCommand.signals.values);
xlabel('Time [s]');
ylabel('Torque [Nm]');
%xlim([T_end-2/f_1,T_end]);
ylim([-30, 10]);

figure()
plot(time, V_dc2);
ylabel('Bus voltage [V]');
xlim([T_end-2/f_1,T_end]);

figure()
plot(time, V_L2);
hold on
plot(time, I_L2);
legend('V_{L}', 'I_{L}');
xlabel('Time [s]');
ylabel('Load current and voltage');
xlim([T_end-2/f_1,T_end]);

%% Build CurrReg
model='dqIdentification';
slbuild(model); 
%Open file explorer to correct location
winopen(['.\' model '_ert_rtw/']);
