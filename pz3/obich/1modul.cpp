#include<iostream>
#include<cmath>

double findHypo(double a, double b) {
    return sqrt((a * a) + (b * b));
}

int main() {
    double a, b;
    std::cin >> a >> b;
    std::cout << findHypo(a, b) << std::endl;
    return 0;
}