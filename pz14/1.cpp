#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::vector<char> st;
    bool ok = true;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push_back(c);
        } else if (c == ')' || c == ']' || c == '}') {
            char open;
            if (c == ')') {
                open = '(';
            } else if (c == ']') {
                open = '[';
            } else {
                open = '{';
            }
            if (st.empty() || st.back() != open) {
                ok = false;
                break;
            }
            st.pop_back();
        }
    }

    if (!st.empty()) ok = false;

    std::cout << (ok ? "yes" : "no") << "\n";
    return 0;
}
