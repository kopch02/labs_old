def n1():
    stroka=input()
    n=len(stroka)
    if n<=2:
        print("слишком маленькая строка!!!!")
        quit()
    print(stroka[2])
    print(stroka[-2])
    print(stroka[:5])
    print(stroka[:n-2])
    print(stroka[:n:2])
    print(stroka[1:n:2])
    print(stroka[::-1])
    revers=stroka[::-1]
    print(revers[:n:2])
    print(n)

def n2():
    stroka=input()
    n=len(stroka)
    two=n//2
    one=n-two
    stone=stroka[:n-two]
    sttwo=stroka[one:n]
    string=str(sttwo)+str(stone)
    print(string)

def n3():
    stroka=input()
    n=len(stroka)
    a=""
    b=False
    for x in range(1,n):
        if stroka[x]=="h":
            x+=1
            while True:
                a+=stroka[x]
                x+=1
                if stroka[x]=="h":
                    b=True
                    break
            if b==True:
                break
    print(a[::-1])

def n4():
    stroka=input()
    n=len(stroka)
    l=list(stroka)
    if "f" in l:
        s=(l.count("f"))
        if s==1:
            a=l.index("f")
            print(a+1)
            quit()
        else:
            a=l.index("f")
            print(a+1)
            revers=stroka[::-1]
            r=list(revers)
            b=r.index("f")
            b-=n
            b*=-1
            print(b)
    else:
        quit()

def n5():
    a=[1,2,2,3,3,3,5,77,6,3,5]
    n=len(a)
    for x in range(1,n):
        if a[x]>a[x-1]:
            print(a[x])

def n6():
    a=[-1,2,-2,-3,3,-3,5,-77,-6,3,5]
    n=len(a)
    for x in range(1,n):
        if a[x]<0 and a[x-1]<0:
            print(a[x-1],a[x],sep=" ")
            quit()
        if a[x]>0 and a[x-1]>0:
            print(a[x-1],a[x],sep=" ")
            quit()

def n7():
    a=[-1,2,-2,-3,3,-3,5,-77,-6,3,5]
    n=len(a)
    if n%2!=0:
        n-=1
    for x in range(1,n,2):
        a[x-1],a[x]=a[x],a[x-1]
    print(a)

def n8():
    a=[-1,2,-2,-3,3,-3,5,-77,-6,3,5]
    n = []
    for number in a:
        if number in n:
            continue
        else:
            n.append(number)
    print(n)


f1=[int(input("ферзь 1 \n1:")),int(input("2:"))]
f2=[int(input("ферзь 2 \n1:")),int(input("2:"))]
f3=[int(input("ферзь 3 \n1:")),int(input("2:"))]
f4=[int(input("ферзь 4 \n1:")),int(input("2:"))]
f5=[int(input("ферзь 5 \n1:")),int(input("2:"))]
f6=[int(input("ферзь 6 \n1:")),int(input("2:"))]
f7=[int(input("ферзь 7 \n1:")),int(input("2:"))]
f8=[int(input("ферзь 8 \n1:")),int(input("2:"))]
f=[f1,f2,f3,f4,f5,f6,f7,f8]
for x in range(8):
    print(f[x])
