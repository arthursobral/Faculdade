#include "arvore.h"
#include "menu.h"
#include <windows.h>

int main(int arqc,const char *arqv[]){
	FILE *f;
	char *nomeArquivo, linhaArq[100];
	Arvore *biblioteca = NULL;
	Livros *aux = NULL;
	int opcao,remover;

	nomeArquivo = nome_Arq(arqv+1); // ignorando o .exe
	printf("%s\n",nomeArquivo);

	f = fopen(nomeArquivo,"r");

	if(f==NULL){
		printf("Arquivo vazio!\n");
	}
	else{
		while(!feof(f)){
			fgets(linhaArq,100,f);

			aux = insere_livro_arq(linhaArq);
			biblioteca = insere_no(biblioteca,aux);
		}
	}

	opcao = menu_ini();

	while(opcao != 0){
		switch (opcao){
			case 1://inserir livro
				aux = insere_livro();
				biblioteca = insere_no(biblioteca,aux);
				msg_sucess();
				break;
			case 2://remover livro
				remover = menu_remove();
				biblioteca = remove_no(biblioteca,remover);
				msg_sucess_r();
				break;
			case 3://atualizar qtd de algum livro

				break;
			case 4://procurar livro

				break;
			case 5://imprimir arvore,arvore por nivel e o acervo em ordem crescente
				system("cls");
				opcao = menu_print();
				switch(opcao){
					case 1://imprimir arvore pre-ordem
						printa_arvore(biblioteca);
						printf("\n");
						break;
					case 2://imprimir arvore por nivel
						break;
					case 3://imprimir acervo em ordem crescente
						system("cls");
						menu_ordem();
						printa_ord(biblioteca);
						printf("\n");
						break;
					case 0:
						break;
					default:
						erro_op();
				}
				break;
			default:
				erro_op();
		}
		system("PAUSE");
		opcao = menu_ini();
	}
	system("cls");

	free(aux);
	free(biblioteca);
	return 0;
}