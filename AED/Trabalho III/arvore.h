#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#define ORDEM 5
#define MAX 100


//estrutura para guardar os dados do livro no arquivo livros.bin
typedef struct livro{
	int codigo;
	char titulo[MAX];
	char autor[MAX];
	int qtd;
}Livros;

//estrutura para guardar o cabeçalho dos livros no arquivo livros.bin
typedef struct CabecalhoLivro{
	int topo;
	int livre;
}CabecalhoLivro;

//estrutura para o nó livre do arquivo arvore.bin
typedef struct nolivre{
	int prox;
}NoLivre;

//estrutura para o livro livre do arquivo livros.bin
typedef struct livrolivre{
	int prox;
}LivroLivre;

//estrutura para guardar o cabecalho do arquivo da arvore
typedef struct cabe{
	int topo;
	int raiz;
	int livre;
}Cabecalho;

//estrutura de um nó de uma arvore b+
typedef struct nodeBmais{
	int chaves[ORDEM];
	int filho[ORDEM+1];
	int eh_folha;
	int numChaves;
	int pai;
}BMais;

///
/// \brief funcao que diz se houve um overflow no nó, ou seja, se o numero de chaves ultrapassou a quantidade maxima permitida
/// \param r: nó da arvore
/// \return retorna 1 caso houve ovewflow e 0 caso nao houve
/// \pre o nó r deve ter sido alocado
/// \pos nenhuma
///
int overflow(BMais *r);

///
/// \brief verifica se o char eh ou nao um espaco ou um \t ou um \n
/// \param um caracter a ser verificado
/// \retorna 1 se for espaco, '\n' ou '\t' e 0 caso contrario
/// \pre nenhuma
/// \pos nenhuma
///
int verifica_espaco(char c);
///
/// \brief retira os espacos extras no comeco e no final da string
/// \param a string a ser verificada
/// \pre nenhuma
/// \pos espaços extras sao retirados da string
///
void retira_espaco(char s[]);

///
/// \brief transforma o que foi lido do cmd para string 
/// \param argv: uma constante contendo o que foi lido do cmd
/// \return retorna a constante em forma de string
/// \pre nenhuma
/// \pos nenhuma
///
char* nomeArq(char const *argv[]);

///
/// \brief funcao que inicializa uma variavel do tipo Livros
/// \return variavel inicializada
/// \pre nenhuma
/// \pos variavel inicializada
///
Livros* inicializa_livro();

///
/// \brief funcao que le o cabeçalho do arquivo livros.bin 
/// \param livrosBin: arquivo dos livros
/// \return o cabeçalho lido do arquivo
/// \pre nenhuma
/// \pos nenhuma
///
CabecalhoLivro* le_cab_livro(FILE *livrosBin);

///
/// \brief funcao que insere uma estrutura do tipo CabecalhoLivro na primeira posicao do arquivo livros.bin
/// \param livrosBin: arquivo dos livros
/// \param livro: cabecalho do arquivo dos livros
/// \pre nenhuma
/// \pos cabeçalho inserido no arquivo
///
void escr_cab_livro(FILE *livrosBin, CabecalhoLivro *livro);

///
/// \brief funcao que pega o livro da posição passada como parametro
/// \param livrosBin: arquivo dos livros
/// \param pos: posição do livro livre
/// \return livro livre
/// \pre nenhuma 
/// \pos nenhuma
///
LivroLivre* pega_livros_livres(FILE *livrosBin, int pos);

///
/// \brief funcao que escreve o cabecalho do arquivo na arvore
/// \param arvorebin: arquivo da arvore
/// \param arvore: cabecalho a ser escrito
/// \pre arvore nao pode estar vazia
/// \pos cabecalho escrito no arquivo
///
void escr_cabe_bmais(FILE *arvorebin, Cabecalho *arvore);

///
/// \brief funcao para inicializar o cabecalho dos livros
/// \param livrosBin: arquivo dos livros
/// \pre nenhuma
/// \pos cabeçalho inicializado
///
void cria_cabe_livro(FILE *livrosBin);

/// 
/// \brief funcao para iniciliazar o cabecalho da arvore
/// \param arvorebin: arquivo dos indices da arvore
/// \pre arquivo criado ou aberto
/// \pos arquivo preenchido com o cabecalho
///
void cria_cabe_bmais(FILE *arvorebin);

