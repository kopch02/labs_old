import java.util.Scanner;

class One {
    public static void main(String[] args) {
        Create r=new Create();
        r.run();
    }
}
class Create{
    public void run(){
        Scanner in = new Scanner(System.in);
        double S;

        System.out.print("endter a and b for eleps a->");
        double ae=in.nextDouble();
        System.out.print("b->");
        double be=in.nextDouble();

        System.out.print("enter radius for circle(r)->");
        double r=in.nextDouble();

        System.out.print("enter a and b sides of the rectangle a->");
        double a=in.nextDouble();
        System.out.print("b->");
        double b=in.nextDouble();

        System.out.print("enter a sides of the square a->");
        double as=in.nextDouble();

        System.out.print("endter base of triangle(base)->");
        double at=in.nextDouble();
        System.out.print("enter height for triangle(h)->");
        double h=in.nextDouble();

        Eleps e= new Eleps();
        Circle c= new Circle();
        Rectangle rec= new Rectangle();
        Square s= new Square();
        Triangle t= new Triangle();


        e.create_eleps(ae, be);
        c.create_circle(r);
        rec.create_rectangle(a, b);
        s.create_square(as);
        t.create_triangle(at, h);

        S=e.area();
        System.out.printf("площадь эллипса= %s\n",S);

        S=c.area();
        System.out.printf("площадь круга= %s\n",S);

        S=rec.area();
        System.out.printf("площадь прямоугольника= %s\n",S);

        S=s.area();
        System.out.printf("площадь квадрата= %s\n",S);

        S=t.area();
        System.out.printf("площадь треугольника= %s\n",S);

        in.close();
    }
}
class Shape{
    final double PI=3.14159265359;
}
class Eleps extends Shape{
    double A;
    double B;
    public void create_eleps(double ae, double be){
        A=ae;
        B=be;
    }
    public double area(){
        return(A*B*PI);
    }
}
class Circle extends Eleps{
    double R;
    public void create_circle(double r){
        R=r;
    }
    public double area(){
        return(R*R*PI);
    }
}
class Triangle extends Shape{
    double A;
    double H;
    public void create_triangle(double a, double h){
        A=a;
        H=h;
    }
    public double area(){
        return(0.5*A*H);
    }
}
class Rectangle extends Shape{
    double A;
    double B;
    public void create_rectangle(double a, double b){
        A=a;
        B=b;
    }
    public double area(){
        return(A*B);
    }
}
class Square extends Rectangle{
    double A;
    public void create_square(double a){
        A=a;
    }
    public double area(){
        return(A*A);
    }
}