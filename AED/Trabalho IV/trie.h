#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#define ALFABETO 26

typedef struct trie{
	struct trie *filhos[ALFABETO];
	int final;
}Trie;

///
/// \brief transforma o que foi lido do cmd para string 
/// \param argv: uma constante contendo o que foi lido do cmd
/// \return retorna a constante em forma de string
///
char *nome_Arq(char const *argv[]){
    
    return ((char*)argv[0]); //char*: convertendo o tipo de dado para string
}

Trie *inicializa(){
	int i;
	Trie *novo = (Trie*)malloc(sizeof(Trie));
	novo->final = 0;

	for(i=0; i < ALFABETO; i++){
		novo->filhos[i] = NULL;
	}

	return novo;
};

void insere(Trie *raiz, char *s){
	Trie *aux = raiz;

	while(*s){
		if(aux->filhos[*s - 'a'] == NULL){
			aux->filhos[*s - 'a'] = inicializa();
		}
		aux = aux->filhos[*s - 'a'];

		s++;
	}
	aux->final = 1;
}

void insere_arq(Trie *raiz,FILE *dicionario ,char *linhaArq){
	int i = 0, tam_lido;
	char palavra[100];

	while (!feof(dicionario)){
		fscanf(dicionario,"%s",palavra);
		insere(raiz,palavra);
	}
}

void printa(Trie *raiz, char palavra[],int indice){
	int i;

	if(raiz->final == 1){
		palavra[indice] = '\0';
		printf("+------------------------------------+\n");
		printf("|         %-27s|\n",palavra);
		printf("+------------------------------------+\n");
	}

	for (i = 0; i < ALFABETO; i++){
		if(raiz->filhos[i] != NULL){
			palavra[indice] = i + 'a';
			printa(raiz->filhos[i],palavra,indice+1);
		}
	}
}

int verifica_filho(Trie *raiz){
	int i;

	for(i=0; i<ALFABETO; i++){
		//verifica se achou um filho
		if(raiz->filhos[i]){
			return 1;
		}
	}
	return 0;
}

int remover(Trie **raiz, char *s){
	if(*raiz == NULL){
		return 0;
	}

	if(*s){
		//recursiva para achar o char correspondende
		//se for 1 deleta o no atual
		//(se nao for o final) 
		if(*raiz != NULL && (*raiz)->filhos[*s - 'a'] != NULL && remover(&((*raiz)->filhos[*s - 'a']),s + 1) && (*raiz)->final == 0){
			if(!verifica_filho(*raiz)){
				free(*raiz);
				(*raiz) = NULL;
				return 1;
			}else{
				return 0;
			}
		}
	}

	if(*s == '\0' && (*raiz)->final){
		if(!verifica_filho(*raiz)){
			free(*raiz);
			(*raiz) = NULL;
			return 1;
		}
		else{
			(*raiz)->final = 0;
			return 0;
		}
	}
	return 0;
}

void remove_stopwords(Trie **raiz){
	int i = 0, tam_lido;
	char palavra[100];
	FILE *stopwords = fopen("stopwords.txt","r");

	while (!feof(stopwords)){
		fscanf(stopwords,"%s",palavra);
		remover(&(*raiz),palavra);
	}
	fclose(stopwords);
}

void printa_aux(Trie *raiz, char palavra[],int indice,int *contador){
	int i;

	if(raiz->final == 1){
		palavra[indice] = '\0';
		(*contador)++;
		printf("+------------------------------------+\n");
		printf("|         %-27s|\n",palavra);
		printf("+------------------------------------+\n");
	}

	for (i = 0; i < ALFABETO && (*contador) < 10; i++){
		if(raiz->filhos[i] != NULL){
			palavra[indice] = i + 'a';
			printa_aux(raiz->filhos[i],palavra,indice+1,contador);
		}
	}
}

void semelhantes(Trie *raiz){
	char palavra[100];
	int indice, i, contador = 0;

	menu_semelhantes();
	gotoXY(10,2);
	scanf("%s",palavra);

	indice = strlen(palavra);

	for(i=0; i < indice; i++){
		raiz = raiz->filhos[palavra[i] - 'a'];
	}

	if(raiz == NULL){
		erro_prefix();
		return;
	}

	printa_aux(raiz,palavra,indice,&contador);
}