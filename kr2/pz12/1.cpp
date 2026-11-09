#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int main() {
    int N, M;
    std::cin >> N >> M;

    // читаем по одному символу: подходит и "0P1E", и "0 P 1 E"
    std::vector<std::vector<char>> g(N, std::vector<char>(M));
    int sr = 0, sc = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> g[i][j];
            if (g[i][j] == 'S') {
                sr = i;
                sc = j;
            }
        }
    }

    if (g[sr][sc] == '1') {
        std::cout << -1 << "\n";
        return 0;
    }

    // Все клетки, достижимые от старта, можно обойти (ходить можно туда-обратно),
    // а потом вернуться к выходу. Значит, ответ - число 'P' в достижимой области,
    // при условии, что выход тоже достижим. Область ищем обходом в ширину (BFS).
    std::vector<std::vector<bool>> vis(N, std::vector<bool>(M, false));
    std::queue<std::pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;

    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    int pdfs = 0;
    bool exitFound = false;

    while (!q.empty()) {
        std::pair<int, int> cur = q.front();
        q.pop();
        int r = cur.first, c = cur.second;

        if (g[r][c] == 'P') ++pdfs;
        if (g[r][c] == 'E') {
            exitFound = true;
            continue;  // из выхода дальше не идём - мы уже на улице
        }

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;  // за границей
            if (vis[nr][nc] || g[nr][nc] == '1') continue;         // был здесь или стена
            vis[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    std::cout << (exitFound ? pdfs : -1) << "\n";
    return 0;
}