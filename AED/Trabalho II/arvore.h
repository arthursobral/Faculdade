#ifndef ARVORE_H
#define ARVORE_H
#include <stdlib.h>
#include <stdio.h>
#define MAX 100

#include "menu.h"

//estrutura para guardar o cabeçalho da arvore no arquivo arvore.bin
typedef struct cabecalho{
	int topo; //primeira posição não usada no fim do arquivo
	int raiz; //começo da arvore
	int livre; //posição do inicio da lista de nós livres
}Cabecalho;

//estrutura para guardar os dados do livro no arquivo livros.bin
typedef struct livro{
	int codigo;
	char titulo[MAX];
	char autor[MAX];
	int qtd;
}Livros;

//estrutura para guardar o código do livro e sua posição no nó da arvore
typedef struct info{
	int codigo;
	int posicao;
}Infos;

//estrutura para guardar o nó da arvore no arquivo arvore.bin
typedef struct arv{
	Infos registro;
	int dir;
	int esq;
	int posicao;
} Arvore;

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

///
/// \brief verifica se o char eh ou nao um espaco ou um \t ou um \n
/// \param um caracter a ser verificado
/// \retorna 1 se for espaco, '\n' ou '\t' e 0 caso contrario
///
int verifica_espaco(char c);

///
/// \brief retira os espacos extras no comeco e no final da string
/// \param a string a ser verificada
///

void retira_espaco(char s[]);

///
/// \brief transforma o que foi lido do cmd para string 
/// \param argv: uma constante contendo o que foi lido do cmd
/// \return retorna a constante em forma de string
///
char *nome_Arq(char const *argv[]);

///
/// \brief funcao que insere uma estrutura do tipo CabecalhoLivro na primeira posicao do arquivo livros.bin
/// \param livrosBin: arquivo dos livros
/// \param livro: cabecalho do arquivo dos livros
///
void escr_cab_livro(FILE *livrosBin, CabecalhoLivro *livro);
///
/// \brief funcao para inicializar o cabecalho dos livros
/// \param livrosBin: arquivo dos livros
///
void cria_cabe_livro(FILE *livrosBin);

///
/// \brief funcao que escreve o cabeçalho do arquivo da arvore
/// \param arvoreBin: arquivo da arvore
/// \param arvore: cabeçalho do arquivo da arvore
///
void escr_cab_arv(FILE *arvoreBin, Cabecalho *arvore);

///
/// \brief funcao para inicializar o caçalho da arvore
/// \param arvoreBin: arquivo da arvore
///
void cria_cabe_arv(FILE *arvoreBin);

///
/// \brief funcao que le os livros do arquivo do livros
/// \param livrosBin: arquivo dos livros
/// \param pos: posicao do livro no arquivo dos livros
/// \return retorna o livro da posição lida no arquivo
///
Livros* le_livros(FILE *livrosBin, int pos);

///
/// \brief funcao que le os nós da arvore do arquivo arvore.bin
/// \param arvoreBin: arquivo da arvore
/// \param pos: posicao do nó no arquivo da arvore
/// \return retorna o nó da posição lida no arquivo
///
Arvore* le_nos(FILE *arvoreBin, int pos);

///
/// \brief funcao que le o cabeçalho do arquivo livros.bin 
/// \param livrosBin: arquivo dos livros
/// \return o cabeçalho lido do arquivo
///
CabecalhoLivro* le_cab_livro(FILE *livrosBin);

///
/// \brief funcao que le o cabeçalho do arquivo arvore.bin 
/// \param arvoreBin: arquivo da arvore
/// \return o cabeçalho lido do arquivo
///
Cabecalho* le_cab_arvore(FILE *arvoreBin);

///
/// \brief funcao que inicializa uma variavel do tipo Livros
/// \return variavel inicializada
///
Livros* inicializa_livro();

