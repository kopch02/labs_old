from cmath import*
import matplotlib.pyplot as plt
import numpy as np

ly=0.0001
w=[0.1,-0.05,0.05]
x0=[1,1,1,1]
x1=[0,0,1,1]
x2=[0,1,0,1]

c=[0,0,0,1]

for epoh in range(100000):
    se=0
    for sample in range(4):
        y=float(w[0])*float(x0[sample])+float(w[1])*float(x1[sample])+float(w[2])*float(x2[sample])
        w[0]+=ly*x0[sample]*(c[sample]-y)
        w[1]+=ly*x1[sample]*(c[sample]-y)
        w[2]+=ly*x2[sample]*(c[sample]-y)

    for i in range(4):
        y=float(w[0])*float(x0[i])+float(w[1])*float(x1[i])+float(w[2])*float(x2[i])
        e=0.5*pow(c[i]-y,2)
        se+=e

    print(se/4)

for sample in range(4):
    y=float(w[0])*float(x0[sample])+float(w[1])*float(x1[sample])+float(w[2])*float(x2[sample])
    print(c[sample],"   ",y)

yy=-(w[1]/w[2])*x1[0]+(0.5-w[2]*x0[0])/w[2]
