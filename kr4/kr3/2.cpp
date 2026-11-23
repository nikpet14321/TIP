#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point { double x, y; };

int main() {
    ifstream in("points.txt");
    ofstream out("distances.txt");
    if (!in || !out) {
        cerr << "Ошибка открытия файла" << endl;
        return 1;
    }

    vector<Point> pts;
    Point p;
    while (in >> p.x >> p.y) pts.push_back(p);

    out << fixed << setprecision(1);
    for (size_t i = 0; i < pts.size(); i++) {
        for (size_t j = i + 1; j < pts.size(); j++) {
            double d = sqrt(pow(pts[j].x - pts[i].x, 2) + pow(pts[j].y - pts[i].y, 2));
            out << "(" << pts[i].x << ", " << pts[i].y << ") - (" << pts[j].x << ", " << pts[j].y << "): " << d << "\n";
        }
    }
    cout << "Готово" << endl;
    return 0;
}