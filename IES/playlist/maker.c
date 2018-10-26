#include"maker.h"
#include"design.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<locale.h>
#include "cadastro.h"
#define MAX 100
#define MAXP 30

///
/// \brief deixa uma espaço para o cliente avaliar o app
///
void avalia(){
    double avaliacao;
    int caso;
    char critica[100];
    printf("\t*********************************************************************\n");
    printf("\t* Deseja avaliar nosso servico? [1]-Sim  [2]-Nao                    *\n");
    printf("\t*                              Opcao:                               *\n");
    printf("\t*********************************************************************\n");
    gotoXY(45,2);
    scanf("%d",&caso);

    switch  (caso){
        case 1:
                system("cls");
                printf("\t*********************************************************************\n");
                printf("\t* Digite um numero de 0 a 5.                                        *\n");
                printf("\t*                              Opcao:                               *\n");
                printf("\t*********************************************************************\n");
                gotoXY(45,2);
                retorna:scanf("%lf",&avaliacao);
                if(avaliacao <0 || avaliacao >5){
                    printf("Digite um numero valido.\n");
                    printf("\n");
                    goto retorna;
                }
                system("CLS");
                printf("\t*********************************************************************\n");
                printf("\t* Deseja escrever uma critica ou sujestao? [1]-Sim  [2]-Nao         *\n");
                printf("\t*                              Opcao:                               *\n");
                printf("\t*********************************************************************\n");
                gotoXY(45,2);
                scanf ("%d",&caso);
                if (caso == 1){
                    system("cls");
                    printf("\t**********************************************************************\n");
                    printf("\t* Escreva a seguir sua critica.                                      *\n");
                    printf("\t* Precione '0' e ENTER para enviar.                                  *\n");
                    printf("\t**********************************************************************\n");
                    printf("\t");
                    scanf("%[^0]", critica);
                    printf("\t*********************************************************************\n");
                    printf("\t* Critica/sujestao enviada com sucesso!                             *\n");
                    printf("\t*********************************************************************\n");
                }
                break;
        }
    printf("\n");
    system("PAUSE");
    system("CLS");
}

///
/// \brief
///
void flush(){
    fflush(stdin);
}

///
/// \brief é printado na tela oque o usuario tem que fazer e tambem será onde a funcao cadastro é chamada
///
void cadastramento(){
    Cadastro *login = inicializa();
    int *a = (int*)malloc(sizeof(int)*1000);
    int n, i;

    system("cls");
    flush();

    printf("\t*********************************************************************\n");
    printf("\t*                           Vibee                              v 0.1*\n");
    printf("\t*********************************************************************\n");
    printf("\t|Nome:                                                              |\n");
    printf("\t|Sobrenome:                                                         |\n");
    printf("\t|Email:                                                             |\n");
    printf("\t|Senha:                                                             |\n");
    printf("\t|Redigite a senha:                                                  |\n");
    printf("\t|Data de nascimento:                                                |\n");
    printf("\t|Telefone:                                                          |\n");
    printf("\t*********************************************************************\n");
    printf("\t*                                                     Troublemarkers*\n");
    printf("\t*********************************************************************\n");

    gotoXY(14,3);
    scanf("%[^\n]%*c", login->nome);
    flush();

    gotoXY(19,4);
    scanf("%[^\n]%*c",login->sobrenome);
    flush();

    gotoXY(15,5);
    scanf("%[^\n]%*c",login->email);
    flush();

    REFAZ:gotoXY(15,6);
    scanf("%[^\n]%*c",login->senha);
    flush();

    gotoXY(26,7);
    scanf("%[^\n]%*c",login->senha2);
    flush();
    if(strcmp(login->senha2,login->senha)!= 0){
        gotoXY(24,14);
        printf("Senhas nao correspondem!");
        goto REFAZ;

    }

    gotoXY(28,8);
    scanf("%d/%d/%d", &login->nascimento.dia, &login->nascimento.mes,&login->nascimento.ano);
    flush();

    gotoXY(18,9);
    scanf("%s%*c",login->numero);
    flush();

    cadastro_save(login);
}

