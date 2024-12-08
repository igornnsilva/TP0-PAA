#include "menu.h"
#include "quadro.h"

void menu()
{
    int resp = 1;
    int tam;
    char **quadro;

    while (resp != 0)
    {
        quadro = CriaQuadro();
        print_menu1();
        scanf("%d", &resp);
        switch (resp)
        {
        case 1:
            printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio):");
            scanf("%d", &tam);
            Asterisco(quadro, verificaEntrada(tam));
            print_quadro(quadro);
            break;
        case 2:
            printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio):");
            scanf("%d", &tam);
            somaComAsterisco(quadro, verificaEntrada(tam));
            print_quadro(quadro);
            break;
        case 3:
            printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio):");
            scanf("%d", &tam);
            LetraX(quadro, verificaEntrada(tam));
            print_quadro(quadro);
            break;
        case 4:
            printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio):");
            scanf("%d", &tam);
            aleatorio(quadro, verificaEntrada(tam));
            print_quadro(quadro);
            break;
        case 5:
            srand(time(0));
            obraDeArteStatic(quadro, verificaEntrada(rand() % 99));
            print_quadro(quadro);
            break;
        default:
            break;
        }
    }
}

void print_menu1()
{
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 80; i++)
    {
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 80; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 24; i++)
    {
        fputs(" ", stdout);
    }
    printf("PROGRAMA GERADOR DE OBRA DE ARTE");
    for (i = 0; i < 24; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 80; i++)
    {
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("Escolha o tipo de figura basica a ser usada para criar a obra:");
    for (i = 0; i < 13; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("1 - asterisco simples.");
    for (i = 0; i < 53; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("2 - simbolo de soma com asteriscos.");
    for (i = 0; i < 40; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("3 - letra X com asteriscos.");
    for (i = 0; i < 48; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("4 - figuras aleatorias.");
    for (i = 0; i < 52; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("5 - obra de arte.");
    for (i = 0; i < 58; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|           ");
    for (i = 0; i < 69; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");

    printf("|");
    for (i = 0; i < 80; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("-->");
    fflush(stdin);
}