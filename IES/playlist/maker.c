#include "maker.h"
#include "design.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <conio.h>
#define MAX 100
#define MAXP 30

void consultarplaylist(Playlist play[],int tam){
    int i;

    for(i=0;i<tam;i++){
        printf("[%d]Playlist de %s: %s\n",i+1,play[i].dono,play[i].titulo);
    }
}

void addnaplaylist(Playlist play[],int ip,Music musicas[],int im){
    int escolhap;

    consultarplaylist(play,ip);

    system("CLS");
    printf("\tLista de playlist existentes:\n");
    printf("\tDeseja adicionar em qual playlist?\n");

    scanf("%d",&escolhap);
}

void printaplay(Playlist play[], int t){
    int i;

    for(i=0;i<play[t].tamanho;i++){
        printf("[%d] %s - %s\n",i,play[t].musicas[i].titulo,play[t].musicas[i].cantor);
    }
}

int consultarmusic(Music musicas[],int tam){
    int i=0;

    printf("\n");
    if(tam==0){
        printf("\t ___________________________________________________________________\n");
        printf("\t|            Nao contem nenhuma musica no momento.                  |\n");
        printf("\t|___________________________________________________________________|\n");
        return 0;
    }else{
        printf("\n");
        printf("\t ___________________________________________________________________\n");
        for(i=0;i<tam;i++){
                printf("\t|[%d] -> %s - %s",i,musicas[i].titulo,musicas[i].cantor);
                printf("\n");
        }
    }
    return i;
}

void criaplaylist(Playlist play[],int ip, Music musicas[],int im){
    int caso;
    int i,aux;
    play[ip].tamanho = 0;

    i=play[ip].tamanho;

    system("CLS");
    fflush(stdin);
    printf("\t ___________________________________________________________________\n");
    printf("\t|Digite o nome playlist:                                            |\n");
    printf("\t|Digite o nome do dono da playlist:                                 |\n");
    printf("\t|___________________________________________________________________|\n");
    gotoXY(32,1);
    scanf("%[^\n]%*c",play[ip].titulo);
    gotoXY(43,2);
    scanf("%[^\n]%*c",play[ip].dono);
    printf("\t|Deseja adicionar alguma musica no momento? [1]-Sim  [2]-Nao        |\n");
    printf("\t|___________________________________________________________________|\n");
    gotoXY(33,4);
    scanf("%d",&caso);
    if(caso == 1){
        aux = consultarmusic(musicas,im);
        if(aux != 0){
            printf("\tQue musica deseja adicionar?\n");
            printf("\t");
            scanf("%d",&caso);
            if(caso<aux || caso>0){
                play[ip].musicas[i] = musicas[caso];
                /*
                play[ip].musicas[i].ano = musicas[caso].ano;
                play[ip].musicas[i].min = musicas[caso].min;
                play[ip].musicas[i].seg = musicas[caso].seg;
                play[ip].musicas[i].nota = musicas[caso].nota;
                */
                play[ip].tamanho++;

                printaplay(play,ip);
            }
        }
    }
    system("PAUSE");
}

void add(Music musicas[],int i){
    system("CLS");
    fflush(stdin);

    ad();
    menumusic();

    gotoXY(38,5);
    scanf("%[^\n]%*c",musicas[i].titulo);
    gotoXY(38,6);
    scanf("%[^\n]%*c",musicas[i].cantor);
    gotoXY(37,7);
    scanf("%[^\n]%*c",musicas[i].autor);
    gotoXY(38,8);
    scanf("%[^\n]%*c",musicas[i].genero);
    gotoXY(39,9);
    scanf("%d",&musicas[i].ano);
    gotoXY(57,10);
    scanf("%d:%d",&musicas[i].min,&musicas[i].seg);
    
    NOTA: gotoXY(43,11);
    scanf("%d",&musicas[i].nota);
    if(musicas[i].nota<0 || musicas[i].nota>5){
        printf("\t|   Digite um numero valido!                                        |\n");
        printf("\t|___________________________________________________________________|\n");
        goto NOTA;
    }
}
