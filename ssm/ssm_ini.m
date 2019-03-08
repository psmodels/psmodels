% simplified synchronous machine (SSM)
S_b = 20e3;
U_b = 400.0;
F_b = 50.0;
Omega_b = 2*pi*50;
Z_b = U_b^2/S_b;
H = 5.0;
D = 50;

K = Omega_b/(2*S_b*H);
K_d = D*S_b/Omega_b;

R_1 = 1.0;
L_1 = 10e-3;
R_pu = R_1/Z_b;
X_pu = L_1*Omega_b/Z_b;

R_2 = 1.0;
L_2 = 1e-3;

params_abc = [S_b,U_b,Omega_b,K,K_d];
params_pu = [S_b,U_b,Omega_b,R_pu,X_pu,H,D];

T_s_power = 100e-6;
T_s_control = 100e-6;

F_b = 50.0;
Omega_b = 2*pi*50;

tau_d = 0.02;
K_p = 1.0/(tau_d*Omega_b);

params_pll = [K_p,Omega_b];

