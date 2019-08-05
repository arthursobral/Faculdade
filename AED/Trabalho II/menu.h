#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

///
/// \brief move o cursor dado uma coordenada x e y
/// \param coordenada x
/// \param coordenada y
/// \post o cursor vai para a coordenadas passada
///
void gotoXY(int x,int y);

///
/// \brief printa o menu principal
/// \return retorna a opcao escolhida
///
int menu_ini();

void menu_insere_livro();

int opcao_print();

void msg_sucess_list();

int procurado();

int atualiza_qtd_msg();

#endif