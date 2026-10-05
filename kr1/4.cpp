#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

// объявление глобальных переменных
std::string firstlastname = "Petrov Nikita";
std::string sim1 = "O";
std::string sim2 = "f";
std::string sim3 = "n";

/**
 * Функция для решения квадратного многочлена ax^2 + bx + c = 0
 * с учетом всех частных случаев (a=0, b=0, c=0 и т.д.)
 */
std::string sqeq(double a, double b, double c) {
    // Особый случай: все коэффициенты равны нулю
    if (a == 0 && b == 0 && c == 0) {
        return "x - любое действительное число";
    } 

    // Особый случай: решения отсутствуют
    if (a == 0 && b == 0 && c != 0) {
        return "решений нет";
    }

    // Линейный случай (когда a = 0, а b != 0)
    if (a == 0 && b != 0) {
        double x = -c / b;
        std::ostringstream ss;
        ss << "x = " << std::fixed << std::setprecision(2) << x;
        return ss.str();
    }

    // Обычный квадратный многочлен (находим дискриминант)
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return "действительных корней нет";
    } else if (discriminant == 0) {
        double x = -b / (2 * a);
        std::ostringstream ss;
        ss << "x = " << std::fixed << std::setprecision(2) << x;
        return ss.str();
    } else {
        double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::ostringstream ss;
        ss << "x1 = " << std::fixed << std::setprecision(2) << x1 
           << ", x2 = " << std::setprecision(2) << x2;
        return ss.str();
    }
}

/**
 * Функция для проверки целого числа на простоту
 */
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    double a = 0.0, b = 0.0, c = 0.0;
    
    // Считывание первичных коэффициентов a, b, c
    if (!(std::cin >> a >> b >> c)) {
        return 0;
    }

    std::string symbol;
    // Считывание символа для выбора действия
    if (!(std::cin >> symbol)) {
        return 0;
    }

    // Обработка вариантов в зависимости от символа
    if (symbol == sim1) {
        // Вывод фамилии и имени
        std::cout << firstlastname << std::endl;
    } 
    else if (symbol == sim2) {
        // Вывод корней квадратного многочлена
        std::cout << sqeq(a, b, c) << std::endl;
    } 
    else if (symbol == sim3) {
        // Повторный запрос коэффициентов a, b, c и значения x для третьего символа
        double new_a = 0.0, new_b = 0.0, new_c = 0.0, x_val = 0.0;
        if (std::cin >> new_a >> new_b >> new_c >> x_val) {
            // Вычисление значения трехчлена ax^2 + bx + c
            double value = new_a * x_val * x_val + new_b * x_val + new_c;
            long long int_value = static_cast<long long>(std::round(value));
            
            std::cout << "Значение трехчлена: " << std::fixed << std::setprecision(2) << value << std::endl;
            
            // Проверка полученного значения на простоту
            if (isPrime(int_value)) {
                std::cout << "Полученное значение является простым числом." << std::endl;
            } else {
                std::cout << "Полученное значение не является простым числом." << std::endl;
            }
        }
    } 
    else {
        std::cout << "Введен неизвестный символ." << std::endl;
    }

    return 0;
}