#include "arvore.h"
#include <string.h>


///
/// \brief verifica se o char eh ou nao um espaco ou um \t ou um \n
/// \param um caracter a ser verificado
/// \retorna 1 se for espaco, '\n' ou '\t' e 0 caso contrario
///
int verifica_espaco(char c){
	
    return c == ' ' || c == '\n' || c == '\t'; 
}

///
/// \brief retira os espacos extras no comeco e no final da string
/// \param a string a ser verificada
///
void retira_espaco(char s[]){
    char *aux = s;
    char *aux1 = s;

    while(verifica_espaco(*aux1)){
        ++aux1;
    }

    while(*aux1){
        *aux++ = *aux1++;
    }

    if(aux>s){
        while(verifica_espaco(aux[-1])){
            --aux;
        }
    }
    *aux = '\0';
}

///
/// \brief transforma o que foi lido do cmd para string 
/// \param argv: uma constante contendo o que foi lido do cmd
/// \return retorna a constante em forma de string
///
char *nome_Arq(char const *argv[]){
    
    return ((char*)argv[0]); //char*: convertendo o tipo de dado para string
}

///
/// \brief funcao que insere uma estrutura do tipo CabecalhoLivro na primeira posicao do arquivo livros.bin
/// \param livrosBin: arquivo dos livros
/// \param livro: cabecalho do arquivo dos livros
///
void escr_cab_livro(FILE *livrosBin, CabecalhoLivro *livro){

	if(!livro){
		return;
	}

	//fseek: move para determinado ponto do arquivo
	//SEEK_SET: move para o inico do arquivo
	fseek(livrosBin, 0, SEEK_SET);

	//fwrite: escreve no arquivo livrosBin o cabecalho do livro passado como parametro
	fwrite(livro, sizeof(CabecalhoLivro), 1, livrosBin);
}

///
/// \brief funcao para inicializar o cabecalho dos livros
/// \param livrosBin: arquivo dos livros
///
void cria_cabe_livro(FILE *livrosBin){

	CabecalhoLivro livro;

	livro.topo = 0;
	livro.livre = -1;

	escr_cab_livro(livrosBin, &livro);
}

///
/// \brief funcao que escreve o cabeçalho do arquivo da arvore
/// \param arvoreBin: arquivo da arvore
/// \param arvore: cabeçalho do arquivo da arvore
///
void escr_cab_arv(FILE *arvoreBin, Cabecalho *arvore){

	if(!arvore){
		return;
	}
	//movendo para o começo do arquivo
	fseek(arvoreBin, 0, SEEK_SET);

	fwrite(arvore, sizeof(Cabecalho), 1, arvoreBin);
}
///
/// \brief funcao para inicializar o caçalho da arvore
/// \param arvoreBin: arquivo da arvore
///
void cria_cabe_arv(FILE *arvoreBin){

	Cabecalho arvore;

	arvore.raiz = -1;
	arvore.topo = 0;
	arvore.livre = -1;

	escr_cab_arv(arvoreBin, &arvore);
}

///
/// \brief funcao que le os livros do arquivo do livros
/// \param livrosBin: arquivo dos livros
/// \param pos: posicao do livro no arquivo dos livros
/// \return retorna o livro da posição lida no arquivo
///
Livros* le_livros(FILE *livrosBin, int pos){

	Livros *aux;

	if(pos == -1){
		return NULL;
	}

	aux = (Livros*)malloc(sizeof(Livros));

	//procura no arquivo livros.bin, desde o começo do arquivo, o livro na posição passado por parametro
	fseek(livrosBin, sizeof(CabecalhoLivro) + sizeof(Livros)*pos, SEEK_SET);

	//insere em aux o livro daquela posição
	fread(&aux->codigo, sizeof(int), 1, livrosBin);
	fread(aux->titulo, sizeof(char)*100, 1, livrosBin);
	fread(aux->autor, sizeof(char)*100, 1, livrosBin);
	fread(&aux->qtd, sizeof(int), 1, livrosBin);

	return aux;
}

///
/// \brief funcao que le os nós da arvore do arquivo arvore.bin
/// \param arvoreBin: arquivo da arvore
/// \param pos: posicao do nó no arquivo da arvore
/// \return retorna o nó da posição lida no arquivo
///
Arvore* le_nos(FILE *arvoreBin, int pos){

	Arvore *aux;

	if(pos == -1){
		return NULL;
	}

	aux = (Arvore*)malloc(sizeof(Arvore));

	//procura no arquivo arvore.bin, desde o começo do arquivo, o nó na posição passada por parametro
	fseek(arvoreBin, sizeof(Cabecalho) + sizeof(Arvore)*pos, SEEK_SET);

	//insere em aux o nó daquela posição
	fread(aux, sizeof(Arvore), 1, arvoreBin);

	return aux;
}

