#ifndef GRAFO_H
#define GRAFO_H

//estrutura para armazenar os dados de um grafo que sera passado no arquivo
typedef struct grafo{
    // indica se ele é ou não orientado
    char orientado[4];

    //adjacentes representa a matriz de adjacentes, totalVertices é o total de vertices que o grafo possui
    //pesos representa os valores de peso das arestas
    int **adjacentes, total_vertices, **pesos;
}Grafo;

///
/// \brief funcao responsavel para iniciar uma instancia do tipo Grafo e guardando o tipo da sua orientacao
/// \param orientado string que indica sua orientacao
/// \return uma variavel do tipo Grafo alocada e com o seu tipo de orientacao preenchida
///
Grafo* inicia_grafo(char orientado[]);

///
/// \brief funcao responsavel para alocar uma matriz quadrada por V e atribui o valor de cada elemento com 0
/// \param v tamanho que a matriz quadrada terá
/// \return matriz alocada preenchida com 0
///
int** aloca_inicial(int v);

#endif // GRAFO_H