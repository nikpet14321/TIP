#include"2proect.hpp"
#include<iostream>

int main() {
    double v, t;
    std::cin >> v >> t;
    std::cout << findCheckpoint(v, t) << std::endl;
    return 0;
}