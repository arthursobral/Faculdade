#include"maker.h"
#include"design.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<locale.h>
#define MAX 100
#define MAXP 30

void consultarplaylist(Playlist play[],int tam){
    int i,j;

    system("CLS");
    if(tam==0){
        printf("\t*********************************************************************\n");
        printf("\t*                     Nenhuma playlist criada.                      *\n");
        printf("\t*********************************************************************\n");
    }
    for(i=0;i<tam;i++){
        printf("\t*******************************************************************\n");
        printf("\t*[%d]Playlist de %s: %s\n",i+1,play[i].dono,play[i].titulo);
        for(j=0;j<play[i].tamanho;j++){
            printf("\t*\t[%d] - Musica: '%s' de '%s'\n",j+1,play[i].musicas[j].titulo,play[i].musicas[j].cantor);
        }
        printf("\t*******************************************************************\n");
    }
}

int repetida(Music musicas[],int tam,Music m){
    int i=0;

    for(i=0;i<tam;i++){
        if(stricmp(musicas[i].titulo,m.titulo)==0 && stricmp(musicas[i].cantor,m.cantor)==0){
            return 1;
        }
    }
    return 0;
}

void addnaplaylist(Playlist play[],int ip,Music musicas[],int im){
    int escolhap,i,aux;

    if(im == 0){
        printf("\t*********************************************************************\n");
        printf("\t*                        Nao ha musica.                             *\n");
        printf("\t*********************************************************************\n");
        system("PAUSE");
        return 0;
    }
    else if(ip == 0){
        printf("\t*********************************************************************\n");
        printf("\t*                        Nao ha playlist.                            *\n");
        printf("\t*********************************************************************\n");
        system("PAUSE");
        return 0;
    }
    N1:
    system("CLS");
    printf("\t*********************************************************************\n");
    printf("\t*                   Deseja adicionar em qual playlist?              *\n");
    printf("\t*                Digite [0] caso queira voltar para o menu.         *\n");
    printf("\t*                               Opcao:                              *\n");
    printf("\t*********************************************************************\n");
    printf("\n");
    printf("\t*********************************************************************\n");
    printf("\t                               Playlist:                             \n");
    for(i=0;i<ip;i++){
        printf("\t [%d] - %s\n",i+1,play[i].titulo);
    }
    printf("\t*********************************************************************\n");

    gotoXY(46,3);
    scanf("%d",&escolhap);
    escolhap--;

    if(escolhap >= ip){
        system("CLS");
        printf("\t*********************************************************************\n");
        printf("\t                          Opcao invalida.                           *\n");
        printf("\t*********************************************************************\n");
        system("PAUSE");
        goto N1;
    }
    else if(escolhap <0){
        return 0;
    }
    else{
        int aux,i,caso,rep;
        aux = consultamusic(musicas,im);
        if(aux != 0){
            printf("\t ___________________________________________________________________\n");
            printf("\t|                 Que musica deseja adicionar?                      |\n");
            printf("\t|         Caso nao queira mais adicionar musicas digite [0]         |\n");
            printf("\t|                          Opcao:                                   |\n");
            printf("\t|___________________________________________________________________|\n");
            printamusic(musicas,im);
            gotoXY(42,3);
            scanf("%d",&caso);
            caso--;
            while(caso >= 0){
                i=play[escolhap].tamanho;
                if(caso>=im){
                    system("CLS");
                    printf("\t********************************************************************\n");
                    printf("\t*                     Numero da musica invalido.                   *\n");
                    printf("\t********************************************************************\n");
                    system("PAUSE");
                    system("CLS");
                    goto FIM;
                }
                else if(caso<aux || caso>0){
                    if(repetida(play[escolhap].musicas,i,musicas[caso])){
                        system("CLS");
                        printf("\t ___________________________________________________________________\n");
                        printf("\t|           Essa musica ja existe nessa playlist.                   |\n");
                        printf("\t|      Deseja adiciona-la novamente? [1] - Sim [0] - Nao            |\n");
                        printf("\t|                          Opcao:                                   |\n");
                        printf("\t|___________________________________________________________________|\n");
                        gotoXY(42,3);
                        scanf("%d",&rep);
                        if(rep == 0){
                            system("CLS");
                            goto FIM;
                        }
                    }
                    play[escolhap].musicas[i] = musicas[caso];
                    play[escolhap].tamanho++;
                }
                system("CLS");
                printf("\t*********************************************************************\n");
                printf("\t*                   Musica adicionada com sucesso!                  *\n");
                printf("\t*********************************************************************\n");
                system("PAUSE");
                FIM:system("CLS");
                printf("\t ___________________________________________________________________\n");
                printf("\t|                 Que musica deseja adicionar?                      |\n");
                printf("\t|         Caso nao queira mais adicionar musicas digite [0]         |\n");
                printf("\t|                          Opcao:                                   |\n");
                printf("\t|___________________________________________________________________|\n");
                printamusic(musicas,im);
                gotoXY(42,3);
                scanf("%d",&caso);
                caso--;
            }
            goto N1;
        }
    }
}

