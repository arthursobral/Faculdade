#ifndef QUICKSORT_H
#define QUICKSORT_H
#define MAX 100

#include "arvore.h"

typedef struct titulo{
	char nome[MAX];
}Titulo;

int Separa(Livros* v[], int esq, int dir);

void QuickSort(Livros* v[], int esq, int dir);

void escreve_vetor(Livros* v[],int t);

void insere_vetor(FILE *arvoreBin,FILE *livrosBin,Livros l[], int *i, Arvore *raiz);

int pega_livro(Livros* l[], int id, FILE*arvoreBin, FILE*livrosBin, Arvore* raiz);

void ordena_vetor(FILE *livrosBin,FILE *arvoreBin);


#endif