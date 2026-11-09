#include <iostream>

void hanoi(int n, int from, int to, int tmp) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, from, tmp, to);
    std::cout << "Ingredient " << n << " move from " << from << " to " << to << "\n";
    hanoi(n - 1, tmp, to, from);
}

int main() {
    int n;
    std::cin >> n;
    hanoi(n, 1, 3, 2);
    return 0;
}