#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

///
/// \brief verifica se o char eh ou nao um espaco ou um \t ou um \n
/// \param um caracter a ser verificado
/// \retorna 1 se for espaco, '\n' ou '\t' e 0 caso contrario
///
int verifica_espaco(char c){
	
    return c == ' ' || c == '\n' || c == '\t'; 
}

///
/// \brief retira os espacos extras no comeco e no final da string
/// \param a string a ser verificada
///
void retira_espaco(char s[]){
    char *aux = s;
    char *aux1 = s;

    while(verifica_espaco(*aux1)){
        ++aux1;
    }

    while(*aux1){
        *aux++ = *aux1++;
    }

    if(aux>s){
        while(verifica_espaco(aux[-1])){
            --aux;
        }
    }
    *aux = '\0';
}


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
int menu(){
	int n;

	system("cls");
	printf("+------------------------------------+\n");
	printf("|            Menu principal          |\n");
    printf("+------------------------------------+\n");
    printf("| 0 - Sair                           |\n");
    printf("| 1 - Menu de voos                   |\n");
    printf("| 2 - Menu de participante           |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    gotoXY(18,6);
    scanf("%d",&n);

    return n;
}

///
/// \brief printa o menu de voos
/// \return retorna a opcao escolhida
///
int menu_voo(){
	int n;

	system("cls");
	printf("+------------------------------------+\n");
	printf("|            Menu de Voos            |\n");
    printf("+------------------------------------+\n");
    printf("| 0 - Voltar                         |\n");
    printf("| 1 - Inserir voo                    |\n");
    printf("| 2 - Listar voos                    |\n");
    printf("| 3 - Remover voo                    |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    gotoXY(18,7);
    scanf("%d",&n);

    return n;
}

///
/// \brief printa o menu para inserir voo
///
void menu_inserir_voo(){
	printf("+-----------------------------------------+\n");
	printf("|                  Voos                   |\n");
    printf("+-----------------------------------------+\n");
    printf("| Prefixo:                                |\n");
    printf("| Origem:                                 |\n");
    printf("| Destino:                                |\n");
    printf("| Horario de partida (hh:mm):             |\n");
    printf("| Horario de chegada (hh:mm):             |\n");
    printf("| Duracao do voo (hh:mm):                 |\n");
    printf("| Modelo do aviao:                        |\n");
    printf("+-----------------------------------------+\n");
}

///
/// \brief de opcoes para participantes
/// \return retorna a escolha do usuario
///
int menu_p(){
	int n;

	system("cls");
	printf("+------------------------------------+\n");
	printf("|         Menu de Participantes      |\n");
    printf("+------------------------------------+\n");
    printf("| 0 - Voltar                         |\n");
    printf("| 1 - Inserir participante           |\n");
    printf("| 2 - Listar participantes           |\n");
    printf("| 3 - Remover participante           |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    gotoXY(18,7);
    scanf("%d",&n);

    return n;
}

///
/// \brief menu para inserir um participante
///
void menu_inserir_p(){
	system("cls");
	printf("+--------------------------------------+\n");
	printf("|         Menu de Participantes        |\n");
    printf("+--------------------------------------+\n");
    printf("| Programa:                            |\n");
    printf("| Nome da pessoa:                      |\n");
    printf("| CPF da pessoa:                       |\n");
    printf("| Categoria:                           |\n");
    printf("| Saldo de milhas:                     |\n");
    printf("+--------------------------------------+\n");
}

///
/// \brief menu para verificar se quer listar todos os participantes ou apenas um
/// \return retorna a escolha do usuario
///
int menu_listar_p(){
	int n;

	system("cls");
	printf("+------------------------------------+\n");
	printf("|         Menu de Participantes      |\n");
    printf("+------------------------------------+\n");
    printf("| 0 - Voltar                         |\n");
    printf("| 1 - Mostrar todos os participantes |\n");
    printf("| 2 - Listar certo participante      |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    gotoXY(18,6);
    scanf("%d",&n);

    return n;
}

///
/// \brief menu para verificar se quer listar todos os voos ou apenas um 
/// \return retorna a escolha do usuario
///
int menu_listar_v(){
	int n;

	system("cls");
	printf("+------------------------------------+\n");
	printf("|           Menu de Voos             |\n");
    printf("+------------------------------------+\n");
    printf("| 0 - Voltar                         |\n");
    printf("| 1 - Mostrar todos os voos          |\n");
    printf("| 2 - Listar certo voo               |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    gotoXY(18,6);
    scanf("%d",&n);

    return n;
}

#endif