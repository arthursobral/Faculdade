#include "menu.h"

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
int menu_ini(){
	int n;

	system("cls");
	printf("+------------------------------------+\n");
	printf("|            Menu principal          |\n");
    printf("+------------------------------------+\n");
    printf("| 1 - Inserir                        |\n");
    printf("| 2 - Remover                        |\n");
    printf("| 3 - Atualizar                      |\n");
    printf("| 4 - Procurar                       |\n");
    printf("| 5 - Imprimir                       |\n");
    printf("| 0 - Sair                           |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    gotoXY(18,9);
    scanf("%d",&n);

    return n;
}

void menu_insere_livro(){
    system("cls");
    printf("+--------------------------------------------+\n");
    printf("|                     Livro                  |\n");
    printf("+--------------------------------------------+\n");
    printf("| Codigo:                                    |\n");
    printf("| Titulo:                                    |\n");
    printf("| Autor:                                     |\n");
    printf("| Quantidade:                                |\n");
    printf("+--------------------------------------------+\n");
}

int opcao_print(){
    int n;

    system("cls");
    printf("+------------------------------------+\n");
    printf("|               Imprimir             |\n");
    printf("+------------------------------------+\n");
    printf("| 1 - Imprimir arvore                |\n");
    printf("| 2 - Imprimir niveis                |\n");
    printf("| 3 - Imprimir acervo                |\n");
    printf("| 4 - Gerar listagem                 |\n");
    printf("| 0 - Sair                           |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");

    gotoXY(18,8);
    scanf("%d",&n);

    return n;
}

void msg_sucess_list(){
    system("CLS");
    printf("+------------------------------------+\n");
    printf("|     Listagem feita com sucesso     |\n");
    printf("+------------------------------------+\n");
}

void nao_encontrado(){
    printf("+------------------------------------+\n");
    printf("|       Elemento nao encontrado      |\n");
    printf("+------------------------------------+\n");
}

int procurado(){
    int n;
    printf("+------------------------------------+\n");
    printf("|               Procurar             |\n");
    printf("+------------------------------------+\n");
    printf("| Digite o codigo do livro:          |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");

    gotoXY(18,4);
    scanf("%d",&n);
    printf("\n");

    return n;
}

int atualiza_qtd_msg(){
    int n;
    system("cls");
    printf("+---------------------------------------------+\n");
    printf("|                  Atualizar                  |\n");
    printf("+---------------------------------------------+\n");
    printf("| Digite a nova quantidade de exemplares:     |\n");
    printf("|                                             |\n");
    printf("+---------------------------------------------+\n");

    gotoXY(21,4);
    scanf("%d",&n);
    printf("\n");

    return n;
}