#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include "arquivo.h"
#include "grafo.h"
#include "fila.h"
#include <string.h>

// estrutura para o algoritmo de profundidade
typedef struct profundidade{
    // cor do vertice
    char cor;
    // vertice pai desse vertice
    int pred;
    // tempo de descoberta e de final de exploração
    int d, f;
    // vertices adjacentes a esse vertice
    int *adj;

} Profundidade;

// estrutura para o algoritmo de largura
typedef struct largura{

    // cor do vertice
    char cor;
    // vertice que precede esse vertice
    int pred;
    // distancia do nó origem
    int d;
    // vertices adjacentes
    int *adj;
} Largura;

// estrutura para o algoritmo de Bellman-Ford
typedef struct bellmanford {
    // peso para chegar nesse vertice
    int d;
    // vertice que precede esse
    int pred;
} BellmanFord;

// estrutura para algoritmo de Kruskal
typedef struct aresta {
    // vertice de origem da aresta, vertice de destino da aresta
    int u, v;
    // peso da aresta
    int peso;
} Aresta;

// variavel para guardar o tempo de descoberta para o algoritmo de profundidade
int timestamp;

///
/// \brief menu para a escolha dos algoritmos
/// \param g grafo onde sera realizado os algoritmos
/// \return nenhum
///
void menu_algoritmos(Grafo *g);

///
/// \brief funcao que visita e atualiza os campos e comeca uma nova busca a partir dele
/// \param vertice vertice que esta sendo visitado
/// \param busca estrutura responsavel por guardar a instacia do algortimo
/// \param n total de vertices
/// \return nenhum 
///
void visita_profundidade(int vertice, Profundidade* busca, int n);

///
/// \brief  algoritmo de busca em profundidade
/// \param  g: grafo a ser feito a busca
/// \param  inicial: vertice origem
/// \return nenhum
///
void buscaProfundidade(Grafo *g, int inicial);

///
/// \brief  algoritmo de busca em largura
/// \param  g: grafo a ser feito a busca
/// \param  origem: vertice origem
/// \return 
///
int buscaLargura(Grafo *g, int origem);

///
/// \brief funcao auxiliar do metodod Bellman-Ford para realizar a verificao do menor caminho
/// \param bf estrutura para armazenar a instacia do algoritmo
/// \param pesos matriz de pesos de cada aresta
/// \param u vertice de origem da aresta
/// \param v vertice de destino da aresta
/// \return nenhum
///
void relax(BellmanFord* bf, int** pesos, int u, int v);

///
/// \brief funcao inicial para o algoritmo de Bellman-Ford
/// \param n quantidade de vertices total
/// \param origem vertice origem do algoritmo
/// \return variavel inicializada
///
BellmanFord* inicializaorigem(int n, int origem);

///
/// \brief funcao para realizar o algoritmo de Bellman-Ford
/// \param g grafo onde vai ser buscado o menor caminho
/// \param origem vertice origem da busca
/// \return 1 caso o algoritmo foi realizado com sucesso e 0 caso contrario 
///
int Bellman(Grafo *g, int origem);

///
/// \brief funcao auxiliar do algoritmo de Kruskal, para percorrer as arestas e verificar se ja existe
/// \param  i vertice de origem da aresta a ser verificada
/// \param  j vertice de destino da aresta
/// \param  peso peso da aresta i indo para j
/// \param  e vetor de Aresta guardadas
/// \param  n tamanho do vetor de Aresta
/// \return 1 se existe ou 0 se nao existe 
///
int jaExiste(int i, int j, int peso, Aresta* e, int n);

///
/// \brief funcao que cria as arestas
/// \param g grafo a ter suas arestas verificadas
/// \param n variavel que guarda a quantidade de arestas existentes
/// \return retorna um vetor de arestas com todas as arestas do grafo
///
Aresta* fazAresta(Grafo *g, int *n);

///
/// \brief intercala, função auxiliar do algoritmo de ordenação Merge Sort
/// \param vet, vetor a ser ordenado
/// \param inicio, indice do inicio da parte do vetor separada
/// \param meio, indice do meio do vetor partido
/// \param fim, tamanho maximo da partição
/// \pre nenhuma
/// \post nenhuma
///
void intercala(Aresta* vet, int inicio, int meio, int fim);

///
/// \brief mergeSortN, algoritmo de ordenação por metodo de separar, ordenar e reajuntar e ordenar
/// \param v, vetor a ser ordenado
/// \param inicio, indice do inicio do vetor
/// \param fim, tamanho maximo do vetor
/// \pre nenhuma
/// \post nenhuma
///
void mergeSortN(Aresta* v, int inicio, int fim);

///
/// \brief funcao recursiva auxiliar do algoritmo de Kruskal, para procurar o valor do conjunto do gerador
/// \param alvo indice a ser buscado o gerador
/// \param conj vetor de conjunto onde vai ser buscado
/// \return retorna o valor do indice
///
int findV(int alvo, int *conj);

///
/// \brief funcao auxiliar do algoritmo de Kruskal para realizar a verificacao se os conjuntos u e v sao diferentes
/// \param u indice do conjunto u
/// \param v indice do conjunto v
/// \param conj vetor de conjunto 
/// \return 1 se forem diferentes e 0 caso contrario
///
int diferente(int u, int v, int *conj);

///
/// \brief funcao para realizar a troca de um valor de um certo indice para outro
/// \param u indice que participara da troca
/// \param v indice que sera trocado
/// \param conj vetor de conjunto 
/// \return nenhum
///
void troca(int u, int v, int *conj);

///
/// \brief funcao auxiliar do algoritmo de Kruskal para realizar a uniao dos conjuntos u e v
/// \param u indice do conjunto u
/// \param v indice do conjunto v
/// \param conj vetor de conjunto 
/// \return nenhum
///
void Uniao(int u, int v, int *conj);

///
/// \brief funcao do algoritmo de Kruskal
/// \param g grafo a ser buscado
/// \return 1 caso foi bem sucedido e 2 caso contrario
///
int Kruskal(Grafo *g);

#endif // ALGORITMOS_H