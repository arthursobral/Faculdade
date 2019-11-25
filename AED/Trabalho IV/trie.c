#include "trie.h"

///
/// \brief transforma o que foi lido do cmd para string 
/// \param argv: uma constante contendo o que foi lido do cmd
/// \return retorna a constante em forma de string
///
char *nome_Arq(char const *argv[]){
    
    return ((char*)argv[0]); //char*: convertendo o tipo de dado para string
}

///
/// \brief verifica se nao existe acento ou um caracter fora do alfabeto, enquanto transforma as maisculas em minusculas
/// \param s: a palavra a ser verificada caracter por caracter
/// \return retorna 1 caso esteja tudo certo com a palavra 0 caso ao contrario
/// \pre nenhuma
/// \pos nenhuma
///
int verifica(char s[]){
	int i;

	for(i=0;i < strlen(s); i++){

		if(isalpha(s[i])){
			if(isupper(s[i])){
				s[i] = tolower(s[i]);
			}
		}else{
			return 0;
		}
	}
	return 1;
}

///
/// \brief inicializa a varivel
/// \return retorna a trie inicializada
/// \pre variavel inexistente
/// \pos variavel existente
///
Trie *inicializa(){
	int i;
	Trie *novo = (Trie*)malloc(sizeof(Trie));
	novo->final = 0;

	for(i=0; i < ALFABETO; i++){
		novo->filhos[i] = NULL;
	}

	return novo;
}


///
/// \brief insere a palavra na trie
/// \param raiz: raiz da trie
/// \param s: palavra a ser inserida
/// \pre nenhuma
/// \pos trie com a palavra inserida
///
void insere(Trie *raiz, char *s){
	Trie *aux = raiz;

	while(*s){
		if(aux->filhos[*s - 'a'] == NULL){
			aux->filhos[*s - 'a'] = inicializa();
		}
		aux = aux->filhos[*s - 'a'];

		s++;
	}
	aux->final = 1;
}

///
/// \brief puxa do arquivo para inserir a palavra na trie
/// \param raiz: raiz da trie
/// \param dicionario: arquivo contendo todas as palavras a serem inseridas
/// \pre nenhuma
/// \pos trie com as palavras inseridas
///
void insere_arq(Trie *raiz,FILE *dicionario){
	int i = 0, tam_lido;
	char palavra[100];

	while (!feof(dicionario)){
		fscanf(dicionario,"%s",palavra);
		if(verifica(palavra)){
			insere(raiz,palavra);
		}
	}
}

///
/// \brief printa o dicionario inserido
/// \param raiz: raiz da trie
/// \param palavra: palavra a ser incrementada para ser printada
/// \param indice: posicao onde o caracter vai na palavra
/// \pre trie inicializada com pelo menos uma palavra, ou seja, nao vazia
/// \pos nenhuma
///
void printa(Trie *raiz, char palavra[],int indice){
	int i;

	if(raiz->final == 1){
		palavra[indice] = '\0';
		printf("+------------------------------------+\n");
		printf("|         %-27s|\n",palavra);
		printf("+------------------------------------+\n");
	}

	for (i = 0; i < ALFABETO; i++){
		if(raiz->filhos[i] != NULL){
			palavra[indice] = i + 'a';
			printa(raiz->filhos[i],palavra,indice+1);
		}
	}
}

///
/// \brief verifica se o nó passado tem algum filho
/// \param raiz: raiz da trie
/// \return retorna 1 se ele acha algum filho, 0 caso o contrario
/// \pre nenhuma
/// \pos nenhuma
///
int verifica_filho(Trie *raiz){
	int i;

	for(i=0; i<ALFABETO; i++){
		//verifica se achou um filho
		if(raiz->filhos[i]){
			return 1;
		}
	}
	return 0;
}

///
/// \brief remove a palavra da trie
/// \param raiz: raiz da trie
/// \param s: palavra a ser removida
/// \return 1 para deletar os pais e 0 para nao deletar os pais
/// \pre nenhuma
/// \pos trie com a palavra removida
///
int remover(Trie **raiz, char *s){
	if(*raiz == NULL){
		return 0;
	}

	if(*s){
		//recursiva para achar o char correspondende
		//se for 1 deleta o no atual
		//(se nao for o final) 
		if(*raiz != NULL && (*raiz)->filhos[*s - 'a'] != NULL && remover(&((*raiz)->filhos[*s - 'a']),s + 1) && (*raiz)->final == 0){
			if(!verifica_filho(*raiz)){
				free(*raiz);
				(*raiz) = NULL;
				return 1;
			}else{
				return 0;
			}
		}
	}

	//se chegamos no final da palavra
	if(*s == '\0' && (*raiz)->final){

		//verifica se ele é o final da palavra e nao tem filhos (ou seja uma folha)
		if(!verifica_filho(*raiz)){
			free(*raiz);
			(*raiz) = NULL;
			return 1; //usado na chamada recursiva para deletar caso precise
		}
		else{// caso ele tenha um filho ele nao deleta
			//ele so tira o final
			(*raiz)->final = 0;
			return 0; //usado na chamada recursiva para nao deletar os pais
		}
	}
	return 0;
}

