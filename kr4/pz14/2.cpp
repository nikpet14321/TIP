#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cctype>

int main() {
    std::set<std::string> seen;        // уже встречавшиеся слова
    std::vector<std::string> words;    // уникальные слова в порядке появления

    std::string token;
    while (std::cin >> token) {
        // длинное тире "–" - не слово (оно многобайтовое, ispunct его не поймает)
        if (token == "–") continue;

        std::string w;
        for (unsigned char c : token) {
            if (std::ispunct(c) && c != '-') continue;  // выкидываем знаки препинания
            w += std::tolower(c);                       // приводим к нижнему регистру
        }

        // дефисы по краям не нужны, а внутри ("всё-таки") остаются
        while (!w.empty() && w.back() == '-') w.pop_back();
        while (!w.empty() && w.front() == '-') w.erase(0, 1);

        if (!w.empty() && seen.insert(w).second) {
            words.push_back(w);
        }
    }

    for (const auto& w : words) {
        std::cout << w << "\n";
    }
    return 0;
}
