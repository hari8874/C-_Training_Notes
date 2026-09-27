/*

syntax : std::array<T.N> array; // T means datatype and N means size
1. std::array is a container that encapsulates fixed size arrays.
2. array size is needed at compile time.
3. Assign by value is actually by value.
4. Access Elements:
   a. at()
   b. []
   c. front()
   d. back()
   e. data() // gives access to the underlying array
*/

#include "iostream"
#include "array"

using namespace std;


int main()
{
    std::array<int ,5> arr1;
    /// initialization
    std::array<int , 5> arr2 = {1,2,3,4,5}; // initialize list
    std::array<int , 5> arr3 {1,2,3,4,5}; // unitfrom initialization
    
    // we can initilize later also unlike in c
    arr1 = {10,20,30,40,50};

}