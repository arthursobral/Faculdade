#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arquivo.h"

int tipo_linha(char linha[]){
    if(strncmp(linha,"orientado",9) == 0){
        return ORIENTADO;
    }
    else if (linha[0] == 'V'){
        return N_VERTICES;
    }
    else{
        return ARESTAS;
    }
}

Grafo* inicia_orientado(char linha[]){
    Grafo* novo;
    char orientado[4];

    sscanf(linha, "orientado= %[^\n]%*c", orientado);

    novo = inicia_grafo(orientado);

    return novo;
}

void aloca_grafo(Grafo* novo){
    novo->pesos = aloca_inicial(novo->total_vertices);
    novo->adjacentes = aloca_inicial(novo->total_vertices);
}

void inicia_n_vertices(char linha[], Grafo* novo){
    sscanf(linha,"V= %d%*c",&novo->total_vertices);

    aloca_grafo(novo);
}

void inicia_arestas(char linha[], Grafo* novo){
    char aux[300];
    int lin, col, peso, trace;

    sscanf(linha, "(%d,%d):%d%n", &lin, &col, &peso, &trace);

    if((lin >= 0 && lin < novo->total_vertices) && (col >= 0 && col < novo->total_vertices)){
        novo->adjacentes[lin][col] = 1;
        novo->pesos[lin][col] = peso;

        if(strcmp(novo->orientado, "nao") == 0){
            novo->adjacentes[col][lin] = 1;
            novo->pesos[col][lin] = peso;
        }
    }
}

Grafo* le_arq(FILE* entrada){
    Grafo* novo = NULL;
    char linha[500];

    while(fgets(linha,500,entrada)){
        strtok(linha,"\n");

        switch(tipo_linha(linha)){
            case 1:
                novo = inicia_orientado(linha);
                break;
            case 2:
                inicia_n_vertices(linha, novo);
                break;
            case 3:
                inicia_arestas(linha, novo);
                break;
        }
    }

    return novo;
}