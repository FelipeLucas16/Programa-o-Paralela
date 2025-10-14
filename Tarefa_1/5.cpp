#include <iostream>

int main()
{

    // A
    for (int i = 1; i <= 20; i++)
    {
        if (i % 2 != 0)
            std::cout << i << " ";
    }

    // B
    int i = 10;
    while (i >= 0 && i <= 10)
    {
        std::cout << "\n"
                  << i;
        i--;
    }

    // C

    int opcao;
    do
    {
        std::cout << "\nMenu: \n1-Cadastrar nome \n2-Listar nomes \n0-Sair\n ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
            std::cout << "Cadastrando nome..." << std::endl;
            break;
        case 2:
            std::cout << "Listando nomes..." << std::endl;
            break;
        case 0:
            std::cout << "Saindo..." << std::endl;
            break;

        default:
            break;
        }
    } while (opcao != 3);

    return 0;
}
