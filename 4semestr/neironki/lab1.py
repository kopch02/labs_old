from cmath import*
ly=0.01
w=[0.1,0.05,0.05]
x=[1,0,0]
y=[]
c=[0,0,0,1]
e=[]
r=0.0
for epoh in range(100):
    for sample in range(4):
        r=float(w[0])*float(x[0])+float(w[1])*float(x[1])+float(w[2])*float(x[2])
        y.append(r)
        for i in range(3):
            w[i]+=ly*x[i]*(c[i]-y[sample])
    for i in range(4):
        t=0.5*pow(c[i]-y[i],2)
        e.append(t)
        print(e[i])