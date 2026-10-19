#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    string current = to_string(x);

    // Первый член уже есть, поэтому строим ещё n - 1 членов.
    for (int step = 1; step < n; step++) {
        string next = "";
        size_t i = 0;

        while (i < current.size()) {
            // Ищем, где заканчивается группа одинаковых цифр, начиная с i.
            size_t j = i;
            while (j < current.size() && current[j] == current[i]) {
                j++;
            }
            // Правило: сначала количество цифр в группе, затем сама цифра.
            // Например, "111" читается как "три единицы" -> "31".
            next += to_string(j - i);
            next += current[i];
            i = j;
        }

        current = next;
    }

    cout << current << endl;

    return 0;
}