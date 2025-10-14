/*
Exercício 5 — Escalonamento
Use novamente o cálculo de a[i] = x[i]^2 + y[i]^2 + z[i]^2, mas:
a) Execute com schedule(static) e schedule(dynamic, 1000).
b) Compare os tempos em diferentes quantidades de threads (2, 4, 8).
c) Explique em quais situações static e dynamic são mais adequados.
*/

#include <iostream>
#include <vector>
#include <omp.h>
#include <iomanip>

int main() {
    const int N = 1'000'000;
    std::vector<double> x(N), y(N), z(N), a(N);

    // Inicializa os vetores
    for (int i = 0; i < N; i++) {
        x[i] = i * 0.5;
        y[i] = i * 0.5 + 1;
        z[i] = i * 0.5 + 2;
    }

    // --- schedule(static) ---
    // Divide igualmente as iterações entre as threads.
    double ini = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++)
        a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
    double tempo_static = omp_get_wtime() - ini;

    // --- schedule(dynamic, 1000) ---
    // Cada thread pega blocos de 1000 iterações conforme termina.
    ini = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic, 1000)
    for (int i = 0; i < N; i++)
        a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
    double tempo_dynamic = omp_get_wtime() - ini;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Tempo (static):  " << tempo_static << " s\n";
    std::cout << "Tempo (dynamic): " << tempo_dynamic << " s\n";

    // static → bom para tarefas com custo igual por iteração.
    // dynamic → ideal quando algumas iterações demoram mais (melhor balanceamento).
    return 0;
}
