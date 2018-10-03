#include "design.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoXY(int x, int y){

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicao;

    posicao.X = x;
    posicao.Y = y;

    SetConsoleCursorPosition(out, posicao);
}

void ad(){
    printf("\t*********************************************************************\n");
    printf("\t|    Trouble Maker                                                  |\n");
    printf("\t|                                                             v 0.1 |\n");
    printf("\t*********************************************************************\n");
}

int menu(){
	int i;

    system("CLS");
    ad();
    printf("\t ___________________________________________________________________\n");
    printf("\t|                                                                   |\n");
    printf("\t|  [1] - para adicionar uma musica.                                 |\n");
    printf("\t|  [2] - para criar uma playlist.                                   |\n");
    printf("\t|  [3] - para consultar as musicas.                                 |\n");
    printf("\t|  [4] - para consultar uma playlist.                               |\n");
    printf("\t|  [5] - para adicionar uma musica existente em uma playlist.       |\n");
    printf("\t|  [0] - Sair                                                       |\n");
    printf("\t|                         Opcao:                                    |\n");
    printf("\t*********************************************************************\n");
    gotoXY(40,12);
    scanf("%d",&i);

    return i;
}

void menumusic(){
    printf("\t ___________________________________________________________________\n");
    printf("\t|   Digite o titulo da musica:                                      |\n");
    printf("\t|   Digite o cantor da musica:                                      |\n");
    printf("\t|   Digite o autor da musica:                                       |\n");
    printf("\t|   Digite o genero da musica:                                      |\n");
    printf("\t|   Digite o ano de lancamento:                                     |\n");
    printf("\t|   Digite a duracao da musica,por exemplo 2:30:                    |\n");
    printf("\t|   Digite a avaliacao (de 0 a 5):                                  |\n");
    printf("\t|___________________________________________________________________|\n");
}

void menuout(){
	printf("\t __________________________________________________________________\n");
    printf("\t|                   Deseja mesmo sair?                             |\n");
    printf("\t|                    [1]-Sim  [0]-Nao                              |\n");
    printf("\t|                                                                  |\n");
    printf("\t|__________________________________________________________________|\n");
}

void msgout(){
    printf("\t __________________________________________________________________\n");
    printf("\t|           Agradecemos por usar nosso aplicativo!                 |\n");
    printf("\t|                          Volte sempre                            |\n");
    printf("\t|__________________________________________________________________|\n");
}