///
/// \brief funcao que le o cabeçalho do arquivo livros.bin 
/// \param livrosBin: arquivo dos livros
/// \return o cabeçalho lido do arquivo
///
CabecalhoLivro* le_cab_livro(FILE *livrosBin){

	CabecalhoLivro *aux = (CabecalhoLivro*)malloc(sizeof(CabecalhoLivro));

	//vai para a primeira posicao do arquivo
	fseek(livrosBin, 0, SEEK_SET);

	//insere em aux o cabeçalho do arquivo livros.bin
	fread(aux, sizeof(CabecalhoLivro), 1, livrosBin);

	return aux;
}

///
/// \brief funcao que le o cabeçalho do arquivo arvore.bin 
/// \param arvoreBin: arquivo da arvore
/// \return o cabeçalho lido do arquivo
///
Cabecalho* le_cab_arvore(FILE *arvoreBin){

	Cabecalho *aux = (Cabecalho*)malloc(sizeof(Cabecalho));

	fseek(arvoreBin, 0, SEEK_SET);

	fread(aux, sizeof(Cabecalho), 1, arvoreBin);

	return aux;
}

///
/// \brief funcao que inicializa uma variavel do tipo Livros
/// \return variavel inicializada
///
Livros* inicializa_livro(){

	Livros *novo = (Livros*)malloc(sizeof(Livros));

	novo->codigo = 0;
	novo->titulo[0] = '\0';
	novo->autor[0] = '\0';
	novo->qtd = 0;

	return novo;
}

///
/// \brief funcao que inicializa uma variavel do tipo Arvore
/// \return variavel inicializada
///
Arvore* inicializa_arvore(){

	Arvore *aux = (Arvore*)malloc(sizeof(Arvore));

	Infos reg;
	reg.codigo = 0;
	reg.posicao = -1;

	aux->registro = reg;
	aux->dir = -1;
	aux->esq = -1;
	aux->posicao = -1;

	return aux;
}

///
/// \brief funcao que pega o nó da posição passada como parametro
/// \param arvoreBin: arquivo da arvore
/// \param pos: posição do nó livre
/// \return nó livre
///
NoLivre* pega_no_livre(FILE *arvoreBin, int pos){

	if(pos == -1){
		return NULL;
	}

	NoLivre *aux = (NoLivre*)malloc(sizeof(NoLivre));

	fseek(arvoreBin, sizeof(Cabecalho) + sizeof(Arvore)*pos, SEEK_SET);

	fread(aux, sizeof(NoLivre), 1, arvoreBin);

	return aux;
}

///
/// \brief funcao que pega o livro da posição passada como parametro
/// \param livrosBin: arquivo dos livros
/// \param pos: posição do livro livre
/// \return livro livre
///
LivroLivre* pega_livros_livres(FILE *livrosBin, int pos){

	if(pos == -1){
		return NULL;
	}

	LivroLivre *aux = (LivroLivre*)malloc(sizeof(LivroLivre));

	fseek(livrosBin, sizeof(CabecalhoLivro) + sizeof(Livros)*pos, SEEK_SET);

	fread(aux, sizeof(LivroLivre), 1, livrosBin);

	return aux;
}

///
/// \brief funcao que escreve o livro no arquivo dos livros
/// \param livrosBin: arquivo dos livros
/// \param cab_livro: cabeçalho do arquivo dos livros
/// \param livro: livro a ser escrito
/// \return posição de onde foi escrito no arquivo
///
int escreve_livro(FILE *livrosBin, CabecalhoLivro *cab_livro, Livros *livro){

	int pos;

	if(!cab_livro){
		return -1;
	}

	//recebe a posição de um registro livre
	pos = cab_livro->livre;

	//verifica se esta livre, e se nao estiver, avança para a posição seguinte do topo
	if(pos == -1){
		pos = cab_livro->topo++;
	}

	else{
		LivroLivre *novo = pega_livros_livres(livrosBin, pos);
		cab_livro->livre = novo->prox;
		free(novo);
	}

	fseek(livrosBin, sizeof(CabecalhoLivro) + sizeof(Livros) *pos, SEEK_SET);

	fwrite(&livro->codigo, sizeof(int), 1, livrosBin);
	fwrite(livro->titulo, sizeof(char), 100, livrosBin);
	fwrite(livro->autor, sizeof(char), 100, livrosBin);
	fwrite(&livro->qtd, sizeof(int), 1, livrosBin);

	return pos;
}

