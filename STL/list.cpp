/*
1. This is double linked list what we know from C programming language.
2. List is sequence container that allow non-contiguous memory allocation.
3. List is faster compared to other sequence containers (vector, forward_list, deque) in terms of 
   insertion, removal and moving elements in any position provided we have the iterator of the position. 
4. We should use this class instead of traditional double linked list because
   a. Well tested
   b. Bunch of available function
5. Few Available Operations
   operator =, assign, front, back, empty, size, max_size, clear, insert, emplace, push_back, pop_back, push_front
   pop_front, reverse, sort, merge, splice, unique, remove, remove_if, resize.
*/

#include "iostream"
#include "list"
using namespace std;

using namespace std;
void print(std::list<int> l)
{
    for(auto i: l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    list<int> list1 = { 3,54,63,6,2,267,3};
    list<int> list2 = { 7,6,1,9};

    print(list1);
    print(list2);

    list2.sort(); // sort the list
    print(list2);

    list1.splice(list1.begin(),list2);
    list1.merge(list2);
    print(list1);
    list1.insert(list1.begin(),1);
    print(list1);
    list1.unique();
    print(list1); // it will only remove the adjacent numbers

}