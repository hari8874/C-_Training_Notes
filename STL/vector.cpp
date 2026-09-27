/*
1. std::vector is a sequence container and also known as Dynamic Array or Array List.
Array is fast access like a[3] and size should be decided;
list will comes into picture when you dont know the size and data can grow dynamically
2. Its size can grow and shrink dynamically, and no need to provide size at compile time.

ELEMENT ACCESS
at(), [], front(), back(), data()

MODIFIERS:
insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()
*/
#include"iostream"
#include"vector"

using namespace std;

int main()
{
    std::vector<int> arr1;
    std::vector<int> arr2{5,20}; // here 5 means size and all those five values are 20
    std::vector<int> arr3 = {1,2,3,4,5}; //initilizer list
    std::vector<int> arr4{1,3,4,5,6,7}; // uniform initialization
    cout<<arr3[3]<<endl;
    arr4.at(3) = 10;

    for (int i =0;i<32;i++)
    {
        arr1.push_back(i);
        cout<<"size : "<< arr1.size() << "capacity : "<< arr1.capacity() << endl;
    }
    std::vector<int> arr5;
    arr5.reserve(100);
    for (int i =0;i<32;i++)
    {
        arr5.push_back(i);
        cout<<"size : "<< arr5.size() << "capacity : "<< arr5.capacity() << endl;
    }


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
    cout<<endl;


    // container inside a container 

    std::vector<std::vector<int>> tree;
    int edge,n1,n2;
    cin >> edge;
    tree.resize(edge);
    for(int i=0;i<edge;i++)
    {
        cin >> n1>>n2;
        tree[n1].push_back(n2);
    }
        for(auto &e1:tree)
        {
            for(auto &e2 : e1)
            {
                cout<<e2;
            }
            cout<<endl;
        }
    

    return 0;
}