///
/// \brief funcao que escreve o nó da arvore no arquivo arvore.bin
/// \param arvoreBin: arquivo da arvore
/// \param no: nó da arvore a ser escrita
/// \param arvore: cabeçalho do arquivo da arvore
/// \return posição do nó escrito no arquivo
///
int escreve_arvore(FILE *arvoreBin, Arvore *no, Cabecalho *arvore){

	//verica se o nó e o cabeçalho da arvore existem
	if(!no || !arvore){

		return -1;
	}

	//posicao recebe o começo da arvore, ou seja, a raiz
	int posicao = no->posicao;

	if(posicao == -1){

		posicao = arvore->livre;
		if(posicao == -1){
			
			posicao = arvore->topo++;
		}
		else{

			NoLivre* livres = pega_no_livre(arvoreBin, posicao);
			arvore->livre = livres->prox;
			free(livres);
		}
	}

	no->posicao = posicao;

	fseek(arvoreBin, sizeof(Cabecalho) + sizeof(Arvore)*posicao, SEEK_SET);
	fwrite(no, sizeof(Arvore), 1, arvoreBin);

	return posicao;
}

///
/// \brief funcao que insere no arquivo da arvore um nó contendo as informações do livro
/// \param arvoreBin: arquivo da arvore
/// \param codigo: codigo do livro a ser inserido
/// \param pos: posição do livro no arquivo livros.bin
///
void insere(FILE *arvoreBin, int codigo, int pos){

	Infos info;	

	info.codigo = codigo;
	info.posicao = pos;

	//le o cabeçalho do arquivo da arvore
	Cabecalho *aux = le_cab_arvore(arvoreBin);

	//le a raiz da arvore no arquivo
	Arvore *raiz = le_nos(arvoreBin, aux->raiz);

	if(!raiz){

		raiz = inicializa_arvore();
		raiz->registro = info;
		aux->raiz = escreve_arvore(arvoreBin, raiz, aux);
	}

	else{
		//cria novo nó a ser inserido
		Arvore *novo, *no_pai;

		novo = inicializa_arvore();
		novo->registro = info;

		while(raiz != NULL){

			//nó que guarda o pai do novo nó que vai ser inserido
			no_pai = le_nos(arvoreBin, raiz->posicao);

			//verifica para que lado do nó vai ser inserido
			if(raiz->registro.codigo < novo->registro.codigo){

				raiz = le_nos(arvoreBin, raiz->dir);
			}
			else if(raiz->registro.codigo > novo->registro.codigo){
	
				raiz = le_nos(arvoreBin, raiz->esq);
			}
			//se os códigos forem iguais, não faz nada
			else
				break;

		}

		//se chegou aonde não tem nó, insere
		if(raiz == NULL){

			int no_pos;
			//insere no arquivo arvore.bin o nó e retorna sua posição
			no_pos = escreve_arvore(arvoreBin, novo, aux);
			//verifica se o novo nó vai para esquerda ou direita do pai
			if(no_pai->registro.codigo > novo->registro.codigo){
				//novo nó vai para a esquerda do pai
				no_pai->esq = no_pos;
			}
			else{
				//novo nó vai para a direita do pai
				no_pai->dir = no_pos;
			}
			//reescreve o pai
			escreve_arvore(arvoreBin, no_pai, aux);
		}
	}

	escr_cab_arv(arvoreBin, aux);
	free(aux);
}

LivroLivre* cria_livro_livre(){

	LivroLivre* novo = (LivroLivre*)malloc(sizeof(LivroLivre));

	novo->prox = -1;

	return novo;
}

void escreve_livro_livres(FILE* arvoreBin, CabecalhoLivro* cab, int pos){

	if(!cab || pos == -1) return;

	int posicao = pos;
	LivroLivre* novo = cria_livro_livre();

	novo->prox = cab->livre;
	cab->topo--;
	cab->livre = posicao;

	fseek(arvoreBin, sizeof(CabecalhoLivro) + sizeof(Livros)*posicao, SEEK_SET);
	fwrite(novo, sizeof(LivroLivre), 1, arvoreBin);

	free(novo);
}

