#include"algoritmos.h"
#include <limits.h>
#include <stdlib.h>

int visita[100], k = 0;

void print(int v[], int n){
    for(int i=0; i < n; i++){
        printf("%d -> ", v[i]);
    }
    printf("\n");
}

void visita_profundidade(int vertice, Profundidade* busca, int n, int **ordem){
    //troca a cor para visitado
    busca[vertice].cor = 'C';
    //atualiza o tempo
    timestamp++;
    //atribui o tempo de descoberta
    busca[vertice].d = timestamp;

    visita[k] = vertice;
    k++;

    //para cada adjacente existente
    for(int i = 0; i < n; i++){
        //se não foram descobertos ainda
        if(busca[vertice].adj[i] == 1 && busca[i].cor == 'B'){
            ordem[vertice][i] = 1;
            busca[i].pred = vertice;
            visita_profundidade(i, busca, n, ordem);
        }
    }

    //troca a cor para fim de exploração e atribui o tempo de finalização
    busca[vertice].cor = 'P';
    timestamp++; 
    busca[vertice].f = timestamp;
}

void buscaProfundidade(Grafo *g, int inicial, int **res){
    k = 0;
    Profundidade* busca = (Profundidade*)malloc(sizeof(Profundidade)*g->total_vertices);

    for (int i = 0; i < g->total_vertices; i++){
        //atribui a cor branco de não descoberto e atribui para predecessir não existente
        busca[i].cor = 'B';
        busca[i].pred = -1;

        //seus adjacentes
        busca[i].adj = (int*)malloc(sizeof(int)*g->total_vertices);
        for (int j = 0; j < g->total_vertices; j++){
            busca[i].adj[j] = (g->adjacentes[i][j] == 1);
        }
    }
    timestamp = 0;

    int i = 0;

    if(busca[inicial].cor == 'B'){
        visita_profundidade(inicial, busca, g->total_vertices, res);
    }

    for(i = 0; i<g->total_vertices; i++){
        if(busca[i].cor == 'B'){
            visita_profundidade(i, busca, g->total_vertices, res);
        }
    }


}

int vertice_origem(Grafo* g){

    int vertice;
    system("cls");
    // printa na tela os vertices do grafo
    printf("Vertices={");
    for(int i = 0; i < g->total_vertices; i++){

        printf(" %d", i);

        (i < g->total_vertices-1)? printf(","): printf("}\n");
    }
    // enquanto a opcao de vertice não ser valida, ele vai executar
    do {
        printf("Entre com o vertice de origem: ");
        scanf("%d%*c", &vertice);
    }while(vertice < 0 && vertice > g->total_vertices);

    return vertice;
}

int buscaLargura(Grafo *g, int origem, int **res){
    //inicia a fila
    Fila *f = start();
    int u, i, j;

    Largura* l = (Largura*)malloc(sizeof(Largura)*g->total_vertices);

    for(i = 0; i < g->total_vertices; i++){
        if(i != origem){
            //atribuindo não descoberto
            l[i].cor = 'B';
            //atribuindo "infinito" para distancia
            l[i].d = INT_MAX;
            //colocando o predecessor com indefinido
            l[i].pred = -1;
            //e pega seus adjacentes
            l[i].adj = (int*)malloc(sizeof(int)*g->total_vertices);

            for(j = 0; j < g->total_vertices; j++){
                l[i].adj[j] = (g->adjacentes[i][j] == 1); 
            }
        }
    }
    //atribui como descoberta para origem
    l[origem].cor = 'C';
    //não tem predecessor
    l[origem].pred = -1;
    //e distancia 0
    l[origem].d = 0;
    l[origem].adj = (int*)malloc(sizeof(int)*g->total_vertices);

    //inicia o vetor de visita
    k = 0;
    visita[k] = origem;
    k++;

    for(j = 0; j < g->total_vertices; j++){
        l[origem].adj[j] = (g->adjacentes[origem][j] == 1);
    }

    //coloca ela na fila
    enqueue(f, origem);

    //enquanto a fila existir
    while(!empty(f)){
        u = dequeue(f);

        if(u == -1) return 0;
        //para cada adjacente deste vertice
        for (i = 0; i < g->total_vertices; i++){
            //se ele ainda nao foi descoberto
            if(l[u].adj[i] && l[i].cor == 'B'){
                //marca o caminho e atribui a distancia e descoberta ao vertice adjacente
                res[u][i] = 1;
                l[i].cor = 'C';
                l[i].d = l[u].d + 1;
                l[i].pred = u;
                
                //enfilera o vertice
                enqueue(f, i);
                visita[k] = i;
                k++;
            }
        }
        l[u].cor = 'P';
    }
    //se ocorreu tudo certo
    return 1;
}

void menu_algoritmos(Grafo *g){
    int opcao, ocorreu;

    do{
        printf("******************************\n");
        printf("* 1 - Profundidade           *\n");
        printf("* 2 - Largura                *\n");
        printf("* 3 - Bellman Ford           *\n");
        printf("* 4 - Kruskal                *\n");
        printf("* 0 - Sair                   *\n");
        printf("******************************\n");
        scanf("%d", &opcao);

        if(opcao == 0){
            break;
        }

        int **res = aloca_inicial(g->total_vertices), vertice;

        if(opcao != 4){
            vertice = vertice_origem(g);
        }

        switch(opcao){
            case 1:
                buscaProfundidade(g, vertice, res);
                print(visita,k);
                free(res);
                break;
            case 2:
                ocorreu = buscaLargura(g, vertice, res);
                if(ocorreu == 1) print(visita,k);
                free(res);
                break;
            case 3:
                //só pode se for orientado
                //ocorreu = bellmanford(g, vertice, res);
                //if(ocorreu == 1) print(visita,k);
                //free(res);
                break;
            case 4:
                //ocorreu = kruskal(g, res);
                //if(ocorreu == 1) print(visita,k);
                //free(res);
                break;
            default:
                break;
        }
    }while(opcao != 0);
}