///
/// \brief login
///
void login (){

    system("cls");
    char* email;
    char* senha;


    printf("\t*********************************************************************\n");
    printf("\t|                            Vibee                                  |\n");
    printf("\t|*******************************************************************|\n");
    printf("\t|                                                                   |\n");
    printf("\t| Email:                                                            |\n");
    printf("\t| Senha:                                                            |\n");
    printf("\t|                                                                   |\n");
    printf("\t*********************************************************************\n");
    printf("\t*                                                     Troublemarkers*\n");
    printf("\t*********************************************************************\n");

    gotoXY(16,4);
    scanf("%s",&email);
    gotoXY(16,5);
    scanf("%s",&senha);

    getchar();
}

///
/// \brief printa todas as playlist existentes e sua musicas
/// \param play, é o vetor de playlist
/// \param tam, é quantas playlist existem
///
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

///
/// \brief verifica se certa musica ja existe
/// \param musicas, vetor de musicas
/// \param tam, é o tamanho desse vetor
/// \param m, é a musica a ser comparada se ja existe ou nao
/// \return retorna 0 se ela nao for repetida e 1 caso contrario
///
int repetida(Music musicas[],int tam,Music m){
    int i=0;

    for(i=0;i<tam;i++){
        if(stricmp(musicas[i].titulo,m.titulo)==0 && stricmp(musicas[i].cantor,m.cantor)==0){
            return 1;
        }
    }
    return 0;
}

