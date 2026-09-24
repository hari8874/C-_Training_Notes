#include <iostream>
using namespace std;

class Base
{
public:
    int x = 10;

    void show()
    {
        cout << "Base show()" << endl;
    }
};
class Derived : public Base
{
public:
    int y = 20;

    void show()
    {
        cout << "Derived show()" << endl;
    }
};
class Employee
{
    int id;
    string name;
    int age;

public:

    Employee()
        : Employee(0, "Unknown", 0)
    {
        cout<<"cons1"<<endl;
    }

    Employee(int i)
        : Employee(i, "Unknown", 0)
    {
                cout<<"cons2"<<endl;

    }

    Employee(int i, string n)
        : Employee(i, n, 0) // constructor delegation
    {
                cout<<"cons3"<<endl;
    }

    Employee(int i, string n, int a)
        : id(i), name(n), age(30)  
    {
                cout<<"cons4"<<endl;
    }

    void show()
    {
        cout<< "id :" << id << " name : "<< name << " age: " << age  <<endl;
    }
};
int main()
{
    Derived d;
    Employee e(101,"Hari");
    e.show();
    Employee e1(103);
    e1.show();
    Base b = d;   // Object slicing

    cout << b.x << endl;
    cout<< d.y <<endl;
}