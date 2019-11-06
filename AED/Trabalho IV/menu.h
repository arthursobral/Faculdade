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
void gotoXY(int x,int y){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicao;

	posicao.X = x;
	posicao.Y = y;

	SetConsoleCursorPosition(out,posicao);
}

///
/// \brief printa o menu principal
/// \return retorna a opcao escolhida
///
int menu_ini(){
	int n;

	system("cls");
	printf("+------------------------------------+\n");
	printf("|            Menu principal          |\n");
    printf("+------------------------------------+\n");
    printf("| 1 - Imprimir                       |\n");
    printf("| 2 - Consultar Palavra              |\n");
    printf("| 3 - Remover                        |\n");
    printf("| 0 - Sair                           |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    gotoXY(18,7);
    scanf("%d",&n);

    return n;
}

void msg_sucess(){
    system("CLS");
    printf("+------------------------------------+\n");
    printf("|      Remocao feita com sucesso     |\n");
    printf("+------------------------------------+\n");
}

void erro(){
    system("CLS");
    printf("+------------------------------------+\n");
    printf("|                 Erro               |\n");
    printf("+------------------------------------+\n");
}

void menu_semelhantes(){
    printf("+------------------------------------+\n");
    printf("|      Digite o prefixo desejado:    |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
}

void erro_prefix(){
    printf("+------------------------------------+\n");
    printf("|        Prefixo inesxistente        |\n");
    printf("+------------------------------------+\n");
}

void msg_dicionario(){
    printf("+------------------------------------+\n");
    printf("|         Dicionario                 |\n");
    printf("+------------------------------------+\n");    
}

#endif