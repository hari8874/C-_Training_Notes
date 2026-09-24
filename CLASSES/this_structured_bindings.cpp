// #include "iostream"
// using namespace std;

// class Number
// {
//     // int value;
//     int Value1;

//     public:
//     Number(int n):Value1(n){}
//     void setValue(int value)
//     {
//         this->Value1= value;
//         // return *this;
//     }

//     void Display() const
//     {
//         cout<<Value1<<endl;
//     }
//     const void Display() 
//     {
//         cout<<Value1<<endl;
//     }
// };
// class Hari
// {
//     mutable int  n;
//     public:

//     void Name()
//     {
//         cout<<"Non COnst"<<endl;
//     }
//     void Name() const 
//     {
//         n++;
//         cout<<" COnst"<<endl;
//     }

// };

// int& getValue()
// {
//     int x=10;
//     return x;
// } 
// int* getValue1()
// {
//     int c=10;
//     return &c;
// }
// class Value
// {
//     int value;

//     Value& getData()
//     {
//         Value d;
//         return d;   // bad 
//     }

// };
// int main()
// {
//     const Number n(20);
//     // n.setValue();
//     n.Display();
//     int& ref = getValue();
//     cout<< ref <<endl;

//     Hari obj1;
//     obj1.Name();
//     const Hari pbj2;
//     pbj2.Name();

    
//     //  n=0x200
//     // n.setValue(100).Display(); //n.setValue(100) = 200 == n // n.Display();
//     // n.setValue(200).setValue(203).setValue(200).Display();
// }

/// structured bindings
#include "iostream"
#include "map"
using namespace std;
class Rectangle
{
    public:
     int len;
     int bre;
     int hei;

     Rectangle(int a,int b, int c):len(a),bre(b),hei(c){}
};
int main()
{
    Rectangle ob1(10,20,30); //parame

    Rectangle ob2{10,200,2002}; //aggreaget initizatiom
    int arr[3] ={10,20,30}; 

    std::map<int,string> data3;
    

    
    std::pair<int,string> data{101,"Hari Sanakr"};

    std::tuple<int,string,char> data1{102,"Rohitsharma",'a'};
    const auto [id,Name,Grade] = data1;
    auto& [empid,Name]=data;
    cout<<empid<<Name<<endl;
    empid=20;


    auto [x,y,z]=arr;
    // auto [a,b] = arr; //error
    cout<<x<<y<<z<<endl;

    auto [a,b,c]=ob2;

}