NoLivre* cria_no_livre(){

	NoLivre* novo = (NoLivre*)malloc(sizeof(NoLivre));

	novo->prox = -1;

	return novo;
}

void escreve_no_livres(FILE* arvoreBin, Cabecalho* cab, Arvore* arv){

	if(!cab || arv->posicao == -1) return;

	int posicao = arv->posicao;
	NoLivre* novo = cria_no_livre();

	novo->prox = cab->livre;
	cab->topo--;
	cab->livre = posicao;

	fseek(arvoreBin, sizeof(Cabecalho) + sizeof(Arvore)*posicao, SEEK_SET);
	fwrite(novo, sizeof(NoLivre), 1, arvoreBin);

	free(novo);
}

int valor_min(FILE* arvoreBin, Arvore* raiz){

	while(raiz != NULL && raiz->esq != -1){

		raiz = le_nos(arvoreBin, raiz->esq);
	}

	return raiz->posicao;
}

int valor_max(FILE* arvoreBin, Arvore* raiz){

	while(raiz != NULL && raiz->dir != -1){

		raiz = le_nos(arvoreBin, raiz->dir);
	}

	return raiz->posicao;
}

void remover(FILE* arvoreBin, FILE* livrosBin){

	int codigo;
	
	printf("Entre com o codigo do livro a ser removido: ");
	scanf("%d", &codigo);

	Cabecalho *cab_arv = le_cab_arvore(arvoreBin);
	CabecalhoLivro *cab = le_cab_livro(livrosBin);

	Arvore *raiz = le_nos(arvoreBin, cab_arv->raiz);

	if(codigo > 0){

		printf("Buscando .");
		retira(arvoreBin, livrosBin, codigo, raiz);
	}
}

int retira(FILE* arvoreBin, FILE* livrosBin, int codigo, Arvore* raiz){

	if(codigo <= 0) return -1;

	printf(".");

	if(raiz == NULL) {
		printf("Codigo de Livro nao achado\n");
		return -1;
	}

	Cabecalho *cab_arv = le_cab_arvore(arvoreBin);
	CabecalhoLivro *cab = le_cab_livro(livrosBin);
	
	if(raiz->registro.codigo > codigo){

		raiz->esq = retira(arvoreBin, livrosBin, codigo, le_nos(arvoreBin, raiz->esq));
		escreve_arvore(arvoreBin, raiz, cab_arv);
	}
	else if(raiz->registro.codigo < codigo){

		raiz->dir = retira(arvoreBin, livrosBin, codigo, le_nos(arvoreBin, raiz->dir));
		escreve_arvore(arvoreBin, raiz, cab_arv);
 	}
 	else{

		escreve_livro_livres(livrosBin, cab, raiz->registro.posicao);

 		if(raiz->esq == -1 && raiz->dir == -1){

			escreve_no_livres(arvoreBin, cab_arv, raiz);

			escr_cab_livro(livrosBin, cab);
			escr_cab_arv(arvoreBin, cab_arv);

			return -1;
 		}
 		else if(raiz->esq == -1){

 			Arvore* minimo = le_nos(arvoreBin, valor_min(arvoreBin, le_nos(arvoreBin, raiz->dir)));

 			int ant_pos_livro = minimo->registro.posicao;

 			minimo->registro.posicao = -1;
 			
 			escreve_arvore(arvoreBin, minimo, cab_arv);
			retira(arvoreBin, livrosBin, minimo->registro.codigo, le_nos(arvoreBin, raiz->dir));

			if(raiz->dir != minimo->posicao)
				minimo->dir = raiz->dir;

			if(cab_arv->raiz == raiz->posicao)
				cab_arv->raiz = minimo->posicao;

 			minimo->registro.posicao = ant_pos_livro;

			escreve_arvore(arvoreBin, minimo, cab_arv);

 			escr_cab_livro(livrosBin, cab);
			escr_cab_arv(arvoreBin, cab_arv);

			return minimo->posicao;
 		}
 		else{

 			Arvore* maximo = le_nos(arvoreBin, valor_max(arvoreBin, le_nos(arvoreBin, raiz->esq)));

 			int ant_pos_livro = maximo->registro.posicao;

 			maximo->registro.posicao = -1;
 			
 			escreve_arvore(arvoreBin, maximo, cab_arv);
			retira(arvoreBin, livrosBin, maximo->registro.codigo, le_nos(arvoreBin, raiz->esq));

			if(raiz->esq != maximo->posicao)
				maximo->esq = raiz->esq;

			if(cab_arv->raiz == raiz->posicao)
				cab_arv->raiz = maximo->posicao;

			maximo->dir = raiz->dir;

 			maximo->registro.posicao = ant_pos_livro;

			escreve_arvore(arvoreBin, maximo, cab_arv);

 			escr_cab_livro(livrosBin, cab);
			escr_cab_arv(arvoreBin, cab_arv);

			return maximo->posicao;
 		}
 	}
}

