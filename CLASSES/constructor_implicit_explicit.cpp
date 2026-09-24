#include "iostream"
using namespace std;
#pragma pack(push,1)

class Number
{
    public:
    int number;

    explicit Number(int n)
    {
        cout<<"Para constructor"<<endl;
        number = n;
    }
};
class Base
{
    // constructor is a special member function 
    // it does nt have return type
    // it can be overloaded
    // it can be explicit 
    // cannot be virtual and static
    public:
    const int al;
    char c;

    Base():al(20),c('s')
    {
        cout<<"Default"<< endl;
        // al=20;
        // c='s';
    }
    // Base(int n, char c)
    // {
    //     al=n;
    //     c=c;
    // }
    Base(int n, char z):al(n),c(z){}
    Base (const Base &other)
    {
        
    }
    void Print()
    {
        cout<< al << "  "<<c <<endl;

    }
};
void Print(Number n)
{
    cout<< "In print function"<<endl;
}
int main()
{
    Base b;
    // Number n = 20; // Number n = Number(20);
    Number n(20);
    cout<< sizeof(b)<<endl;
    b.Print();
    Print(n);  //Print(Number(25));
    // cout <<sizeof(Base)<<endl;
}

