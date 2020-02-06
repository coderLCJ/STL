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
    Complex operator+(const double a){
        return Complex(this->A+a,this->B);
    }

};

Complex operator+(const Complex a){
        return Complex(+a,this->B);
}

int  main()
{
    Complex a(2,5),b(7,8),c(0,0);
    c=a+1.2;
    c=1.2+a;
    cout<<c.A<<' '<<c.B<<endl;
    return  0 ;
}

