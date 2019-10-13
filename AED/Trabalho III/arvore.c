#include "arvore.h"

///
/// \brief funcao que diz se houve um overflow no nó, ou seja, se o numero de chaves ultrapassou a quantidade maxima permitida
/// \param r: nó da arvore
/// \return retorna 1 caso houve ovewflow e 0 caso nao houve
/// \pre o nó r deve ter sido alocado
/// \pos nenhuma
///
int overflow(BMais *r){

	return r->numChaves == ORDEM;
}

///
/// \brief verifica se o char eh ou nao um espaco ou um \t ou um \n
/// \param um caracter a ser verificado
/// \retorna 1 se for espaco, '\n' ou '\t' e 0 caso contrario
/// \pre nenhuma
/// \pos nenhuma
///
int verifica_espaco(char c){
	
    return c == ' ' || c == '\n' || c == '\t'; 
}

///
/// \brief retira os espacos extras no comeco e no final da string
/// \param a string a ser verificada
/// \pre nenhuma
/// \pos espaços extras sao retirados da string
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
/// \pre nenhuma
/// \pos nenhuma
///
char* nomeArq(char const *argv[]){
    
    return ((char*)argv[0]); //char*: convertendo o tipo de dado para string
}

///
/// \brief funcao que inicializa uma variavel do tipo Livros
/// \return variavel inicializada
/// \pre nenhuma
/// \pos variavel inicializada
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
/// \brief funcao que le o cabeçalho do arquivo livros.bin 
/// \param livrosBin: arquivo dos livros
/// \return o cabeçalho lido do arquivo
/// \pre nenhuma
/// \pos nenhuma
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
/// \brief funcao que insere uma estrutura do tipo CabecalhoLivro na primeira posicao do arquivo livros.bin
/// \param livrosBin: arquivo dos livros
/// \param livro: cabecalho do arquivo dos livros
/// \pre nenhuma
/// \pos cabeçalho inserido no arquivo
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
/// \brief funcao que pega o livro da posição passada como parametro
/// \param livrosBin: arquivo dos livros
/// \param pos: posição do livro livre
/// \return livro livre
/// \pre nenhuma 
/// \pos nenhuma
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
/// \brief funcao que escreve o cabecalho do arquivo na arvore
/// \param arvorebin: arquivo da arvore
/// \param arvore: cabecalho a ser escrito
/// \pre arvore nao pode estar vazia
/// \pos cabecalho escrito no arquivo
///
void escr_cabe_bmais(FILE *arvorebin, Cabecalho *arvore){
	
	fseek(arvorebin,0,SEEK_SET);

	fwrite(arvore,sizeof(Cabecalho),1,arvorebin);
}

///
/// \brief funcao para inicializar o cabecalho dos livros
/// \param livrosBin: arquivo dos livros
/// \pre nenhuma
/// \pos cabeçalho inicializado
///
void cria_cabe_livro(FILE *livrosBin){

	CabecalhoLivro livro;

	livro.topo = 0;
	livro.livre = -1;

	escr_cab_livro(livrosBin, &livro);
}

/// 
/// \brief funcao para iniciliazar o cabecalho da arvore
/// \param arvorebin: arquivo dos indices da arvore
/// \pre arquivo criado ou aberto
/// \pos arquivo preenchido com o cabecalho
///
void cria_cabe_bmais(FILE *arvorebin){
	Cabecalho arvore;

	arvore.raiz = -1;
	arvore.topo = 0;
	arvore.livre = -1;

	escr_cabe_bmais(arvorebin,&arvore);
}

///
/// \brief funcao que inicializa uma variavel do tipo Arvore
/// \return variavel inicializada
/// \pre nenhuma
/// \pos variavel inicializada
///
BMais* inicializa_arvore(){

	BMais *aux = (BMais*)malloc(sizeof(BMais));

	aux->numChaves = 1;
	aux->eh_folha = 1;
	aux->pai = -1;
	
	int i;

	for(i = 0; i < ORDEM; i++){
		aux->chaves[i] = 0;
		aux->filho[i] = -1;
	}
	
	return aux;
}

///
/// \brief funcao que pega o nó da posição passada como parametro
/// \param arvoreBin: arquivo da arvore
/// \param pos: posição do nó livre
/// \return nó livre
/// \pre nenhuma
/// \pos nenhuma
///
NoLivre* pega_no_livre(FILE *arvoreBin, int pos){

	if(pos == -1){
		return NULL;
	}

	NoLivre *aux = (NoLivre*)malloc(sizeof(NoLivre));

	fseek(arvoreBin, sizeof(Cabecalho) + sizeof(BMais)*pos, SEEK_SET);

	fread(aux, sizeof(NoLivre), 1, arvoreBin);

	return aux;
}

