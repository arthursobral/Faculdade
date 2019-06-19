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

///
/// \brief printa o menu para escolhas de visualizacao da biblioteca
/// \return retorna a opcao escolhida
///
int menu_print();

///
/// \brief mensagem de erro caso a opcao escolhida nao exista
///
void erro_op();

void menu_insere();

void msg_sucess();

int menu_remove();

void msg_sucess_r();

#endif