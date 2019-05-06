#ifndef AVIAO_H
#define AVIAO_H

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include "menu.h"
#define MAX 50

typedef struct voo{
    char prefixo[MAX];
    char nome_sigla_org[MAX];
    char nome_sigla_dst[MAX];
    char tipo_aer[MAX];

    int hh_part,mm_part;
    int hh_cheg,mm_cheg;
    int hh_dura,mm_dura;

    struct voo *prox;
}Voo;


/// \brief verifica se a lista esta vazia
/// \param lista encadeada de voos
/// \return retorna 1 se a lista for vazia
/// \pre lista encadeada
/// \post nenhuma
///
int vazia(Voo *l){

    return(l==NULL);
}

///
/// \brief limpa o buffer do cmd
///
void limpaStdin(){
    char c; // discard all characters up to and including newline
    while ((c = getchar()) != '\n' && c != EOF);
}

///
/// \brief verifica se os caracteres de uma string sao maiuculos
/// \param uma string
/// \return retorna se string e ou nao maiuscula
/// \pre string
/// \post 0 para falso, nao sao todos caracteres maiusculos e 1 para verdadeiro, sao todos maiusculos
///
int eh_maiusucula(char *string){

    int i, aux;

    aux=strlen(string);

    for(i=0; i<aux; i++){


        if(!isupper(string[i]))

            return 0;
    }

    return 1;
}

///
/// \brief insere um novo voo na lista encadeada lendo os elementos do teclado
/// \param lista encadeada
/// \return lista alterada com um novo elemento ou cria uma nova lista com o novo item inserido
/// \pre lista encadeada e elemento a ser inserido
/// \post lista encadeada com item inserido
///
Voo *insere_voo(Voo *l){
    if(vazia(l)){
        int n = 0,np;

        Voo *nova = (Voo*)malloc(sizeof(Voo));

        menu_inserir_voo();
        
        fflush(stdin);
        gotoXY(11,3);
        scanf("%[^\n]%*c",nova->prefixo);

        fflush(stdin);
        gotoXY(10,4);
        scanf("%[^\n]%*c",nova->nome_sigla_org);

        if(strlen(nova->nome_sigla_org)!=3 || !eh_maiusucula(nova->nome_sigla_org)){
            system("cls");
            printf("+-----------------------------------------------------------------------+\n");
            printf("| Erro: a sigla de origem deve ser formado por 3 caracteres maiusculos! |\n");
            printf("+-----------------------------------------------------------------------+\n");
            free(nova);
            return l;
        }

        fflush(stdin);
        gotoXY(11,5);
        scanf("%[^\n]%*c",nova->nome_sigla_dst);

        if(strlen(nova->nome_sigla_dst)!=3 || !eh_maiusucula(nova->nome_sigla_dst)){
            system("cls");
            printf("+------------------------------------------------------------------------+\n");
            printf("| Erro: a sigla de destino deve ser formado por 3 caracteres maiusculos! |\n");
            printf("+------------------------------------------------------------------------+\n");
            free(nova);
            return l;
        }
        if(!strcmp(nova->nome_sigla_org, nova->nome_sigla_dst)){
            system("cls");
            printf("+----------------------------------------------------+\n");
            printf("| Erro: o destino nao pode ser o mesmo que a origem! |\n");
            printf("+----------------------------------------------------+\n");
            free(nova);

            return l;
        }

        fflush(stdin);
        gotoXY(22,6);
        scanf("%d:%d",&nova->hh_part,&nova->mm_part);

        if(nova->hh_part<0 || nova->hh_part>23 || nova->mm_part<0 || nova->mm_part>59){
            system("cls");
            printf("+-------------------------------------+\n");
            printf("| Erro: horario de partida incorreto! |\n");
            printf("+-------------------------------------+\n");
            free(nova);
            return l;
        }

        fflush(stdin);
        gotoXY(22,7);
        scanf("%d:%d",&nova->hh_cheg,&nova->mm_cheg);

        if(nova->hh_cheg<0 || nova->hh_cheg>23 || nova->mm_cheg<0 || nova->mm_cheg>59){
            system("cls");
            printf("+-------------------------------------+\n");
            printf("| Erro: horario de chegada incorreto! |\n");
            printf("+-------------------------------------+\n");
            free(nova);
            return l;
        }

        fflush(stdin);
        gotoXY(18,8);
        scanf("%d:%d",&nova->hh_dura, &nova->mm_dura);

        if(nova->hh_dura<0 || nova->hh_dura>23 || nova->mm_dura<0 || nova->mm_dura>59){
            system("cls");
            printf("+-------------------------------------+\n");
            printf("| Erro: horario de duração incorreto! |\n");
            printf("+-------------------------------------+\n");
            free(nova);
            return l;
        }

        fflush(stdin);
        gotoXY(19,9);
        scanf("%[^\n]%*c",nova->tipo_aer);

        nova->prox=NULL;
        l=nova;
        printf("+------------------------------------+\n");
        printf("|      Voo inserido com sucesso!     |\n");
        printf("+------------------------------------+\n");
        return l;
    }

    l->prox=insere_voo(l->prox);
    return l;
}