///
/// \brief funcao auxiliar que escreve a arvore no arquivo binario
/// \param arvoreBin: arquivo da arvore
/// \param raiz: no da arvore a ser escrita
/// \param pos: posicao onde ele sera escrito no arquivo
/// \pre arquivo aberto
/// \pos arquivo preenchido com o no da arvore
///
void escreve_arvore_aux(FILE *arvorebin, BMais *raiz, int pos){
	
	fseek(arvorebin, sizeof(Cabecalho) + sizeof(BMais)*pos, SEEK_SET);
	
	fwrite(raiz, sizeof(BMais), 1, arvorebin);
}

///
/// \brief funcao que escreve o nó da arvore no arquivo arvore.bin
/// \param arvoreBin: arquivo da arvore
/// \param no: nó da arvore a ser escrita
/// \param arvore: cabeçalho do arquivo da arvore
/// \return posição do nó escrito no arquivo
/// \pre nenhuma
/// \pos nó da arvore escrita no arquivo
///
int escreveArvore(FILE *arvoreBin, BMais *no, Cabecalho *arvore){
	if(!no || !arvore){
		return -1;
	}

	int posicao;

	if (arvore->livre == -1){
		posicao = arvore->topo++;
	}else{
		posicao = arvore->livre;
		NoLivre* livres = pega_no_livre(arvoreBin,posicao);
		arvore->livre = livres->prox;
		free(livres);
	}
	
	escr_cabe_bmais(arvoreBin,arvore);
	escreve_arvore_aux(arvoreBin, no, posicao);

	return posicao;
}

///
/// \brief funcao que o nó da arvore do arquivo arvore.bin
/// \param arvorebin: arquivo da arvore
/// \param posicao: posicao do nó no arquivo da arvore
/// \return nó da posicao lida no arquivo
/// \pre nenhuma
/// \pos nenhuma
///
BMais* le_noh(FILE *arvorebin, int posicao){
	
	BMais *no;

	if(posicao == -1){
		return NULL;
	}

	no = (BMais*)malloc(sizeof(BMais));

	fseek(arvorebin,sizeof(Cabecalho) + sizeof(BMais)*posicao, SEEK_SET);

	fread(no, sizeof(BMais),1,arvorebin);

	return no;
}

///
/// \brief funcao que le o cabeçalho do arquivo arvore.bin 
/// \param arvorebin: arquivo da arvore
/// \return cabeçalho lido do arquivo
/// \pre nenhuma
/// \pos cabeçalho do arquivo lido
///
Cabecalho* le_cab_arvore(FILE *arvorebin){
	
	Cabecalho *aux = (Cabecalho*)malloc(sizeof(Cabecalho));

	fseek(arvorebin,0,SEEK_SET);

	fread(aux,sizeof(Cabecalho),1,arvorebin);

	return aux;
}

///
/// \brief funcao que escreve o livro no arquivo dos livros
/// \param livrosBin: arquivo dos livros
/// \param cab_livro: cabeçalho do arquivo dos livros
/// \param livro: livro a ser escrito
/// \return posição de onde foi escrito no arquivo
/// \pre nenhuma
/// \pos livro escrito no arquivo dos livros
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
/// \brief funcao que le os livros do arquivo do livros
/// \param livrosBin: arquivo dos livros
/// \param pos: posicao do livro no arquivo dos livros
/// \return retorna o livro da posição lida no arquivo
/// \pre nenhuma
/// \pos livros do arquivo lidos
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
/// \brief funcao que printa as informações do livro passado como parametro
/// \param l: array do tipo Livros que contem as informações do livro
/// \pre livro deve existir
/// \pos nenhuma
///
void printa_livro(Livros *l){
	printf("+---------------------------------------------------------+\n");
	printf("| Codigo: %-48d|\n", l->codigo);
	printf("| Titulo: %-48s|\n", l->titulo);
	printf("| Autor: %-49s|\n", l->autor);
	printf("| Quantidade: %-44d|\n", l->qtd);
	printf("+---------------------------------------------------------+\n");
}

///
/// \brief funcao que imprime as informacoes do livro
/// \param arvorebin: arquivo binario da arvore
/// \param livrosbin: arquivo binario dos livros
/// \pre nenhuma
/// \pos nenhuma
///
void imprime_acervo(FILE *arvorebin, FILE *livrobin){
	int i;
	Cabecalho *aux = le_cab_arvore(arvorebin);
	BMais *raiz = le_noh(arvorebin,aux->raiz);

	while(!raiz->eh_folha){
		raiz = le_noh(arvorebin,raiz->filho[0]);
	}

	while(raiz){
		for(i=0; i<raiz->numChaves; i++){
			printa_livro(le_livros(livrobin,raiz->filho[i]));
		}
		raiz = le_noh(arvorebin,raiz->filho[ORDEM]);
	}
}

