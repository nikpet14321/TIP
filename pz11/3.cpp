#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    int N, K, L;
    std::cin >> N >> K >> L;

    std::vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    // Если даже по L штук каждого вида не хватает на K растений, букет не собрать
    if ((long long)N * L < K) {
        std::cout << -1 << "\n";
        return 0;
    }

    // Жадность: сортируем виды по убыванию стоимости и берём самые дорогие,
    // по L штук каждого, пока не наберём K растений.
    std::sort(a.begin(), a.end(), std::greater<long long>());

    long long sum = 0;
    int left = K;  // сколько растений ещё нужно взять
    for (int i = 0; i < N && left > 0; ++i) {
        int take = std::min(L, left);
        sum += (long long)take * a[i];
        left -= take;
    }

    std::cout << sum << "\n";
    return 0;
}