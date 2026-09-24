#include "iostream"
using namespace std;

class Number
{
    public:
    int *ptr;
    // const int val;
    // Number()
    // {
    //     ptr = new int (0);
    //     val =n9;
    // }
    Number():ptr(new int(0)){}
    Number(int x):ptr(new int(x)){}

    // it will create a new object with existing object

    Number(const Number &other)
    {
        cout<<"Copy constructor"<<endl;
        ptr = new int (*other.ptr);
    }
    Number(Number &&other)
    {
      cout<<"MOVE "<<endl;
      ptr = new int(*other.ptr);  // this->ptr;
      other.ptr= nullptr;  
    }
    
    // it will assign the values to the already existing object 

    Number& operator = (const Number& other)
    {
        cout<<"Copy assign"<<endl;

        if(this != &other)
        {
            delete ptr;
            ptr = new int(*other.ptr);
        }
        return *this;
    }
    Number& operator = (Number&& other)
    {
        cout<<"Copy assign"<<endl;

        if(this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
  ~Number(){
    cout<<"Dest"<<endl;
    delete ptr;
  }

};

int main()
{
    Number n(20);
    Number m(n); /// copy constrictor
    Number a=n;
    Number r{30};
    Number p1 = Number(20); /// 

    Number obj1 = std::move(n);

    cout<<"obj1 value"<<*obj1.ptr << " N ob value"<<endl;

    int z = 10;
    int *p = &z;
    int o = z+30;

    int &ref = z;

    // int &ref1 = 30;  // u cant assign temp values

    int &&ref2 = 40;  // only to assign temporary values 
    // int &&ref2 = z; /// it wont work
    int && ref3 = std::move(z);
    cout<<z<<endl;


    Number x(30);

    // x=n; /// copy wont work because i already moved the n obj to obj1  
    return 0;
}