///
/// \brief funcao que inicializa uma variavel do tipo Arvore
/// \return variavel inicializada
///
Arvore* inicializa_arvore();

int retira(FILE* arvoreBin, FILE* livrosBin, int codigo, Arvore* raiz);

int pega_livro(Livros* l[], int id, FILE*arvoreBin, FILE*livrosBin, Arvore* raiz);

NoLivre* cria_no_livre();

void escreve_no_livres(FILE* arvoreBin, Cabecalho* cab, Arvore* arv);

LivroLivre* cria_livro_livre();

void escreve_livro_livres(FILE* arvoreBin, CabecalhoLivro* cab, int pos);

///
/// \brief funcao que pega o nó da posição passada como parametro
/// \param arvoreBin: arquivo da arvore
/// \param pos: posição do nó livre
/// \return nó livre
///
NoLivre* pega_no_livre(FILE *arvoreBin, int pos);

///
/// \brief funcao que pega o livro da posição passada como parametro
/// \param livrosBin: arquivo dos livros
/// \param pos: posição do livro livre
/// \return livro livre
///
LivroLivre* pega_livros_livres(FILE *livrosBin, int pos);

///
/// \brief funcao que escreve o livro no arquivo dos livros
/// \param livrosBin: arquivo dos livros
/// \param cab_livro: cabeçalho do arquivo dos livros
/// \param livro: livro a ser escrito
/// \return posição de onde foi escrito no arquivo
///
int escreve_livro(FILE *livrosBin, CabecalhoLivro *cab_livro, Livros *livro);

///
/// \brief funcao que escreve o nó da arvore no arquivo arvore.bin
/// \param arvoreBin: arquivo da arvore
/// \param no: nó da arvore a ser escrita
/// \param arvore: cabeçalho do arquivo da arvore
/// \return posição do nó escrito no arquivo
///
int escreve_arvore(FILE *arvoreBin, Arvore *no, Cabecalho *arvore);

///
/// \brief funcao que insere no arquivo da arvore um nó contendo as informações do livro
/// \param arvoreBin: arquivo da arvore
/// \param codigo: codigo do livro a ser inserido
/// \param pos: posição do livro no arquivo livros.bin
///
void insere(FILE *arvoreBin, int codigo, int pos);

void remover(FILE* arvoreBin, FILE* livrosBin);

///
/// \brief função para ler uma linha do arquivo texto e inserir nos arquivos binários
/// \param livrosBin: arquivo dos livros
/// \param arvoreBin: arquivo da arvore
/// \param linhaArq: string que contém o nome do arquivo
///
void le_arq(FILE *livrosBin, FILE *arvoreBin, char *linhaArq);


void leStd(FILE *livrosBin, FILE *arvoreBin);

void printa_livro(Livros *l);

///
/// \brief função que printa os livros dentro do arquivo de livros
/// \param livrosBin: arquivo dos livros
///
void printa_arq(FILE *livrosBin);

///
/// \brief função que printa o nó atual e chama recursivamente os filhos
/// \param arvoreBin: arquivo da arvore
/// \param raiz: nó a ser impresso
///
void printa_no(FILE* arvoreBin, Arvore* raiz);

///
/// \brief função que le o cabeçalho e chama a função de printar os nós
/// \param arvoreBin: arquivo da arvore
///
void printa_arv(FILE* arvoreBin);

void inordem(FILE *arvoreBin, FILE *livrosBin, Arvore *raiz,Livros *livro);

void printa_inordem(FILE *arvoreBin, FILE *livrosBin);

int altura(FILE *arvoreBin,Arvore *raiz);

void imprime(FILE *arvoreBin, Arvore *raiz, int nivel);

void imprime_nivel(FILE *arvoreBin);

Arvore* busca_no(FILE *arvoreBin,Arvore *r,int p);

void buscar(FILE *arvoreBin,FILE *livrosBin);

void atualiza(FILE *arvoreBin,FILE *livrosBin);

#endif 