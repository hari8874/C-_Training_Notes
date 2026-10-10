/*
forward_list  --- single linked list

1. This is single linked list what we know from C programming language.
2. Why forward_list why not single_list ?
3. We should use this class instead of traditional single linked list because
   a. Well tested
   b. Bunch of available function
4. Few Available Operations
   operator =, assign, front, empty, max_size, clear, insert_after, emplace_after, reverse, sort, merge
   splice_after, unique, remove, remove_if, resize
*/

#include "iostream"
#include "forward_list"
using namespace std;
void print(std::forward_list<int> l)
{
    for(auto i: l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    forward_list<int> list1 = {1,2,3,4};
    forward_list<int> list2 = {5,6,7,8};
    list1.insert_after(list1.begin(),8);  // if you wanted to add an element
    print(list1);
    list1.sort();  // sort out the list
    list2.sort();
    print(list1);
    print(list2);
    list1.splice_after(list1.begin(),list2); // if you wanted to add another list
    print(list1);
    list1.sort();
    print(list1); 
    forward_list<int> list3 = {10,27,27,65};
    list1.splice_after(list1.begin(),list3);
    print(list1);
    list1.unique(); // remove the adjacent duplicate
    print(list1);
    list1.remove(2);  // remove the elements 2
    print(list1);

    list1.remove_if([](int n){return n > 9;}); // remove the elements greater than 9
    print(list1);
    list1.resize(3);  // resize to only 3 elements
    print(list1);

}