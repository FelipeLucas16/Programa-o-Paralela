#include <iostream> 

int main() {

    //A
    int numero1, numero2;

    std::cout << "Digite o primeiro numero: ";
    std::cin >> numero1;
    std::cout << "Digite o segundo numero: ";   
    std::cin >> numero2;
    std::cout << "A soma dos numeros: " << numero1 + numero2 << std::endl;
    std::cout << "A subtracao dos numeros: " << numero1 - numero2 << std::endl;
    std::cout << "A multiplicacao dos numeros: " << numero1 * numero2 << std::endl;
    std::cout << "A divisao inteira: " << numero1 / numero2 << std::endl;
    std::cout << "A divisão real: " << numero1 / (double)numero2 << std::endl;
    
    //B

    int maior = (numero1 > numero2) ? numero1 : numero2;
    std::cout << "O maior numero e: " << maior << std::endl;

    return 0;
}

