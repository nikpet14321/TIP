#include<iostream>
#include<vector>

int main() {
    std::vector<int> arr1 = {1, 4, 7, 10};
    std::vector<int> arr2 = {2, 3, 8, 12, 13};
    std::vector<int> arrob;

    int i = 0;
    int j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            arrob.push_back(arr1[i]);
            i++;
        } else {
            arrob.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        arrob.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        arrob.push_back(arr2[j]);
        j++;
    }

    for (int element : arrob) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    return 0;
}
