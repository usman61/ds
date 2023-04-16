#include <iostream>
using namespace std;
int myfunction(int value){
if (value <= 0)
return 1;
else
return value * myfunction(value-2) * myfunction(value-3);
}
int main()
{
int a,b;
a = myfunction(5);
b = myfunction(6);
cout<<a<<endl;
cout<<b<<endl;
cout<<a+b<<endl;
return 0;
}