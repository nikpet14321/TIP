#include<iostream>

double findCheckpoint(double v, double t) {
    double s;
    s = v * t;
    if (s >= 109) {
        while (s > 109) {
            s -= 109;
        }
        return s;
    } else {
        return s;
    }
}

int main() {
    double v, t;
    std::cin >> v >> t;
    std::cout << findCheckpoint(v, t) << std::endl;
    return 0;
}