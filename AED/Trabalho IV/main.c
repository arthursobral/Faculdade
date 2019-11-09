#include "trie.h"

int main(int arqc, const char *arqv[]){
	Trie *raiz = inicializa();
	char s[100],linhaArq[200],*nomeArquivo;
    int opcao;
    FILE *dicionario;

    nomeArquivo = nome_Arq(arqv+1);

    dicionario = fopen(nomeArquivo,"r");
    insere_arq(raiz,dicionario);
    opcao = menu_ini();

    while(opcao!=0){
        switch (opcao){
        case 1:
            system("cls");
            msg_dicionario();
            printa(raiz,s,0);
            break;
        case 2:
            system("cls");
            consultar(raiz);
            break;
        case 3:
            system("cls");
            remove_stopwords(&raiz);
            break;
        default:
            system("cls");
            erro();
            break;
        }
        system("pause");
        opcao = menu_ini();
    }
    fclose(dicionario);

    free(raiz);

	return 0;
}