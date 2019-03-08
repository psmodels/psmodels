clear all
clc
f = 50;
omega = 2*pi*50;
L_t = 1.25e-3;
R_t = L_t*omega/10;
L_s = 1.25e-3;
R_s = L_t*omega/10;
R_d = 1;
C = 1e-6;
R_L = 10;
tau_c = 1e-3;
Ts_Power=50e-6;
Ts_Control=50e-6;
K_p = L_t/tau_c;
K_i = R_t/tau_c;
v_dc=730;
K_pv=0.002;
K_iv=0.00001;

params=[R_t;L_t;R_s;L_s;K_p;K_i;C;K_pv;K_iv];