void printamusic(Music musicas[],int tam){
    int i=0;

    if(tam==0){
        printf("\t*********************************************************************\n");
        printf("\t*            Nao contem nenhuma musica no momento.                  *\n");
        printf("\t*********************************************************************\n");
        return 0;
    }else{
        printf("\n");
        printf("\t *******************************************************************\n");
        for(i=0;i<tam;i++){
            printf("\t* [%d] -> '%s' - '%s'",i+1,musicas[i].titulo,musicas[i].cantor);
            printf("\n");
        }
        printf("\t *******************************************************************\n");
    }
}

void printaplay(Playlist play[], int t){
    int i,j;

    for(i=0;i<t;i++){
        printf("\t*******************************************************************\n");
        printf("\t [%d]Playlist de %s: %s\n",i+1,play[i].dono,play[i].titulo);
    }
    printf("\t*******************************************************************\n");
}

int consultamusic(Music musicas[],int tam){
    int i=0;

    system("CLS");
    if(tam==0){
        printf("\t*********************************************************************\n");
        printf("\t*            Nao contem nenhuma musica no momento.                  *\n");
        printf("\t*********************************************************************\n");
        return 0;
    }
    return tam;
}

void criaplaylist(Playlist play[],int ip, Music musicas[],int im){
    int caso;
    int i,aux,rep;
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
    printf("\t|                                                                   |\n");
    printf("\t|___________________________________________________________________|\n");
    gotoXY(33,4);
    scanf("%d",&caso);
    gotoXY(0,6);
    if(caso == 1){
        if(im == 0){
            printf("\t*********************************************************************\n");
            printf("\t*                        Nao ha musica.                             *\n");
            printf("\t*********************************************************************\n");
            system("PAUSE");
        }
        system("CLS");
        aux = consultamusic(musicas,im);
        if(aux != 0){
            printf("\t ___________________________________________________________________\n");
            printf("\t|                 Que musica deseja adicionar?                      |\n");
            printf("\t|                          Opcao:                                   |\n");
            printf("\t|         Caso nao queira mais adicionar musicas digite [0]         |\n");
            printf("\t|___________________________________________________________________|\n");
            printamusic(musicas,im);
            gotoXY(42,2);
            scanf("%d",&caso);
            caso--;
            while(caso >= 0){
                i=play[ip].tamanho;
                if(caso>=im){
                    system("CLS");
                    printf("\t********************************************************************\n");
                    printf("\t*                     Numero da musica invalido.                   *\n");
                    printf("\t********************************************************************\n");
                    system("PAUSE");
                    system("CLS");
                    goto MENU;
                }
                else if(caso<aux || caso>0){
                    if(repetida(play[ip].musicas,i,musicas[caso])){
                        system("CLS");
                        printf("\t ___________________________________________________________________\n");
                        printf("\t|           Essa musica ja existe nessa playlist.                   |\n");
                        printf("\t|      Deseja adiciona-la novamente? [1] - Sim [0] - Nao            |\n");
                        printf("\t|                          Opcao:                                   |\n");
                        printf("\t|___________________________________________________________________|\n");
                        gotoXY(42,3);
                        scanf("%d",&rep);
                        if(rep == 0){
                            system("CLS");
                            goto MENU;
                        }
                    }
                    //o 'i' serve para pegar a proxima musica e nao a proxima playlist
                    play[ip].musicas[i] = musicas[caso];
                    play[ip].tamanho++;
                }
                system("CLS");
                printf("\t *******************************************************************\n");
                printf("\t|                   Musica adicionada com sucesso!                  |\n");
                printf("\t *******************************************************************\n");
                system("PAUSE");
                system("CLS");
                MENU: printf("\t ___________________________________________________________________\n");
                printf("\t|                 Que musica deseja adicionar?                      |\n");
                printf("\t|                          Opcao:                                   |\n");
                printf("\t|         Caso nao queira mais adicionar musicas digite [0]         |\n");
                printf("\t|___________________________________________________________________|\n");
                printamusic(musicas,im);
                gotoXY(42,2);
                scanf("%d",&caso);
                caso--;
            }
        }
    }
    system("CLS");
    printf("\t*********************************************************************\n");
    printf("\t*                     Playlist criada com sucesso!                  *\n");
    printf("\t*********************************************************************\n");
    system("PAUSE");
}

