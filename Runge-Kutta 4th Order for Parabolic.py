#================================================================
# Runge-Kutta 4th Order Function for Parabolic Problem
#
# Author: Bayu R. J. (remove this lol)
# Version: 1.0.1 *initial release
# Level: Easy
# Python : IDLE 3.6.3 (use 'new file' to make a whole script)
#================================================================
# Updates
#
# 08/09/2020 (1.0.1) - Keep the damp spring for remembering purpose.
#-----------------------------------------------------------------
# Compatibility
#
# *Function can be seperate independently (import math first)
#----------------------------------------------------------------
# Known Bugs
#
# *None
#-----------------------------------------------------------------

#import sect
import math

def dy(v, y, g, t):
    dy = v * math.sin(degree) + g * t
    return dy

def dx(v, t):
    if(t == 0):
        dx = 0
    else:
        dx = v * math.cos(degree) / t
    return dx

def dxx(c, m, f, v, t):
    dxx = -1 * ((c/m) * dx(v, t) * math.pow(f, 0.5))
    return dxx

def dyy(c, m, y, f, g, v, t):
    dyy = (-1 * ((c/m) * dy(v, y, g, t) * math.pow(f, 0.5))) - g
    return dyy

#Not used
#--------------------------------
def du(x, u):
    k = 2 # spring constant
    c = 460 # damping coefficient
    m = 450 # mass

    du = (-c*u - k*x) / m;
    return du;
#---------------------------------

# initial value
y = 0
x = 0

#constant value
degree = math.degrees(30)
m = 0.25
v = 50
c = 0.03
g = 9.80665
x1 = dx(v, 0)
y1 = dy(v, y, g, 0)
f = math.sqrt(math.pow(x1, 2) + math.pow(y1, 2))
r = 0

#print(dxx(c, m, f, v, t))

# number of steps
N = 3

#step size
h = 0.01

tpoints = [x]
for i in range(99999):
    r += h
    if (r < N):
        tpoints.append(r)
    i += 1
R1points = []
R2points = []
xpoints = []
ypoints = []
#print(xpoints) buat debugging

#inisialisasi kondisi
kondisiJatuh = 0
kondisiTinggi = 0
jarakJatuh = 0
waktuJatuh = 0
waktuTinggi = 0
intChecker = 0

#Runge-Kutta 4th Order for x
for t in tpoints: 
    xpoints.append(x)
    ypoints.append(y)

    k1 = dxx(c, m, f, v, t)
    k2 = dxx(c + k1*h/2, m + k1*h/2, f + k1*h/2, v + k1*h/2, t + k1*h/2)
    k3 = dxx(c + k2*h/2, m + k2*h/2, f + k2*h/2, v + k2*h/2, t + k2*h/2)
    k4 = dxx(c + k3*h/2, m + k3*h/2, f + k3*h/2, v + k3*h/2, t + k3*h/2)
    
    L1 = dyy(c, m, y, f, g, v, t) 
    L2 = dyy(c + L1*h/2, m + L1*h/2, y + L1*h/2, f + L1*h/2, g + L1*h/2, v + L1*h/2, t + L1*h/2)
    L3 = dyy(c + L2*h/2, m + L2*h/2, y + L2*h/2, f + L2*h/2, g + L2*h/2, v + L2*h/2, t + L2*h/2)
    L4 = dyy(c + L3*h/2, m + L3*h/2, y + L3*h/2, f + L3*h/2, g + L3*h/2, v + L3*h/2, t + L3*h/2)
    
    x += (k1 + 2*k2 + 2*k3 + k4)/6
    y += (L1 + 2*L2 + 2*L3 + L4)/6

    if (y < 0 and kondisiJatuh == 0):
        jarakJatuh = x
        waktuJatuh = t
        kondisiJatuh = 1

    if (ypoints[intChecker] < ypoints[intChecker - 1] and kondisiTinggi == 0):
        waktuTinggi = t - h
        kondisiTinggi = 1
        
    intChecker += 1
print ("Waktu bola jatuh berada pada R = ", jarakJatuh, " saat waktu t = ", waktuJatuh)
print ("Waktu bola tertinggi berada pada t = ", waktuTinggi)
#print(ypoints)
