#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 100

typedef struct l{
	int acervo;
	char titulo[MAX];
	char autor[MAX];
	int qtd;
}Livros;

char *nome_Arq(char const *argv[]);

Livros *insere_livro();

Livros *insere_livro_arq(char *linhaArq);

#endif