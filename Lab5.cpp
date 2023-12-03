#include <iostream>
#include <cmath>


double f(double x, double y) {
    return x+sin(y/3);
}

double f2(double x, double y) {
    return 0.417 * (pow(x, 2) + cos(0.8 * x)) + 0.972 * y;
}

// Метод Ейлера
double euler(double (*func)(double, double), double y0, double x, double h) {
    return y0 + h * func(x, y0);
}

// Модифікований метод Ейлера
double modEuler(double (*func)(double, double),double y0, double x, double h) {
    double y1 = euler(func,y0, x, h);
    return y0 + h / 2 * (func(x, y0) + func(x + h, y1));
}

// Метод Рунге-Кутта
double rungeKutta(double (*func)(double, double), double y0, double x, double h) {
    double k1 = h * func(x, y0);
    double k2 = h * func(x + h / 2, y0 + k1 / 2);
    double k3 = h * func(x + h / 2, y0 + k2 / 2);
    double k4 = h * func(x + h, y0 + k3);
    return y0 + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
}


void solve(double (*func)(double, double),double h) {
    double x0 = 1.6, y = 4.6;
    int num_intervals = static_cast<int>(2.6 / h);

    for (int i = 0; i <= num_intervals; i++) {
        if (x0 >= 1.6 && x0 <= 2.6) {
            std::cout << "At x = " << x0 << ", h = " << h << ", Euler: " << euler(func, y, x0, h) << ", Modified Euler: " << modEuler(func, y, x0, h) << ", Runge-Kutta: " << rungeKutta(func, y, x0, h) << std::endl;
        }
        y = rungeKutta(func, y, x0, h);
        x0 += h;
    }
    std::cout << std::endl;
}

void solve2(double (*func)(double, double)) {
    double x0 = 0.2;
    double y = 0.25;
    double h = 0.1;
    int num_intervals = 100;

    for (int i = 0; i <= num_intervals; i++) {
        if (x0 >= 0.2 && x0 <= 1.2) {
            std::cout << "At x = " << x0 << ", h = " << h << ", Euler: " << euler(func, y, x0, h) << ", Modified Euler: " << modEuler(func, y, x0, h) << ", Runge-Kutta: " << rungeKutta(func, y, x0, h) << std::endl;
        }
        y = rungeKutta(func, y, x0, h);
        x0 += h;
    }

}

int main() {
    std::cout << "1st function; [1.6;2.6]; h=0.1" << std::endl;
    solve(f, 0.05);
    std::cout << "1st function; [1.6;2.6]; h=0.05" << std::endl;
    solve(f, 0.1);
    std::cout << "2nd function; [0.2;1.2]; h=0.1" << std::endl;
    solve2(f2);
    return 0;
}