#include<iostream>
#include<vector>
#include<cmath>

int main() {
    std::vector<int> arr = {1, 5, 4, 3, 0};
    int summa_el_pr, n;
    int summa_el_fact = 0;
    n = arr.size();
    summa_el_pr = (n * (n + 1)) / 2;
    for (int i = 0; i < n; i++) {
        summa_el_fact += arr[i];
    }
    std::cout << summa_el_pr - summa_el_fact << std::endl;
    return 0;
}