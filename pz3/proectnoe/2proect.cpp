#include"2proect.hpp"

double findCheckpoint(double v, double t) {
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