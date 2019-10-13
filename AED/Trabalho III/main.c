#include <stdio.h>
#include "arvore.h"
#include "menu.h"

int main(int arqc, const char *arqv[]){

	FILE *info, *arvoreBin, *livrosBin;
	char *nomeArquivo, linhaArq[200];
	int opcao;

	nomeArquivo = nomeArq(arqv+1); //ignorando o .exe

	info = fopen(nomeArquivo, "r");

	arvoreBin = fopen("arvore.bin", "wb+");
	livrosBin = fopen("livros.bin", "wb+");

	cria_cabe_bmais(arvoreBin);
	cria_cabe_livro(livrosBin);

	if(info == NULL){
		printf("Arquivo vazio!\n");
		system("PAUSE");
	}
	else{
		while(!feof(info)){
			
			fgets(linhaArq, 100, info);

			le_arq(livrosBin, arvoreBin, linhaArq);
		}
	}

	
	opcao = menu_ini();

	while(opcao != 0){
		switch (opcao){
			case 1://inserir livro nos arqvs bin
				leStd(livrosBin, arvoreBin);
				break;
			case 2://remover livro dos arqvs bin
				remover(arvoreBin,livrosBin);
				break;
			case 3://atualizar qtd de algum livro
				atualiza(arvoreBin,livrosBin);
				break;
			case 4://procurar livro
				busca_(arvoreBin,livrosBin);
				break;
			case 5://imprimir arvore e arvore por nivel

				system("cls");
				opcao = opcao_print();
				
				switch(opcao){
					case 1://imprimir arvore pre-ordem
						system("cls");
						imprime_acervo(arvoreBin,livrosBin);
						break;
					case 2://imprimir arvore por nivel
						system("cls");
						imprime_nivel(arvoreBin);
						break;
					case 3:
						printf("\n");
						printa_arv(arvoreBin);
						break;
				}
				break;
			default:
				printf("Opcao invalida\n");
		}
		printf("\n");
		system("PAUSE");
		opcao = menu_ini();
	}

	fclose(arvoreBin);
	fclose(livrosBin);
	fclose(info);

	return 0;
}