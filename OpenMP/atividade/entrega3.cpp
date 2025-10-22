#include <iostream> 
#include <vector>
#include <cmath>
#include <omp.h>

double primeira_raiz_bhaskara(double a, double b, double c) {
    double delta = (b * b) - (4 * a * c);
    if (delta < 0) return 0.0; 
    return (-b + std::sqrt(delta)) / (2 * a);
}

int main() {
    const int N = 8; 
    std::vector<double> a(N, 1.0), b(N, -5.0), c(N, 6.0);
    std::vector<double> raizes_x1(N); 

    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        #pragma omp for
        for (int i = 0; i < N; ++i) {
            raizes_x1[i] = primeira_raiz_bhaskara(a[i], b[i], c[i]);
            printf("Thread %d calculou a raiz para i = %d.\n", id, i);
        }

        #pragma omp barrier

        #pragma omp for
        for (int i = 0; i < N; ++i) {
            printf("Thread %d verificando o resultado de i = %d, que é %.2f.\n", id, i, raizes_x1[i]);
        }
    }

    return 0;
}
