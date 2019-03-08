import numpy as np
import numba
from pysimu.nummath import interp


class rl_class: 
    def __init__(self): 

        self.t_end = 0.100000 
        self.Dt = 0.001000 
        self.decimation = 10.000000 
        self.itol = 0.000000 
        self.solvern = 1 
        self.imax = 100 
        self.N_x = 2 
        self.N_y = 2 
        self.update() 

    def update(self): 

        self.N_steps = int(np.ceil(self.t_end/self.Dt)) 
        self.N_store = int(np.ceil(self.N_steps/self.decimation))
        dt =  [  
        ('t_end', np.float64),
        ('Dt', np.float64),
        ('decimation', np.float64),
        ('itol', np.float64),
        ('solvern', np.int64),
        ('imax', np.int64),
                    ('N_steps', np.int64),
                    ('N_store', np.int64),
                ('R', np.float64),
                ('L', np.float64),
                ('v_t_d', np.float64),
                ('v_t_q', np.float64),
                ('v_s_d', np.float64),
                ('v_s_q', np.float64),
                ('omega', np.float64),
                    ('N_x', np.int64),
                    ('idx', np.int64),
                    ('f', np.float64, (2,1)),
                    ('x', np.float64, (2,1)),
                    ('x_0', np.float64, (2,1)),
                    ('h', np.float64, (2,1)),
                    ('Fx', np.float64, (2,2)),
                    ('T', np.float64, (self.N_store+1,1)),
                    ('X', np.float64, (self.N_store+1,2)),
                ]  

        values = [
                self.t_end,
                self.Dt,
                self.decimation,
                self.itol,
                self.solvern,
                self.imax,
                self.N_steps,
                self.N_store,
                1.0,   # R 
                 0.001,   # L 
                 0,   # v_t_d 
                 0,   # v_t_q 
                 0.0,   # v_s_d 
                 0,   # v_s_q 
                 314.1592653589793,   # omega 
                 2,
                0,
                np.zeros((2,1)),
                np.zeros((2,1)),
                np.zeros((2,1)),
                np.zeros((2,1)),
                                np.zeros((2,2)),
                np.zeros((self.N_store+1,1)),
                np.zeros((self.N_store+1,2)),
                ]  
        ini_struct(dt,values)

        dt +=     [('t', np.float64)]
        values += [0.0]

        dt +=     [('N_y', np.int64)]
        values += [self.N_y]

        dt +=     [('g', np.float64, (2,1))]
        values += [np.zeros((2,1))]
        dt +=     [('y', np.float64, (2,1))]
        values += [np.zeros((2,1))]
        dt +=     [('Fy', np.float64, (2,2))]
        values += [np.zeros((2,2))]
        dt +=     [('Gx', np.float64, (2,2))]
        values += [np.zeros((2,2))]
        dt +=     [('Gy', np.float64, (2,2))]
        values += [np.zeros((2,2))]




        self.struct = np.rec.array([tuple(values)], dtype=np.dtype(dt))


    def ini_problem(self,x):
        self.struct[0].x_ini[:,0] = x[0:self.N_x]
        self.struct[0].y_ini[:,0] = x[self.N_x:(self.N_x+self.N_y)]
        initialization(self.struct)
        fg = np.vstack((self.struct[0].f_ini,self.struct[0].g_ini))[:,0]
        return fg

    def run_problem(self,x):
        t = self.struct[0].t
        self.struct[0].x[:,0] = x[0:self.N_x]
        self.struct[0].y[:,0] = x[self.N_x:(self.N_x+self.N_y)]
        run(t,self.struct,2)
        run(t,self.struct,3)
        run(t,self.struct,10)
        run(t,self.struct,11)
        fg = np.vstack((self.struct[0].f,self.struct[0].g))[:,0]
        return fg
