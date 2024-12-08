#ifndef QUADRO_H
#define QUADRO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

char **inicioQuadro(int Linha, int Coluna); 
char **CriaQuadro();                       
void print_quadro(char **quadro);             

void Asterisco(char **matriz, int quantidade);
void somaComAsterisco(char **matriz,int qtdFiguras);
void LetraX(char **matriz, int quantidade);
void aleatorio(char **matriz, int quantidade);
void obraDeArte(char **quadro, int quantidade);

void obraDeArteStatic(char **quadro, int quantidade);

int verificaEntrada(int tam);
void alegre(char **quadro, int quantidade);
void tedio(char **quadro, int quantidade);
void serio(char **quadro, int quantidade);
void susto(char **quadro, int quantidade);

void inseriralegre(char **quadro, int x, int y);
void inserirtedio(char **quadro, int x, int y);
void inserirserio(char **quadro, int x, int y);
void inserirsusto(char **quadro, int x, int y);



#endif //QUADRO_H