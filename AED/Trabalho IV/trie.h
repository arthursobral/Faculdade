#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#define ALFABETO 26

typedef struct trie{
	struct trie *filhos[ALFABETO];
	int final;
}Trie;

///
/// \brief transforma o que foi lido do cmd para string 
/// \param argv: uma constante contendo o que foi lido do cmd
/// \return retorna a constante em forma de string
///
char *nome_Arq(char const *argv[]);

///
/// \brief verifica se nao existe acento ou um caracter fora do alfabeto, enquanto transforma as maisculas em minusculas
/// \param s: a palavra a ser verificada caracter por caracter
/// \return retorna 1 caso esteja tudo certo com a palavra 0 caso ao contrario
/// \pre nenhuma
/// \pos nenhuma
///
int verifica(char s[]);

///
/// \brief inicializa a varivel
/// \return retorna a trie inicializada
/// \pre variavel inexistente
/// \pos variavel existente
///
Trie *inicializa();

///
/// \brief insere a palavra na trie
/// \param raiz: raiz da trie
/// \param s: palavra a ser inserida
/// \pre nenhuma
/// \pos trie com a palavra inserida
///
void insere(Trie *raiz, char *s);

///
/// \brief puxa do arquivo para inserir a palavra na trie
/// \param raiz: raiz da trie
/// \param dicionario: arquivo contendo todas as palavras a serem inseridas
/// \pre nenhuma
/// \pos trie com as palavras inseridas
///
void insere_arq(Trie *raiz,FILE *dicionario);

///
/// \brief printa o dicionario inserido
/// \param raiz: raiz da trie
/// \param palavra: palavra a ser incrementada para ser printada
/// \param indice: posicao onde o caracter vai na palavra
/// \pre trie inicializada com pelo menos uma palavra, ou seja, nao vazia
/// \pos nenhuma
///
void printa(Trie *raiz, char palavra[],int indice);

///
/// \brief verifica se o nó passado tem algum filho
/// \param raiz: raiz da trie
/// \return retorna 1 se ele acha algum filho, 0 caso o contrario
/// \pre nenhuma
/// \pos nenhuma
///
int verifica_filho(Trie *raiz);

///
/// \brief remove a palavra da trie
/// \param raiz: raiz da trie
/// \param s: palavra a ser removida
/// \return 1 para deletar os pais e 0 para nao deletar os pais
/// \pre nenhuma
/// \pos trie com a palavra removida
///
int remover(Trie **raiz, char *s);

///
/// \brief puxa do arquivo para remover as palavras da trie
/// \param raiz: raiz da trie
/// \pre nenhuma
/// \pos trie com as palavras removidas
///
void remove_stopwords(Trie **raiz);

///
/// \brief funcao auxiliar para a semelhantes, mesma coisa que o printa porém printa no max dez palavras
/// \param raiz: raiz da trie
/// \param s: palavra a ser incrementada para printar
/// \param indice: onde ira ser incrementado o caracter na palavra
/// \param contador: contador de 0 ate 9 para printar no maximo dez palavras
/// \pre nenhuma
/// \pos nenhuma
///
void printa_aux(Trie *raiz, char palavra[],int indice,int *contador);

///
/// \brief verifica se sao palavras semelhantes
/// \param s1: string contendo a palavra
/// \param s2: string contendo o prefixo
/// \param dife: o total maximo que pode ter de diferença entre a palavra e o prefixo
/// \return 0 caso a nao serem semelhantes conforme a variavel dife e 1 caso o contrario
/// \pre nenhuma
/// \post nenhuma
///
int semelhantes(char* s1, char* s2, int dife);

///
/// \brief funcao auxiliar para a semelhantes
/// \param raiz: raiz da trie
/// \param palavra: palavra a ser incrementada para printar
/// \param prefix: prefixo para comparar a diferenca entre a palavra
/// \param indice: onde ira ser incrementado o caracter na palavra
/// \param dife: total de diferença entre a palavra e o prefix  
/// \pre nenhuma
/// \pos nenhuma
///
void printa_semelhantes(Trie *raiz, char *palavra, char *prefix, int indice,int dife);

///
/// \brief funcao para a chamada da funcao semelhantes
/// \param raiz: raiz da trie
/// \pre trie nao vazia
/// \post nenhuma
///
void chama_semelhantes(Trie *raiz);

#endif