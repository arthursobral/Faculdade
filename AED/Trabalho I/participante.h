#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "menu.h"


#define MAX 50

struct participante{

    char *programa; //SMILES, Multiplus, etc
    char *pessoa;
    char *cpf;
    char *categoria; //Bronze, Prata, Ouro, etc
    double milhas;

    struct participante *prox;

};typedef struct participante Participante;

///
/// \brief verifica se uma lista encadeada de participantes e vazia ou nao
/// \param lista encadeada de participante
/// \return retorna 1 se for vazia e 0 o contrario
///
int vazia_p(Participante *p){

    return (p == NULL);
}

///
/// \brief analisa a letra lida do arquivo
/// \param a letra a ser analisada
/// \return retorna 1 caso seja p ou P, 2 caso seja v ou V e 3 caso nao seja nenhuma das dessas
///
int qual_cadastro(char letra){

    if(letra == 'P' || letra == 'p'){

        return 1;
    }

    if(letra == 'V' || letra == 'v'){

        return 2;
    }

    else{

        return 3;
    }
}

///
/// \brief inicializa um no de participantes
/// \return retorna o no inicializado
///
Participante *inicializa(){

    Participante *novo = (Participante*)malloc(sizeof(Participante));

    novo->programa = (char*)malloc(sizeof(char)*MAX);
    novo->pessoa = (char*)malloc(sizeof(char)*MAX);
    novo->cpf = (char*)malloc(sizeof(char)*MAX);
    novo->categoria = (char*)malloc(sizeof(char)*MAX);

    return novo;
}

///
/// \brief imprime os dados do participante
/// \param lista encadeada de participantes
///
void mostrar_part(Participante *p){
    if(!vazia_p(p)){

        printf("| Programa: %-25s| \n", p->programa);
        printf("| Participante: %-21s|\n", p->pessoa);
        printf("| CPF: %-30s|\n", p->cpf);
        printf("| Categoria: %-24s|\n", p->categoria);
        printf("| Milhas: %-27.2lf|\n", p->milhas);
        printf("+------------------------------------+\n");
    }

    else{

        printf("Nao existem participantes.\n");
    }
}

///
/// \brief insere participante a partir da leitura do arquivo
/// \param lista encadeada de participantes
/// \param linha do arquivo de onde ele ira ler
/// \return retorna a lista de participantes alterada com o novo participante inserido
///
Participante *insere_part(Participante *p, char *linhaArq){
    if(vazia_p(p)){

        int n = 0, np;
        p = inicializa();

        sscanf(linhaArq, "%[^;];%n", p->programa, &np);
        retira_espaco(p->programa);
        n += np;

        sscanf(linhaArq + n, "%[^;];%n", p->pessoa, &np);
        retira_espaco(p->pessoa);
        n += np;

        sscanf(linhaArq + n, "%[^;];%n", p->cpf, &np);
        retira_espaco(p->cpf);
        n += np;

        sscanf(linhaArq + n, "%[^;];%n", p->categoria, &np);
        retira_espaco(p->categoria);
        n += np;

        sscanf(linhaArq + n, "%lf", &p->milhas);
        p->prox = NULL;
    }
    else{

        p->prox = insere_part(p->prox, linhaArq);
    }

    return p;
}

///
/// \brief insere participante a partir da leitura do teclado
/// \param lista encadeada de participantes
/// \return retorna a lista de participantes alterada com o novo participante inserido
///
Participante *insere_part1(Participante *p){
    Participante *novo = inicializa();
    Participante *aux = p;
    int n = 0, np;

    system("cls");
    menu_inserir_p();

    fflush(stdin);
    gotoXY(12,3);
    scanf("%[^\n]%*c", novo->programa);
    
    fflush(stdin);
    gotoXY(18,4);
    scanf("%[^\n]%*c", novo->pessoa);
    
    fflush(stdin);
    gotoXY(17,5);
    sscanf("%[^\n]%*c", novo->cpf);
    
    fflush(stdin);
    gotoXY(13,6);
    sscanf("%[^\n]%*c", novo->categoria);
    
    fflush(stdin);
    gotoXY(19,7);
    scanf("%lf", &novo->milhas);

    novo->prox = NULL;

    if(vazia_p(p)){

        p = novo;
    }
    else{
        while(aux->prox != NULL){

            aux = aux->prox;
        }

        aux->prox = novo;
    }

    return p;
}


///
/// \brief imprime todos os participantes existentes
/// \param lista encadeada de participantes
///
void listar_part(Participante *p){
    if(p == NULL){
        printf("+------------------------------------+\n");
        printf("|      Nao existe participantes      |\n");
        printf("+------------------------------------+\n");
    }

    else{
        Participante *percorre = p;
        printf("+------------------------------------+\n");
        printf("|            Participante            |\n");
        printf("+------------------------------------+\n");

        while(!vazia_p(percorre)){

            mostrar_part(percorre);

            percorre = percorre->prox;
        }
    }
}

///
/// \brief exclui participante com o cpf passado
/// \param lista encadeada com todos os participantes
/// \param cpf do participante a ser excluido
/// \return a lista alterada sem o participante
///
Participante* excluir_part(Participante *p, char cpf_procurado[]){
    if(p != NULL && !strcmp(p->cpf, cpf_procurado)){
        Participante *removido = p;
        removido->programa = NULL;
        removido->pessoa = NULL;
        removido->cpf = NULL;
        removido->categoria = NULL;
        p = p->prox;
        free(removido);

        system("cls");
        printf("+------------------------------------+\n");
        printf("| Participante removido com sucesso! |\n");
        printf("+------------------------------------+\n");

        return p;
    }
    else{
        if( p != NULL){
            p->prox = excluir_part(p->prox, cpf_procurado);
            return p;
        }
        else{
            printf("+------------------------------------+\n");
            printf("|    Participante nao encontrado!    |\n");
            printf("+------------------------------------+\n");
            return NULL;
        }
    }
}

///
/// \brief procura um participante pelo cpf e exibi suas informações
/// \param a lista que contem todos os participantes
/// \param cpf a ser procurado
///
void procurar_part(Participante *p, char cpf_procurado[]){
    if(p != NULL && !strcmp(p->cpf, cpf_procurado)){
        system("cls");
        mostrar_part(p);
    }
    else{
        if(p != NULL)
            procurar_part(p->prox, cpf_procurado);
        else {
            printf("+------------------------------------+\n");
            printf("|    Participante nao encontrado!    |\n");
            printf("+------------------------------------+\n");
        }
    }
}


///
/// \brief transforma oque foi lido do cmd para string
/// \param uma constante contendo oque foi lido do cmd
/// \return retorna a constante em forma de string
///
char *nome_Arq(char const *argv[]){
    
    return ((char*)argv[0]); //char*: convertendo o tipo de dado para string
}

#endif