F_b = 50.0;
L_t = 1.25e-3;
R_t = 0.5;
L_s = 1.25e-3;
R_s = 0.5;
C_ac = 1.0e-6;
C_dc = 1e6;
R_d = 20.0;
V_dc = 730.0;

tau_ref = 0.01;
L = L_t + L_s;
R = R_t + R_s;
K_p = L/tau_ref;
K_i = R/tau_ref;

vsc_ini = [0,0,V_dc];
vsc_ctrl_ini = [0,0];