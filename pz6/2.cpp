#include<iostream>

int main() {
    int N, M, W;
    std::cin >> N >> M >> W;


    bool mushroom[34][34] = {};

    for (int k = 0; k < W; k++) {
        int r, c;
        std::cin >> r >> c;
        if (r >= 1 && r <= N && c >= 1 && c <= M) {
            mushroom[r][c] = true;
        }
    }

    for (int i = 1; i <= N;i++) {
        for (int j = 1;j <= M;j++) {
            if (mushroom[i][j] == true) {
                std::cout << '*';
            } else {
                int count = 0;
                for (int di =-1;di <= 1; di++) {
                    for (int dj=-1;dj <= 1; dj++) {
                        if (mushroom[i + di][j + dj]) {
                            count++;
                        }
                    }
                }
                std::cout << count;
            }
        }
        std::cout << "\n";
    }
    return 0;
}