///
/// \brief addnaplaylist
/// \param play
/// \param ip
/// \param musicas
/// \param im
///
void addnaplaylist(Playlist play[],int ip,Music musicas[],int im){
    int escolhap,i,aux;

    if(im == 0){
        msgerromusic();
        system("PAUSE");
        return 0;
    }
    else if(ip == 0){
        msgerroplay();
        system("PAUSE");
        return 0;
    }
    N1:
    system("CLS");
    menuchooseplay();
    printf("\n");
    printf("\t*********************************************************************\n");
    printf("\t                               Playlist:                             \n");
    for(i=0;i<ip;i++){
        printf("\t[%d]Playlist de %s: %s\n",i+1,play[i].dono,play[i].titulo);
    }
    printf("\t*********************************************************************\n");

    gotoXY(46,3);
    scanf("%d",&escolhap);
    escolhap--;

    if(escolhap >= ip){
        system("CLS");
        msgerro();
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
            menuchoosemusic();
            printamusic(musicas,im);
            gotoXY(42,3);
            scanf("%d",&caso);
            caso--;
            while(caso >= 0){
                i=play[escolhap].tamanho;
                if(caso>=im){
                    system("CLS");
                    msgerro();
                    system("PAUSE");
                    system("CLS");
                    goto FIM;
                }
                else if(caso<aux || caso>0){
                    if(repetida(play[escolhap].musicas,i,musicas[caso])){
                        system("CLS");
                        menurepetida();
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
                musicaddsucess();
                system("PAUSE");
                FIM:system("CLS");
                menuchoosemusic();
                printamusic(musicas,im);
                gotoXY(42,3);
                scanf("%d",&caso);
                caso--;
            }
            goto N1;
        }
    }
}

///
/// \brief printa todas as musicas existentes
/// \param musicas, é o vetor que contém todas as musicas
/// \param tam, é quantas musicas existem
///
void printamusic(Music musicas[],int tam){
    int i=0;

    if(tam==0){
        msgerromusic();
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

///
/// \brief printa todas as playlist existente, porém so o nome e o dono
/// \param play, é o vetor de playlist
/// \param t, é quantas playlist existem
///
void printaplay(Playlist play[], int t){
    int i,j;

    for(i=0;i<t;i++){
        printf("\t*******************************************************************\n");
        printf("\t [%d]Playlist de %s: %s\n",i+1,play[i].dono,play[i].titulo);
    }
    printf("\t*******************************************************************\n");
}

///
/// \brief consultamusic
/// \param musicas
/// \param tam
/// \return
///
int consultamusic(Music musicas[],int tam){
    int i=0;

    system("CLS");
    if(tam==0){
        msgerromusic();
        return 0;
    }
    return tam;
}

///
/// \brief cria uma playlist, e caso ele queira adicionar uma musica na playlist ele ja adiciona
/// \param play, é o vetor onde vai ser adicionado a playlist
/// \param ip, é quantas playlist existem atualmente
/// \param musicas, é o vetor de musicas
/// \param im, é quantas musicas existem
///
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
            msgerromusic();
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
                    msgerro();
                    system("PAUSE");
                    system("CLS");
                    goto MENU;
                }
                else if(caso<aux || caso>0){
                    if(repetida(play[ip].musicas,i,musicas[caso])){
                        system("CLS");
                        menurepetida();
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
                musicaddsucess();
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

///
/// \brief adiciona uma musica no banco de dados
/// \param musicas, é onde ela vai ser amazenada
/// \param i, é a posição dela
///
///
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
        printf("\t|   Digite um numero valido!                                        |\n");
        printf("\t|___________________________________________________________________|\n");
        goto NOTA1;
    }
    printf("\t|   Digite a avaliacao (de 0 a 5):                                  |\n");
    NOTA: gotoXY(43,11);
    scanf("%d",&musicas[i].nota);
    if(musicas[i].nota<0 || musicas[i].nota>5){
        printf("\t|   Digite um numero valido!                                        |\n");
        printf("\t|___________________________________________________________________|\n");
        goto NOTA;
    }
}

///
/// \brief muda o nome de uma playlist
/// \param play, é o vetor de playlist existente
/// \param ip, é quantas playlists existem
///
void mudanome(Playlist play[],int ip){
    int caso,i;

    if(ip == 0){
        msgerroplay();
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

///
/// \brief remove uma ou mais musicas de uma playlist
/// \param play, é o vetor de playlist existente
/// \param ip, é quantas playlist existen
///
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
            printf("\t[%d]Playlist de %s: %s - duracao %d:%d:%d",i+1,play[i].dono,play[i].titulo,play[ip].hr,play[ip].min,play[ip].seg);
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
        printf("\t*********************************************************************\n");
        printf("\t*               Deseja remover mais alguma musica?                  *\n");
        printf("\t*                             Opcao:                                *\n");
        printf("\t*                 Digite [0] - nao e [1] - sim                      *\n");
        printf("\t*********************************************************************\n");
        gotoXY(46,2);
        scanf("%d",&caso);
    }
}

///
/// \brief exclui uma ou mais playlists
/// \param play, é vetor de playlists existentes
/// \param ip, é quantas existem
/// \pre nenhuma
/// \post ip é atualizado para saber quantas existem
///
void excluiplay(Playlist play[],int ip){
    int i,escolhap;

    system("CLS");
    if(ip == 0){
            msgerroplay();
            system("PAUSE");
            return 0;
    }
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
    escolhap--;

    for(i=escolhap;i<ip;i++){
            play[i] = play[i++];
    }
    system("CLS");
    printf("\t*********************************************************************\n");
    printf("\t*                 Playlist excluida com sucesso.                    *\n");
    printf("\t*********************************************************************\n");
}

///
/// \brief abre uma seção difereten para edita alguma playlist
/// \param play, é vetor de quantas playlists existentes
/// \param ip, é quantas playlists existem
/// \param musicas, é o vetor de musicas existentes
/// \param im, é quantas musica existem
///
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
        }
        printf("\n");
        system("CLS");
        edita();
        gotoXY(43,6);
        scanf("%d",&caso);
        caso--;
    }
}
