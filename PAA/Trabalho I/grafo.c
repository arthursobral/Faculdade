#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "grafo.h"

///
/// \brief funcao responsavel para iniciar uma instancia do tipo Grafo e guardando o tipo da sua orientacao
/// \param orientado string que indica sua orientacao
/// \return uma variavel do tipo Grafo alocada e com o seu tipo de orientacao preenchida
///
Grafo* inicia_grafo(char orientado[]){
    Grafo *novo = (Grafo*)malloc(sizeof(Grafo));

    strcpy(novo->orientado, orientado);

    return novo;
}

///
/// \brief funcao responsavel para alocar uma matriz quadrada por V e atribui o valor de cada elemento com 0
/// \param v tamanho que a matriz quadrada terá
/// \return matriz alocada preenchida com 0
///
int** aloca_inicial(int v){
    int** alvo = (int**)malloc(sizeof(int*)*v);

    for(int i = 0; i < v; i++){
        alvo[i] = (int*)malloc(sizeof(int)*v);

        for(int j = 0; j < v; j++){
            alvo[i][j] = 0;
        }
    }

    return alvo;
}