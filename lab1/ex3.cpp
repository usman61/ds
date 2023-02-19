#include <iostream>
using namespace std; 
int main () {
int arr[5], *ptr1,*ptr2, i;

cout<<"Enter Values into an array: "<<endl;
for(int i=0 ; i<=4 ; i++)
{
    cin>>arr[i];
}
ptr1=arr;
cout<<"Values from array Using Pointer notation: "<<endl;
for(int i=0 ; i<=4 ; i++)
{
    cout<<*ptr1++<<"\t";
}
cout<<endl;
ptr2 = arr;

cout<<"Using While Loop: "<<endl;

while (*ptr2){
	cout<<*ptr2++<<"\t";
	
}
cout<<endl;
   return 0;
}
