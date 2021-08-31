#ifndef FILA_H
#define FILA_H

typedef struct no{
    int info;
    struct no *prox, *ant;
}No;

typedef struct fila{
    //tamanho
    int n;
    //cabeca
    struct no* inicio;
    //cauda
    struct no* final;
}Fila;

// \brief inicializa a fila
// \return fila inicializada e devidamente alocada
Fila* start();

// \brief verifica se a fila está vazia
// \param f: fila que irá ser verificada
// \return 1 se estiver vazia e 0 se não estiver
int empty(Fila *f);

// \brief cria uma variavel do tipo no e aloca ela
// \param dados: valor a ser guardado dentro do no
// \return uma variavel do tipo no com o campo info ja atribuido
No* criaNo(int dados);

// \brief insere na cauda da fila um novo nó contendo o dado a ser inserido
// \param f: fila onde vai ser inserido o novo nó
// \param dados: dado a ser inserido
void enqueue(Fila *f, int dados);

// \brief retira da fila o primeiro nó
// \param f: fila onde vai ser removido o nó
// \return o valor do nó removido
int dequeue(Fila *f);

#endif