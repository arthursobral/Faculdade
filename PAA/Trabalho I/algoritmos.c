#include"algoritmos.h"
#include <limits.h>
#include <stdlib.h>

int visita[100], k = 0;

///
/// \brief printa vetor de visitas paras o algoritmos de Profundidade e Largura
/// \param vet, vetor a ser ordenado
/// \param inicio, indice do inicio da parte do vetor separada
/// \return nenhum
///
void print(int v[], int n){
    for(int i=0; i < n; i++){
        printf("%d -> ", v[i]);
    }
    printf("\n");
}

///
/// \brief funcao que visita e atualiza os campos e comeca uma nova busca a partir dele
/// \param vertice vertice que esta sendo visitado
/// \param busca estrutura responsavel por guardar a instacia do algortimo
/// \param n total de vertices
/// \return nenhum 
///
void visita_profundidade(int vertice, Profundidade* busca, int n){
    //troca a cor para visitado
    busca[vertice].cor = 'C';
    //atualiza o tempo
    timestamp++;
    //atribui o tempo de descoberta
    busca[vertice].d = timestamp;

    visita[k] = vertice;
    k++;

    //para cada adjacente existente
    for(int i = 0; i < n; i++){
        //se não foram descobertos ainda
        if(busca[vertice].adj[i] == 1 && busca[i].cor == 'B'){
            busca[i].pred = vertice;
            visita_profundidade(i, busca, n);
        }
    }

    //troca a cor para fim de exploração e atribui o tempo de finalização
    busca[vertice].cor = 'P';
    timestamp++; 
    busca[vertice].f = timestamp;
}

///
/// \brief  algoritmo de busca em profundidade
/// \param  g: grafo a ser feito a busca
/// \param  inicial: vertice origem
/// \return nenhum
///
void buscaProfundidade(Grafo *g, int inicial){
    k = 0;
    Profundidade* busca = (Profundidade*)malloc(sizeof(Profundidade)*g->total_vertices);

    for (int i = 0; i < g->total_vertices; i++){
        //atribui a cor branco de não descoberto e atribui para predecessir não existente
        busca[i].cor = 'B';
        busca[i].pred = -1;

        //seus adjacentes
        busca[i].adj = (int*)malloc(sizeof(int)*g->total_vertices);
        for (int j = 0; j < g->total_vertices; j++){
            busca[i].adj[j] = (g->adjacentes[i][j] == 1);
        }
    }
    timestamp = 0;

    int i = 0;

    if(busca[inicial].cor == 'B'){
        visita_profundidade(inicial, busca, g->total_vertices);
    }

    for(i = 0; i<g->total_vertices; i++){
        if(busca[i].cor == 'B'){
            visita_profundidade(i, busca, g->total_vertices);
        }
    }
}

///
/// \brief funcao auxiliar para pegar o vertice de origem
/// \param g grafo inicial
/// \return o vertice de origem escolhido 
///
int vertice_origem(Grafo* g){

    int vertice;
    system("cls");
    // printa na tela os vertices do grafo
    printf("Vertices={");
    for(int i = 0; i < g->total_vertices; i++){

        printf(" %d", i);

        (i < g->total_vertices-1)? printf(","): printf("}\n");
    }
    // enquanto a opcao de vertice não ser valida, ele vai executar
    do {
        printf("Entre com o vertice de origem: ");
        scanf("%d%*c", &vertice);
    }while(vertice < 0 && vertice > g->total_vertices);

    return vertice;
}

