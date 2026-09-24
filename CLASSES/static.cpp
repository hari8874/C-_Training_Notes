#include "iostream"
using namespace std;
// int y = 0;

class Static
{
    public:
    static int x;
    int *ptr;

    Static(int x):ptr(new int(x)){}
    void show()
    {
        cout<<*ptr<<endl;
    }
    static int GetValue()
    {
        // cout<<this->ptr<<endl;
        // cout<<*ptr<<endl;
        return x;
    }
};
int Static::x = 20;
// static int y = 0;
// void counter()
// {
//     static int x = 0;
//     x++;
//     // y++;
//     cout<<x<<endl;
//     // cout<<y<<endl;
// }
int main()
{
    // // cout<<x<<endl;
    // counter();
    // counter();
    // counter();

    // static types  
    // local static variable 
    // global static variablee 
    // static member function of a class 
    // static member variable of a class

    Static ob1(100);
    ob1.show();
    cout<<ob1.GetValue()<<endl;
    Static ob2(200);
    ob2.show();
    cout<<ob2.GetValue()<<endl;
    cout<<Static::GetValue()<<endl;

}