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
    printf("| 1 - Imprimir                       |\n");
    printf("| 2 - Consultar Palavra              |\n");
    printf("| 3 - Remover                        |\n");
    printf("| 4 - Semelhantes                    |\n");
    printf("| 0 - Sair                           |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    gotoXY(18,8);
    scanf("%d",&n);

    return n;
}

///
/// \brief printa msg de remocao com sucesso
///
void msg_sucess(){
    printf("+------------------------------------+\n");
    printf("|      Remocao feita com sucesso     |\n");
    printf("+------------------------------------+\n");
}

///
/// \brief printa msg de erro
///
void erro(){
    system("CLS");
    printf("+------------------------------------+\n");
    printf("|                 Erro               |\n");
    printf("+------------------------------------+\n");
}

///
/// \brief printa menu para consultar a palavra
///
void menu_consultar(){
    printf("+------------------------------------+\n");
    printf("|      Digite o prefixo desejado:    |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
}


///
/// \brief printa erro no prefixo
///
void erro_prefix(){
    printf("+------------------------------------+\n");
    printf("|        Prefixo inesxistente        |\n");
    printf("+------------------------------------+\n");
}


///
/// \brief printa dicionario
///
void msg_dicionario(){
    printf("++++++++++++++++++++++++++++++++++++++\n");
    printf("|         Dicionario                 |\n");
    printf("++++++++++++++++++++++++++++++++++++++\n");    
}

///
/// \brief menu remove
///
void menu_remove(){
    printf("+------------------------------------+\n");
    printf("|      Digite o nome do arquivo:     |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");    
}

///
/// \brief printa se o arquivo esta vazio
///
void erro_arq(){
    printf("+------------------------------------+\n");
    printf("|           Arquivo vazio            |\n");
    printf("+------------------------------------+\n");
}

///
/// \brief printa menu para consultar semelhantes da palavra
///
void menu_semelhantes(){
    printf("+------------------------------------+\n");
    printf("|      Digite o prefixo desejado:    |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    printf("|     Digite a distancia desejada:   |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
}