///
/// \brief funcao que verifica se o nó existe na posicao passada e informa a posicao em que ele deve ser inserido no vetor
/// \param raiz: nó onde a chave vai ser inserida
/// \param codigo: codigo do livro do nó a ser inserido
/// \param pos: posicao do nó
/// \return 1 caso exista, 0 caso nao exista
/// \pre nenhuma
/// \pos informa a posicao do nó aonde deve ser inserido
///
int busca(BMais *raiz, int codigo, int *pos){
	for ((*pos) = 0; (*pos) < raiz->numChaves ; (*pos)++){
		if(codigo == raiz->filho[(*pos)]){
			return 1;
		}
		else if(codigo < raiz->chaves[(*pos)]){
			break;
		}
	}
	return 0;
}

//colocar antes do remove
void seta_pai(FILE *arvorebin, int pos, int pos_pai){
	int i;

	BMais *raiz = le_noh(arvorebin,pos);

	raiz->pai = pos_pai;
	escreve_arvore_aux(arvorebin,raiz,pos);

	if(!raiz->eh_folha){
		for(i=0; i<=raiz->numChaves; i++){
			seta_pai(arvorebin, raiz->filho[i], pos);
		}
	}
}

//seta_pai(arvorebin,cab->raiz,cab->raiz);

///
/// \brief funcao que adiciona a chave a ser inserida na direita do nó
/// \param raiz: nó onde a chave vai ser inserida
/// \param pos: posicao do livro no vetor onde vai ser inserido
/// \param codigo: codigo do livro a ser inserido
/// \param pos_livro: posicao do vetor onde foi inserido
/// \pre nenhuma
/// \pos chave é adicionada no nó
///
void adiciona_direita(BMais *raiz, int pos, int codigo, int pos_livro){
	int i;

	int k = 1;

	if (raiz->eh_folha){
		k = 0;
	}

	for (i = raiz->numChaves; i > pos; i--){
		raiz->chaves[i] = raiz->chaves[i-1];
		raiz->filho[i+k] = raiz->filho[i+k-1];
	}
	raiz->chaves[pos] = codigo;
	raiz->filho[pos+k] = pos_livro;
	raiz->numChaves++;
}

///
/// \brief funcao que faz o split de um nó
/// \param arvoreBin: arquivo binário da arvore
/// \param raiz: nó onde deseja fazer o split
/// \param m: chave do meio do nó
/// \param pos: posicao da chave no vetor
/// \return o nó pai do nó onde foi feito o split
/// \pre nenhuma
/// \pos split do nó é feito
///
BMais *split(FILE *arvoreBin, BMais *raiz, int *m, int pos){
	BMais *y = (BMais*)malloc(sizeof(BMais));

	int k=0,i;

	if(!raiz->eh_folha){
		y->eh_folha = 0;
		k=1;
	}else{
		y->eh_folha = 1;
	}

	int q = raiz->numChaves/2; 

	y->numChaves = raiz->numChaves - q - k;
	raiz->numChaves = q;

	*m = raiz->chaves[q];
	y->filho[0] = raiz->filho[q+k];
	for(i=0;i<y->numChaves; i++){
		y->chaves[i] = raiz->chaves[q+i+k];
		y->filho[i+1] = raiz->filho[q+i+1+k];
	}

	escreve_arvore_aux(arvoreBin,raiz,pos);

	return y;	
}

///
/// \brief funcao auxiliar que insere a chave no nó caso ja tenha uma raiz
/// \param arvoreBin: arquivo binário da arvore
/// \param pos_livro: posicao do vetor onde foi inserido a chave
/// \param codigo: codigo do livro a ser inserido
/// \param pos_raiz: posicao do nó no arquivo da arvore
/// \pre nenhuma
/// \pos 
///
void insere_aux(FILE *arvoreBin, int pos_livro, int codigo, int pos_raiz){
	int pos;

	BMais *raiz = le_noh(arvoreBin,pos_raiz);

	if(!busca(raiz,codigo,&pos)){
		if(raiz->eh_folha){
			adiciona_direita(raiz,pos,codigo,pos_livro);
			escreve_arvore_aux(arvoreBin,raiz,pos_raiz);
		}else{
			insere_aux(arvoreBin,pos_livro,codigo,raiz->filho[pos]);
			BMais *filho = le_noh(arvoreBin, raiz->filho[pos]);

			if(overflow(filho)){
				int m;
				Cabecalho *cab = le_cab_arvore(arvoreBin);
				BMais *aux = split(arvoreBin,filho,&m,raiz->filho[pos]);
				int nova_pos = escreveArvore(arvoreBin,aux,cab);
				if(filho->eh_folha){
					aux->filho[ORDEM] = filho->filho[ORDEM];
					filho->filho[ORDEM] = nova_pos;
				}
				adiciona_direita(raiz,pos,m,nova_pos);

				escreve_arvore_aux(arvoreBin,aux,nova_pos);
				escreve_arvore_aux(arvoreBin,filho,raiz->filho[pos]);
				escreve_arvore_aux(arvoreBin,raiz,pos_raiz);
				free(aux);
			}
		}
	}
}

