#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;
    
    double result = tgamma(n+1);  // calculate the Gamma function of n+1
    int factorial = round(result);  // round the result to the nearest integer
    
    cout << "The factorial of " << n << " is " << factorial << endl;

    return 0;
}