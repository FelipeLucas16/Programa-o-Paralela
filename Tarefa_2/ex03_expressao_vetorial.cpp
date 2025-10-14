/*
Exercício 3 — Expressão Vetorial
Implemente a expressão: a[i] = x[i]^2 + y[i]^2 + z[i]^2 para vetores de tamanho 1.000.000.
a) Faça a versão sequencial.
b) Paralelize com #pragma omp parallel for schedule(static).
c) Mostre o tempo total de execução em cada versão.
*/

#include <iostream>
#include <vector>
#include <omp.h>
#include <iomanip>

int main() {
    const int N = 1'000'000;           // Tamanho dos vetores
    std::vector<double> x(N), y(N), z(N), a(N);

    // Inicializa os vetores com valores crescentes
    for (int i = 0; i < N; i++) {
        x[i] = i * 0.5;
        y[i] = i * 0.5 + 1;
        z[i] = i * 0.5 + 2;
    }

    // --- Versão Sequencial ---
    double inicio = omp_get_wtime();   // Marca o tempo inicial
    for (int i = 0; i < N; i++)
        a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
    double tempo_seq = omp_get_wtime() - inicio;

    // --- Versão Paralela ---
    // schedule(static): divide o loop igualmente entre as threads
    inicio = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++)
        a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
    double tempo_par = omp_get_wtime() - inicio;

    // Exibe o tempo de execução das duas versões
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Tempo sequencial: " << tempo_seq << " s\n";
    std::cout << "Tempo paralelo:   " << tempo_par << " s\n";

    return 0;
}
