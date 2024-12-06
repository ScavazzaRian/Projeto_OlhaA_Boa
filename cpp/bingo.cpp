#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define MAX_CARTELA 10

using namespace std;

struct numeroBingo
{
    // Nem tinha necessidade de uma struct pra isso, mas fazer oq
    int valor;
};

struct cartelaBingo
{
    numeroBingo B[5], I[5], N[5], G[5], O[5];
};

int gerarAleatorio(int min, int max);
void preencheCartelaBingo(numeroBingo *vetor, int min, int max);
void marcaNumCartela(cartelaBingo *cartelaBingo, int num);
void exibiCartelaBingo(cartelaBingo *cartelaBingo);
void salvaCartela(cartelaBingo *cartelaBingo, int qtde);

int main()
{
    srand(time(0));
    cartelaBingo cartelas[MAX_CARTELA];
    int quantidadeCartelas = 0;
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
        {
            if (quantidadeCartelas == MAX_CARTELA)
            {
                cout << "Todas as cartelas já foram criadas! Não é possível criar mais.\n";
                break;
            }

            int novasCartelas;
            cout << "Digite um número entre 1 e 10: ";
            cin >> novasCartelas;

            if (novasCartelas <= 0 || quantidadeCartelas + novasCartelas > MAX_CARTELA)
            {
                cout << "Já viu esse numero de cartela??\n";
                break;
            }

            for (int i = 0; i < novasCartelas; i++)
            {
                preencheCartelaBingo(cartelas[quantidadeCartelas].B, 1, 15);
                preencheCartelaBingo(cartelas[quantidadeCartelas].I, 16, 30);
                preencheCartelaBingo(cartelas[quantidadeCartelas].N, 31, 45);
                preencheCartelaBingo(cartelas[quantidadeCartelas].G, 46, 60);
                preencheCartelaBingo(cartelas[quantidadeCartelas].O, 61, 75);
                // Ajustando o Free do bingo
                cartelas[quantidadeCartelas].N[2].valor = 0;
                quantidadeCartelas++;
            }

            cout << novasCartelas << " Cartelas criadas!!!\n";
            break;
        }

        case 2:
        {
            if (quantidadeCartelas == 0)
            {
                cout << "Crie uma cartela para jogar!!.\n";
                break;
            }

            cout << "Bingo iniciando, boa sorte!!\n";

            bool jogoTerminado = false;
            while (jogoTerminado == false)
            {
                int numeroSorteado;
                cout << "Digite o numero sorteado ou 0 para encerrar: ";
                cin >> numeroSorteado;
                cout << "Numero sorteado: " << numeroSorteado << endl;

                for (int i = 0; i < quantidadeCartelas; i++)
                {
                    marcaNumCartela(&cartelas[i], numeroSorteado);
                }

                for (int i = 0; i < quantidadeCartelas; i++)
                {
                    cout << "\nCartela " << i + 1 << ":\n";
                    exibiCartelaBingo(&cartelas[i]);
                }

                for (int i = 0; i < quantidadeCartelas; i++)
                {
                    salvaCartela(&cartelas[i], i);
                }

                if (numeroSorteado == 0)
                    jogoTerminado = true;
            }

            break;
        }

        case 3:
            cout << "Tchau tchau Margarida!\n";
            break;

        default:
            cout << "Seleciona certo ze ruela.\n";
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
        if (repetido == false)
        {
            vetor[i].valor = num;
            i++;
        }
    }
}

void marcaNumCartela(cartelaBingo *cartelaBingo, int num)
{
    // Acho que daria pra melhorar essas parte, mas vai ficar assim. Ele vai verificar todas as vetores letra.
    for (int i = 0; i < 5; i++)
    {
        if (cartelaBingo->B[i].valor == num)
        {
            cartelaBingo->B[i].valor = 0;
        }
        if (cartelaBingo->I[i].valor == num)
        {
            cartelaBingo->I[i].valor = 0;
        }
        if (cartelaBingo->N[i].valor == num)
        {
            cartelaBingo->N[i].valor = 0;
        }
        if (cartelaBingo->G[i].valor == num)
        {
            cartelaBingo->G[i].valor = 0;
        }
        if (cartelaBingo->O[i].valor == num)
        {
            cartelaBingo->O[i].valor = 0;
        }
    }
}

void exibiCartelaBingo(cartelaBingo *cartelaBingo)
{
    // Também acho que daria pra deixar isso aqui bem mais simples, mas fazer oq
    bool colunaCompleta_B = true;
    bool colunaCompleta_I = true;
    bool colunaCompleta_N = true;
    bool colunaCompleta_G = true;
    bool colunaCompleta_O = true;

    for (int i = 0; i < 5; i++)
    {
        if (cartelaBingo->B[i].valor != 0)
            colunaCompleta_B = false;
        if (cartelaBingo->I[i].valor != 0)
            colunaCompleta_I = false;
        if (cartelaBingo->N[i].valor != 0)
            colunaCompleta_N = false;
        if (cartelaBingo->G[i].valor != 0)
            colunaCompleta_G = false;
        if (cartelaBingo->O[i].valor != 0)
            colunaCompleta_O = false;
    }

    if (colunaCompleta_B == true)
        cout << "COLUNA B COMPLETA!" << endl;
    if (colunaCompleta_I == true)
        cout << "COLUNA I COMPLETA!" << endl;
    if (colunaCompleta_N == true)
        cout << "COLUNA N COMPLETA!" << endl;
    if (colunaCompleta_G == true)
        cout << "COLUNA G COMPLETA!" << endl;
    if (colunaCompleta_O == true)
        cout << "COLUNA O COMPLETA!" << endl;

    cout << "B\tI\tN\tG\tO" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (i == 2)
        {
            cout << cartelaBingo->B[i].valor << "\t"
                 << cartelaBingo->I[i].valor << "\t"
                 << "FREE" << "\t"
                 << cartelaBingo->G[i].valor << "\t"
                 << cartelaBingo->O[i].valor << endl;
        }
        else
        {
            cout << cartelaBingo->B[i].valor << "\t"
                 << cartelaBingo->I[i].valor << "\t"
                 << cartelaBingo->N[i].valor << "\t"
                 << cartelaBingo->G[i].valor << "\t"
                 << cartelaBingo->O[i].valor << endl;
        }
    }
}

void salvaCartela(cartelaBingo *cartelaBingo, int qtde)
{

    string qtdeCartelas = "cartela" + to_string(qtde + 1) + ".txt";

    ofstream arquivo(qtdeCartelas);

    if (arquivo.is_open())
    {
        arquivo << "Cartela " << qtde + 1 << ":\n";
        for (int i = 0; i < 5; i++)
        {
            if (i == 2)
            {
                arquivo << cartelaBingo->B[i].valor << "\t"
                        << cartelaBingo->I[i].valor << "\t"
                        << "FREE" << "\t"
                        << cartelaBingo->G[i].valor << "\t"
                        << cartelaBingo->O[i].valor << endl;
            }
            else
            {
                arquivo << cartelaBingo->B[i].valor << "\t"
                        << cartelaBingo->I[i].valor << "\t"
                        << cartelaBingo->N[i].valor << "\t"
                        << cartelaBingo->G[i].valor << "\t"
                        << cartelaBingo->O[i].valor << endl;
            }
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo para a cartela " << qtde + 1 << endl;
    }
}