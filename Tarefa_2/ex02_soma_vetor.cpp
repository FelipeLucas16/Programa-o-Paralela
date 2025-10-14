/*
Exercício 2 — Paralelizando um for simples
a) Crie um vetor v de tamanho 100 e inicialize todos os elementos com o valor 1.
b) Escreva um loop sequencial que soma todos os elementos.
c) Refaça o loop com #pragma omp parallel for reduction(+:soma).
d) Compare os resultados e explique por que a diretiva reduction é necessária.
*/

#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 100;                 // Tamanho do vetor
    std::vector<int> vetor(N, 1);      // Inicializa todos os 100 elementos com 1
    int soma_seq = 0, soma_par = 0;    // Variáveis para armazenar as somas

    // --- SOMA SEQUENCIAL ---
    // Apenas uma thread executa (modo normal)
    for (int i = 0; i < N; i++)
        soma_seq += vetor[i];

    // --- SOMA PARALELA ---
    // A diretiva abaixo divide o loop entre as threads.
    // Cada thread executa parte das iterações e faz uma soma local.
    // A cláusula reduction(+:soma_par) faz o OpenMP somar todas as cópias locais no final.
    #pragma omp parallel for reduction(+:soma_par)
    for (int i = 0; i < N; i++)
        soma_par += vetor[i];

    // Exibe os resultados
    std::cout << "Soma sequencial: " << soma_seq << std::endl;
    std::cout << "Soma paralela:   " << soma_par << std::endl;

    // A cláusula reduction é essencial, pois sem ela várias threads
    // tentariam escrever ao mesmo tempo na mesma variável (condição de corrida).
    return 0;
}
