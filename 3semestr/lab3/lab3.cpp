#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double PI=3.14159265359;


class shape
{
    public:
    virtual void draw()=0;
    virtual void move()=0;
    virtual double area()=0;
    shape()
    {

    }
};

class eleps : public shape
{
    protected:
    double A;
    double B;
    public:
    eleps(double ae, double be):shape()
    {
        if (ae>0)
        {
            A=ae;
        }
        if(be>0)
        {
            B=be;
        }
    }
    double area()
    {
        return (A*B*PI);
    }
    int pth (int x,int y) 
    {
        return sqrt (pow(x,2)+pow(y,2));
    }
    void draw()
    {
        
    int c=B;
    int r=A;
    int q=A-B;
    if(q<0)
    {
        q=q*(-1);
    }
    if(q==0)
    {
        q=1;
    }

    const int width=r;
    const int length=c*1.5;

    for (int y=width;y >= -width;y-=2)  {
        for (int x=-length;x <= length;x++)  {

            if (((int) pth(x+q,y)==r)) cout << "*";
            else cout << " ";

         }
         cout << "\n";
     }
     cin.get();
    }
    void move()
    {

    }
};

class circle : public eleps
{
private:
    double R;
    public:
    circle(double r):eleps(A, B)
    {
        if (r>0)
        {
            R=r;
            A=r;
            B=r;
        }
       
    }
    double area()
    {
        return (PI*R*R);
    }
    void draw()
    {
        eleps::draw();
    }
    void move()
    {

    }

};

class triangle : public shape
{
    private:
    double A;
    double H;
    public:
    triangle(double a, double h):shape()
    {
        if (a>0)
        {
            A=a;
        }
        if (h>0)
        {
            H=h;
        }
    }
    double area()
    {
        return (0.5*A*H);
    }
        void draw()
    {

    }
    void move()
    {

    }
};

class rectangle : public shape
{
    protected:
    double A;
    double B;
    public:
    rectangle(double a, double b):shape()
    {
        if (a>0)
        {
            A=a;
        }
        if(b>0)
        {
            B=b;
        }
    }
    double area()
    {
        return (A*B);
    }
    void draw()
    {
        
        for(int i=0; i!=A; i++)
        {
            for(int k=0;k!=B;k++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }
    void move()
    {

    }
};

class square : public rectangle
{
    private:
    double A;
    public:
    square(double a):rectangle(A,B)
    {
        if (a>0)
        {
            A=a;
            B=a;
        }
    }
    double area()
    {
        return (A*A);
    }
    void draw()
    {
        rectangle::draw();
    }
    void move()
    {

    }
};

class run
{
    public:
    void runmain()
    {
        double a,b,r,h,base, ae, be, S;
        cout<<endl<<"enter radius for circle(r)->";
        cin>>r;
        cout<<endl<<"enter hight for triangle(h)->";
        cin>>h;
        cout<<endl<<"endter base of triangle(base)->";
        cin>>base;
        cout<<endl<<"enter a,b sides of the rectangle(side a will be used for the square) a->";
        cin>>a; cout<<"b->"; cin>>b;
        cout<<endl<<"endter a and b for eleps a->";
        cin>>ae; cout<<"b->"; cin>>be;
        eleps x=eleps(ae,be);
        circle c=circle(r);
        triangle v=triangle(base,h);
        rectangle n=rectangle(a,b);
        square z=square(a);

        S=c.area();
        cout<<endl<<"circle="<<S<<endl;
        c.draw();
        /*
        S=v.area();
        cout<<endl<<"triangle="<<S<<endl;
        S=n.area();
        cout<<endl<<"rectangle="<<S<<endl;
        n.draw();
        S=z.area();
        cout<<endl<<"square="<<S<<endl;
        z.draw();*/
        S=x.area();
        cout<<endl<<"eleps="<<S<<endl;
        //x.draw();
        
        
    }
};


int main()
{ 
    run l;
    l.runmain();
    
    
    return 0;
}  