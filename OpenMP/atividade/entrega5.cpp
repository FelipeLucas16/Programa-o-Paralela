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
    double soma_total = 0.0;

    omp_lock_t lock_soma;
    omp_init_lock(&lock_soma);

    double t0 = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        double soma_local = resolver_bhaskara(1, -5, 6);

        omp_set_lock(&lock_soma); 
        soma_total += soma_local;  
        omp_unset_lock(&lock_soma); 
    }

    double t1 = omp_get_wtime();

    omp_destroy_lock(&lock_soma);

    double tempo_total = t1 - t0;

    std::cout << "Tempo total de execução: " << tempo_total << " segundos\n";
    std::cout << "Soma total das raízes: " << soma_total << std::endl;

    return 0;
}
