#include<iostream>
#include<vector>

std::vector<int> arr1 = {};
int summa = 0;

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        arr1.push_back(num);
    }

    for (int i = 0; i + 1 < arr1.size();i++) {
        if (arr1[i] == arr1[i + 1]) {
            arr1.erase(arr1.begin() + i, arr1.begin() + i + 2);
            summa += 2;
            if (i > 0) {
                i = i - 2;
            } else {
                i = -1;
            }
        }
    }

    std::cout << "\n" << summa << std::endl;
    return 0;
}