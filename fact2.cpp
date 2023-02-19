#include <iostream>
#include <cmath>

using namespace std;
int main(){ 
int i,k=1; 
cin >> i ;
point: 
	if(i!=0){ 
	k=k*i; 
	i--; 
	goto point; 
	} 
printf("%d",k);

return 0;
} 