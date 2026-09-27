#include "iostream"
using namespace std;
class Rectangle
{
    public:
    int len,bred,height;
    // if we have a constructor then it will call the constructor so commented it
    // // Rectangle():len(0),bred(0),height(0){} 
    // Rectangle(int x) :Rectangle(x,0){
    //     cout<<"const2"<<endl;
    // }
    // Rectangle(int x, int y, int z=30):len(x),bred(y),height(z){
    //     cout<<"const1"<<endl;
    // }
    void show()
    {
        cout<<len << bred << height <<endl;    }
};
int main()
{

    // Aggregateb intializatoin or unifrom initialization
    // it will not work if variables are private
    Rectangle rec{13,14,15};
    Rectangle rec1{13,18};

    int arr[4] = {1,2,3};

    // designated initialization

    Rectangle rec2{
        .len = 30,
        .bred = 40,
        .height =50 
    };
      Rectangle rec3{
        .len = 30,
        .bred = 40
    };
    rec3.show();
    rec2.show();
    rec.show();
    rec1.show();
}