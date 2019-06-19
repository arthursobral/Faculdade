#include "biblioteca.h"
#include "menu.h"

char *nome_Arq(char const *argv[]){
    return ((char*)argv[0]); //char*: convertendo o tipo de dado para string
}

Livros *insere_livro(){
	Livros *l = (Livros*)malloc(sizeof(Livros));

	menu_insere();

	gotoXY(10,3);
	scanf("%d",&l->acervo);

	fflush(stdin);
	gotoXY(10,4);
	scanf("%[^\n]%*c",l->titulo);

	fflush(stdin);
	gotoXY(9,5);
	scanf("%[^\n]%*c",l->autor);

	fflush(stdin);
	gotoXY(14,6);
	scanf("%d",&l->qtd);

	return l;
}

Livros *insere_livro_arq(char *linhaArq){
	int n=0,np;

	Livros *l = (Livros*)malloc(sizeof(Livros));

	sscanf(linhaArq,"%d;%n",&l->acervo,&np);
	n+=np;

	sscanf(linhaArq + n,"%[^;];%n",l->titulo,&np);
	n+=np;

	sscanf(linhaArq + n,"%[^;];%n",l->autor,&np);
	n+=np;

	sscanf(linhaArq + n,"%d;%n",&l->qtd,&np);

	return l;
}