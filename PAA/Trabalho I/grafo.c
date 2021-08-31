#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "grafo.h"

Grafo* inicia_grafo(char orientado[]){
    Grafo *novo = (Grafo*)malloc(sizeof(Grafo));

    strcpy(novo->orientado, orientado);

    return novo;
}

int** aloca_inicial(int v){
    int** alvo = (int**)malloc(sizeof(int*)*v);

    for(int i = 0; i < v; i++){
        alvo[i] = (int*)malloc(sizeof(int)*v);

        for(int j = 0; j < v; j++){
            alvo[i][j] = 0;
        }
    }

    return alvo;
}