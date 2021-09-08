#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "arquivo.h"
#include "algoritmos.h"

int main(){
    FILE *entrada;
    int opcao;
    char nomeArq[100];

    Grafo *grafo = NULL;

    printf("******************************\n");
    printf("* 1 - Carregar arquivo       *\n");
    printf("* 2 - Algoritmos             *\n");
    printf("* 0 - Sair                   *\n");
    printf("******************************\n");
    scanf("%d%*c", &opcao);

    while(opcao != 0){
        switch(opcao){
            case 1:
                printf("*****************************************\n");
                printf("* Digite o nome do arquivo (com .txt):  *\n");
                printf("*****************************************\n");
                scanf("%s%*c", nomeArq);

                entrada = fopen(nomeArq,"r+");

                if(entrada == NULL){
                    printf("Erro no arquivo\n");
                    system("pause");
                    break;
                }

                grafo = le_arq(entrada);
                fclose(entrada);
                break;
            case 2:
                system("cls");
                menu_algoritmos(grafo);
                break;
        }
        system("cls");
        printf("******************************\n");
        printf("* 1 - Carregar arquivo       *\n");
        printf("* 2 - Algoritmos             *\n");
        printf("* 0 - Sair                   *\n");
        printf("******************************\n");
        scanf("%d%*c", &opcao);
    }
}