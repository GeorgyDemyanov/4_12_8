#include <iostream>
#include <cmath>

double f(double x) {
    return x * exp(-x * x);
}

double diff(double f(double), double x) {
    double h = 0.01;
    return (f(x + h) - f(x - h)) / (2 * h);
}

int main() {
    double x0 = 0.5;

    while (diff(f, x0) >= 0.001) {
        x0 += 0.001;
    }
    double y_pol = f(x0) / 2;

    double x1 = 1.5;
    while (std::abs(y_pol - f(x1)) >= 0.0001) {
        x1 = (log(x1) - log(y_pol)) / x1;
    }

    double x2 = 0.2;
    while (std::abs(y_pol - f(x2)) >= 0.0001) {
        x2 = y_pol * exp(x2 * x2);
    }
    std::cout << "x1=" << round(x1 * 1000) / 1000 << " " << "x2=" << round(x2 * 1000) / 1000 << " " << "detltaX="
              << round((x1 - x2) * 1000) / 1000 << std::endl;


}
