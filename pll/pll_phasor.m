F_b = 50.0;
Omega_b = 2*pi*50;

tau_d = 0.02;
K_p = 1.0/(tau_d*Omega_b);

params = [K_p,Omega_b];

S_b = 20e3;
U_b = 400.0;

Z_b = U_b^2/S_b;
X = 0.2*Z_b
L = X/(Omega_b);
R = 0.0;

R = 0.635;
X = 0.565;