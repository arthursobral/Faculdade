#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include "arquivo.h"
#include "grafo.h"
#include "fila.h"

// estrutura para o algoritmo de profundidade
typedef struct profundidade{
    // cor do vertice
    char cor;
    // vertice pai desse vertice
    int pred;
    // tempo de descoberta e de final de exploração
    int d, f;
    // vertices adjacentes a esse vertice
    int *adj;

} Profundidade;

// estrutura para o algoritmo de largura
typedef struct largura{

    // cor do vertice
    char cor;
    // vertice que precede esse vertice
    int pred;
    // distancia do nó origem
    int d;
    // vertices adjacentes
    int *adj;
} Largura;

// estrutura para o algoritmo de Bellman-Ford
typedef struct bellmanford {
    // peso para chegar nesse vertice
    int d;
    // vertice que precede esse
    int pred;
} BellmanFord;


// estrutura para algoritmo de Kruskal
typedef struct aresta {
    // vertice de origem da aresta, vertice de destino da aresta
    int u, v;
    // peso da aresta
    int peso;
} Aresta;

// variavel para guardar o tempo de descoberta para o algoritmo de profundidade
int timestamp;

void menu_algoritmos(Grafo *g);

void visita_profundidade(int vertice, Profundidade* busca, int n, int **ordem);

void buscaProfundidade(Grafo *g, int inicial, int **res);

int buscaLargura(Grafo *g, int origem, int **res);

#endif // ALGORITMOS_H