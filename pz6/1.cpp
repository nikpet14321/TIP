#include<iostream>

int main() {
    int N = 0;
    std::cin >> N;
    for (int i = 0;i<N; i++) {
        for (int j = 0;j < N; j++) {
            if (i + j < N - 1) {
                std::cout << 0 << " ";
            }
            if (i + j == N - 1) {
                std::cout << 1 << " ";
            }
            if (i + j > N - 1) {
                std::cout << 2 << " ";
            }
        }
    std::cout << "\n";
    }
    return 0;
}