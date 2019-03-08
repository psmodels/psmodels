F_b = 50.0;
Omega_b = 2*pi*50;

tau_d = 0.02;
K_p = 1.0/(tau_d*Omega_b);

params = [K_p,Omega_b];