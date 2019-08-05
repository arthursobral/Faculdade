#include "quicksort.h"
#include "arvore.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int Separa(Livros* v[], int esq, int dir){
	int j = esq,k;
	Livros *pivo;
	Livros *temp;

	//destino , origem
	pivo = v[dir];
	//strcpy(pivo,v[dir]->titulo);

	for(k=esq; k<dir; k++){
		//strcmp compara duas strings < 0 string1 é menor que string2
		v[k]->titulo[0] = toupper(v[k]->titulo[0]);
		pivo->titulo[0] = toupper(pivo->titulo[0]);
		if(strcmp(v[k]->titulo,pivo->titulo)<0){
			temp = v[j];
			v[j] = v[k];
			v[k] = temp;
			j++;
			
		}
	}
	v[dir] = v[j];
	v[j] = pivo;

	return j;
}

void QuickSort(Livros* v[], int esq, int dir){
	int j;

	if(esq<dir){
		j = Separa(v,esq,dir);
		QuickSort(v,esq,j-1);
		QuickSort(v,j+1,dir);
	}
}

void escreve_vetor(Livros* v[], int t){
	FILE *f;
	int i;

	f = fopen("titulo_ordenado.txt","w");

	for(i=0;i<t;i++){
		fprintf(f, "%d; ", v[i]->codigo);
		fprintf(f, "%s; ", v[i]->titulo);
		fprintf(f, "%s; ", v[i]->autor);
		fprintf(f, "%d", v[i]->qtd);
		fprintf(f, "\n");
	}

	fclose(f);
}

int pega_livro(Livros* l[], int id, FILE*arvoreBin, FILE*livrosBin, Arvore* raiz){

	if(raiz != NULL){

		int pos;
		
		l[id] = le_livros(livrosBin, raiz->registro.posicao);

		if(raiz->esq != -1)
			pos = pega_livro(l, id+1, arvoreBin, livrosBin, le_nos(arvoreBin, raiz->esq));
		else
			pos = id;
	
		if(raiz->dir != -1)
			pos = pega_livro(l, pos+1, arvoreBin, livrosBin, le_nos(arvoreBin, raiz->dir));
		
		return pos;
	}

	return id;
}

void ordena_vetor(FILE *livrosBin, FILE *arvoreBin){

	CabecalhoLivro *cabecalho = le_cab_livro(livrosBin);
	Livros *l[cabecalho->topo];
	Cabecalho* cab_arv = le_cab_arvore(arvoreBin);
	Arvore* arv = le_nos(arvoreBin, cab_arv->raiz);
	int i, pos;

	pos = pega_livro(l, 0, arvoreBin, livrosBin, arv);

	QuickSort(l,0,pos);
	escreve_vetor(l,pos);
}