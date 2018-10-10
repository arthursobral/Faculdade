#include "design.h"
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

///
/// \brief ira receber 2 numeros sendo o primeiro da coordenada x e outro de y
/// \param coordenada x
/// \param coordenada y
/// \pre nenhuma
/// \post o cursor vai para a coordenada passada
///
void gotoXY(int x, int y){

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicao;

    posicao.X = x;
    posicao.Y = y;

    SetConsoleCursorPosition(out, posicao);
}


///
/// \brief muda o tamanho do ecrã do cmd
/// \pre nenhuma
/// \post muda o tamanho
///
void tamanho(){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT sr;
    COORD consoleSize;

    consoleSize.X = 110;
    consoleSize.Y = 30;

    //aqui vc mexe no tamanho da tela
    sr.Top = 0;
    sr.Left = 0;
    sr.Right = 80;
    sr.Bottom = 16;

    SetConsoleWindowInfo(console,TRUE,&sr);
    SetConsoleScreenBufferSize(console,consoleSize);
}

///
/// \brief printa o cabeçalho principal
///
void ad(){
    setlocale(LC_ALL,"Portuguese");
    printf("\t*********************************************************************\n");
    printf("\t*                           Vibee                                   *\n");
    printf("\t* Troublemakers                                               v 0.1 *\n");
    printf("\t*********************************************************************\n");
}

///
/// \brief printa o menu principal e pega a opção desejada
/// \return retorna a opção escolhida
///
int menu(){
    int i;

    system("CLS");
    ad();
    printf("\t*********************************************************************\n");
    printf("\t|                                                                   |\n");
    printf("\t|  [1] - para adicionar uma musica.                                 |\n");
    printf("\t|  [2] - para criar uma playlist.                                   |\n");
    printf("\t|  [3] - para mostrar todas as musicas.                             |\n");
    printf("\t|  [4] - para consultar as playlist.                                |\n");
    printf("\t|  [5] - Editar uma playlist.                                       |\n");
    printf("\t|  [6] - Caso queira excluir uma playlist.                          |\n");
    printf("\t|  [0] - Sair                                                       |\n");
    printf("\t|                                                                   |\n");
    printf("\t|                         Opcao:                                    |\n");
    printf("\t*********************************************************************\n");
    gotoXY(40,14);
    scanf("%d",&i);

    return i;
}

///
/// \brief printa o menu musica principal
///
void menumusic(){
    printf("\t ___________________________________________________________________\n");
    printf("\t|   Digite o titulo da musica:                                      |\n");
    printf("\t|   Digite o cantor da musica:                                      |\n");
    printf("\t|   Digite o autor da musica:                                       |\n");
    printf("\t|   Digite o genero da musica:                                      |\n");
    printf("\t|   Digite o ano de lancamento:                                     |\n");
    printf("\t|   Digite a duracao da musica,por exemplo 2:30:                    |\n");
    printf("\t|   Digite a avaliacao (de 0 a 5):                                  |\n");
    printf("\t|___________________________________________________________________|\n");
}

///
/// \brief printa o menu de confirmação de que vai sair
///
void menuout(){
    printf("\t __________________________________________________________________\n");
    printf("\t|                   Deseja mesmo sair?                             |\n");
    printf("\t|                    [1]-Sim  [0]-Nao                              |\n");
    printf("\t|                                                                  |\n");
    printf("\t|__________________________________________________________________|\n");
}

///
/// \brief mensagem antes de sair do programa
///
void msgout(){
    printf("\t __________________________________________________________________\n");
    printf("\t|           Agradecemos por usar nosso aplicativo!                 |\n");
    printf("\t|                          Volte sempre                            |\n");
    printf("\t|__________________________________________________________________|\n");
}

///
/// \brief printa o menu para editar uma playlist
///
void edita(){
    printf("\t*********************************************************************\n");
    printf("\t*   [0] - Caso queira voltar para o menu principal.                 *\n");
    printf("\t*   [1] - Caso queira mudar o nome de uma playlist.                 *\n");
    printf("\t*   [2] - Caso queira adicionar uma musica a uma playlist.          *\n");
    printf("\t*   [3] - Caso queira remover uma musica da playlist.               *\n");
    printf("\t*                                                                   *\n");
    printf("\t*                            Opcao:                                 *\n");
    printf("\t*********************************************************************\n");
}

///
/// \brief mensagem padrao de erro caso uma opção nao seja valida
///
void msgerro(){
    printf("\t*********************************************************************\n");
    printf("\t*                   Digite um numero valido!                        *\n");
    printf("\t*********************************************************************\n");
}

///
/// \brief mensagem caso o nome da playlist tenha sido alterado com sucesso
///
void nomesucesso(){
    system("CLS");
    printf("\t*********************************************************************\n");
    printf("\t*                  Nome alterado com sucesso!                       *\n");
    printf("\t*********************************************************************\n");
}

///
/// \brief mensagem caso não exista nenhuma playlist
///
void msgerroplay(){
    system("CLS");
    printf("\t*********************************************************************\n");
    printf("\t*                  Nao ha nenhuma playlist!                         *\n");
    printf("\t*********************************************************************\n");
}

///
/// \brief mensagem caso não contenha musica nenhuma
///
void msgerromusic(){
    printf("\t*********************************************************************\n");
    printf("\t*                        Nao ha musica.                             *\n");
    printf("\t*********************************************************************\n");
}

///
/// \brief menu para adicionar uma musica na playlist
///
void menuchooseplay(){
    printf("\t*********************************************************************\n");
    printf("\t*                   Deseja adicionar em qual playlist?              *\n");
    printf("\t*                Digite [0] caso queira voltar para o menu.         *\n");
    printf("\t*                               Opcao:                              *\n");
    printf("\t*********************************************************************\n");
}

///
/// \brief menu para escolher uma musica
///
void menuchoosemusic(){
    printf("\t ___________________________________________________________________\n");
    printf("\t|                 Que musica deseja adicionar?                      |\n");
    printf("\t|         Caso nao queira mais adicionar musicas digite [0]         |\n");
    printf("\t|                          Opcao:                                   |\n");
    printf("\t|___________________________________________________________________|\n");
}

///
/// \brief menu caso uma musica seja repetida
///
void menurepetida(){
    printf("\t ___________________________________________________________________\n");
    printf("\t|           Essa musica ja existe nessa playlist.                   |\n");
    printf("\t|      Deseja adiciona-la novamente? [1] - Sim [0] - Nao            |\n");
    printf("\t|                          Opcao:                                   |\n");
    printf("\t|___________________________________________________________________|\n");

}

///
/// \brief mensagem caso uma musica tenha sido adicionada com sucesso
///
void musicaddsucess(){
    printf("\t*********************************************************************\n");
    printf("\t*                   Musica adicionada com sucesso!                  *\n");
    printf("\t*********************************************************************\n");
}
