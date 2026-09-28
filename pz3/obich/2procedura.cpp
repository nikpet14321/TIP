#include<iostream>

int main() {
    double v, t, s;
    std::cin >> v >> t;
    s = v * t;
    if (s >= 109) {
        while (s > 109) {
            s -= 109;
        }
        std::cout << s << std::endl;
    } else {
        std::cout << s << std::endl;
    }
    return 0;
}