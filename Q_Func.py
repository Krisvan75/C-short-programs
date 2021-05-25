import numpy as np
from scipy import special as sp
import math

def Qfunc(f):
    return 0.5-0.5*sp.erf(f/math.sqrt(2))

def inv_Qfunc(f):
    return math.sqrt(2)*sp.erfcinv(2*f)

f = float(input("y:"))
mode = input('mode:(Q or invQ)')

if mode == 'Q':
    print(Qfunc(f))

elif mode == 'invQ':
    print(inv_Qfunc(f))