///
/// \brief insere um novo voo na lista encadeada lendo os elementos de um arquivo
/// \param lista encadeada
/// \return lista alterada com um novo elemento ou cria uma nova lista com o novo item inserido
/// \pre lista encadeada e elemento a ser inserido
/// \post lista encadeada com item inserido
///
Voo* insere_voo_a(Voo* l, char *linhaArq){
    if(vazia(l)){
        int n = 0,np;

        Voo *nova = (Voo*)malloc(sizeof(Voo));

        sscanf(linhaArq,"%[^;];%n",nova->prefixo,&np);
        retira_espaco(nova->prefixo);
        n+=np;

        sscanf(linhaArq + n,"%[^;];%n",nova->nome_sigla_org,&np);
        retira_espaco(nova->nome_sigla_org);
        n+=np;

        if(strlen(nova->nome_sigla_org)!=3 || !eh_maiusucula(nova->nome_sigla_org)){
            system("cls");
            printf("+-----------------------------------------------------------------------+\n");
            printf("|               Erro ao ler informacoes do voo %-25s|\n",nova->prefixo);
            printf("| Obs: a sigla de origem deve ser formado por 3 caracteres maiusculos   |\n");
            printf("+-----------------------------------------------------------------------+\n");
            free(nova);
            system("pause");
            return l;
        }

        sscanf(linhaArq + n,"%[^;];%n",nova->nome_sigla_dst,&np);
        retira_espaco(nova->nome_sigla_dst);
        n+=np;

        if(strlen(nova->nome_sigla_dst)!=3 || !eh_maiusucula(nova->nome_sigla_dst)){
            system("cls");
            printf("+-----------------------------------------------------------------------+\n");
            printf("|               Erro ao ler informacoes do voo %-25s|\n",nova->prefixo);
            printf("| Obs: a sigla de destino deve ser formado por 3 caracteres maiusculos  |\n");
            printf("+-----------------------------------------------------------------------+\n");
            free(nova);
            system("pause");
            return l;
        }
        if(!strcmp(nova->nome_sigla_org, nova->nome_sigla_dst)){
            system("cls");
            printf("+-----------------------------------------------------------------------+\n");
            printf("|               Erro ao ler informacoes do voo %-25s|\n",nova->prefixo);
            printf("|            Obs: o destino nao pode ser o mesmo que a origem           |\n");
            printf("+-----------------------------------------------------------------------+\n");
            free(nova);
            system("pause");
            return l;
        }

        sscanf(linhaArq + n,"%d:%d;%n",&nova->hh_part,&nova->mm_part,&np);
        n+=np;

        if(nova->hh_part<0 || nova->hh_part>23 || nova->mm_part<0 || nova->mm_part>59){
            system("cls");
            printf("+-----------------------------------------------------------------------+\n");
            printf("|               Erro ao ler informacoes do voo %-25s|\n",nova->prefixo);
            printf("|                     Obs: horario de partida incorreto                 |\n");
            printf("+-----------------------------------------------------------------------+\n");
            free(nova);
            system("pause");
            return l;
        }

        sscanf(linhaArq + n,"%d:%d;%n",&nova->hh_cheg,&nova->mm_cheg,&np);
        n+=np;

        if(nova->hh_cheg<0 || nova->hh_cheg>23 || nova->mm_cheg<0 || nova->mm_cheg>59){
            system("cls");
            printf("+-----------------------------------------------------------------------+\n");
            printf("|               Erro ao ler informacoes do voo %-25s|\n",nova->prefixo);
            printf("|                     Obs: horario de chegada incorreto                 |\n");
            printf("+-----------------------------------------------------------------------+\n");
            free(nova);
            system("pause");
            return l;
        }

        sscanf(linhaArq + n,"%d:%d;%n",&nova->hh_dura, &nova->mm_dura,&np);
        n+=np;

        if(nova->hh_dura<0 || nova->hh_dura>23 || nova->mm_dura<0 || nova->mm_dura>59){
            system("cls");
            printf("+-----------------------------------------------------------------------+\n");
            printf("|               Erro ao ler informacoes do voo %-25s|\n",nova->prefixo);
            printf("|                     Obs: horario de duracao incorreto                 |\n");
            printf("+-----------------------------------------------------------------------+\n");
            free(nova);
            system("pause");
            return l;
        }

        sscanf(linhaArq + n, "%[^\n]%*c",nova->tipo_aer);
        retira_espaco(nova->tipo_aer);

        nova->prox=NULL;
        l=nova;
        return l;
    }

    l->prox=insere_voo_a(l->prox,linhaArq);
    return l;
}


