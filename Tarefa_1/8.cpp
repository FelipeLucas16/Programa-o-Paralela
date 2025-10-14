#include <iostream>
#include <vector>

void triplica(int& r) { r *= 3; };
int main()
{
    //A
    int numero = 10;
    int *p = &numero;
    
    triplica(numero);
    std::cout << "Valor de numero triplicado: " << numero << std::endl;

    *p *= 2;

    std::cout << "Valor de numero: " << numero << std::endl;

    //B

    int *dinamico = new int(50);
    std::cout << "Valor do inteiro alocado dinamicamente: " << *dinamico << std::endl;
    delete dinamico;


    return 0;
}
