#include"iostream"
#include"vector"

using namespace std;

int main()
{
    std::vector<int> v;
    std::cout<<"Size of vector: "<<v.size()<<endl;
    std::cout<<"Capacity of vector: "<<v.capacity()<<endl;
    for(auto i=0; i<10; i++)
    {
        v.push_back(i);
    }
    std::cout<<"Size of vector: "<<v.size()<<endl;
    std::cout<<"Capacity of vector: "<<v.capacity()<<endl;

    for(auto i: v)
    {
        std::cout<<i<<" ";
    }
    return 0;
}