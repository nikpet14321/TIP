#include<iostream>

int rec(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + rec(n - 1);
}

int main() {
    std::cout << rec(5) << std::endl;
    return 0;
}
