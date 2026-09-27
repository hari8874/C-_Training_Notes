#include "iostream"
#include "memory"

using namespace std;

// SIZE OF AN EMPTY CLASS WILL BE 1

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