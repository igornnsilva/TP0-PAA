#include "quadro.h"

//funcao para iniciar quadro
char **inicioQuadro(int Linha, int Coluna)
{
    int i, j;
    char **Quadro = (char **)malloc(Linha * sizeof(char *));
    for (i = 0; i < Linha; i++)
    {
        Quadro[i] = (char *)malloc(Coluna * sizeof(char));

        for (j = 0; j < Coluna; j++)
        {
            Quadro[i][j] = ' ';
        }
    }
    return Quadro;
}

//função para criar um quadro em branco com bordas feitas por '-' e '|' , com o interior preenchido por espaco
char **CriaQuadro()
{
    int Linha = 20, Coluna = 80, i, j;
    char **Quadro = inicioQuadro(Linha, Coluna);
    for (i = 0; i < Linha; i++)
    {
        for (j = 0; j < Coluna; j++)
        {
            if (i == 0 || i == (Linha - 1))
            { 
                Quadro[i][j] = '-';
            }
            else if (j == 0 || j == (Coluna - 1))
            {
                Quadro[i][j] = '|';
            }
            else
            {
                Quadro[i][j] = ' ';
            }
        }
    }
    return Quadro;
}

//função pra printar o quadro
void print_quadro(char **quadro)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            printf("%c", quadro[i][j]);
        }
        printf("\n");
    }
}
//função pra verificar a entrada dada pelo usuario
int verificaEntrada(int tam)
{
    //condicao para retornar 100 caso o usuario digite acima de 100
    if (tam > 100)
    {
        return 100;
    }
    else if (tam <= 0)
    {
        return rand() % 99;
    }
    else
    {
        return tam;
    }
}
//funcao que insere quantidade de astericos em posicoes aleatorias da matriz
void Asterisco(char **matriz, int quantidade)
{

    int x, y;

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {

            x = 1 + rand() % 18;
            y = 1 + rand() % 78;

            if (matriz[x][y] == ' ')
            {
                break;
            }
        }
        matriz[x][y] = '*';
    }
}

void somaComAsterisco(char **matriz, int qtdFiguras)
{
    int x, y;

    for (int i = 0; i < qtdFiguras; i++)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;
            if (matriz[x][y] == ' ' && matriz[x + 1][y] == ' ' && matriz[x - 1][y] == ' ' && matriz[x][y + 1] == ' ' && matriz[x][y - 1] == ' ')
                break;
        }
        matriz[x][y] = '*';
        matriz[x + 1][y] = '*';
        matriz[x - 1][y] = '*';
        matriz[x][y + 1] = '*';
        matriz[x][y - 1] = '*';
    }
}

void LetraX(char **matriz, int quantidade)
{
    int x, y;

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (matriz[x][y] == ' ' && matriz[x + 1][y + 1] == ' ' && matriz[x - 1][y - 1] == ' ' && matriz[x + 1][y - 1] == ' ' && matriz[x - 1][y + 1] == ' ')
            {
                break;
            }
        }
        matriz[x][y] = '*';
        matriz[x + 1][y + 1] = '*';
        matriz[x - 1][y - 1] = '*';
        matriz[x - 1][y + 1] = '*';
        matriz[x + 1][y - 1] = '*';
    }
}
//funcao que distribui aleatoriamente uma qtd de astericos e letra x
void aleatorio(char **matriz, int quantidade)
{
    srand(time(0));
    int sizes[3], options[3];
    do
    {
        options[0] = rand() % 3;
        options[1] = rand() % 3;
        options[2] = rand() % 3;

    } while (options[0] == options[1] || options[0] == options[2] || options[1] == options[2]);

    sizes[0] = rand() % quantidade;
    sizes[1] = rand() % (quantidade - sizes[0]);
    sizes[2] = quantidade - (sizes[0] + sizes[1]);

    switch (options[0])
    {
    case 0:
        Asterisco(matriz, sizes[0]);
        if (options[1] == 1)
        {
            somaComAsterisco(matriz, sizes[1]);
            LetraX(matriz, sizes[2]);
        }
        else
        {
            LetraX(matriz, sizes[1]);
            somaComAsterisco(matriz, sizes[2]);
        }
        break;
    case 1:
        somaComAsterisco(matriz, sizes[0]);
        if (options[1] == 0)
        {
            Asterisco(matriz, sizes[1]);
            LetraX(matriz, sizes[2]);
        }
        else
        {
            LetraX(matriz, sizes[1]);
            Asterisco(matriz, sizes[2]);
        }
        break;
    case 2:
        LetraX(matriz, sizes[0]);
        if (options[1] == 0)
        {
            Asterisco(matriz, sizes[1]);
            somaComAsterisco(matriz, sizes[2]);
        }
        else
        {
            somaComAsterisco(matriz, sizes[1]);
            Asterisco(matriz, sizes[2]);
        }
        break;
    default:
        break;
    }
}

