// C++ program to illustrate dynamic allocation
// and deallocation of memory using new and delete
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int *ptr=arr;
    for(int i=0; i<n; i++)
    *ptr++=i+1;



    for(int j=0; j<n; j++)
    cout<<*(--ptr)<<"\t";
    // cout<<arr[j]<<"\t";


return 0;
}