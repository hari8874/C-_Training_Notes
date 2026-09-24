#include "iostream"
#include "limits"

using namespace std;
int main()
{
int a;
cout<<sizeof(a)<<endl;
cout << "Min  = " << numeric_limits<int>::min() << endl;
cout << "Max  = " << numeric_limits<int>::max() << endl;
}