#include<iostream>
#include<cmath>


class RightTriangle {
private:
    double a, b;

public:
    RightTriangle(double legA, double legB) {
        a = legA;
        b = legB;
    }

    double findHypo() const {
        return sqrt((a * a) + (b * b));
    }

};

int main() {
    double a, b;
    std::cin >> a >> b;
    RightTriangle triangle(a, b);
    std::cout << triangle.findHypo() << std::endl;
    return 0;
}