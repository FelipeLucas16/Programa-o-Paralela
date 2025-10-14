/*
-----------------------------------------------------------
Exercício 1 — “Hello World” Paralelo
a) Crie uma região paralela com #pragma omp parallel.
b) Cada thread deve imprimir uma mensagem indicando seu número (omp_get_thread_num())
   e o total de threads (omp_get_num_threads()).
c) Configure o programa para rodar com 4 threads.
-----------------------------------------------------------
*/

#include <iostream>  
#include <sstream>   
#include <omp.h>     

int main() {
    // A diretiva abaixo cria uma região paralela com 4 threads.
    // O código dentro das chaves será executado simultaneamente por cada thread.
    #pragma omp parallel num_threads(4)
    {
        // omp_get_thread_num() retorna o número (ID) da thread atual (0 até N-1)
        int id = omp_get_thread_num();

        // omp_get_num_threads() retorna o número total de threads criadas na região paralela
        int total = omp_get_num_threads();

        // std::ostringstream cria um buffer local para montar a string completa
        // Isso evita que várias threads imprimam pedaços de texto ao mesmo tempo.
        std::ostringstream buffer;
        buffer << "Olá do mundo paralelo! Sou a thread "
               << id << " de " << total << "\n";

        // A região crítica garante que apenas uma thread por vez execute este bloco.
        // Isso impede que as saídas no terminal se misturem.
        #pragma omp critical
        {
            std::cout << buffer.str();
        }
    }

    return 0;
}
