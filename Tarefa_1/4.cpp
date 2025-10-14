#include <iostream> 

int main() {

    //A
    int nota;
    std::cout << "Digite a nota do aluno (0-10): ";
    std::cin >> nota;
    if(nota >=6)
        std::cout << "Aprovado" << std::endl;
    if(nota <6 && nota >= 4)
        std::cout << "Prova Final" << std::endl;
    if(nota <4)
        std::cout << "Reprovado" << std::endl;

    //B

    int opcao;
    std::cout << "\nMenu: \n1-Cadastrar nome \n2-Listar nomes \n3-Sair\n ";
    std::cin >> opcao;

    switch (opcao)
    {
    case 1:
        std::cout << "Cadastrando nome..." << std::endl;
        break;
    case 2:
        std::cout << "Listando nomes..." << std::endl;
        break;
    case 3:
        std::cout << "Saindo..." << std::endl;
    break;
    
    default:
        break;
    }
       
    return 0;
}