///
/// \brief  algoritmo de busca em largura
/// \param  g: grafo a ser feito a busca
/// \param  origem: vertice origem
/// \return 
///
int buscaLargura(Grafo *g, int origem){
    //inicia a fila
    Fila *f = start();
    int u, i, j;

    Largura* l = (Largura*)malloc(sizeof(Largura)*g->total_vertices);

    for(i = 0; i < g->total_vertices; i++){
        if(i != origem){
            //atribuindo não descoberto
            l[i].cor = 'B';
            //atribuindo "infinito" para distancia
            l[i].d = INT_MAX;
            //colocando o predecessor com indefinido
            l[i].pred = -1;
            //e pega seus adjacentes
            l[i].adj = (int*)malloc(sizeof(int)*g->total_vertices);

            for(j = 0; j < g->total_vertices; j++){
                l[i].adj[j] = (g->adjacentes[i][j] == 1); 
            }
        }
    }
    //atribui como descoberta para origem
    l[origem].cor = 'C';
    //não tem predecessor
    l[origem].pred = -1;
    //e distancia 0
    l[origem].d = 0;
    l[origem].adj = (int*)malloc(sizeof(int)*g->total_vertices);

    //inicia o vetor de visita
    k = 0;
    visita[k] = origem;
    k++;

    for(j = 0; j < g->total_vertices; j++){
        l[origem].adj[j] = (g->adjacentes[origem][j] == 1);
    }

    //coloca ela na fila
    enqueue(f, origem);

    //enquanto a fila existir
    while(!empty(f)){
        u = dequeue(f);

        if(u == -1) return 0;
        //para cada adjacente deste vertice
        for (i = 0; i < g->total_vertices; i++){
            //se ele ainda nao foi descoberto
            if(l[u].adj[i] && l[i].cor == 'B'){
                //marca o caminho e atribui a distancia e descoberta ao vertice adjacente
                l[i].cor = 'C';
                l[i].d = l[u].d + 1;
                l[i].pred = u;
                
                //enfilera o vertice
                enqueue(f, i);
                visita[k] = i;
                k++;
            }
        }
        l[u].cor = 'P';
    }
    //se ocorreu tudo certo
    return 1;
}

///
/// \brief funcao auxiliar do metodod Bellman-Ford para realizar a verificao do menor caminho
/// \param bf estrutura para armazenar a instacia do algoritmo
/// \param pesos matriz de pesos de cada aresta
/// \param u vertice de origem da aresta
/// \param v vertice de destino da aresta
/// \return nenhum
///
void relax(BellmanFord* bf, int** pesos, int u, int v){
    // se o peso for menor por essa aresta, atribui o novo peso
    if(bf[v].d > (bf[u].d + pesos[u][v])){
        bf[v].d = bf[u].d + pesos[u][v];
        bf[v].pred = u;
    }
}

///
/// \brief funcao inicial para o algoritmo de Bellman-Ford
/// \param n quantidade de vertices total
/// \param origem vertice origem do algoritmo
/// \return variavel inicializada
///
BellmanFord* inicializaorigem(int n, int origem){
    BellmanFord* bf = (BellmanFord*)malloc(sizeof(BellmanFord)*n);

    for(int i = 0; i < n; i++){
        if(i != origem) {
            bf[i].d = 50000;
            bf[i].pred = -1;
        }
    }

    bf[origem].d = 0;
    bf[origem].pred = -1;

    return bf;
}

///
/// \brief funcao para realizar o algoritmo de Bellman-Ford
/// \param g grafo onde vai ser buscado o menor caminho
/// \param origem vertice origem da busca
/// \return 1 caso o algoritmo foi realizado com sucesso e 0 caso contrario 
///
int Bellman(Grafo* g, int origem){
    BellmanFord* bf = inicializaorigem(g->total_vertices, origem);

    if(strcmp(g->orientado,"nao") == 0){
        printf("Grafo nao orientado, nao é possivel realizar o algoritmo\n");
        return 0;
    }

    int i, j, k;

    printf("origem: %d\n", origem);

    for(i = 0; i < g->total_vertices - 1; i++){
        for(k = 0; k < g->total_vertices; k++){
            for(j = 0; j < g->total_vertices; j++){
                if(g->adjacentes[k][j] == 1){
                    relax(bf, g->pesos, k, j);
                }
            }
        }
    }
    
    for(i = 0; i < g->total_vertices; i++){
        for(j = 0; j < g->total_vertices; j++){
            if(g->adjacentes[i][j] == 1 && (bf[j].d > bf[i].d + g->pesos[i][j])){
                return 0;
            }
        }
    }


    for(i = 0; i < g->total_vertices; i++){
        int v[100];
        j = i;
        printf("dest: %d dist: %d caminho: %d - ", i, bf[i].d, origem);
        k = 0;

        while(bf[j].pred != origem && bf[j].pred != -1){
            v[k] = bf[j].pred;
            j = bf[j].pred;
            k++;
        }

        if(i != origem){
            for(int y = k-1; y >= 0; y--){
                printf("%d - ", v[y]);
            }
            printf("%d\n", i);
        }else{
            printf("\n");
        }
    }

    free(bf);
    return 1;
}

