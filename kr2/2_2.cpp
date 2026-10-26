#include <iostream>

long long gcd(long long a, long long b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        } 
    }
    return a;
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}