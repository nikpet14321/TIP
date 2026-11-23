#include <iostream>
#include <iomanip>

int main() {
    double x;
    std::cout << "Введите вещественное число: ";
    std::cin >> x;
   std::cout << std::scientific << std::setprecision(4) << x << std::endl;
    return 0;
}