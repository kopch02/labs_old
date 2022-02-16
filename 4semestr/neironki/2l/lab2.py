x0=[1,1,1,1]
x1=[0,0,1,1]
x2=[0,1,0,1]

wx=[0.1,-0.05,0.05]
wx2=[0.1,-0.1,0.01]
wy=[-0.05,-0.01,-0.05]
w=[wx,wy,wx2]

y0=[1,1,1,1]
y1=[0,0,0,0]
y2=[0,0,0,0]

c=[0,1,1,0]

e1=0
e2=0

ly=0.0001

for epoh in range(10000):
    E=0
    for sample in range(4):
        y1[sample]=float(w[0][0])*float(x0[sample])+float(w[0][1])*float(x1[sample])+float(w[0][2])*float(x2[sample])
        y2[sample]=float(w[2][0])*float(x0[sample])+float(w[2][1])*float(x1[sample])+float(w[2][2])*float(x2[sample])
    
        z=float(w[1][0])*float(y0[sample])+float(w[1][1])*float(y1[sample])+float(w[1][2])*float(y2[sample])
        w[1][0]+=ly*y0[sample]*(c[sample]-z)
        w[1][1]+=ly*y1[sample]*(c[sample]-z)
        w[1][2]+=ly*y2[sample]*(c[sample]-z)

        z=float(w[1][0])*float(y0[sample])+float(w[1][1])*float(y1[sample])+float(w[1][2])*float(y2[sample])
        e=0.5*pow(c[sample]-z,2)
        E+=e
    
        e1=E*w[1][1]
        e2=E*w[1][2]
        for i in range(3):
            w[0][i]+=ly*x0[i]*(e1)

            w[2][i]+=ly*x0[i]*(e2)

    
    print(E/4)
        
for sample in range(4):
    z=float(w[1][0])*float(y0[sample])+float(w[1][1])*float(y1[sample])+float(w[1][2])*float(y2[sample])
    print(c[sample],"   ",z)