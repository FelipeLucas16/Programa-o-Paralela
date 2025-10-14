#include <iostream> 
#include <vector>  
#include <cmath> 
#include <omp.h>

double resolver_bhaskara(double a, double b, double c) {
    double delta = (b * b) - (4 * a * c);
    if (delta < 0) {
        return 0.0;
    }
    double x1 = (-b + std::sqrt(delta)) / (2 * a);
    double x2 = (-b - std::sqrt(delta)) / (2 * a);
    return x1 + x2;
}

int main(){

    const int N = 1000;
    std::vector<double> a(N), b(N), c(N);
    double soma_total = 0.0;
    for (int i = 0; i < N; ++i) {
        a[i] = 1.0;
        b[i] = -5.0;
        c[i] = 6.0;
    }

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        double soma_local = resolver_bhaskara(a[i], b[i], c[i]);
        #pragma omp critical
        {
            soma_total += soma_local;
        }
    }
    
    std::cout << "Soma total das raízes: " << soma_total << std::endl;

    return 0;
}


