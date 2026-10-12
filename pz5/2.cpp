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

    int i = 0;
    while (i + 1 < (int)arr1.size()) {
        if (arr1[i] == arr1[i + 1]) {
            arr1.erase(arr1.begin() + i, arr1.begin() + i + 2);
            summa += 2;
            if (i > 0) i--;
        } else {
            i++;
        }
    }

    std::cout << "\n" << summa << std::endl;
    return 0;
}