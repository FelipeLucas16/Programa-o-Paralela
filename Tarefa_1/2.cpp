#include <iostream> 
#include <string>
#include <windows.h>

int main() {

    //A
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
   std::string nome;
   int idade;

    std::cout << "Digite o nome do aluno: ";
    std::cin >> nome;
    std::cout << "Digite a idade do aluno: ";
    std::cin >> idade;

    std::cout << u8"Olá, " <<nome<<"! Você tem "<<idade<<" anos."<< std::endl;

    //B

    std::string nomeCompleto;
    std::cout << "Digite o seu nome completo: ";
    std::getline(std::cin >> std::ws, nomeCompleto);
    std::cout << "Seu nome completo é: " << nomeCompleto << std::endl;

    return 0;
}

