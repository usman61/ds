#include <iostream>
using namespace std;

int myfunction(int value){
if (value == 6)
    return 2;
else if (value>6)
    return 3;    
else
    return value + myfunction(value+1) * myfunction(value+2);
}


int main()
{
    int a,b;
    a = myfunction(3);
    b = myfunction(4);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<a+b<<endl;
    
    return 0;
}
