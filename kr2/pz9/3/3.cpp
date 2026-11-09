#include <iostream>
#include <fstream>
#include <string>
#include <regex>

std::string toBinary(unsigned long long n) {
    if (n == 0) return "0";
    std::string result;
    while (n > 0) {
        result = char('0' + n % 2) + result;
        n /= 2;
    }
    return result;
}

int main() {
    std::ifstream fin("input.txt");
    if (!fin.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return 1;
    }
    std::ofstream fout("output.txt");

    std::string line;
    std::regex number_expr("\\d+");

    while (std::getline(fin, line)) {
        std::sregex_iterator words_begin(line.begin(), line.end(), number_expr);
        std::sregex_iterator words_end;

        std::string result;
        size_t last = 0;

        for (std::sregex_iterator it = words_begin; it != words_end; ++it) {
            std::smatch match = *it;

            result += line.substr(last, match.position() - last);
            result += toBinary(std::stoull(match.str()));
            last = match.position() + match.length();
        }
        result += line.substr(last);

        fout << result << std::endl;
    }

    fin.close();
    fout.close();
    return 0;
}