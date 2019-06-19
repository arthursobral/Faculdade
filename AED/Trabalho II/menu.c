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
    printf("| 1 - Inserir Livro                  |\n");
    printf("| 2 - Remover Livro                  |\n");
    printf("| 3 - Atualizar quantidade           |\n");
    printf("| 4 - Procurar Livro                 |\n");
    printf("| 5 - Imprimir Livros                |\n");
    printf("| 0 - Sair                           |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    gotoXY(18,9);
    scanf("%d",&n);

    return n;
}

///
/// \brief printa o menu para escolhas de visualizacao da biblioteca
/// \return retorna a opcao escolhida
///
int menu_print(){
    int n;

    system("cls");
    printf("+------------------------------------+\n");
    printf("|            Menu principal          |\n");
    printf("+------------------------------------+\n");
    printf("| 1 - Imprimir arvore                |\n");
    printf("| 2 - Imprimir arvore por nivel      |\n");
    printf("| 3 - Imprimir por acervo            |\n");
    printf("| 0 - Sair                           |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    gotoXY(18,7);
    scanf("%d",&n);

    return n;
}

///
/// \brief mensagem de erro caso a opcao escolhida nao exista
///
void erro_op(){
    system("cls");
    printf("+------------------------------------+\n");
    printf("|            Opcao invalida          |\n");
    printf("+------------------------------------+\n");
}

void menu_insere(){
    system("cls");
    printf("+----------------------------------------------------------------+\n");
    printf("|                               Insercao                         |\n");
    printf("+----------------------------------------------------------------+\n");
    printf("| Acervo:                                                        |\n");
    printf("| Titulo:                                                        |\n");
    printf("| Autor:                                                         |\n");
    printf("| Quantidade:                                                    |\n");
    printf("+----------------------------------------------------------------+\n");
}

void msg_sucess(){
    printf("|                   Livros inserido com sucesso                  |\n");
    printf("+----------------------------------------------------------------+\n");
}

void menu_ordem(){
    printf("+----------------------------------------------------------------+\n");
    printf("|                             Acervo                             |\n");
    printf("+----------------------------------------------------------------+\n");
}

int menu_remove(){
    int n;

    system("cls");
    printf("+------------------------------------+\n");
    printf("|               Remocao              |\n");
    printf("+------------------------------------+\n");
    printf("| Digite o codigo do acervo:         |\n");
    printf("+------------------------------------+\n");

    gotoXY(28,3);
    scanf("%d",&n);

    return n;
}

void msg_sucess_r(){
    printf("|                                    |\n");
    printf("|     Livro removido com sucesso     |\n");
    printf("+------------------------------------+\n");
}