///
/// \brief funcao principal de inserção da chave no nó
/// \param arvoreBin: arquivo binário da arvore
/// \param codigo: codigo do livro a ser inserido
/// \param pos_livro: posicao do vetor onde o livro vai ser inserido
/// \param cab: cabeçalho do arquivo da arvore
/// \pre nenhuma
/// \pos livro inserido
///
void insere(FILE *arvoreBin, int codigo, int pos_livro, Cabecalho *cab){
	BMais *raiz = le_noh(arvoreBin,cab->raiz);

	if(!raiz){
		raiz = inicializa_arvore();
		raiz->chaves[0] = codigo;
		raiz->filho[0] = pos_livro;
		raiz->filho[ORDEM] = -1;
		raiz->numChaves = 1;
		cab->raiz = escreveArvore(arvoreBin,raiz,cab);
		escr_cabe_bmais(arvoreBin,cab);
		free(raiz);
		free(cab);
		return;
	}

	insere_aux(arvoreBin,pos_livro,codigo,cab->raiz);
	cab = le_cab_arvore(arvoreBin);

	raiz = le_noh(arvoreBin,cab->raiz);
	

	if(overflow(raiz)){
		int m;
		//Cabecalho *cab2 = le_cab_arvore(arvoreBin);
		BMais *aux = split(arvoreBin,raiz,&m,cab->raiz);
		int nova_pos = escreveArvore(arvoreBin,aux,cab);
		if(raiz->eh_folha){
			aux->filho[ORDEM] = raiz->filho[ORDEM];
			raiz->filho[ORDEM] = nova_pos;
		}
		BMais *new_raiz = inicializa_arvore();
		new_raiz->chaves[0] = m;
		new_raiz->filho[0] = cab->raiz;
		new_raiz->filho[1] = nova_pos;
		new_raiz->numChaves = 1;
		new_raiz->eh_folha = 0;

		escreve_arvore_aux(arvoreBin,aux,nova_pos);
		escreve_arvore_aux(arvoreBin,raiz,cab->raiz);

		cab->raiz = escreveArvore(arvoreBin,new_raiz,cab);
		escr_cabe_bmais(arvoreBin,cab);

		free(aux);
		free(new_raiz);
	}
	 
	free(raiz);
}

///
/// \brief funcao que le do teclado as informações do livro a ser inserido e escreve nos arquivos binarios
/// \param livrosBin: arquivo binario dos livros
/// \param arvoreBin: arquivo binario da arvore
/// \pre nenhuma
/// \pos informacoes do livro escritas nos arquivos
///
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
	Cabecalho *aux = le_cab_arvore(arvoreBin);

	pos = escreve_livro(livrosBin, cab_livro, livro);
	insere(arvoreBin, livro->codigo, pos, aux);
	escr_cab_livro(livrosBin, cab_livro);
	free(livro);
}

///
/// \brief função para ler uma linha do arquivo texto e inserir nos arquivos binários
/// \param livrosBin: arquivo dos livros
/// \param arvoreBin: arquivo da arvore
/// \param linhaArq: string que contém o nome do arquivo
/// \pre nenhuma
/// \pos linha inserida nos arquivos binarios
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
	Cabecalho *aux = le_cab_arvore(arvoreBin);

	pos = escreve_livro(livrosBin, cab_livro, livro);
	insere(arvoreBin, livro->codigo, pos, aux);
	escr_cab_livro(livrosBin, cab_livro);
	free(livro);
}

