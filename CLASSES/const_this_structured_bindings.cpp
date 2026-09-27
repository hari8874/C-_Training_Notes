#include "iostream"
#include "map"
using namespace std;

class Number
{
    // int value;
    int Value1;

    public:
    Number(int n):Value1(n){}
    void setValue(int value)
    {
        this->Value1= value;
        // return *this;
    }

    void Display() const
    {
        cout<<Value1<<endl;
    }
    const void Display() 
    {
        cout<<Value1<<endl;
    }
};
class Hari
{
    mutable int  n;
    public:

    void Name()
    {
        cout<<"Non COnst"<<endl;
    }
    void Name() const 
    {
        n++;
        cout<<" COnst"<<endl;
    }

};
 // Dangling reference
int& getValue()
{
    int x=10;
    return x;
} 

// Dangling pointer
int* getValue1()
{
    int c=10;
    return &c;
}

class Value
{
    int value;

    // Dangling
    Value& getData()
    {
        Value d;
        return d;   // bad 
    }

};

/// structured bindings
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
    const Number n(20);
    // n.setValue(); it will not call y because n object is a const and u cant call non const functions
    n.Display();
    int& ref = getValue();
    cout<< ref <<endl;

    Hari obj1;
    obj1.Name();
    const Hari pbj2{};
    pbj2.Name();

    
    //  n=0x200
    // n.setValue(100).Display(); //n.setValue(100) = 200 == n // n.Display();
    // n.setValue(200).setValue(203).setValue(200).Display();



    Rectangle ob1(10,20,30); //parame
    Rectangle ob2{10,200,2002}; //aggreaget initizatiom
    auto [a,b,c]=ob2;

    std::pair<int,string> data{101,"Hari Sanakr"};
    auto& [empid,Name]=data; // oroginal vlaue may effest if you use reference
    empid = 202;
    cout<<data.first<<endl;
    std::tuple<int,string,char> data1{102,"Rohitsharma",'a'};
    const auto [id,Name1,Grade] = data1;
    cout<<empid <<" "<<Name1<<endl;
    empid=20;

     int arr[3] ={10,20,30}; 
    auto [x,y,z]=arr; 
    // auto [a,b] = arr; //error --  only 2
    cout<<x<<y<<z<<endl;

}