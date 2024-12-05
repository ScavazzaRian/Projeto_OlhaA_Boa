#include <iostream>
// Biblioteca do C++ utlizada pra gerar os números aleatórios
#include <cstdlib>
// Utilizada ara iniciar a semente do gerador de números com base no horário.
#include <ctime>
#define MAX_CARTELA 10

using namespace std;

int gerarAleatorio(int min, int max);
void preencheCartelaBingo(numeroBingo *vetor, int min, int max);

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
        cout << "|=================================|" << endl;
        cout << "|      BEM VINDO AO BINGO CPP     |" << endl;
        cout << "|=================================|" << endl;
        cout << "| Escolha uma das opcoes a seguir:|" << endl;
        cout << "| 1 - Criar cartelas              |" << endl;
        cout << "| 2 - Jogar                       |" << endl;
        cout << "| 3 - Sair                        |" << endl;
        cout << "|=================================|" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Cartelas cadastradas com sucesso!!" << endl;
            break;
        }
    } while (opcao != 3);

    return 0;
}

int gerarAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void preencheCartelaBingo(numeroBingo *vetor, int min, int max)
{
    int i = 0;
    // Tive que fazer um while já que só posso incrementar se não houver número repetido no vetor
    while (i < 5)
    {
        int num = gerarAleatorio(min, max);
        bool repetido = false;
        /*Comparo cada elemento gerado até j < i. Como eu só incremento o i quando os valores são únicos, caso os números sejam iguais ele irá cair no if e irá reiniciar o ciclo até gerar um número único.*/
        for (int j = 0; j < i; j++)
        {
            if (vetor[j].valor == num)
            {
                repetido = true;
                break;
            }
        }
        // Por fim caso o número não seja repitido eu incremento o i e adiciono um valor a ele.
        vetor[i].valor = num;
        vetor[i].marcado = false;
        i++;
    }
}
