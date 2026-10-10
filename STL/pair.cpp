/*
NOTES:
0. std::pair is a struct template that provides a way to store two heterogeneous objects as a single unit.
1. map, multimap, unorder_map, unorder_multimap can use pair to insert data into their structures.
*/
#include "iostream"
#include "list"
using namespace std;
template<typename T,typename U>
void print(std::pair<T,U> temp)
{
    cout<<temp.first<<"  "<<temp.second<<endl;
}
template<typename T>
void print_STL(T t)
{
    for(auto i:t)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}
int main()
{
    std::pair<int,string> empinfo = {101,"Hari Sankar"};


    std::list<std::pair<int,string>> list1;
    list1.push_back(empinfo);
    list1.push_front(pair<int,string>(102,"Rohit sharma"));
    list1.push_back(pair<int,string>(103," Jr Ntr"));

    print(empinfo);

    print_STL(list1);
}