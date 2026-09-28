#include<iostream>

class carCheckpoint {
    private:
    double v, t;

    public:
    carCheckpoint(double velocity, double time) {
        v = velocity;
        t = time;
    }

    double findCheckpoint() const {
    double s;
    s = v * t;
    if (s >= 109) {
        while (s > 109) {
            s -= 109;
        }
        return s;
    } else {
        return s;
    }
    }
};

int main() {
    double v, t;
    std::cin >> v >> t;
    carCheckpoint car(v, t);
    std::cout << car.findCheckpoint() << std::endl;
    return 0;
}