void add(Music musicas[],int i){
    system("CLS");
    fflush(stdin);

    ad();
    menumusic();
    setlocale(LC_ALL,"Portuguese");

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
    NOTA1:gotoXY(57,10);
    scanf("%d:%d",&musicas[i].min,&musicas[i].seg);
    if(musicas[i].min>59 || musicas[i].seg>59){
        printf("\t|   Digite um número válido!                                        |\n");
        printf("\t|___________________________________________________________________|\n");
        goto NOTA1;
    }
    printf("\t|   Digite a avaliacao (de 0 a 5):                                  |\n");
    NOTA: gotoXY(43,11);
    scanf("%d",&musicas[i].nota);
    if(musicas[i].nota<0 || musicas[i].nota>5){
        printf("\t|   Digite um número válido!                                        |\n");
        printf("\t|___________________________________________________________________|\n");
        goto NOTA;
    }
}

void mudanome(Playlist play[],int ip){
    int caso,i;

    if(ip == 0){
        printf("\n");
        printf("\t*********************************************************************\n");
        printf("\t*                     Nenhuma playlist criada.                      *\n");
        printf("\t*********************************************************************\n");
        system("PAUSE");
        return 0;
    }
    OBS: system("CLS");
    printf("\t*********************************************************************\n");
    printf("\t*             Deseja mudar o nome de qual playlist?                 *\n");
    printf("\t*                           Opcao:                                  *\n");
    printf("\t*********************************************************************\n");
    printaplay(play,ip);
    gotoXY(42,2);
    scanf("%d",&caso);
    caso--;

    if(caso > ip || caso < 0){
        msgerro();
        system("PAUSE");
        goto OBS;
    }
    system("CLS");
    printf("\t*********************************************************************\n");
    printf("\t*                    Nome atual: %s                                 *\n",play[caso].titulo);
    printf("\t*                Deseja mudar para qual nome?                       *\n");
    printf("\t*                     Novo nome:                                    *\n");
    printf("\t*********************************************************************\n");
    gotoXY(40,3);
    fflush(stdin);
    scanf("%[^\n]%*c",play[caso].titulo);

    nomesucesso();
    system("PAUSE");
}

void removedaplay(Playlist play[],int ip){
    int caso = 1,i,j,p,m;

    while(caso == 1){
        system("CLS");
        printf("\t*********************************************************************\n");
        printf("\t*                    Digite de qual playlist:                       *\n");
        printf("\t*                  E a posicao dela na playlist:                    *\n");
        printf("\t*********************************************************************\n");
        printf("\t*********************************************************************\n");
        printf("\t                           Playlists:                                \n");
        for(i=0;i<ip;i++){
            printf("\t[%d]Playlist de %s: %s\n",i+1,play[i].dono,play[i].titulo);
            printf("\t                              Musicas:                             \n");
            for(j=0;j<play[i].tamanho;j++){
                printf("\t\t[%d] - '%s' de '%s'\n",j+1,play[i].musicas[j].titulo,play[i].musicas[j].cantor);
            }
        }
        printf("\t*******************************************************************\n");

        gotoXY(53,1);
        scanf("%d",&p);
        p--;
        gotoXY(56,2);
        scanf("%d",&m);
        m--;

        for(i=m;i<play[p].tamanho;i++){
            play[p].musicas[i] = play[p].musicas[i++];
        }
        play[p].tamanho--;

        system("CLS");
        printf("\t*******************************************************************\n");
        printf("\t*               Deseja remover mais alguma musica?                *\n");
        printf("\t*                             Opcao:                              *\n");
        printf("\t*                 Digite [0] - nao e [1] - sim                    *\n");
        printf("\t*******************************************************************\n");
        gotoXY(46,2);
        scanf("%d",&caso);
    }
}

void excluiplay(Playlist play[],int ip){
    int caso = 1,i,escolhap;

    while(caso==1){
        printf("\t*********************************************************************\n");
        printf("\t*             Digite qual playlist deseja remover:                  *\n");
        printf("\t*********************************************************************\n");
        printf("\n");
        printf("\t*********************************************************************\n");
        printf("\t                           Playlists:                                \n");
        for(i=0;i<ip;i++){
            printf("\t[%d]Playlist de %s: %s\n",i+1,play[i].dono,play[i].titulo);
        }
        printf("\t*********************************************************************\n");
        gotoXY(58,1);
        scanf("%d",&escolhap);


    }
}

void editaplay(Playlist play[], int ip,Music musicas[],int im){
    int caso;

    system("CLS");
    edita();
    printaplay(play,ip);
    gotoXY(43,6);
    scanf("%d",&caso);
    caso--;

    while(caso>=0){
        switch (caso){
            case 0:
                mudanome(play,ip);
                break;
            case 1:
                addnaplaylist(play,ip,musicas,im);
                break;
            case 2:
                removedaplay(play,ip);
                break;
            case 3:
                //excluiplay(play,ip);
                break;
        }
        printf("\n");
        system("CLS");
        edita();
        gotoXY(43,6);
        scanf("%d",&caso);
        caso--;
    }
}
