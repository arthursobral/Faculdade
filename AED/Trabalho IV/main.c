#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALFABETO 26

typedef struct no{
    char p;
    struct no *filho[ALFABETO];
    int final; //indica final da palavra, booleano
}Trie;

Trie *inicializa(){
    Trie *no = (Trie*)malloc(sizeof(Trie));
    no->final = 0;
    int i;

    for(i=0;i<ALFABETO; i++){
        no->filho[i] = NULL;
    }

    return no;
}

/*
void insert(Trie *raiz, char *p){
    Trie *aux = raiz;

    if(raiz == NULL){
        raiz = inicializa();
        raiz->p = *p;
        printf("%c",raiz->p);
        p++;
    }

    while(*p){
        printf("teste");
        if(raiz->filho[*p - 'a'] == NULL){
            raiz->filho[*p - 'a'] = inicializa();
            raiz->filho[*p - 'a']->p = *p;
        }
        raiz = raiz->filho[*p - 'a'];
        p++;
    }

    raiz->final = 1;
} 
*/

void insere(Trie *raiz, char *p){
    Trie *atual = raiz;

    while(*p){
        if(atual->filho[*p - 'a'] == NULL){
            atual->filho[*p - 'a'] = inicializa();
            atual->filho[*p - 'a']->p = *p;
        }
        atual = atual->filho[*p - 'a'];

        p++;
    }
    atual->final = 1;
}

int search(Trie *raiz, char *p){
    if(raiz == NULL){
        return 0;
    }
    Trie *atual = raiz;

    while(*p){
        atual = atual->filho[*p - 'a'];
        //printf("%c",atual->p);

        if(atual == NULL){
            return 0;
        }
        p++;
    }
    return atual->final;
}


Trie *proximo(Trie *raiz){
    int i;
    Trie *aux = raiz;

    for(i=0;i<ALFABETO;i++){
        if(aux->filho[i] != NULL){
            return aux->filho[i];
        }
    }
    return NULL;
}

void semelhantes(Trie *raiz, char *p){
    if(raiz == NULL){
        return;
    }

    int i;
    int j = strlen(p),conta=0,init = 0;
    Trie *aux = raiz;
    Trie *aux2;
    char *p2 = p;

    while(*p){
        aux = aux->filho[*p - 'a'];
        //printf("%c",aux->p);
        ++p;
    }

    printf("%s\n",p2);
    for(i = 0; i < ALFABETO && conta < 10; i++){
        aux2 = aux->filho[i];
        if(aux2 != NULL){
            //printf("%c ",aux2->p);
            //printf("aux2 = %c\n",aux2->p);
            conta++;
            printf("%s",p2);
            while (aux2 != NULL){
                printf("%c",aux2->p);
                aux2 = proximo(aux2);
            }
            printf("\n");
        }
    }
}

int main(){
    Trie *nova = inicializa();

    insere(nova,"teste");
    insere(nova,"testando");
    insere(nova,"testecarai");
    
    //int i = search(nova,"teste");
    //i = search(nova,"poha");
    semelhantes(nova,"test");

    return 0;
}