///
/// \brief funcao auxiliar que printa a arvore
/// \param arvoreBin: arquivo binario da arvore
/// \param raiz: nó atual a ser printado
/// \param pos: posicao do nó da arvore
/// \pre arvore nao pode ser vazia
/// \pos nenhuma
///
void printa_arv_aux(FILE *arvorebin, BMais *raiz, int pos){
	
	printf("[");
	
	int i,j;
	
	for(i=0; i < raiz->numChaves; i++){
		printf("%d ",raiz->chaves[i]);
		if (i < raiz->numChaves){
			printf(", ");
		}
	}
	printf("]\n");

	if(!raiz->eh_folha){
		for(j = 0; j <= raiz->numChaves; j++){
			printa_arv_aux(arvorebin,le_noh(arvorebin,raiz->filho[j]),raiz->filho[j]);
		}
	}
	
}

///
/// \brief funcao principal que printa a arvore
/// \param arvoreBin: arquivo binario da arvore
/// \pre nenhuma
/// \pos nenhuma
///
void printa_arv(FILE *arvorebin){
	Cabecalho *aux = le_cab_arvore(arvorebin);
	BMais *raiz = le_noh(arvorebin,aux->raiz);
	
	printa_arv_aux(arvorebin,raiz,aux->raiz);
}

///
/// \brief funcao que calcula a altura da arvore
/// \param arvoreBin: arquivo binario da arvore
/// \return altura da arvore
/// \pre nenhuma
/// \pos nenhuma
///
int altura(FILE *arvorebin){
	Cabecalho *aux = le_cab_arvore(arvorebin);

	if(aux->raiz == -1){
		return 0;
	}

	BMais *raiz = le_noh(arvorebin,aux->raiz);
	int nivel = 0;
	while (!raiz->eh_folha){
		nivel++;
		raiz = le_noh(arvorebin,raiz->filho[0]);
	}
	free(aux);
	free(raiz);

	return nivel;
}

///
/// \brief funcao para printar o codigo dos livros
/// \param raiz: no a ser printado
/// \pre a raiz nao estar nula
/// \post nenhuma
///
void print_aux(BMais *raiz){
	printf("[ ");
	int i;
	for(i=0; i < raiz->numChaves; i++){
		printf(" %d",raiz->chaves[i]);
		if (i < raiz->numChaves){
			printf(",");
		}
	}
	printf(" ]");
}

///
/// \brief funcao auxiliar que imprime a arvore por nivel
/// \param arvoreBin: arquivo binario da arvore
/// \param raiz: nó atual da arvore
/// \param nivel: numero de niveis da arvore
/// \param i: contador para verificar se todos os niveis foram printados
/// \pre nenhuma
/// \pos nenhuma
///
void imprime_nivel_aux(FILE *arvorebin, BMais *raiz, int nivel, int i){
	if(nivel == i){
		print_aux(raiz);
		return;
	}

	i++;
	int j;
	for(j=0; j<=raiz->numChaves; j++){
		imprime_nivel_aux(arvorebin, le_noh(arvorebin,raiz->filho[j]), nivel, i);
	}
}

///
/// \brief funcao que imprime a arvore por nivel
/// \param arvoreBin: arquivo binario da arvore
/// \pre nenhuma
/// \pos nenhuma
///
void imprime_nivel(FILE *arvorebin){
	int nivel = altura(arvorebin);
	int i;

	if(nivel == 0){
		erro_arvore_empty();
	}

	Cabecalho *aux = le_cab_arvore(arvorebin);
	BMais *raiz = le_noh(arvorebin,aux->raiz);
	for(i=0; i<=nivel; i++){
		imprime_nivel_aux(arvorebin,raiz,i,0);
		printf("\n");
	}
}

///
/// \brief funcao auxliar que busca o codigo do livro
/// \param arvorebin: arquivo da arvore
/// \param raiz: nó da arvore onde está procurando a chave
/// \param codigo: codigo do livro a ser procurado
/// \param pos: posicao do vetor onde vai ser inserido o livro
/// \return nó do livro buscado
/// \pre nenhuma
/// \pos nenhuma
///
BMais* busca_aux(FILE *arvorebin, BMais *raiz, int codigo, int *pos){
	if(!raiz){
		return NULL;
	}

	int i=0;

	while(i<raiz->numChaves && raiz->chaves[i] < codigo){
		i++;
	}
	if(raiz->chaves[i] > codigo || !raiz->eh_folha){
		return busca_aux(arvorebin,le_noh(arvorebin,raiz->filho[i]),codigo,pos);
	}

	*pos = i;

	return raiz;
}