///
/// \brief imprime
/// \param lista encad. com voos
/// \pre lista encadeada
/// \post nenhuma
///
void imprime_voo(Voo* l){
    if(!vazia(l)){
        printf("| Prefixo do voo: %-19s|\n", l->prefixo);
        printf("| Sigla origem: %-21s|\n", l->nome_sigla_org);
        printf("| Sigla destino: %-20s|\n", l->nome_sigla_dst);

        if(l->hh_part>9){
            printf("| Horario partida: %-1d:%-15d|\n", l->hh_part, l->mm_part);
        }else{
            printf("| Horario partida: %d:%-16d|\n", l->hh_part, l->mm_part);
        }

        if(l->hh_cheg>10){
            printf("| Horario chegada: %-1d:%-15d|\n", l->hh_cheg, l->mm_cheg);
        }else{
            printf("| Horario chegada: %d:%-16d|\n", l->hh_cheg, l->mm_cheg);
        }
        printf("| Duracao voo: %d:%-20d|\n", l->hh_dura, l->mm_dura);
        printf("| Tipo de areonave: %-17s|\n", l->tipo_aer);

        printf("+------------------------------------+\n");
        imprime_voo(l->prox);
    }
}

///
/// \brief remover
/// \param lista encad
/// \return nova lista com um elemento removido
/// \pre lista encadeada com elementos
/// \post lista encadeada com item removido
///
Voo *remover_voo (Voo* l){
    Voo* anterior = l;
    Voo* atual = l;
    char prefixo[MAX];

    fflush(stdin);
    system("cls");
    printf("+---------------------------------------------+\n");
    printf("| Digite o prefixo do voo que deseja remover: |\n");
    printf("|                                             |\n");
    printf("+---------------------------------------------+\n");
    fflush(stdin);
    gotoXY(4,2);
    scanf("%[^\n]%*c",prefixo);
    printf("\n");


    while( atual != NULL && strcmp(prefixo, atual->prefixo)!=0){

        anterior=atual;

        atual=atual->prox;
    }

    if(atual!=NULL){

        if(atual==l)
            l=l->prox;
        else
            anterior->prox = atual->prox;

        printf("+------------------------------------+\n");
        printf("|      Voo removido com sucesso!     |\n");
        printf("+------------------------------------+\n");
        free(atual);
    }
    else{
        printf("+------------------------------------+\n");
        printf("|      Elemento nao encontrado!      |\n");
        printf("+------------------------------------+\n");
    }

    return l;
}


///
/// \brief um certo voo de acordo com o prefixo dado
/// \param lista encadeada contendo todos os voos
/// \param prefixo a ser procurado na lista
/// \pre nenhuma
/// \post nenhuma
///
void imprime_voo_pro(Voo *l,char prefixo[]){
    if(l != NULL && !strcmp(l->prefixo, prefixo)){
        printf("| Prefixo do voo: %-19s|\n", l->prefixo);
        printf("| Sigla origem: %-21s|\n", l->nome_sigla_org);
        printf("| Sigla destino: %-20s|\n", l->nome_sigla_dst);

        if(l->hh_part>9){
            printf("| Horario partida: %-1d:%-15d|\n", l->hh_part, l->mm_part);
        }else{
            printf("| Horario partida: %d:%-16d|\n", l->hh_part, l->mm_part);
        }

        if(l->hh_cheg>10){
            printf("| Horario chegada: %-1d:%-15d|\n", l->hh_cheg, l->mm_cheg);
        }else{
            printf("| Horario chegada: %d:%-16d|\n", l->hh_cheg, l->mm_cheg);
        }
        printf("| Duracao voo: %d:%-20d|\n", l->hh_dura, l->mm_dura);
        printf("| Tipo de areonave: %-17s|\n", l->tipo_aer);

        printf("+------------------------------------+\n");

    }
    else{
        if(l != NULL)
            imprime_voo_pro(l->prox, prefixo);
        else {
            printf("+------------------------------------+\n");
            printf("|         Voo nao encontrado!        |\n");
            printf("+------------------------------------+\n");
        }
    }
}

#endif