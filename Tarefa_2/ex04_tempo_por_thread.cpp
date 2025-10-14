/*
Exercício 4 — Medindo tempo por thread
a) Medir e exibir o tempo total de execução.
b) Medir e exibir o tempo gasto por cada thread.
c) Mostrar quantas threads foram utilizadas no cálculo.
*/

#include <iostream>
#include <vector>
#include <omp.h>
#include <iomanip>

int main() {
    const int N = 1'000'000;
    std::vector<double> x(N), y(N), z(N), a(N);

    // Inicialização dos vetores
    for (int i = 0; i < N; i++) {
        x[i] = i * 0.5;
        y[i] = i * 0.5 + 1;
        z[i] = i * 0.5 + 2;
    }

    // Vetor que armazena o tempo de cada thread
    std::vector<double> tempo_thread(omp_get_max_threads(), 0.0);
    int usadas = 0;
    double inicio_total = omp_get_wtime();

    // Região paralela
    #pragma omp parallel
    {
        int id = omp_get_thread_num();   // ID da thread

        // Executado apenas por uma thread (define quantas estão em uso)
        #pragma omp single
        usadas = omp_get_num_threads();

        double ini_local = omp_get_wtime();  // Tempo inicial da thread

        // Cada thread processa um subconjunto dos índices
        #pragma omp for schedule(static)
        for (int i = 0; i < N; i++)
            a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];

        double fim_local = omp_get_wtime();
        tempo_thread[id] = fim_local - ini_local; // Tempo gasto por thread
    }

    double total = omp_get_wtime() - inicio_total;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Threads utilizadas: " << usadas << "\n";
    std::cout << "Tempo total: " << total << " s\n";

    // Mostra o tempo de cada thread
    for (int i = 0; i < usadas; i++)
        std::cout << "Thread " << i << ": " << tempo_thread[i] << " s\n";

    return 0;
}
