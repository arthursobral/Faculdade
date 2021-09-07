#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

/// \brief inicializa a fila
/// \return fila inicializada e devidamente alocada
Fila* start(){
    Fila *aux = (Fila*)malloc(sizeof(Fila));

    aux->inicio = NULL;
    aux->final = NULL;
    aux->n = 0;

    return aux;
}

/// \brief verifica se a fila está vazia
/// \param f: fila que irá ser verificada
/// \return 1 se estiver vazia e 0 se não estiver
int empty(Fila* f){
	return (f->inicio) ? 0: 1;
}

/// \brief cria uma variavel do tipo no e aloca ela
/// \param dados: valor a ser guardado dentro do no
/// \return uma variavel do tipo no com o campo info ja atribuido
No* criaNo(int dados){
    No* aux = (No*)malloc(sizeof(No));

    aux->info = dados;

    aux->prox = NULL;
    aux->ant = NULL;

    return aux;
}

/// \brief insere na cauda da fila um novo nó contendo o dado a ser inserido
/// \param f: fila onde vai ser inserido o novo nó
/// \param dados: dado a ser inserido
void enqueue(Fila *f, int dados){
    if(!f){
        return;
    }

    No* aux = criaNo(dados);

    if(!f->inicio){
        f->inicio = f->final = aux;
    }else{
        aux->ant = f->final;
        f->final->prox = aux;
        f->final = aux;
    }

    f->n++;
}

/// \brief retira da fila o primeiro nó
/// \param f: fila onde vai ser removido o nó
/// \return o valor do nó removido ou -1 caso a fila nao tenha nada para remover
int dequeue(Fila *f){
    if(empty(f)){
        return -1;
    }

    if(f->inicio == NULL){
        return -1;
    }

    No* aux = f->inicio;

    f->inicio = aux->prox;

    if(f->inicio){
        f->inicio->ant = NULL;
    }else{
        f->final = NULL;
    }

    f->n--;

    return aux->info;
}