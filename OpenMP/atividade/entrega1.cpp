#include <iostream> 
#include <vector>  
#include <cmath> 
#include <omp.h>

double resolver_bhaskara(double a, double b, double c) {
    
    double b_quadrado, quatro_ac, x1, x2;

    #pragma omp parallel
    {
        double b_quadrado = b * b;
        double quatro_ac = 4 * a * c;
    }

    double delta = b_quadrado - quatro_ac;

    if (delta < 0) {
        return 0.0;
    }

    #pragma omp parallel
    {
        double x1 = (-b + std::sqrt(delta)) / (2 * a);
        double x2 = (-b - std::sqrt(delta)) / (2 * a);
    }
    return x1 + x2;
}

int main(){

    const int N = 10;

    double soma_total= 0;

    double t0 = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        double soma_local = resolver_bhaskara(1, 8, -9);
        #pragma omp critical
        {
            soma_total += soma_local;
        }
    }

    double t1 = omp_get_wtime();

    double tempo_total = t1 - t0;
    std::cout << "Tempo total de execução: " << tempo_total << " segundos\n";
    std::cout << "Soma total das raízes: " << soma_total << std::endl;

    return 0;
}


