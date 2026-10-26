#include <iostream>

long long fastPow(long long a, long long n) {
    long long result = 1;
    while (n > 0) {
        if (n & 1) {
            result *= a;
        }
        a *= a;
        n >>= 1;
    }
    return result;
}

int main() {
    long long a, n;
    std::cin >> a >> n;
    std::cout << fastPow(a, n) << std::endl;
    return 0;
}