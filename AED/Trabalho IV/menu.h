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
/// \brief printa msg de remocao com sucesso
///
void msg_sucess();

///
/// \brief printa msg de erro
///
void erro();

///
/// \brief printa menu para consultar a palavra
///
void menu_consultar();

///
/// \brief printa erro no prefixo
///
void erro_prefix();

///
/// \brief printa dicionario
///
void msg_dicionario();

///
/// \brief menu remove
///
void menu_remove();

///
/// \brief printa se o arquivo esta vazio
///
void erro_arq();

#endif