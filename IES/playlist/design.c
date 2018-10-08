#include "design.h"
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

void gotoXY(int x, int y){

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicao;

    posicao.X = x;
    posicao.Y = y;

    SetConsoleCursorPosition(out, posicao);
}

void tamanho(){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT sr;
    COORD consoleSize;

    consoleSize.X = 110;
    consoleSize.Y = 30;

    //aqui vc mexe no tamanho da tela
    sr.Top = sr.Left = 0;
    sr.Right = 80;
    sr.Bottom = 15;

    SetConsoleWindowInfo(console,TRUE,&sr);
    SetConsoleScreenBufferSize(console,consoleSize);
}

void ad(){
    printf("\t*********************************************************************\n");
    printf("\t*                      Trouble Maker                                *\n");
    printf("\t* Copyright 2018                                              v 0.1 *\n");
    printf("\t*********************************************************************\n");
}

int menu(){
    int i;

    system("CLS");
    ad();
    printf("\t*********************************************************************\n");
    printf("\t|                                                                   |\n");
    printf("\t|  [1] - para adicionar uma musica.                                 |\n");
    printf("\t|  [2] - para criar uma playlist.                                   |\n");
    printf("\t|  [3] - para mostrar todas as musicas.                             |\n");
    printf("\t|  [4] - para consultar as playlist.                                |\n");
    printf("\t|  [5] - Editar uma playlist.                                       |\n");
    printf("\t|  [0] - Sair                                                       |\n");
    printf("\t|                                                                   |\n");
    printf("\t|                         Opcao:                                    |\n");
    printf("\t*********************************************************************\n");
    gotoXY(40,13);
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

void edita(){
    printf("\t*********************************************************************\n");
    printf("\t*   [0] - Caso queira voltar para o menu principal.                 *\n");
    printf("\t*   [1] - Caso queira mudar o nome de uma playlist.                 *\n");
    printf("\t*   [2] - Caso queira adicionar uma musica a uma playlist.          *\n");
    printf("\t*   [3] - Caso queira remover uma musica da playlist.               *\n");
    printf("\t*   [4] - Caso queira excluir uma playlist.                         *\n");
    printf("\t*                            Opcao:                                 *\n");
    printf("\t*********************************************************************\n");
}

void msgerro(){
    printf("\t*********************************************************************\n");
    printf("\t*                   Digite um numero valido!                        *\n");
    printf("\t*********************************************************************\n");
}

void nomesucesso(){
    system("CLS");
    printf("\t*********************************************************************\n");
    printf("\t*                  Nome alterado com sucesso!                       *\n");
    printf("\t*********************************************************************\n");
}
