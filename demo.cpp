#include <iostream>
#include <algorithm>

int main() {
    int a = 5, b = 10;
    int maxVal = std::max(a, b);
    std::cout << "The maximum value between " << a << " and " << b << " is " << maxVal << std::endl;
    return 0;
}