///
/// \brief puxa do arquivo para remover as palavras da trie
/// \param raiz: raiz da trie
/// \pre nenhuma
/// \pos trie com as palavras removidas
///
void remove_stopwords(Trie **raiz){
	int i = 0, tam_lido;
	char palavra[100], aux[100];
	menu_remove();
	gotoXY(10,2);
	scanf("%s",aux);
	FILE *stopwords = fopen(aux,"r");

	if(stopwords == NULL){
		erro_arq();
		return;
	}

	while (!feof(stopwords)){
		fscanf(stopwords,"%s",palavra);
		if(verifica(palavra)){
			remover(&(*raiz),palavra);
		}
	}
	msg_sucess();
	fclose(stopwords);
}

///
/// \brief funcao auxiliar para a semelhantes, mesma coisa que o printa porém printa no max dez palavras
/// \param raiz: raiz da trie
/// \param s: palavra a ser incrementada para printar
/// \param indice: onde ira ser incrementado o caracter na palavra
/// \param contador: contador de 0 ate 9 para printar no maximo dez palavras
/// \pre nenhuma
/// \pos nenhuma
///
void printa_aux(Trie *raiz, char palavra[],int indice,int *contador){
	int i;

	if(raiz->final == 1){
		palavra[indice] = '\0';
		(*contador)++;
		printf("%s, ",palavra);
	}

	for (i = 0; i < ALFABETO && (*contador) < 10; i++){
		if(raiz->filhos[i] != NULL){
			palavra[indice] = i + 'a';
			printa_aux(raiz->filhos[i],palavra,indice+1,contador);
		}
	}
}

///
/// \brief consulta a palavra na trie
/// \param raiz: raiz da trie
/// \pre nenhuma
/// \pos nenhuma
///
void consultar(Trie *raiz){
	char palavra[100];
	int indice, i, contador = 0;

	menu_consultar();
	gotoXY(10,2);
	scanf("%s",palavra);

	indice = strlen(palavra);

	if(verifica(palavra) == 0){
		erro_prefix();
		return;
	}

	for(i=0; i < indice; i++){
		if(raiz->filhos[palavra[i] - 'a'] != NULL){
			raiz = raiz->filhos[palavra[i] - 'a'];
		}else{
			erro_prefix();
			return;
		}
	}

	if(raiz == NULL){
		erro_prefix();
		return;
	}

	printf("\n");
	printa_aux(raiz,palavra,indice,&contador);
	printf("\n");
}

///
/// \brief verifica se sao palavras semelhantes
/// \param s1: string contendo a palavra
/// \param s2: string contendo o prefixo
/// \param dife: o total maximo que pode ter de diferença entre a palavra e o prefixo
/// \return 0 caso a nao serem semelhantes conforme a variavel dife e 1 caso o contrario
/// \pre nenhuma
/// \post nenhuma
///
int semelhantes(char* s1, char* s2, int dife){
    if(dife<0)
        return 0;

    if(!*s1 && !*s2)
        return 1;

    if(!*s1)
        return strlen(s2) <=dife;

    if(!*s2)
        return strlen(s1) <= dife;

    if(*s1 == *s2)
        return semelhantes(s1+1, s2+1, dife);

    --dife;

    if(semelhantes(s1, s2+1, dife))
        return 1;

    if(semelhantes(s1+1, s2, dife))
        return 1;

    if(semelhantes(s1+1, s2+1, dife))
        return 1;

    return 0;
}

///
/// \brief funcao auxiliar para a semelhantes
/// \param raiz: raiz da trie
/// \param palavra: palavra a ser incrementada para printar
/// \param prefix: prefixo para comparar a diferenca entre a palavra
/// \param indice: onde ira ser incrementado o caracter na palavra
/// \param dife: total de diferença entre a palavra e o prefix  
/// \pre nenhuma
/// \pos nenhuma
///
void printa_semelhantes(Trie *raiz, char *palavra, char *prefix, int indice,int dife){
	if(raiz->final == 1 && semelhantes(palavra,prefix,dife)){
		palavra[indice] = '\0';
		printf("+------------------------------------+\n");
		printf("|         %-27s|\n",palavra);
		printf("+------------------------------------+\n");
	}

	int i;

	for (i = 0; i < ALFABETO; i++){
		if(raiz->filhos[i] != NULL){
			palavra[indice] = i + 'a';
			printa_semelhantes(raiz->filhos[i],palavra,prefix,indice+1,dife);
		}
	}
}

///
/// \brief funcao para a chamada da funcao semelhantes
/// \param raiz: raiz da trie
/// \pre trie nao vazia
/// \post nenhuma
///
void chama_semelhantes(Trie *raiz){
	char palavra[256], prefix[256];
	int qtd;

	system("cls");
	menu_semelhantes();
	gotoXY(10,2);
	scanf("%s",prefix);
	gotoXY(10,5);
	scanf("%d",&qtd);

	printf("\n");
	printa_semelhantes(raiz,palavra,prefix,0,qtd);
}