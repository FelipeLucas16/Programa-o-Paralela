#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

double resolver_bhaskara(double a, double b, double c) {
    double delta = (b * b) - (4 * a * c);
    if (delta < 0) return 0.0;
    double x1 = (-b + std::sqrt(delta)) / (2 * a);
    double x2 = (-b - std::sqrt(delta)) / (2 * a);
    return x1 + x2;
}

int main() {
    const int N = 10;
    std::vector<double> a(N, 1.0), b(N, -5.0), c(N, 6.0);

    #pragma omp parallel for ordered
    for (int i = 0; i < N; ++i) {
        double soma_local = resolver_bhaskara(a[i], b[i], c[i]);

        #pragma omp ordered
        {
            std::cout << "Resultado para a equação " << i << ": Soma das raízes = " << soma_local << std::endl;
        }
    }

    return 0;
}