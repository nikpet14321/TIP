#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, D;
    std::cin >> N >> D;

    std::vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    auto can = [&](long long x) {
        int days = 1;
        long long start = a[0];  // самый "низкокалорийный" пирожок текущего дня
        for (int i = 1; i < N; ++i) {
            if (a[i] - start > x) {
                ++days;
                start = a[i];
            }
        }
        return days <= D;
    };

    // Бинарный поиск минимального x, для которого can(x) == true
    long long lo = 0, hi = a[N - 1] - a[0];
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (can(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    std::cout << lo << "\n";
    return 0;
}