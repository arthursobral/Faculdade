#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <conio.h>
#include "maker.h"
#include "design.h"
#include<locale.h>
#include"cadastro.h"
#define MAX 100
#define MAXP 30

int main(){
    system("color F1");
    tamanho();
    int opcao = 1;
    while(opcao){
        system("cls");
        printf("\t*********************************************************************\n");
        printf("\t*                             Vibee                            v 0.1*\n");
        printf("\t*********************************************************************\n");
        printf("\t|                                                                   |\n");
        printf("\t| Opcao:                                                            |\n");
        printf("\t| [1]|Login                                                         |\n");
        printf("\t| [2]|Cadastro                                                      |\n");
        printf("\t| [0]|Sair                                                          |\n");
        printf("\t|                                                                   |\n");
        printf("\t*********************************************************************\n");
        printf("\t*                                                     Troublemakers *\n");
        printf("\t*********************************************************************\n");
        gotoXY(16,4);
        scanf("%d",&opcao);
        switch (opcao){
            case 1:
                //login();
                system("color F1");
                tamanho();
                int caso;
                int tam=0,tamp=0;
                Music musicas[MAX];
                Playlist play[MAXP];

                APP:system("CLS");
                caso = menu();

                while(caso != 0){
                    switch (caso){
                        case 0:
                            return 0;
                        case 1:
                            add(musicas,tam);
                            if(repetida(musicas,tam,musicas[tam])){
                                printf("\t ___________________________________________________________________\n");
                                printf("\t|                 Musica ja existente.                              |\n");
                                printf("\t|___________________________________________________________________|\n");
                                system("PAUSE");
                            }
                            else{
                                gotoXY(0,12);
                                printf("\t *******************************************************************\n");
                                printf("\t|                   Musica adicionada com sucesso!                  |\n");
                                printf("\t *******************************************************************\n");
                                system("PAUSE");
                                tam++;
                            }
                                break;
                        case 2:
                            criaplaylist(play,tamp,musicas,tam);
                            tamp++;
                            break;
                        case 3:
                            printamusic(musicas,tam);
                            system("PAUSE");
                            break;
                        case 4:
                            consultarplaylist(play,tamp);
                            system("PAUSE");
                            break;
                        case 5:
                            editaplay(play,tamp,musicas,tam);
                            break;
                        case 6:
                            if(tamp == 0){
                                msgerroplay();
                                system("PAUSE");
                            }
                            else{
                                excluiplay(play,tamp);
                                tamp--;
                                break;
                            }
                        }
                    caso = menu();
                }
                system("CLS");

                menuout();

                gotoXY(37,3);
                scanf("%d",&caso);

                if(caso==0){
                    goto APP;
                }
                system("CLS");
                msgout();
                break;
            case 2:
                cadastramento();
                break;
        }
    }
    system("CLS");
    avalia();
    msgout();
    system("PAUSE");
    return 0;
}
