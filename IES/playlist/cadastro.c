#include "cadastro.h"
#include "data.h"
#include <time.h>

///
/// \brief inicializa a data como 1/1/1 caso nao seja colocado a data de nascimento.
///
Data inicializaData(){
    Data new;
    new.dia = 1;
    new.mes = 1;
    new.ano = 1;

    return new;
}

///
/// \brief grava cada dado escrito no cadastro.
/// \return ira retornar tudo que sera escrito dentro do arquivo.
/// \pre nao tem
/// \post nao tem
///
Cadastro* inicializa(){

	Cadastro* new = (Cadastro*)malloc(sizeof(Cadastro));

	new->nome = (char*)malloc(sizeof(char)*100);
	new->sobrenome = (char*)malloc(sizeof(char)*100);
	new->email = (char*)malloc(sizeof(char)*100);
	new->senha = (char*)malloc(sizeof(char)*100);
	new->senha2 = (char*)malloc(sizeof(char)*100);
	new->nascimento = inicializaData();
	new->numero = (char*)malloc(sizeof(char)*100);
	
	return new;
}

///
/// \brief cadastro_save,  Aqui é oque sera printado dentro do arquivo
/// \return mostra no arquivo o tudo que seja correspondente ao cadastro.
///
void cadastro_save(Cadastro *login){
	char* s = (char*)malloc(sizeof(char)*100);

	strcpy(s, login->email);

	strcat(s, ".txt");

	FILE *f = fopen(s, "w+");

    fprintf(f,"Nome:%s\n", login->nome);
    fprintf(f,"Sobrenome:%s\n", login->sobrenome);
    fprintf(f,"email:%s\n", login->email);
    fprintf(f,"senha:%s\n", login->senha);
    fprintf(f,"Redigite a senha:%s\n", login->senha2);
    fprintf(f,"data de nascimento:%d/%d/%d\n", login->nascimento.dia, login->nascimento.mes, login->nascimento.ano);
    fprintf(f,"Telefone:%s\n", login->numero);

    fclose(f);
}
