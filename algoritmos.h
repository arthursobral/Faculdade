#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include"grafo.h"
#include<stdio.h>

//profundidade
typedef struct profundidade{
    //cor
    char cor;
    //predecessor
    char pred;
    //tempo de descoberta
    int d, t;
    //adjacentes
    int *adj;
}Profundidade;


//largura
typedef struct largura{
    //cor
    char cor;
    //predecessor
    char pred;
    //distancia
    int d;
    //adjacentes
    int *adj;
}Largura;

//Bellman-Ford
typedef struct bellmanford{
    //peso
    int d;
    //predecessor
    int pred;
}Bellman_Ford;

//Kruskal

void menu_algoritmos(Grafo *g);

#endif // ALGORITMOS_H