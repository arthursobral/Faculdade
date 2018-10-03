#ifndef MAKER_H
#define MAKER_H
#define MAX 100
#define MAXP 30

#include <stdio.h>

typedef struct Musicas{
    char titulo[MAX];
    char cantor[MAX];
    char autor[MAX];
    char genero[MAX];
    int ano;
    int min,seg;
    int nota;
}Music;

typedef struct lista{
    char titulo[MAX];
    char dono[MAX];
    struct Musicas musicas[MAX];
    int tamanho;
    int duracao;
}Playlist;

void add(Music musicas[],int i);
int consultarmusic(Music musicas[],int tam);
void consultarplaylist(Playlist play[],int tam);
void criaplaylist(Playlist play[],int ip, Music musicas[],int im);
void addnaplaylist(Playlist play[],int ip,Music musicas[],int im);
void printaplay(Playlist play[], int t);

#endif
