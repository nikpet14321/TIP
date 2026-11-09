#include<iostream>
#include<fstream>
#include<string>

int main() {
    std::ifstream file1("input1.txt");
    if (!file1.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
    }
    std::string X((std::istreambuf_iterator<char>(file1)), std::istreambuf_iterator<char>());
    file1.close();

    std::ifstream file2("input2.txt");
    if (!file2.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
    }
    std::string Y((std::istreambuf_iterator<char>(file2)), std::istreambuf_iterator<char>());
    file2.close();

    size_t found = X.find(Y);

    if (found != std::string::npos) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    return 0;
}