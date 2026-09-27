#include "iostream"
using namespace std;
#pragma pack(push,1)

class Base
{
    public:
    int n;
    char c;
    Base(int c)
    {
        n=c;
        cout<<"In Base constructor"<<endl;
    }

    Base(int c,char x)
    {
        n=c;
        c=x;
        cout<<"In Base constructor"<<endl;
    }

};
#pragma pack(pop)
void Print(int n)
{
    cout<<" n value: "<<n<<endl;
}
void Print_Class(Base n)
{
     cout<<" Print_Class n value: "<<n.n<<endl;
}
int main()
{
    Base m (30,'s');  /// Base m = Base m(30);  
    Print(10);
    Print_Class(10);
    cout<<sizeof(m)<<endl;
}