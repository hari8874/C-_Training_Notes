#include "iostream"
#include "memory"

using namespace std;

class Base
{
    public:
    int variable;
    Base():variable(0){}

    void Print()
    {
        std::cout<<variable<<std::endl;
    }

};
int main()
{
    Base b_obj;
    b_obj.Print();

}