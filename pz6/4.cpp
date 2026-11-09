#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open()) {
        cerr << "Не удалось открыть input.txt" << endl;
        return 1;
    }

    int n, m, w;
    fin >> n >> m >> w;

    bool mushroom[34][34] = {};

    for (int k = 0; k < w; k++) {
        int r, c;
        fin >> r >> c;
        if (r >= 1 && r <= n && c >= 1 && c <= m) {
            mushroom[r][c] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mushroom[i][j]) {
                fout << '*';
            } else {
                int count = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (mushroom[i + di][j + dj]) {
                            count++;
                        }
                    }
                }
                fout << count;
            }
        }
        fout << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}