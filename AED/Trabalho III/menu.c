#include "menu.h"

///
/// \brief funcao que move o cursor dado uma coordenada x e y
/// \param coordenada x: coordenada em relação ao eixo horizontal
/// \param coordenada y: coordenada em relação ao eixo vertical
/// \pre nenhuma
/// \pos o cursor vai para as coordenadas passadas como parametro
///
void gotoXY(int x,int y){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicao;

	posicao.X = x;
	posicao.Y = y;

	SetConsoleCursorPosition(out,posicao);
}

///
/// \brief funcao que printa o menu principal
/// \return retorna a opcao escolhida
/// \pre nenhuma
/// \pos nenhuma
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

///
/// \brief funcao que printa o menu para ler as informações do livro a ser inserido
/// \pre nenhuma
/// \pos nenhuma
///
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

///
/// \brief funcao que printa o menu para escolher o tipo de impressão
/// \pre nenhuma
/// \pos nenhuma
///
int opcao_print(){
    int n;

    system("cls");
    printf("+------------------------------------+\n");
    printf("|               Imprimir             |\n");
    printf("+------------------------------------+\n");
    printf("| 1 - Imprimir arvore                |\n");
    printf("| 2 - Imprimir niveis                |\n");
    printf("| 0 - Sair                           |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");

    gotoXY(18,6);
    scanf("%d",&n);

    return n;
}

///
/// \brief funcao que printa uma mensagem dizendo que a listagem foi gerada com sucesso
/// \pre nenhuma
/// \pos nenhuma
///
void msg_sucess_list(){
    system("CLS");
    printf("+------------------------------------+\n");
    printf("|     Listagem feita com sucesso     |\n");
    printf("+------------------------------------+\n");
}

///
/// \brief funcao que printa uma mensagem dizendo que o elemento nao foi encontrado
/// \pre nenhuma
/// \pos nenhuma
///
void nao_encontrado(){
    printf("+------------------------------------+\n");
    printf("|       Elemento nao encontrado      |\n");
    printf("+------------------------------------+\n");
}

///
/// \brief funcao que printa o menu para ler o codigo do livro a ser procurado
/// \pre nenhuma
/// \pos nenhuma
///
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

///
/// \brief funcao que printa o menu para ler a quantidade nova de exemplares de um livro
/// \pre nenhuma
/// \pos nenhuma
///
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

///
/// \brief funcao que printa uma mensagem dizendo que a arvore esta vazia
/// \pre nenhuma
/// \pos nenhuma
///
void erro_arvore_empty(){
    printf("+------------------------------------+\n");
    printf("|            Arvore vazia            |\n");
    printf("+------------------------------------+\n");
}

///
/// \brief funcao que printa o menu para remover o elemento
/// \return retorna o elemento a ser removido
/// \pre nenhuma
/// \pos nenhuma
///
int menu_remove(){
    system("cls");
    int n;
    printf("+------------------------------------+\n");
    printf("|                Remover             |\n");
    printf("+------------------------------------+\n");
    printf("| Digite o codigo do livro:          |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");

    gotoXY(18,4);
    scanf("%d",&n);
    printf("\n");

    return n;
}