#ifndef GRAFO_H
#define GRAFO_H

typedef struct grafo{
    // indica se ele é ou não orientado
    char orientado[4];

    //adjacentes representa a matriz de adjacentes, totalVertices é o total de vertices que o grafo possui
    //pesos representa os valores de peso das arestas
    int **adjacentes, total_vertices, **pesos;
}Grafo;

Grafo* inicia_grafo(char orientado[]);

int ** aloca_inicial(int v);

#endif // GRAFO_H