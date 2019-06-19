#ifndef ARVORE_H
#define ARVORE_H

#include "biblioteca.h"

typedef struct arvore{
	Livros livro;

	struct arvore *esq;
	struct arvore *dir;
}Arvore;

int vazia(Arvore *biblioteca);

void printa_arvore(Arvore *biblioteca);

void printa_ord(Arvore *biblioteca);

int maximo(Arvore *biblioteca);

int minimo(Arvore *biblioteca);

Arvore *insere_no(Arvore *biblioteca,Livros *l);

Arvore *remove_no(Arvore *biblioteca,int remover);

#endif 