//funçao que cria a obra de arte com os rostinhos
void obraDeArte(char **quadro, int quantidade)
{
    srand(time(0));
    int sizes[3], options[3];
    do
    {
        options[0] = rand() % 3;
        options[1] = rand() % 3;
        options[2] = rand() % 3;

    } while (options[0] == options[1] || options[0] == options[2] || options[1] == options[2]);

    sizes[0] = rand() % quantidade;
    sizes[1] = rand() % (quantidade - sizes[0]);
    sizes[2] = quantidade - (sizes[0] + sizes[1]);

    switch (options[0])
    {
    case 0:
        alegre(quadro, sizes[0]);
        if (options[1] == 1)
        {
            tedio(quadro, sizes[1]);
            serio(quadro, sizes[2]);
        }
        else
        {
            serio(quadro, sizes[1]);
            tedio(quadro, sizes[2]);
        }
        break;
    case 1:
        tedio(quadro, sizes[0]);
        if (options[1] == 0)
        {
            alegre(quadro, sizes[1]);
            serio(quadro, sizes[2]);
        }
        else
        {
            serio(quadro, sizes[1]);
            alegre(quadro, sizes[2]);
        }
        break;
    case 2:
        serio(quadro, sizes[0]);
        if (options[1] == 0)
        {
            alegre(quadro, sizes[1]);
            tedio(quadro, sizes[2]);
        }
        else
        {
            tedio(quadro, sizes[1]);
            alegre(quadro, sizes[2]);
        }
        break;
    default:
        break;
    }
}

//funcao para fazer o rostinho alegre
void alegre(char **quadro, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (quadro[x][y] == ' ' && quadro[x][y + 1] == ' ' && quadro[x][y + 2] == ' ' && quadro[x][y + 3] == ' ' && quadro[x][y + 4] == ' ' && quadro[x][y + 5] == ' ' && quadro[x][y + 6] == ' ')
            {
                break;
            }
        }
        inseriralegre(quadro, x, y);
    }
}

void inseriralegre(char **quadro, int x, int y)
{


    quadro[x][y] = '/';
    quadro[x][y + 1] = '(';
    quadro[x][y + 2] = '^';
    quadro[x][y + 3] = 'o';
    quadro[x][y + 4] = '^';
    quadro[x][y + 5] = ')';
    quadro[x][y + 6] = '/';
};

//funcao para fazer o rostinho de tedio
void tedio(char **quadro, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (quadro[x][y] == ' ' && quadro[x][y + 1] == ' ' && quadro[x][y + 2] == ' ' && quadro[x][y + 3] == ' ' && quadro[x][y + 4] == ' ' && quadro[x][y + 5] == ' ')
            {
                break;
            }
        }
        inserirtedio(quadro, x, y);
    }
}

void inserirtedio(char **quadro, int x, int y)
{


    quadro[x][y] = '(';
    quadro[x][y + 1] = ' ';
    quadro[x][y + 2] = '-';
    quadro[x][y + 3] = '_';
    quadro[x][y + 4] = '-';
    quadro[x][y + 5] = ')';
}

//funcao para fazer o rostinho de serio
void serio(char **quadro, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (quadro[x][y] == ' ' && quadro[x][y + 1] == ' ' && quadro[x][y + 2] == ' ' && quadro[x][y + 3] == ' ' && quadro[x][y + 4] == ' ' && quadro[x][y + 5] == ' ' && quadro[x][y + 6] == ' ' && quadro[x][y + 7] == ' ' && quadro[x][y + 8] == ' ')
            {
                break;
            }
        }
        inserirserio(quadro, x, y);
    }
}

void inserirserio(char **quadro, int x, int y)
{

    quadro[x][y] = '~';
    quadro[x][y + 1] = '(';
    quadro[x][y + 2] = ' ';
    quadro[x][y + 3] = '-';
    quadro[x][y + 4] = '.';
    quadro[x][y + 5] = '-';
    quadro[x][y + 6] = ' ';
    quadro[x][y + 7] = ')';
    quadro[x][y + 8] = '~';
}

//funcao para fazer o rostinho de susto
void susto(char **quadro, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (quadro[x][y] == ' ' && quadro[x][y + 1] == ' ' && quadro[x][y + 2] == ' ')
            {
                break;
            }
        }
        inserirsusto(quadro, x, y);
    }
}

void inserirsusto(char **quadro, int x, int y)
{

    quadro[x][y] = 'o';
    quadro[x][y + 1] = '_';
    quadro[x][y + 2] = 'o';
}



void obraDeArteStatic(char **quadro, int quantidade)
{
    srand(time(0));
    int sizes[4], options[4];
    do
    {
        options[0] = rand() % 10;
        options[1] = rand() % 10;
        options[2] = rand() % 10;
        options[3] = rand() % 10;
    } while (options[0] == options[1] || options[0] == options[2] || options[0] == options[3] || options[1] == options[2] || options[1] == options[3] || options[2] == options[3]);

    sizes[0] = rand() % quantidade;
    sizes[1] = rand() % (quantidade - sizes[0]);
    sizes[2] = rand() % (quantidade - (sizes[0] + sizes[1]));
    sizes[3] = quantidade - (sizes[0] + sizes[1] + sizes[2]);

    for (int i = 0; i < 4; i++)
    {
        switch (options[i])
        {
        case 0:
            alegre(quadro, sizes[i]);
            break;
        case 1:
            tedio(quadro, sizes[i]);
            break;
        case 2:
            serio(quadro, sizes[i]);
            break;
        case 3:
            susto(quadro, sizes[i]);
            break;
        default:
            break;
        }
    }
}

