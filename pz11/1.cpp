#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<long long>> a(N, std::vector<long long>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> a[i][j];
        }
    }

    // dp[i][j] - максимальная сумма баллов, с которой можно оказаться в клетке (i, j)
    std::vector<std::vector<long long>> dp(N, std::vector<long long>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = a[i][j];                          // старт
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + a[i][j];           // первая строка: пришли только слева
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + a[i][j];           // первый столбец: пришли только сверху
            } else {
                // в клетку можно прийти сверху или слева - берём лучший вариант
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
        }
    }

    // Восстановление пути: идём из правого нижнего угла назад,
    // каждый раз выбирая ту соседнюю клетку, где значение dp больше.
    std::vector<std::pair<int, int>> path;
    int i = N - 1, j = M - 1;
    while (true) {
        path.push_back({i, j});
        if (i == 0 && j == 0) break;
        if (i == 0) {
            --j;
        } else if (j == 0) {
            --i;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    std::reverse(path.begin(), path.end());  // путь собран с конца, разворачиваем

    for (const auto& p : path) {
        std::cout << p.first << " " << p.second << "\n";
    }
    return 0;
}