///
/// \brief funcao que busca o codigo do livro a ser procurado
/// \param arvorebin: arquivo da arvore
/// \param livrosbin: arquivo dos livros
/// \pre o codigo deve ser um numero valido, maior que 0
/// \pos mostra as informações do livro procurado, se ele existir
///
void busca_(FILE *arvorebin, FILE *livrosbin){
	system("cls");
	int busca = procurado();
	int pos;

	Cabecalho *aux = le_cab_arvore(arvorebin);
	BMais *raiz = le_noh(arvorebin,aux->raiz);
	BMais *achado = (BMais*)malloc(sizeof(BMais));

	achado = busca_aux(arvorebin,raiz,busca,&pos);

	if(achado->chaves[pos] != busca){ 
		nao_encontrado();
		return;
	}
	Livros *livro = le_livros(livrosbin,achado->filho[pos]);
	printa_livro(livro);
}

///
/// \brief funcao que atualiza a quantidade de exemplares do livro
/// \param livrosBin: arquivo binario dos livros
/// \param arvoreBin: arquivo binario da arvore
/// \pre nenhuma
/// \pos quantidade de exemplares do livro atualizada
///
void atualiza(FILE *arvorebin, FILE *livrosbin){
	system("cls");
	int busca = procurado();
	int pos;

	Cabecalho *aux = le_cab_arvore(arvorebin);
	BMais *raiz = le_noh(arvorebin,aux->raiz);
	BMais *achado = (BMais*)malloc(sizeof(BMais));

	achado = busca_aux(arvorebin,raiz,busca,&pos);

	if(achado->chaves[pos] != busca){ 
		nao_encontrado();
		return;
	}
	Livros *livro = le_livros(livrosbin,achado->filho[pos]);
	int nova = atualiza_qtd_msg();
	livro->qtd = nova;

	fseek(livrosbin, sizeof(CabecalhoLivro) + sizeof(Livros) * achado->filho[pos], SEEK_SET);

	fwrite(&livro->codigo, sizeof(int), 1, livrosbin);
	fwrite(livro->titulo, sizeof(char), 100, livrosbin);
	fwrite(livro->autor, sizeof(char), 100, livrosbin);
	fwrite(&livro->qtd, sizeof(int), 1, livrosbin);

}

///
///	\brief cria um novo no livre
/// \return um novo no livre inicializado
///
NoLivre* cria_no_livre(){

	NoLivre* novo = (NoLivre*)malloc(sizeof(NoLivre));

	novo->prox = -1;

	return novo;
}

///
/// \brief reescreve o no da arvore para remove-lo do arquivo
/// \param arvorebin: arquivo com os nos da arvore
/// \param pos: onde ele se encontra
///
void remove_arvore(FILE *arvorebin,int pos){
	Cabecalho *cab = le_cab_arvore(arvorebin);
	NoLivre *aux = cria_no_livre();

	aux->prox = cab->livre;
	cab->livre = pos;
	
	escr_cabe_bmais(arvorebin,cab);
	fseek(arvorebin, sizeof(Cabecalho) + sizeof(BMais)*pos, SEEK_SET);
	fwrite(aux, sizeof(NoLivre), 1, arvorebin);

	free(aux);
	free(cab);
}

///
///	\brief cria um livro livre
/// \return um livro livre inicializado
///
LivroLivre* cria_livro_livre(){

	LivroLivre* novo = (LivroLivre*)malloc(sizeof(LivroLivre));

	novo->prox = -1;

	return novo;
}

/// 
/// \brief funcao para escrever um livro livre
/// \param livrosbin: arquivo com os livros
/// \param pos: onde ele vai ser escrito
///
void escreve_livro_livres(FILE* livrosbin, int pos){
	CabecalhoLivro *cab = le_cab_livro(livrosbin);

	if(!cab) return;

	int posicao = pos;
	LivroLivre* novo = cria_livro_livre();

	novo->prox = cab->livre;
	cab->topo--;
	cab->livre = posicao;

	escr_cab_livro(livrosbin,cab);

	fseek(livrosbin, sizeof(CabecalhoLivro) + sizeof(Livros)*posicao, SEEK_SET);
	fwrite(novo, sizeof(LivroLivre), 1,livrosbin);

	free(novo);
	free(novo);
}

///
///	\brief funcao para retornar o minimo da arvore
/// \param arvorebin: arquivo com os nos da arvore
/// \param pos: onde ele se encontra
///
int minimo(FILE *arvorebin,int pos){
	BMais *raiz = le_noh(arvorebin,pos);

	if(raiz->eh_folha){
		return raiz->chaves[0];
	}
	return minimo(arvorebin,raiz->filho[0]);
}

