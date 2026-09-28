#include<iostream>
#include<cmath>
int main() {
    double a, b, c;
    std::cin >> a >> b;
    c = sqrt((a * a) + (b * b));
    std::cout << c << std::endl;
    return 0;
}