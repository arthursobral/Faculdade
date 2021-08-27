#ifndef ARQUIVO_H
#define ARQUIVO_H

#include<stdio.h>
#include<stdlib.h>
#include "grafo.h"

#define ORIENTADO 1;
#define N_VERTICES 2;
#define ARESTAS 3;

int tipo_linha(char linha[]);

Grafo* inicia_orientado(char linha[]);

void aloca_grafo(Grafo* novo);

void inicia_n_vertices(char linha[], Grafo* novo);

void inicia_arestas(char linha[], Grafo* novo);

Grafo* le_arq(FILE *entrada);

#endif // ARQUIVO_H