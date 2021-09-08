#ifndef ARQUIVO_H
#define ARQUIVO_H

#include<stdio.h>
#include<stdlib.h>
#include "grafo.h"

#define ORIENTADO 1;
#define N_VERTICES 2;
#define ARESTAS 3;

///
/// \brief função para diferenciar o tipo da linha que esta sendo lida
/// \param linha linha lida do arquivo para determinar seu tipo
/// \return número que indica qual o tipo da linha
///
int tipo_linha(char linha[]);

///
/// \brief função que verifica qual o tipo de orientação que esta no arquivo e aloca a estrutura
/// \param linha linha do arquivo que sera lida
/// \return o grafo devidamente alocado e com seu tipo de orientação armazenado
///
Grafo* inicia_orientado(char linha[]);

///
/// \brief função para alocar os campos da estrutura grafo
/// \param novo grafo que sera alocado
/// \return nenhum
///
void aloca_grafo(Grafo* novo);

///
/// \brief função responsavel para armazenar a quantidade total de vertices
/// \param linha linha do arquivo a ser lida
/// \param novo grafo aonde sera inserido os dados passados
/// \return nenhum
///
void inicia_n_vertices(char linha[], Grafo* novo);

///
/// \brief função responsavel para ler a linha de arestas do arquivo armazenando u, v e o peso no grafo
/// \param linha linha do arquivo a ser lida
/// \param novo grafo aonde sera inserido os dados passados
/// \return nenhum
///
void inicia_arestas(char linha[], Grafo* novo);

///
/// \brief função que pega o arquivo aberto e lê as linhas dele armazenando em um grafo
/// \param entrada arquivo de onde sera lido o grafo
/// \return variavel do tipo Grafo contendo os dados passados pelo arquivo
///
Grafo* le_arq(FILE *entrada);

#endif // ARQUIVO_H