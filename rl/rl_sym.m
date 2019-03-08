syms L R real
syms v_t_d v_t_q v_s_d v_s_q i_s_d i_s_q real
syms omega real

di_s_d = 1/L*(v_t_d - R*i_s_d + L*omega*i_s_q - v_s_d);
di_s_q = 1/L*(v_t_q - R*i_s_q - L*omega*i_s_d - v_s_q);

sol_idq = solve([di_s_d,di_s_q],[i_s_d,i_s_q])