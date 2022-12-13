clear all;
close all;
clc;
fileName = 'sevenPhaseTest_2022-12-03_H13-M40-S55.csv';
data = xlsread(fileName, 'A2:AA40081');
time = data(:,1);
IPh = data(:, 2:8);
I_d1 = data(:, 10);
I_q1 = data(:, 11);
I_d3 = data(:,12);
I_q3 = data(:,13);
I_d5 = data(:,14);
I_q5 = data(:,15);
I_d1ref = data(:,16);
I_q1ref = data(:,17);
I_d3ref = data(:,18);
I_q3ref = data(:,19);
I_d5ref = data(:,20);
I_q5ref = data(:,21);
plot_size = [0.25 2.5 2.3 1.75];
figure()
plot(time, I_d1);
hold on
plot(time, I_d1ref, 'linewidth', 1.2);
plot(time, I_q1);
plot(time, I_q1ref, 'linewidth', 1.2);
ylim([-4,4])
xlim([0, 4])
h1=legend('$I_{d1}$', '$I_{d1(ref)}$', '$I_{q1}$','$I_{q1(ref)}$', 'location','best');
set (h1, 'FontSize',8,'FontName','TimesNewRoman', 'box', 'off','Interpreter', 'latex');
xlabel('Time [s]','Interpreter','latex','FontSize',6,...
            'FontName','TimesNewRoman');
ylabel ('Current [A]','Interpreter','latex','FontSize',6,...
            'FontName','TimesNewRoman');
set(gca,'FontName','TimesNewRoman','FontSize',8,'color', 'none');
set(gcf, 'PaperPositionMode', 'manual', 'PaperUnits', 'inches', 'PaperPosition', plot_size);
print('-dsvg','-noui','Fundamental');

figure()
plot(time, I_d3);
hold on
plot(time, I_d3ref, 'linewidth', 1.2);
plot(time, I_q3);
plot(time, I_q3ref, 'linewidth', 1.2);
ylim([-4,4])
xlim([0, 4])
h1=legend('$I_{d3}$', '$I_{d3(ref)}$', '$I_{q3}$','$I_{q3(ref)}$', 'location','best');
set (h1, 'FontSize',8,'FontName','TimesNewRoman', 'box', 'off','Interpreter', 'latex');
xlabel('Time [s]','Interpreter','latex','FontSize',6,...
            'FontName','TimesNewRoman');
ylabel ('Current [A]','Interpreter','latex','FontSize',6,...
            'FontName','TimesNewRoman');
set(gca,'FontName','TimesNewRoman','FontSize',8,'color', 'none');
set(gcf, 'PaperPositionMode', 'manual', 'PaperUnits', 'inches', 'PaperPosition', plot_size);
print('-dsvg','-noui','ThirdHarmonic');

figure()
plot(time, I_d5);
hold on
plot(time, I_d5ref, 'linewidth', 1.2);
plot(time, I_q5);
plot(time, I_q5ref, 'linewidth', 1.2);
ylim([-4,4])
xlim([0, 4.0079])
h1=legend('$I_{d5}$', '$I_{d5(ref)}$', '$I_{q5}$','$I_{q5(ref)}$', 'location','best');
set (h1, 'FontSize',8,'FontName','TimesNewRoman', 'box', 'off','Interpreter', 'latex');
xlabel('Time [s]','Interpreter','latex','FontSize',6,...
            'FontName','TimesNewRoman');
ylabel ('Current [A]','Interpreter','latex','FontSize',6,...
            'FontName','TimesNewRoman');
set(gca,'FontName','TimesNewRoman','FontSize',8,'color', 'none');
set(gcf, 'PaperPositionMode', 'manual', 'PaperUnits', 'inches', 'PaperPosition', plot_size);
print('-dsvg','-noui','FifthHarmonic');