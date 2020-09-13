#================================================================
# Runge-Kutta 4th Order Function
#
# Author: Bayu R. J. (remove this lol)
# Version: 1.0 *initial release
# Level: Beginner
# Python : IDLE 3.6.3 (use 'new file' to make a whole script)
#================================================================
# Compatibility
#
# *Function can be seperate independently
#----------------------------------------------------------------
# Known Bugs
#
# *None
#-----------------------------------------------------------------

def dy(u):
    dy = u
    return dy

def du(x, u):
    k = 2 # spring constant
    c = 460 # damping coefficient
    m = 450 # mass

    du = (-c*u - k*x) / m;
    return du;

#initial value
y = 0.01
u = 0
r = 0

# number of steps
N = 10

# initial y
a = y

# final y
b = 1

#step size
h = (b-a)/N

xpoints = [y]
for i in range(99999):
    r += h
    if (r < b):
        xpoints.append(r)
    i += 1

ypoints = []
upoints = []
#print(xpoints) buat debugging

#Runge-Kutta 4th Order
for x in xpoints: 
    ypoints.append(y)
    upoints.append(u)

    k1 = dy(u)
    m1 = du(y, u);  

    k2 = dy(u + m1*h)
    m2 = du(y + k1*h / 2, u + m1*h / 2)

    k3 = dy(u + m2*h / 2)
    m3 = du(y + k2*h / 2, u + m2*h / 2)

    k4 = dy(u + m3*h)
    m4 = du(y + k3*h, u + m3*h)
    
    y += (k1 + 2*k2 + 2*k3 + k4)/6
    u += (m1 + 2*m2 + 2*m3 + m4)/6

print (y)
