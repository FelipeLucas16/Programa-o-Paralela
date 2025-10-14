#include <iostream>

int soma(int a, int b)
{
    return a + b;
}

int soma(int a, int b, int c)
{
    return a + b + c;
}

int incrementa(int a)
{
    return a++;
}

int main()
{
    //A
    int num1, num2;
    std::cout << "Digite dois numeros inteiros: ";
    std::cin >> num1 >> num2;
    int resultado = soma(num1, num2);
    std::cout << "A soma de " << num1 << " e " << num2 << " e: " << resultado << std::endl;

    //B
    int numero;
    std::cout << "Digite um numero inteiro: ";
    std::cin >> numero;
    int valorIncrementado = incrementa(numero);
    std::cout << "O valor incrementado de " << numero << " e: " << valorIncrementado << std::endl;

    //C 
    int n1, n2, n3;
    std::cout << "Digite tres numeros inteiros: ";  
    std::cin >> n1 >> n2 >> n3;
    int resultado3 = soma(n1, n2, n3);
    std::cout << "A soma de " << n1 << ", " << n2 << " e " << n3 << " e: " << resultado3 << std::endl;

    return 0;
}