@numba.jit(nopython=True, cache=True)
def run(t,struct, mode):

    sin = np.sin
    cos = np.cos
    sqrt = np.sqrt
    it = 0

    # parameters 
    R = struct[it].R
    L = struct[it].L

    # inputs 
    v_t_d = struct[it].v_t_d
    v_t_q = struct[it].v_t_q
    v_s_d = struct[it].v_s_d
    v_s_q = struct[it].v_s_q
    omega = struct[it].omega

    # states 
    i_s_d  = struct[it].x[0,0] 
    i_s_q  = struct[it].x[1,0] 


    # algebraic states 
    i_s_i = struct[it].y[0,0] 
    i_s_r = struct[it].y[1,0] 


    if mode==2: # derivatives 

        di_s_d = 1/L*(v_t_d - R*i_s_d + L*omega*i_s_q - v_s_d) 
        di_s_q = 1/L*(v_t_q - R*i_s_q - L*omega*i_s_d - v_s_q) 

        struct[it].f[0,0] = di_s_d   
        struct[it].f[1,0] = di_s_q   

    if mode==3: # algebraic equations 

        struct[it].g[0,0] = -i_s_d + sqrt(2)*i_s_i  
        struct[it].g[1,0] = -i_s_q - sqrt(2)*i_s_r  

    if mode==4: # outputs 

        struct[it].h[0,0] = i_s_r  
        struct[it].h[1,0] = i_s_i  
    

    if mode==10: # Fx 

        struct[it].Fx[0,0] = -R/L 
        struct[it].Fx[0,1] = omega 
        struct[it].Fx[1,0] = -omega 
        struct[it].Fx[1,1] = -R/L 
    

    if mode==11: # Fy,Gx,Gy 

    

        struct[it].Gx[0,0] = -1 
        struct[it].Gx[1,1] = -1 
    

        struct[it].Gy[0,0] = sqrt(2) 
        struct[it].Gy[1,1] = -sqrt(2) 


@numba.njit(cache=True)
def initialization(struct):

    sin = np.sin
    cos = np.cos
    sqrt = np.sqrt
    R = struct[0].R 
    L = struct[0].L 
    v_t_d = struct[0].v_t_d 
    v_t_q = struct[0].v_t_q 
    v_s_d = struct[0].v_s_d 
    v_s_q = struct[0].v_s_q 
    omega = struct[0].omega 
    i_s_d = struct[0].x_ini[0,0] 
    i_s_q = struct[0].x_ini[1,0] 
    i_s_r = struct[0].y_ini[0,0] 
    i_s_i = struct[0].y_ini[1,0] 
    struct[0].f_ini[0,0] = (L*i_s_q*omega - R*i_s_d - v_s_d + v_t_d)/L 
    struct[0].f_ini[1,0] = (-L*i_s_d*omega - R*i_s_q - v_s_q + v_t_q)/L 
    struct[0].g_ini[0,0]  = -i_s_d + sqrt(2)*i_s_i  
    struct[0].g_ini[1,0]  = -i_s_q - sqrt(2)*i_s_r  
    struct[0].Fx_ini[0,0] = -R/L 
    struct[0].Fx_ini[0,1] = omega 
    struct[0].Fx_ini[1,0] = -omega 
    struct[0].Fx_ini[1,1] = -R/L 
    struct[0].Gx_ini[0,0] = -1 
    struct[0].Gx_ini[1,1] = -1 
    struct[0].Gy_ini[0,1] = sqrt(2) 
    struct[0].Gy_ini[1,0] = -sqrt(2) 


def ini_struct(dt,values):

    dt +=     [('x_ini', np.float64, (2,1))]
    values += [np.zeros((2,1))]
    dt +=     [('y_ini', np.float64, (2,1))]
    values += [np.zeros((2,1))]
    dt +=     [('f_ini', np.float64, (2,1))]
    values += [np.zeros((2,1))]
    dt +=     [('g_ini', np.float64, (2,1))]
    values += [np.zeros((2,1))]
    dt +=     [('Fx_ini', np.float64, (2,2))]
    values += [np.zeros((2,2))]
    dt +=     [('Fy_ini', np.float64, (2,2))]
    values += [np.zeros((2,2))]
    dt +=     [('Gx_ini', np.float64, (2,2))]
    values += [np.zeros((2,2))]
    dt +=     [('Gy_ini', np.float64, (2,2))]
    values += [np.zeros((2,2))]