///
/// \brief funcao que inicializa uma variavel do tipo Arvore
/// \return variavel inicializada
/// \pre nenhuma
/// \pos variavel inicializada
///
BMais* inicializa_arvore();

///
/// \brief funcao que pega o nó da posição passada como parametro
/// \param arvoreBin: arquivo da arvore
/// \param pos: posição do nó livre
/// \return nó livre
/// \pre nenhuma
/// \pos nenhuma
///
NoLivre* pega_no_livre(FILE *arvoreBin, int pos);

///
/// \brief funcao auxiliar que escreve a arvore no arquivo binario
/// \param arvoreBin: arquivo da arvore
/// \param raiz: no da arvore a ser escrita
/// \param pos: posicao onde ele sera escrito no arquivo
/// \pre arquivo aberto
/// \pos arquivo preenchido com o no da arvore
///
void escreve_arvore_aux(FILE *arvorebin, BMais *raiz, int pos);

///
/// \brief funcao que escreve o nó da arvore no arquivo arvore.bin
/// \param arvoreBin: arquivo da arvore
/// \param no: nó da arvore a ser escrita
/// \param arvore: cabeçalho do arquivo da arvore
/// \return posição do nó escrito no arquivo
/// \pre nenhuma
/// \pos nó da arvore escrita no arquivo
///
int escreveArvore(FILE *arvoreBin, BMais *no, Cabecalho *arvore);

///
/// \brief funcao que o nó da arvore do arquivo arvore.bin
/// \param arvorebin: arquivo da arvore
/// \param posicao: posicao do nó no arquivo da arvore
/// \return nó da posicao lida no arquivo
/// \pre nenhuma
/// \pos nenhuma
///
BMais* le_noh(FILE *arvorebin, int posicao);

///
/// \brief funcao que le o cabeçalho do arquivo arvore.bin 
/// \param arvorebin: arquivo da arvore
/// \return cabeçalho lido do arquivo
/// \pre nenhuma
/// \pos cabeçalho do arquivo lido
///
Cabecalho* le_cab_arvore(FILE *arvorebin);

///
/// \brief funcao que escreve o livro no arquivo dos livros
/// \param livrosBin: arquivo dos livros
/// \param cab_livro: cabeçalho do arquivo dos livros
/// \param livro: livro a ser escrito
/// \return posição de onde foi escrito no arquivo
/// \pre nenhuma
/// \pos livro escrito no arquivo dos livros
///
int escreve_livro(FILE *livrosBin, CabecalhoLivro *cab_livro, Livros *livro);

///
/// \brief funcao que le os livros do arquivo do livros
/// \param livrosBin: arquivo dos livros
/// \param pos: posicao do livro no arquivo dos livros
/// \return retorna o livro da posição lida no arquivo
/// \pre nenhuma
/// \pos livros do arquivo lidos
///
Livros* le_livros(FILE *livrosBin, int pos);

///
/// \brief funcao que printa as informações do livro passado como parametro
/// \param l: array do tipo Livros que contem as informações do livro
/// \pre livro deve existir
/// \pos nenhuma
///
void printa_livro(Livros *l);

///
/// \brief funcao que imprime as informacoes do livro
/// \param arvorebin: arquivo binario da arvore
/// \param livrosbin: arquivo binario dos livros
/// \pre nenhuma
/// \pos nenhuma
///
void imprime_acervo(FILE *arvorebin, FILE *livrobin);

///
/// \brief funcao que verifica se o nó existe na posicao passada e informa a posicao em que ele deve ser inserido no vetor
/// \param raiz: nó onde a chave vai ser inserida
/// \param codigo: codigo do livro do nó a ser inserido
/// \param pos: posicao do nó
/// \return 1 caso exista, 0 caso nao exista
/// \pre nenhuma
/// \pos informa a posicao do nó aonde deve ser inserido
///
int busca(BMais *raiz, int codigo, int *pos);

//colocar antes do remove
void seta_pai(FILE *arvorebin, int pos, int pos_pai);

//seta_pai(arvorebin,cab->raiz,cab->raiz);

