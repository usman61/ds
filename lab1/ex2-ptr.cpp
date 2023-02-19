#include <iostream>
using namespace std;
int main () {
int arr[5], *ptr1,*ptr2, i;
cout<<"Enter Values into an array: "<<endl;
ptr1 = arr;
for(int i=0 ; i<=4 ; i++)
{

cin>>arr[i];
// cin>>*ptr1++;
}
ptr1=arr;    // ptr1 = &arr[0]
cout<<"Values from array Using Pointer notation: "<<endl;
for(int i=0 ; i<=4 ; i++)
{
cout<<*ptr1++<<"\t";
// cout<<arr[i]<<"\t";
}
cout<<endl;

// ptr1 = arr;

cout<<"Using While Loop: "<<endl;
for(int i=0 ; i<=4 ; i++)
{
  // ptr1--;
cout<<*(ptr1--)<<"\t";
// cout<<arr[i]<<"\t";
}
cout<<endl;

return 0;
}