@numba.njit(cache=True) 
def solver(struct): 
    sin = np.sin
    cos = np.cos
    sqrt = np.sqrt
    i = 0 

    Dt = struct[i].Dt 
    N_steps = struct[i].N_steps 
    N_store = struct[i].N_store 
    N_x = 2 
    N_outs = 1 
    decimation = struct[i].decimation 
    # initialization 
    t = 0.0 
    run(0.0,struct, 1) 
    it_store = 0 
    struct[i]['T'][0] = t 
    struct[i].X[0,:] = struct[i].x[:,0]  
    for it in range(N_steps-1): 
        t += Dt 
 
        perturbations(t,struct) 
        solver = struct[i].solvern 
        if solver == 1: 
            # forward euler solver  
            run(t,struct, 2)  
            struct[i].x[:] += Dt*struct[i].f  
 
        if solver == 2: 
            # bacward euler solver
            x_0 = np.copy(struct[i].x[:]) 
            for j in range(struct[i].imax): 
                run(t,struct, 2) 
                run(t,struct, 10)  
                phi =  x_0 + Dt*struct[i].f - struct[i].x 
                Dx = np.linalg.solve(-(Dt*struct[i].Fx - np.eye(N_x)), phi) 
                struct[i].x[:] += Dx[:] 
                if np.max(np.abs(Dx)) < struct[i].itol: break 
 
        if solver == 3: 
            # trapezoidal solver
            run(t,struct, 2) 
            f_0 = np.copy(struct[i].f[:]) 
            x_0 = np.copy(struct[i].x[:]) 
            for j in range(struct[i].imax): 
                run(t,struct, 10)  
                phi =  x_0 + 0.5*Dt*(f_0 + struct[i].f) - struct[i].x 
                Dx = np.linalg.solve(-(0.5*Dt*struct[i].Fx - np.eye(N_x)), phi) 
                struct[i].x[:] += Dx[:] 
                run(t,struct, 2) 
                if np.max(np.abs(Dx)) < struct[i].itol: break 
        
        # channels 
        if it >= it_store*decimation: 
          struct[i]['T'][it_store+1] = t 
          struct[i].X[it_store+1,:] = struct[i].x[:,0] 
          it_store += 1 
        
    return struct[i]['T'][:], struct[i].X[:] 


@numba.njit(cache=True) 
def perturbations(t,struct): 
    if t>1.000000: struct[0].RoCoF = 1.000000



if __name__ == "__main__":
    sys = {'t_end': 0.1, 'Dt': 0.001, 'solver': 'forward-euler', 'decimation': 10, 'name': 'rl', 'models': [{'params': {'R': 1.0, 'L': 0.001}, 'f': ['di_s_d = 1/L*(v_t_d - R*i_s_d + L*omega*i_s_q - v_s_d)', 'di_s_q = 1/L*(v_t_q - R*i_s_q - L*omega*i_s_d - v_s_q)'], 'g': ['i_s_i @ -i_s_d + sqrt(2)*i_s_i', 'i_s_r @ -i_s_q - sqrt(2)*i_s_r'], 'u': {'v_t_d': 0, 'v_t_q': 0, 'v_s_d': 0.0, 'v_s_q': 0, 'omega': 314.1592653589793}, 'y': ['i_s_r', 'i_s_i'], 'y_ini': ['i_s_r', 'i_s_i'], 'h': ['i_s_r', 'i_s_i']}], 'perturbations': [{'type': 'step', 'time': 1.0, 'var': 'RoCoF', 'final': 1.0}], 'itol': 1e-08, 'imax': 100, 'solvern': 1}
    syst =  rl_class()
    T,X = solver(syst.struct)
    from scipy.optimize import fsolve
    x0 = np.ones(syst.N_x+syst.N_y)
    s = fsolve(syst.ini_problem,x0 )
    print(s)