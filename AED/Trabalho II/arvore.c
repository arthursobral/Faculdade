#include "arvore.h"
#include "biblioteca.h"

int vazia(Arvore *biblioteca){
	return (biblioteca==NULL);
}

void printa_arvore(Arvore *biblioteca){
	if(!vazia(biblioteca)){
		printf("[%d,", biblioteca->livro.acervo);
		printa_arvore(biblioteca->esq);
		printf(",");
		printa_arvore(biblioteca->dir);
		printf("]");
	}
	else{
		printf("[]");
	}
}

void printa_ord(Arvore *biblioteca){
	if(!vazia(biblioteca)){
		printa_ord(biblioteca->esq);
		printf("Acervo: %-57d|\n", biblioteca->livro.acervo);
		printf("Titulo: %-57s|\n", biblioteca->livro.titulo);
		printf("Autor: %-58s|\n", biblioteca->livro.autor);
		printf("Quantidade: %-53d|\n", biblioteca->livro.qtd);
    	printf("+----------------------------------------------------------------+\n");
		printa_ord(biblioteca->dir);
	}
}

Arvore *insere_no(Arvore *biblioteca,Livros *l){
	if(vazia(biblioteca)){
		biblioteca = (Arvore*) malloc(sizeof(Arvore));

		biblioteca->livro.acervo = l->acervo;
		strcpy(biblioteca->livro.titulo,l->titulo);
		strcpy(biblioteca->livro.autor,l->autor);
		biblioteca->livro.qtd = l->qtd;
		biblioteca->esq = NULL;
		biblioteca->dir = NULL;
	}
	else if(l->acervo < biblioteca->livro.acervo){
		biblioteca->esq = insere_no(biblioteca->esq,l);
	}
	else{
		biblioteca->dir = insere_no(biblioteca->dir,l);
	}

	return biblioteca;
}

int maximo(Arvore *biblioteca){
	while(biblioteca->dir != NULL){
		biblioteca = biblioteca->dir;
	}	
	return biblioteca->livro.acervo;
}

int minimo(Arvore *biblioteca){
	while(biblioteca->esq != NULL){
		biblioteca = biblioteca->esq;
	}
	return biblioteca->livro.acervo;
}

Arvore *remove_no(Arvore *biblioteca,int remover){
	if(vazia(biblioteca)){
		return NULL;
	}
	if(remover < biblioteca->livro.acervo){
		biblioteca->esq = remove_no(biblioteca->esq,remover);
	}
	else if(remover > biblioteca->livro.acervo){
		biblioteca->dir = remove_no(biblioteca->dir,remover);
	}
	else{//caso remover == acervo
		if(biblioteca->esq == NULL && biblioteca->dir == NULL){ //eh um no folha
			free(biblioteca);
			biblioteca = NULL;
		}
		else if(biblioteca->esq == NULL){ // caso ele tenha um filho na direta
			biblioteca->livro.acervo = minimo(biblioteca->dir);
			biblioteca->dir = remove_no(biblioteca->dir,biblioteca->livro.acervo);
		}
		else{ //caso ele tenha 2 filhos ou um na esquerda
			biblioteca->livro.acervo = maximo(biblioteca->esq);
			biblioteca->esq = remove_no(biblioteca->esq,biblioteca->livro.acervo);
		}
	}
	return biblioteca;
}