///
/// \brief função para ler uma linha do arquivo texto e inserir nos arquivos binários
/// \param livrosBin: arquivo dos livros
/// \param arvoreBin: arquivo da arvore
/// \param linhaArq: string que contém o nome do arquivo
///
void le_arq(FILE *livrosBin, FILE *arvoreBin, char *linhaArq){

	int i = 0, tam_lido;

	CabecalhoLivro *cab_livro = le_cab_livro(livrosBin);
	Livros *livro = inicializa_livro();

	sscanf(linhaArq,"%d;%n", &livro->codigo, &tam_lido);
	i += tam_lido;

	sscanf(linhaArq + i, "%[^;];%n", livro->titulo, &tam_lido);
	retira_espaco(livro->titulo);
	i += tam_lido;

	sscanf(linhaArq + i,"%[^;];%n", livro->autor, &tam_lido);
	retira_espaco(livro->autor);
	i += tam_lido;

	sscanf(linhaArq + i,"%d", &livro->qtd);


	int pos;

	pos = escreve_livro(livrosBin, cab_livro, livro);

	insere(arvoreBin, livro->codigo, pos);
	escr_cab_livro(livrosBin, cab_livro);	
	free(livro);
}

Arvore* busca_no(FILE *arvoreBin,Arvore *raiz,int p){
	if(raiz == NULL){
		return NULL;
	}
	if(raiz->registro.codigo > p){
		return busca_no(arvoreBin,le_nos(arvoreBin,raiz->esq),p);
	}
	if(raiz->registro.codigo < p){
		return busca_no(arvoreBin,le_nos(arvoreBin,raiz->dir),p);
	}
	return raiz;
}

void leStd(FILE *livrosBin, FILE *arvoreBin){
	Livros *livro = inicializa_livro();
	CabecalhoLivro *cab_livro = le_cab_livro(livrosBin);

	menu_insere_livro();
	gotoXY(9,3);
	scanf("%d",&livro->codigo);

	fflush(stdin);
	gotoXY(9,4);
	scanf("%[^\n]%*c",livro->titulo);

	fflush(stdin);
	gotoXY(8,5);
	scanf("%[^\n]%*c",livro->autor);

	fflush(stdin);
	gotoXY(13,6);
	scanf("%d",&livro->qtd);

	int pos;

	pos = escreve_livro(livrosBin, cab_livro, livro);
	insere(arvoreBin, livro->codigo, pos);
	escr_cab_livro(livrosBin, cab_livro);
	free(livro);
}

void printa_livro(Livros *l){
	printf("+---------------------------------------------------------+\n");
	printf("| Codigo: %-48d|\n", l->codigo);
	printf("| Titulo: %-48s|\n", l->titulo);
	printf("| Autor: %-49s|\n", l->autor);
	printf("| Quantidade: %-44d|\n", l->qtd);
	printf("+---------------------------------------------------------+\n");
}


///
/// \brief função que printa os livros dentro do arquivo de livros
/// \param livrosBin: arquivo dos livros
///
void printa_arq(FILE *livrosBin){

	Livros *l;

	CabecalhoLivro *cabecalho = le_cab_livro(livrosBin);
	printf("Quantidade de livros: %d\n", cabecalho->topo);
	//*l = (Livros**)malloc(sizeof(Livros*)*cabecalho->topo);
	int i;

	for(i = 0; i < cabecalho->topo; i++){

		printf("\n");
		printf("Livro [%d]\n", i+1);
		l = le_livros(livrosBin, i);
		printf("codigo: %d\n", l->codigo);
		printf("titulo: %s\n", l->titulo);
		printf("autor: %s\n", l->autor);
		printf("qtd: %d\n", l->qtd);
	}
}