///
/// \brief funcao auxiliar do algoritmo de Kruskal, para percorrer as arestas e verificar se ja existe
/// \param  i vertice de origem da aresta a ser verificada
/// \param  j vertice de destino da aresta
/// \param  peso peso da aresta i indo para j
/// \param  e vetor de Aresta guardadas
/// \param  n tamanho do vetor de Aresta
/// \return 1 se existe ou 0 se nao existe 
///
int jaExiste(int i, int j, int peso, Aresta* e, int n){

    for(int k = 0; k < n; k++){

        if(((e[k].u == i && e[k].v == j) || (e[k].u == j && e[k].v == i)) && e[k].peso == peso) return 1;
    }

    return 0;
}

///
/// \brief funcao que cria as arestas
/// \param g grafo a ter suas arestas verificadas
/// \param n variavel que guarda a quantidade de arestas existentes
/// \return retorna um vetor de arestas com todas as arestas do grafo
///
Aresta* fazAresta(Grafo *g, int *n){
    Aresta* novo = (Aresta*)malloc(sizeof(Aresta)*g->total_vertices*g->total_vertices);

    int i, j, k = 0;
    // para cada aresta, cria um Aresta
    for(i = 0; i < g->total_vertices; i++){
        for(j = 0; j < g->total_vertices; j++){
            if(g->adjacentes[i][j] == 1 && !jaExiste(i, j, g->pesos[i][j], novo, k)){
                novo[k].u = i;
                novo[k].v = j;
                novo[k++].peso = g->pesos[i][j];
            }
        }
    }

    *n = k;

    novo = (Aresta*)realloc(novo, sizeof(Aresta)*k);

    return novo;
}

///
/// \brief intercala, função auxiliar do algoritmo de ordenação Merge Sort
/// \param vet, vetor a ser ordenado
/// \param inicio, indice do inicio da parte do vetor separada
/// \param meio, indice do meio do vetor partido
/// \param fim, tamanho maximo da partição
/// \return nenhum
///
void intercala(Aresta* vet, int inicio, int meio, int fim)
{
    int i, j, k;
    Aresta *vet_aux;

    //aloca o vetor
    vet_aux = malloc((fim-inicio)*sizeof(Aresta));

    i = inicio; j = meio; k = 0;

    //enquanto não for o meio ou o fim
    while( i < meio && j < fim)
    {
        //se o vetor J é maior ou igual a o vetor I, adiciona o valor de I em K, aumenta ambos
        if(vet[i].peso <= vet[j].peso)
            vet_aux[k++] = vet[i++];
        else
        {
            //se não é menor ou igual, adiciona o valor de J em K, aumenta ambos
            vet_aux[k++] = vet[j++];
        }
    }

    //enquanto não for o meio, adiciona I em K, aumenta ambos
    while (i < meio)
        vet_aux[k++] = vet[i++];

    //enquanto não for o meio, adiciona J em K, aumenta ambos
    while (j < fim)
        vet_aux[k++] = vet[j++];

    //adiciona no vetor original, o vetor K
    for(i = inicio; i < fim; i++)
        vet[i] = vet_aux[i-inicio];

    //libera o vetor auxiliar
    free(vet_aux);
}

///
/// \brief mergeSortN, algoritmo de ordenação por metodo de separar, ordenar e reajuntar e ordenar
/// \param v vetor a ser ordenado
/// \param inicio indice do inicio do vetor
/// \param fim tamanho maximo do vetor
/// \return nenhum
///
void mergeSortN(Aresta* v, int inicio, int fim)
{
    if( inicio < fim - 1)
    {
        //chama recursivamente ate tiver um vetor separado com 2 valores
        int meio = (inicio + fim) / 2;
        mergeSortN(v, inicio, meio);
        mergeSortN(v, meio, fim);
        intercala(v, inicio, meio, fim);
    }
}

///
/// \brief funcao recursiva auxiliar do algoritmo de Kruskal, para procurar o valor do conjunto do gerador
/// \param alvo indice a ser buscado o gerador
/// \param conj vetor de conjunto onde vai ser buscado
/// \return retorna o valor do indice
///
int findV(int alvo, int *conj){
    //se for oq busca, retorna o valor do indice, se não for continua buscando
    if(conj[alvo] < 0) {
        return alvo;
    }else{
        return findV(conj[alvo], conj);
    }
}