///
/// \brief funcao para arrumar a arvore
/// \param arvorebin: arquivo com os nos da arvore
/// \param pos: onde ele se encontra
/// \param codigo: codigo do elemento a ser retirado
///
void arruma_arvore(FILE *arvorebin,int pos, int codigo){
	BMais *raiz = le_noh(arvorebin,pos);
	int i;

	if(!raiz->eh_folha){
		for(i=0;i<raiz->numChaves; i++){
			raiz->chaves[i] = minimo(arvorebin,raiz->filho[i+1]);
			arruma_arvore(arvorebin,raiz->filho[i],codigo);
		}
		escreve_arvore_aux(arvorebin,raiz,pos);
		arruma_arvore(arvorebin,raiz->filho[raiz->numChaves],codigo);
	}
}

///
/// \brief funcao para verificar o underflow
/// \param raiz: nó a ser verificado
/// \return retorna 0 caso nao tenha underflow e 1 caso contrario
///
int underflow(BMais *raiz){

	return raiz->numChaves == (ORDEM/2)-1;
}

///
/// \brief funcao para buscar aonde o codigo se encontra no vetor
/// \param raiz: nó a ser verificado
/// \param codigo: codigo do elemento a ser encontrado
///
int busca_vet(BMais *raiz, int codigo){
	int i;

	for(i=0;i<raiz->numChaves;i++){
		if(raiz->chaves[i] > codigo) return i;
	}
	return raiz->numChaves;
}

///
/// \brief funcao para retirar o elemento na posicao pos
/// \param raiz: nó a ser modificado
/// \param pos: onde ele se encontra
///
void retira_direita(BMais *raiz, int pos){
	int i=pos;

	for(i=pos; i<raiz->numChaves-1; i++){
		raiz->chaves[i] = raiz->chaves[i+1];
		raiz->filho[i+1] = raiz->filho[i+2];
	}
	raiz->numChaves--;
}

///
/// \brief funcao para emprestar de um irmao para o outro
/// \param arvorebin: arquivo que contem todos os nos da arvore
/// \param pos_mod: posicao do no a ser modificado
/// \param pai: pai para saber quais sao os irmaos
/// \param pos_vet: posicao do vetor que se encontra o no responsavel para localizar os irmaos
///
int empresta(FILE *arvorebin, int pos_mod, BMais *pai, int pos_vet){
	BMais *raiz = le_noh(arvorebin,pos_mod);
	BMais *esq = le_noh(arvorebin,pai->filho[pos_vet - 1]);
	BMais *dir = le_noh(arvorebin,pai->filho[pos_vet + 1]);

	if(esq->numChaves > ORDEM/2 && pos_vet > 0){
		int ultima_pos = esq->numChaves-1;

		//adiciona a ultima chave do irmao nele
		adiciona_direita(raiz,0,esq->chaves[ultima_pos],esq->filho[ultima_pos]);
		escreve_arvore_aux(arvorebin,raiz,pos_mod);

		//e retira a chave do irmao
		retira_direita(esq,ultima_pos);
		escreve_arvore_aux(arvorebin,esq,pai->filho[pos_vet-1]);
		
		return 1;
	}
	if(dir->numChaves > ORDEM/2 && pos_vet < raiz->numChaves){
		//coloca a primeira chave do irmao nele
		adiciona_direita(raiz,raiz->numChaves,dir->chaves[0],dir->filho[0]);
		escreve_arvore_aux(arvorebin,raiz,pos_mod);

		//e tira a chave do irmao logo em seguida
		dir->filho[0] = dir->filho[1];
		retira_direita(dir,0);
		escreve_arvore_aux(arvorebin,dir,pai->filho[pos_vet+1]);

		return 1;
	}

	free(raiz);
	free(esq);
	free(dir);

	return 0;
}

