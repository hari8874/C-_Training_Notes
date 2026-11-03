#include "iostream"
#include "thread"
#include "mutex"
using namespace std;

std::mutex m1;

int counter = 100;

void increment()
{
    // m1.lock();
    lock_guard<std::mutex> lock(m1); 
    for(int i=0;i<100000;i++)
    {
        counter++;
    }
    // m1.unlock();
}
void decrement()
{
    // m1.lock();
    lock_guard<std::mutex> lock(m1);
    for(int i=0;i<100000;i++)
    {
      counter--;
    }
    // m1.unlock();
}
void display()
{
    // for(int i = 0; i < 64; i++)
    // {
        cout<<" I am in display and value of i : "<<endl;
    // }
    
}

int add(int &a, int &b)
{
    int c= a+b;
    return c;
}

int main()
{
    // thread t1(display);
    // t1.detach();
    // int a=19,b=40;
    // thread t2(add,10,20); 
    // thread t3(add,std::ref(a),std::ref(b)); // std::ref for pass by ref


    thread t5(increment);
    thread t6(decrement);

    t5.join();
    t6.join();
    cout<<"counter value : "<< counter<<endl;

    // std::thread t([&a](){return a;});

    // if(t1.joinable())
    // {
    //    t1.join();
    // }
    

    // use of join main thread waits untill t1 finishes
    cout<<"I am in main"<<endl;
}