///
/// \brief funcao auxiliar do algoritmo de Kruskal para realizar a verificacao se os conjuntos u e v sao diferentes
/// \param u indice do conjunto u
/// \param v indice do conjunto v
/// \param conj vetor de conjunto 
/// \return 1 se forem diferentes e 0 caso contrario
///
int diferente(int u, int v, int *conj){
    //se forem diferentes de começo
    if(findV(u, conj) == u && findV(v, conj) == v)
        return 1;
    else{
        //se não forem, busque mais adentro
        int a = (conj[u] < 0)? u : findV(conj[u], conj), b = (conj[v] < 0)? v: findV(conj[v], conj);
        
        if(a != b) return 1;

        return 0;
    }
}

///
/// \brief funcao para realizar a troca de um valor de um certo indice para outro
/// \param u indice que participara da troca
/// \param v indice que sera trocado
/// \param conj vetor de conjunto 
/// \return nenhum
///
void troca(int u, int v, int *conj){
    int temp;

    temp = conj[u];
    conj[u] = v;
    conj[v] += temp;
}

///
/// \brief funcao auxiliar do algoritmo de Kruskal para realizar a uniao dos conjuntos u e v
/// \param u indice do conjunto u
/// \param v indice do conjunto v
/// \param conj vetor de conjunto 
/// \return nenhum
///
void Uniao(int u, int v, int *conj){

    int temp;
    // se forem o que busca
    if(findV(u, conj) == u && findV(v, conj) == v){
        // se um for maior, insere no maior, se não insere no outro
        if(conj[u] >= conj[v]){
            troca(u, v, conj);
        }else{
            troca(v, u, conj); 
        }
    }else{
        // busca o pai da arvore e insere no que for maior
        int a = findV(u, conj), b = findV(v, conj);
        if(conj[a] >= conj[b]){
            troca(a, b, conj);
        }else{
            troca(b, a, conj); 
        }
    }
}

///
/// \brief funcao do algoritmo de Kruskal
/// \param g grafo a ser buscado
/// \return 1 caso foi bem sucedido e 2 caso contrario
///
int Kruskal(Grafo *g){
    //alocando os conjuntos
    int *conj = (int *)malloc(sizeof(int)*g->total_vertices);
    
    //todos com -1
    for(int k = 0; k < g->total_vertices; k++) conj[k] = -1;

    int i, j, n, ki = 0;
    Aresta* E = fazAresta(g, &n);
    Aresta* kruskal = (Aresta*)malloc(sizeof(Aresta)*n);
    int pesoto=0;
    //ordena as arestas
    mergeSortN(E, 0, n);
    //para cada conjunto
    for(i = 0 ; i < n; i++){
        //se formam arvores diferentes, insere no vetor solucao e une as arvores
        if(diferente(E[i].u, E[i].v, conj)){
            kruskal[ki].u = E[i].u;
            kruskal[ki].v = E[i].v;
            kruskal[ki++].peso = E[i].peso;
            Uniao(E[i].u, E[i].v, conj);
            pesoto += E[i].peso;
        }
    }

    kruskal = (Aresta*)realloc(kruskal, sizeof(Aresta)*ki);
    printf("peso total: %d\n", pesoto);
    for(i = 0; i < ki; i++){
        printf("(%d,%d) ", kruskal[i].u, kruskal[i].v);
    }
    printf("\n");
}

///
/// \brief menu para a escolha dos algoritmos
/// \param g grafo onde sera realizado os algoritmos
/// \return nenhum
///
void menu_algoritmos(Grafo *g){
    int opcao, ocorreu;

    do{
        printf("******************************\n");
        printf("* 1 - Profundidade           *\n");
        printf("* 2 - Largura                *\n");
        printf("* 3 - Bellman Ford           *\n");
        printf("* 4 - Kruskal                *\n");
        printf("* 0 - Sair                   *\n");
        printf("******************************\n");
        scanf("%d", &opcao);

        if(opcao == 0){
            break;
        }

        int vertice;

        if(opcao != 4){
            vertice = vertice_origem(g);
        }

        switch(opcao){
            case 1:
                buscaProfundidade(g, vertice);
                print(visita,k);
                break;
            case 2:
                ocorreu = buscaLargura(g, vertice);
                if(ocorreu == 1) print(visita,k);
                break;
            case 3:
                //só pode se for orientado
                Bellman(g, vertice);
                break;
            case 4:
                Kruskal(g);
                break;
            default:
                break;
        }
    }while(opcao != 0);
}