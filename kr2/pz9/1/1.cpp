#include<iostream>
#include<fstream>
#include<cctype>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (!fin.is_open()) {
        std::cerr << "Не удалось открыть input.txt" << std::endl;
    }
    char ch;
    while (fin.get(ch)) {
        char ch1 = std::tolower(ch);
        if (ch1 != 'u' && ch1 != 's' && ch1 != 'e' && ch1 != 'r' && ch1 != 'a' && ch1 != 'g' && ch1 != 'r' && ch1 != 'e' && ch1 != 'm' && ch1 != 'n' && ch1 != 't') {
            fout << ch;
        }
    }

    fin.close();
    fout.close();
    return 0;
}