///
/// \brief funcao que adiciona a chave a ser inserida na direita do nó
/// \param raiz: nó onde a chave vai ser inserida
/// \param pos: posicao do livro no vetor onde vai ser inserido
/// \param codigo: codigo do livro a ser inserido
/// \param pos_livro: posicao do vetor onde foi inserido
/// \pre nenhuma
/// \pos chave é adicionada no nó
///
void adiciona_direita(BMais *raiz, int pos, int codigo, int pos_livro);

///
/// \brief funcao que faz o split de um nó
/// \param arvoreBin: arquivo binário da arvore
/// \param raiz: nó onde deseja fazer o split
/// \param m: chave do meio do nó
/// \param pos: posicao da chave no vetor
/// \return o nó pai do nó onde foi feito o split
/// \pre nenhuma
/// \pos split do nó é feito
///
BMais *split(FILE *arvoreBin, BMais *raiz, int *m, int pos);

///
/// \brief funcao auxiliar que insere a chave no nó caso ja tenha uma raiz
/// \param arvoreBin: arquivo binário da arvore
/// \param pos_livro: posicao do vetor onde foi inserido a chave
/// \param codigo: codigo do livro a ser inserido
/// \param pos_raiz: posicao do nó no arquivo da arvore
/// \pre nenhuma
/// \pos 
///
void insere_aux(FILE *arvoreBin, int pos_livro, int codigo, int pos_raiz);

///
/// \brief funcao principal de inserção da chave no nó
/// \param arvoreBin: arquivo binário da arvore
/// \param codigo: codigo do livro a ser inserido
/// \param pos_livro: posicao do vetor onde o livro vai ser inserido
/// \param cab: cabeçalho do arquivo da arvore
/// \pre nenhuma
/// \pos livro inserido
///
void insere(FILE *arvoreBin, int codigo, int pos_livro, Cabecalho *cab);

///
/// \brief funcao que le do teclado as informações do livro a ser inserido e escreve nos arquivos binarios
/// \param livrosBin: arquivo binario dos livros
/// \param arvoreBin: arquivo binario da arvore
/// \pre nenhuma
/// \pos informacoes do livro escritas nos arquivos
///
void leStd(FILE *livrosBin, FILE *arvoreBin);

///
/// \brief função para ler uma linha do arquivo texto e inserir nos arquivos binários
/// \param livrosBin: arquivo dos livros
/// \param arvoreBin: arquivo da arvore
/// \param linhaArq: string que contém o nome do arquivo
/// \pre nenhuma
/// \pos linha inserida nos arquivos binarios
///
void le_arq(FILE *livrosBin, FILE *arvoreBin, char *linhaArq);

///
/// \brief funcao auxiliar que printa a arvore
/// \param arvoreBin: arquivo binario da arvore
/// \param raiz: nó atual a ser printado
/// \param pos: posicao do nó da arvore
/// \pre arvore nao pode ser vazia
/// \pos nenhuma
///
void printa_arv_aux(FILE *arvorebin, BMais *raiz, int pos);

///
/// \brief funcao principal que printa a arvore
/// \param arvoreBin: arquivo binario da arvore
/// \pre nenhuma
/// \pos nenhuma
///
void printa_arv(FILE *arvorebin);

///
/// \brief funcao que calcula a altura da arvore
/// \param arvoreBin: arquivo binario da arvore
/// \return altura da arvore
/// \pre nenhuma
/// \pos nenhuma
///
int altura(FILE *arvorebin);

///
/// \brief funcao para printar o codigo dos livros
/// \param raiz: no a ser printado
/// \pre a raiz nao estar nula
/// \post nenhuma
///
void print_aux(BMais *raiz);

///
/// \brief funcao auxiliar que imprime a arvore por nivel
/// \param arvoreBin: arquivo binario da arvore
/// \param raiz: nó atual da arvore
/// \param nivel: numero de niveis da arvore
/// \param i: contador para verificar se todos os niveis foram printados
/// \pre nenhuma
/// \pos nenhuma
///
void imprime_nivel_aux(FILE *arvorebin, BMais *raiz, int nivel, int i);

///
/// \brief funcao que imprime a arvore por nivel
/// \param arvoreBin: arquivo binario da arvore
/// \pre nenhuma
/// \pos nenhuma
///
void imprime_nivel(FILE *arvorebin);