///
/// \brief funcao para fazer o merge
/// \param arvorebin: arquivo que contem todos os nos da arvore
/// \param pos_mod: posicao do no a ser modificado
/// \param pos_irmao: posicao do irmao
/// \param lado_new: onde ele vai ser adicionado
/// \param codigo: elemento a ser removido
///
void merge(FILE *arvorebin, int pos_mod, int pos_irmao, int lado_new, int codigo){
	BMais *raiz = le_noh(arvorebin,pos_mod);
	BMais *irmao = le_noh(arvorebin,pos_irmao);
	BMais *pai = le_noh(arvorebin,raiz->pai);

	int i;

	//concatena
	for(i=0;i<raiz->numChaves;i++){
		adiciona_direita(irmao,lado_new,raiz->chaves[i],raiz->filho[i]);
		if(lado_new != 0){
			lado_new++;
		}
	}

	if(lado_new != 0 && irmao->eh_folha){
		irmao->filho[ORDEM] = raiz->filho[ORDEM];
	}

	int k = (lado_new == 0)? 0:1;
	int pos_pai = busca_vet(pai,codigo);
	int valor_pai = pai->chaves[pos_pai - k];
	int pos_irmao_vetor = busca_vet(irmao,valor_pai);

	if(!raiz->eh_folha){
		adiciona_direita(irmao,pos_irmao_vetor,valor_pai,raiz->filho[raiz->numChaves]);
	}

	int temp,j;

	if(lado_new == 0){
		for(j=0;j<=i;j++){
			temp = irmao->filho[j+1];
			irmao->filho[j+1] = irmao->filho[j];
			irmao->filho[j] = temp;
		}
	}else{
		for(j=irmao->numChaves; j >= raiz->filho[raiz->numChaves];j--){
			temp = irmao->filho[j];
			irmao->filho[j] = irmao->filho[j-1];
			irmao->filho[j-1] = temp;
		}
	}

	retira_direita(pai,pos_pai-1);

	escreve_arvore_aux(arvorebin,pai,irmao->pai);
	escreve_arvore_aux(arvorebin,irmao,pos_irmao);
	//é aqui mesmo q da errado
	remove_arvore(arvorebin,pos_mod);

	Cabecalho *cab = le_cab_arvore(arvorebin);
	//verifica se ele é a raiz
	if(pai->pai == cab->raiz){
		if(pai->numChaves){
			cab->raiz = pos_irmao;
			remove_arvore(arvorebin,irmao->pai);
			escr_cabe_bmais(arvorebin,cab);
		}
	}

	if(irmao->pai != cab->raiz && underflow(pai)){
		BMais *vo = le_noh(arvorebin,pai->pai);
		int pos_vetor_pai = busca_vet(vo,codigo);

		if(!empresta(arvorebin,irmao->pai, vo, pos_vetor_pai)){
			if(pos_vetor_pai > 0){
				BMais *dir = le_noh(arvorebin,vo->filho[pos_vetor_pai + 1]);
				lado_new = dir->numChaves-1;
				pos_irmao = vo->filho[pos_vetor_pai - 1];
				free(dir);
			}
			else{
				lado_new = 0;
				pos_irmao = vo->filho[pos_vetor_pai + 1];
			}
			merge(arvorebin,irmao->pai,pos_irmao,lado_new,codigo);
		}
	}
}

///
/// \brief funcao auxliar no remover
/// \param arvorebin: arquivo q contem todos os nos da arvore
///	\param codigo: elemento a ser removido
/// \param pos: posicao da raiz
/// 
int remove_aux(FILE *arvorebin, int codigo, int pos){
	BMais *raiz = le_noh(arvorebin,pos);
	int vet;
	int pos_mod;

	while(!raiz->eh_folha){
		vet = busca_vet(raiz,codigo);
		pos_mod = raiz->filho[vet];
		raiz = le_noh(arvorebin,pos_mod);
	}
	vet = busca_vet(raiz,codigo);

	if(raiz->chaves[vet-1] != codigo){
		return -1;
	}

	int achou = raiz->filho[vet-1];

	retira_direita(raiz, vet-1);
	escreve_arvore_aux(arvorebin,raiz,pos_mod);

	if(underflow(raiz)){
		BMais *pai = le_noh(arvorebin,raiz->pai);
		int vet_pai = busca_vet(pai,codigo);
		BMais *dir = le_noh(arvorebin,raiz->filho[ORDEM]);
		BMais *esq = le_noh(arvorebin,raiz->filho[vet_pai-1]);

		if(!empresta(arvorebin,pos_mod,pai,vet_pai)){
			int lado_new,pos_irmao;

			if(vet_pai > 0){
				lado_new = dir->numChaves;
				pos_irmao = pai->filho[vet_pai - 1];
			}else{
				lado_new = 0;
				pos_irmao = pai->filho[vet_pai + 1];
				esq->filho[ORDEM] = raiz->filho[ORDEM];
				escreve_arvore_aux(arvorebin,esq,raiz->filho[vet_pai - 1]);
			}
			merge(arvorebin,pos_mod,pos_irmao,lado_new,codigo);
		}
	}

	arruma_arvore(arvorebin,pos,codigo);

	return achou;
}

///
/// \brief funcao auxliar no remover
/// \param arvorebin: arquivo q contem todos os nos da arvore
///	\param livrosbin: arquivo q contem todos os livros
/// 
void remover(FILE *arvorebin, FILE *livrosbin){
	int busca = menu_remove();
	Cabecalho *aux = le_cab_arvore(arvorebin);
	seta_pai(arvorebin,aux->raiz,aux->raiz);

	int achou = remove_aux(arvorebin,busca,aux->raiz);

	if(achou == -1){
		nao_encontrado();
	}else{
		escreve_livro_livres(livrosbin,achou);
	}
}