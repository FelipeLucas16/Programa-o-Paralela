#include <iostream> 
#include <string>

int main() {

    //A
    std::string aluno = "Felipe Ferreira";
    int idade = 23;
    double altura = 1.75;
    bool aprovado = true;

    std::cout << "Nome: " << aluno << std::endl;
    std::cout << "Idade: " << idade << std::endl; 
    std::cout << "Altura: " << altura << std::endl;
    std::cout << "Aprovado: " << (aprovado ? "Sim" : "Nao") << std::endl;

    //B

    const double pi = 3.14159;
    double raio = 5.0;

    double area = pi * raio * raio;

    std::cout << "Area do circulo com raio " << raio << " e: " << area << std::endl;

    return 0;
}