///
/// \brief funcao auxliar que busca o codigo do livro
/// \param arvorebin: arquivo da arvore
/// \param raiz: nó da arvore onde está procurando a chave
/// \param codigo: codigo do livro a ser procurado
/// \param pos: posicao do vetor onde vai ser inserido o livro
/// \return nó do livro buscado
/// \pre nenhuma
/// \pos nenhuma
///
BMais* busca_aux(FILE *arvorebin, BMais *raiz, int codigo, int *pos);

///
/// \brief funcao que busca o codigo do livro a ser procurado
/// \param arvorebin: arquivo da arvore
/// \param livrosbin: arquivo dos livros
/// \pre o codigo deve ser um numero valido, maior que 0
/// \pos mostra as informações do livro procurado, se ele existir
///
void busca_(FILE *arvorebin, FILE *livrosbin);
///
/// \brief funcao que atualiza a quantidade de exemplares do livro
/// \param livrosBin: arquivo binario dos livros
/// \param arvoreBin: arquivo binario da arvore
/// \pre nenhuma
/// \pos quantidade de exemplares do livro atualizada
///
void atualiza(FILE *arvorebin, FILE *livrosbin);

///
///	\brief cria um novo no livre
/// \return um novo no livre inicializado
///
NoLivre* cria_no_livre();

///
/// \brief reescreve o no da arvore para remove-lo do arquivo
/// \param arvorebin: arquivo com os nos da arvore
/// \param pos: onde ele se encontra
///
void remove_arvore(FILE *arvorebin,int pos);

///
///	\brief cria um livro livre
/// \return um livro livre inicializado
///
LivroLivre* cria_livro_livre();

/// 
/// \brief funcao para escrever um livro livre
/// \param livrosbin: arquivo com os livros
/// \param pos: onde ele vai ser escrito
///
void escreve_livro_livres(FILE* livrosbin, int pos);

///
///	\brief funcao para retornar o minimo da arvore
/// \param arvorebin: arquivo com os nos da arvore
/// \param pos: onde ele se encontra
///
int minimo(FILE *arvorebin,int pos);

///
/// \brief funcao para arrumar a arvore
/// \param arvorebin: arquivo com os nos da arvore
/// \param pos: onde ele se encontra
/// \param codigo: codigo do elemento a ser retirado
///
void arruma_arvore(FILE *arvorebin,int pos, int codigo);

///
/// \brief funcao para verificar o underflow
/// \param raiz: nó a ser verificado
/// \return retorna 0 caso nao tenha underflow e 1 caso contrario
///
int underflow(BMais *raiz);

///
/// \brief funcao para buscar aonde o codigo se encontra no vetor
/// \param raiz: nó a ser verificado
/// \param codigo: codigo do elemento a ser encontrado
///
int busca_vet(BMais *raiz, int codigo);

///
/// \brief funcao para retirar o elemento na posicao pos
/// \param raiz: nó a ser modificado
/// \param pos: onde ele se encontra
///
void retira_direita(BMais *raiz, int pos);

///
/// \brief funcao para emprestar de um irmao para o outro
/// \param arvorebin: arquivo que contem todos os nos da arvore
/// \param pos_mod: posicao do no a ser modificado
/// \param pai: pai para saber quais sao os irmaos
/// \param pos_vet: posicao do vetor que se encontra o no responsavel para localizar os irmaos
///
int empresta(FILE *arvorebin, int pos_mod, BMais *pai, int pos_vet);

///
/// \brief funcao para fazer o merge
/// \param arvorebin: arquivo que contem todos os nos da arvore
/// \param pos_mod: posicao do no a ser modificado
/// \param pos_irmao: posicao do irmao
/// \param lado_new: onde ele vai ser adicionado
/// \param codigo: elemento a ser removido
///
void merge(FILE *arvorebin, int pos_mod, int pos_irmao, int lado_new, int codigo);

///
/// \brief funcao auxliar no remover
/// \param arvorebin: arquivo q contem todos os nos da arvore
///	\param codigo: elemento a ser removido
/// \param pos: posicao da raiz
/// 
int remove_aux(FILE *arvorebin, int codigo, int pos);

///
/// \brief funcao auxliar no remover
/// \param arvorebin: arquivo q contem todos os nos da arvore
///	\param livrosbin: arquivo q contem todos os livros
/// 
void remover(FILE *arvorebin, FILE *livrosbin);

#endif