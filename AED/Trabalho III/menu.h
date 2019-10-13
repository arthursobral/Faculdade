#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>


///
/// \brief funcao que move o cursor dado uma coordenada x e y
/// \param coordenada x: coordenada em relação ao eixo horizontal
/// \param coordenada y: coordenada em relação ao eixo vertical
/// \pre nenhuma
/// \pos o cursor vai para as coordenadas passadas como parametro
///
void gotoXY(int x,int y);

///
/// \brief funcao que printa o menu principal
/// \return retorna a opcao escolhida
/// \pre nenhuma
/// \pos nenhuma
///
int menu_ini();

///
/// \brief funcao que printa o menu para ler as informações do livro a ser inserido
/// \pre nenhuma
/// \pos nenhuma
///
void menu_insere_livro();
///
/// \brief funcao que printa o menu para escolher o tipo de impressão
/// \pre nenhuma
/// \pos nenhuma
///
int opcao_print();

///
/// \brief funcao que printa uma mensagem dizendo que a listagem foi gerada com sucesso
/// \pre nenhuma
/// \pos nenhuma
///
void msg_sucess_list();

///
/// \brief funcao que printa uma mensagem dizendo que o elemento nao foi encontrado
/// \pre nenhuma
/// \pos nenhuma
///
void nao_encontrado();

///
/// \brief funcao que printa o menu para ler o codigo do livro a ser procurado
/// \pre nenhuma
/// \pos nenhuma
///
int procurado();

///
/// \brief funcao que printa o menu para ler a quantidade nova de exemplares de um livro
/// \pre nenhuma
/// \pos nenhuma
///
int atualiza_qtd_msg();

///
/// \brief funcao que printa uma mensagem dizendo que a arvore esta vazia
/// \pre nenhuma
/// \pos nenhuma
///
void erro_arvore_empty();

int menu_remove();

#endif