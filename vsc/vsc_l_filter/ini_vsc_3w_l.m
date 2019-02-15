F_b = 50.0;
L_s = 2.5e-3;
R_s = 0.2;
C_dc = 1e6;

V_dc = 730.0;

tau_ref = 0.005;
K_p = L_s/tau_ref;
K_i = R_s/tau_ref;

vsc_ini = [0,0,V_dc];
vsc_ctrl_ini = [0,0];