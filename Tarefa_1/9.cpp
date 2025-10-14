#include <iostream>
#include <vector>

struct Aluno
{
    std::string nome;
    int idade;
};

class ContaBancaria
{
private:
    double valor;

public:
    void depositar(double v)
    {
        this->valor += v;
    }

    bool sacar(double v) {
        if (v <= this->valor){
            this->valor -= v;
            return true;
        }
        return false;
    }

    void imprimir()
    {
        std::cout << "Valor:" << this->valor << std::endl;
    }
};

int main(){
    // A
    Aluno aluno1;
    std::cout << "Digite o nome do aluno: ";
    std::getline(std::cin >> std::ws, aluno1.nome);
    std::cout << "Digite a idade do aluno: ";
    std::cin >> aluno1.idade;
    std::cout << "Nome: " << aluno1.nome << ", Idade: " << aluno1.idade << std::endl;

    // B
    ContaBancaria conta;

    conta.depositar(100.0);
    conta.imprimir();
    conta.sacar(30.0);
    conta.imprimir();


    return 0;
}