///
/// \brief função que printa o nó atual e chama recursivamente os filhos
/// \param arvoreBin: arquivo da arvore
/// \param raiz: nó a ser impresso
///
void printa_no(FILE* arvoreBin, Arvore* raiz){

	if(raiz == NULL)
		printf("[]");

	else{
		printf("[%d, ", raiz->registro.codigo);
		printa_no(arvoreBin, le_nos(arvoreBin, raiz->esq));
		printf(",");
		printa_no(arvoreBin, le_nos(arvoreBin, raiz->dir));
		printf("]");
	}
}

///
/// \brief função que le o cabeçalho e chama a função de printar os nós
/// \param arvoreBin: arquivo da arvore
///
void printa_arv(FILE* arvoreBin){

	Cabecalho* cab = le_cab_arvore(arvoreBin);
	Arvore* raiz = le_nos(arvoreBin, cab->raiz);

	printa_no(arvoreBin, raiz);
}

void inordem(FILE *arvoreBin, FILE *livrosBin, Arvore *raiz,Livros *livro){
	if(raiz != NULL){
		inordem(arvoreBin,livrosBin,le_nos(arvoreBin, raiz->esq),livro);
		livro = le_livros(livrosBin,raiz->registro.posicao);
		printa_livro(livro);
		inordem(arvoreBin,livrosBin,le_nos(arvoreBin,raiz->dir),livro);
	}
}

void printa_inordem(FILE *arvoreBin, FILE *livrosBin){
	Cabecalho* cab = le_cab_arvore(arvoreBin);
	Arvore* raiz = le_nos(arvoreBin, cab->raiz);
	Livros *livro;

	inordem(arvoreBin, livrosBin, raiz, livro);
}


int altura(FILE *arvoreBin, Arvore *raiz){
	if(raiz != NULL){
		int tam_esq,tam_dir;

		tam_esq = altura(arvoreBin,le_nos(arvoreBin,raiz->esq));
		tam_dir = altura(arvoreBin,le_nos(arvoreBin,raiz->dir));

		if(tam_esq > tam_dir){
			return tam_esq+1;
		}else{
			return tam_dir+1;
		}
	}
	return 0;
}

void imprime(FILE *arvoreBin, Arvore *raiz, int nivel){
	if(raiz != NULL){
		if(nivel == 0){
			printf("%d ", raiz->registro.codigo);
		}
		else{
			imprime(arvoreBin,le_nos(arvoreBin,raiz->esq),nivel-1);
			imprime(arvoreBin,le_nos(arvoreBin,raiz->dir),nivel-1);
		}
	}
}

void imprime_nivel(FILE *arvoreBin){
	Cabecalho *aux = le_cab_arvore(arvoreBin);
	Arvore *raiz = le_nos(arvoreBin, aux->raiz);

	int i, alt = altura(arvoreBin,raiz);

	for(i=0;i<alt;i++){
		imprime(arvoreBin,raiz,i);
		printf("\n");
	}
}

void buscar(FILE *arvoreBin,FILE *livrosBin){
	Arvore *achou;
	Cabecalho *aux = le_cab_arvore(arvoreBin);
	Arvore *raiz = le_nos(arvoreBin,aux->raiz);
	int p;

	system("cls");
	p = procurado();

	achou = busca_no(arvoreBin,raiz,p);

	if(achou == NULL){
		nao_encontrado();
	}
	else{
		Livros *l;

		l = le_livros(livrosBin,achou->registro.posicao);
		printa_livro(l);
	}
	free(achou);
}

void atualiza(FILE *arvoreBin,FILE *livrosBin){
	Arvore *achou;
	Cabecalho *aux = le_cab_arvore(arvoreBin);
	Arvore *raiz = le_nos(arvoreBin,aux->raiz);
	int p;

	system("cls");
	p = procurado();

	achou = busca_no(arvoreBin,raiz,p);
	if(achou == NULL){
		nao_encontrado();
	}
	else{
		Livros *l;
		int qtd;

		l = le_livros(livrosBin,achou->registro.posicao);
		qtd = atualiza_qtd_msg();

		l->qtd = qtd;
		printa_livro(l);

		fseek(livrosBin, sizeof(CabecalhoLivro) + sizeof(Livros) * achou->registro.posicao, SEEK_SET);

		fwrite(&l->codigo, sizeof(int), 1, livrosBin);
		fwrite(l->titulo, sizeof(char), 100, livrosBin);
		fwrite(l->autor, sizeof(char), 100, livrosBin);
		fwrite(&l->qtd, sizeof(int), 1, livrosBin);
	}

	free(achou);
}
