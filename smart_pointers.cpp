#include "iostream"
#include "memory"
using namespace std;

// void Function()
// {
//     int *ptr = new int (1);
//     if( *ptr = 1)
//     {
//         return;
//     }
//    delete ptr;
// }
void Function()
{
    unique_ptr<int> ptr = make_unique<int>(10);  // c++ 14
    // unique_ptr<int> ptr2 = new int (100); // c++ 11
    if( *ptr = 1)
    {
        return;
    }
//    delete ptr;
}

class Unique_ptr_obj
{
    public:
    int *ptr;
    explicit Unique_ptr_obj(int *p = nullptr): ptr(p){}

    ~Unique_ptr_obj()
    {
        delete ptr;
    }
    Unique_ptr_obj(const Unique_ptr_obj &other) = delete;
    Unique_ptr_obj& operator = (Unique_ptr_obj &other) = delete;
    Unique_ptr_obj(Unique_ptr_obj &&other)
    {
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    Unique_ptr_obj& operator = (Unique_ptr_obj &&other)
    {
        if(this != &other)
        {
            delete ptr;
            ptr= other.ptr;
            other.ptr=nullptr;
        }
        return *this;
    }

    int* get() 
    {
        cout<< "Get"<<endl;
        return ptr;
    }
    int* release()
    {
        cout<< "release"<<endl;
        int *temp=ptr;
        ptr =nullptr;
        return temp;
    }
    void reset(int* p = nullptr)
    {
        cout<< "reset"<<endl;
        if(ptr != p)
        {
        cout<< "Inside if"<<endl;
        delete ptr;
        ptr = p;
        }
       cout<< "Outside if"<<endl;
    }
};

void process(std::unique_ptr<int> ptr)
{
    cout<<*ptr<<endl;
}
void process1(int *ptr)
{
    cout<<*ptr<<endl;
}
void process2(int& ptr)
{
    cout<<ptr<<endl;
}
int main()
{
    int* ptr = new int (100);  //ptr and assigning value of 100
    int *ptr1 = new int [10];  // array of 10 ptrs
    unique_ptr<int> ptr3 = make_unique<int>(10);
    process2(*ptr3);
    unique_ptr<int> ptr2;
    ptr2 = std::move(ptr3);
    // Unique_ptr_obj obj13; //stack
    unique_ptr<Unique_ptr_obj> obj1 = make_unique<Unique_ptr_obj>(); //heap

    process(std::move(ptr2));
    cout<< ptr2 <<endl;
    unique_ptr<int> a = make_unique<int>(10);
    unique_ptr<int> b = make_unique<int>(10);
    process1(a.get());

    int *ptr5 = a.release(); // a ownership lost then raw pointer will allocate to ptr5
    delete ptr5;
    b.reset();
    b.reset(new int(30)); // resetting and updating the new value
    Function();

    Unique_ptr_obj objx(new int (20));
    int *x = objx.get();
    int *z = objx.release();
    cout<<objx.ptr<<endl;
    objx.reset(new int(20));


    // task

    // shared_ptr : ownership can be shared ;
    // shared_ptr<int> p1; // ref strong count 1
    // shared_ptr<int> p2  = p1 ; //ref strong count 2
    // shared_ptr<int> p3 = p2 ; // ref strong count 3
    // Base class
    // b1,b2,b3 respectively ;
    // ref strong count = 0 what will happen // p1 it will destroy
    // now if you delete p2 what will have to p1 ; ref strong count 1 
    // shared_ptr it has oen raw pointer with control block
    // control block have ref count : strong weak

    // 

    // class Parent_class //ref parent 1
    // {
    //     public:
    //     shared_ptr<class child> ob2=make_shared<child>(); //ref child 1
    // };
    // class child //ref child 2
    // {
    //     public:
    //     shared_ptr<Parent_class> ob2=make_shared<Parent_class>(); //ref parent 2 
    //     weak_ptr<Parent_class> ob2=make_shared<Parent_class>(); //ref parent  
    //     weak = 1;
    // };
    // lock(); // weak ptr
    // Parent_class p;
    // child c;
}