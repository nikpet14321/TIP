#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Стек с минимумом за O(1): вместе с каждым элементом храним
// минимум среди всех элементов, лежащих в стеке не выше него.
class MinStack {
public:
    void push(long long x) {
        long long m = data.empty() ? x : std::min(x, data.back().second);
        data.push_back({x, m});
    }

    long long pop() {
        long long x = data.back().first;
        data.pop_back();
        return x;
    }

    bool empty() const {
        return data.empty();
    }

    long long getMin() const {
        return data.back().second;
    }

private:
    std::vector<std::pair<long long, long long>> data;  // (значение, минимум на этот момент)
};

int main() {
    MinStack st;
    std::string cmd;

    // команды: push x, pop, empty, min
    while (std::cin >> cmd) {
        if (cmd == "push") {
            long long x;
            std::cin >> x;
            st.push(x);
        } else if (cmd == "pop") {
            if (st.empty()) std::cout << "error\n";
            else std::cout << st.pop() << "\n";
        } else if (cmd == "empty") {
            std::cout << (st.empty() ? "yes" : "no") << "\n";
        } else if (cmd == "min") {
            if (st.empty()) std::cout << "error\n";
            else std::cout << st.getMin() << "\n";
        }
    }
    return 0;
}
