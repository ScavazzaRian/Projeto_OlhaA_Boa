#include <iostream>
//Biblioteca do C++ utlizada pra gerar os números aleatórios
#include <cstdlib>
//Utilizada ara iniciar a semente do gerador de números com base no horário.
#include <ctime>
#define MAX_CARTELA 10

using namespace std;

struct numeroBingo
{
    int valor;
    bool marcado;
};

struct cartelaBingo
{
    numeroBingo B[5], I[5], N[5], G[5], O[5];
};

int main()
{
    srand(time(0));

    int opcao;

    do
    {
        cout << "======================" << endl;
        cout << "BEM VINDO AO BINGO CPP" << endl;
        cout << "Escolha uma das opcoes a seguir" << endl;
        cout << "1 - Criar cartelas \n2 - Jogar \n3 - Sair" << endl;
        cin >> opcao;
    } while(opcao != 3);

    return 0;
}