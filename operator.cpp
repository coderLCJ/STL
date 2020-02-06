#include <iostream>
using  namespace std;
class Complex
{
public:
    double A,B;
    Complex(double a,double b)
    {
        A=a;
        B=b;
    }
    friend Complex operator+(const Complex &a,const Complex &b);
    friend Complex operator+(const Complex &a,const double b);
    friend Complex operator+(const double a,const Complex &b);
};

Complex operator+(const Complex &a,const Complex &b)
{
    return Complex(a.A+b.A,a.B+b.B);
}

Complex operator+(const Complex &a,const double b)
{
    return Complex(a.A+b,a.B);
}

Complex operator+(const double a,const Complex &b)
{
    return Complex(a+b.A,b.B);
}

int  main()
{
    Complex a(2,5),b(7,8),c(0,0);
    c = a + b;
    cout<<c.A<<' '<<c.B<<endl;
    c = a+ 4.1;
    cout<<c.A<<' '<<c.B<<endl;
    c = 5.6 + a;
    cout<<c.A<<' '<<c.B<<endl;
    return  0 ;
}

