#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    srand(time(0));
    int linhas = 20;
    int colunas = 80;
    int matriz[20][80];

    for (int i = 0; i < linhas; i++)
    {

        for (int j = 0; j < colunas; j++)
        {
            int randomNumber1 = rand() % 20;
            if (i == 0 && j == 0)
            {
                printf("-");
            }
            
            else if(i == 0){
                printf("-");
            }
            else if(i == 19){
                printf("-");
            }
            else if(j == 0 ){
                printf("|");
            }
            else if(j == 79){
                printf("|");
            }
            else if(i == randomNumber1){
                printf("*");
            }
            else{
                printf(" ");
            }
            
        }
        printf("\n");
    }
    
}