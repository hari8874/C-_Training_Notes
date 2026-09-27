/*
Inheritance allows one class to acquire properties and behavior of another class
it has to be IS-A relation  
Access Specifiers
public: U can access these variables from anywhere
protected : U can access in subclass or derived class or child class
private : U can access only in the same class (particular class)
*/
#include "iostream"
#include "string"
using namespace std;


struct Empl{
    string name;

    void show()
    {

    }
};

// default inhertiance for structure will be the private inhertiance
struct Developer : Empl{

};
class vehicle // base class or parent class or super class
{
    public:
        string type;
        int speed;
        string color;
        string model;

        // Base class should always consits if you have parameter constructor while inheriting
        // constuctors calls top to bottom
        // destructors calls bottom to top
        vehicle():type("None"), speed(0), color("No color"), model("00000")
        {
            cout <<"Base constructor"<<endl;
        }

        vehicle(string type, int speed,string colour,string model):type(type),speed(speed),color(color),model(model){
            cout <<"Base constructor"<<endl;
        }

        void Display()
        {
            cout<<"Details: "<<endl;
            cout<<"type: "<<this->type<<endl;
            cout<<"Speed: "<<this->speed<<endl;
            cout<<"color: "<<this->color<<endl;
            cout<<"model: "<<this->model<<endl;
        }
        ~vehicle()
        {
            cout <<"Base destructor"<<endl;

        }

};
// Access specifers while inheriting

// default inhertiance for class will be the private inhertiance
// public inheritacne
// base class  : public --> public
// protected --> protected
// private --> inaccesible


// protectde inheritance
// public --> protected
// protected --> protected
// private --> inaccesible

// private inheritance
// public --> private
// protected --> private
// private --> inaccesible

class car:protected vehicle  // derived class or child class or subclass
{
    public:
        int seats;
        int wheels;

        car(int a, int b):seats(a), wheels(b){
            cout <<"Derived constructor"<<endl;
        }

        void Display()
        {
            cout<<"car details:"<<endl;
            cout<<"seats: "<<seats<<endl;
            cout<<"wheels: "<<wheels<<endl;
        }
        ~car()
        {
           cout <<"Derved destructor"<<endl;
        }

};
class Toyoto : public car{

    void show()
    {
        cout<<type<<endl;
    }

};

/* Inhritance types
single
multi level
multiple
hierarchical
hybrid
*/

// single
class Food
{

};
class Biryani : Food{

};

//multi level
class Food1
{

};
class Sweet1 : Food1{

};
class GulabJammon1 : Sweet1{

};
// multiple
class camera
{

};
class Memory
{

};
class smartphone : camera,Memory
{

};
// hierarchical
class Vehicle
{

};
class Car: Vehicle
{

};
class Lorry : Vehicle
{

};
// hybrid
// ambimgutiy will occur
class GrandParent
{
    public: 
    int age;
    GrandParent(int age):age(age){}
};
class Father : virtual public GrandParent
{
    public:
    Father():GrandParent(10){}

};
class Mother : virtual public GrandParent
{
    public:
    Mother():GrandParent(20){}

};
class child : public Father , public Mother{

    public:
     child():GrandParent(30){}
};


class Base
{
    public:
    // hidden vptr --> size of vptr --> it depends on arch 32bit --> 4 bytes 64 bit --> 8 bytes 
    virtual void show()
    {
        cout<< " abse show()"<<endl;

    }
    void show(int x) // shadow  // overcome  by   // using Base::show;
    {
        cout<< "base show(x)"<<endl;

    }

};

// upcasting --> derived object can be treated as a base object
// downcasting -->  base object can be treated as a derived object
class Derived : public Base{
    public:
    using Base::show;
    void show()
    {
        cout<< "derived show()"<<endl;       
    }

};

int main()
{

    Derived dobj;
    Base *ptr=&dobj;

    Base *bobj;
    Derived *ptr1=static_cast<Derived*>(bobj); // it will not be that much active
    Base *bobj1 = new Base;
    Derived *ptr2=dynamic_cast<Derived*>(bobj1); // efficient 

    car c(4, 4);
    c.Display();
    child cd;
    Derived d;
    d.show(); // derived 
    d.show(10); //
    cout<<sizeof(Base)<<endl;
    // c.type = "Lorry";  u cannot access in main becaue Vehicle is inherited as a protected
}