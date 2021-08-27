#include"algoritmos.h"

void menu_algoritmos(Grafo *g){
    int opcao;

    do{
        printf("******************************\n");
        printf("* 1 - Profundidade           *\n");
        printf("* 2 - Largura                *\n");
        printf("* 3 - Bellman Ford           *\n");
        printf("* 4 - Kruskal                *\n");
        printf("* 0 - Sair                   *\n");
        printf("******************************\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                //buscaProfundidade(g, vertice);
                break;
            case 2:
                //buscaLargura(g, vertice);
                break;
            case 3:
                //bellmanford(g, vertice);
                break;
            case 4:
                //kaskal(g, vertice);
                break;
            default:
                break;
        }
    }while(opcao != 0);
}