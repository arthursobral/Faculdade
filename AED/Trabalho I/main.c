#include <stdio.h>
#include "participante.h"
#include "aviao.h" 

//arqv: contem tudo o que foi escrito de comando
//arqc: quantidade de palavras escritas na linha de comando
int main(int arqc,const char *arqv[]){
	int opcao,opcao1,opcao2;
	FILE *f;
	Participante *p = NULL;
	Voo *v = NULL;
	char *nomeArquivo, linhaArq[100], cpf_procurado[MAX],prefixo[MAX];
	nomeArquivo = nome_Arq(arqv+1); // argv+1 ignora o a.exe
	printf("%s\n",nomeArquivo);

	f = fopen(nomeArquivo,"r");

	if(f == NULL){

		printf("Arquivo esta vazio\n");
	}
	else{
		while(!feof(f)){
			fgets(linhaArq,100,f);

			switch(qual_cadastro(linhaArq[0])){
				case 1:
					//Cadastro do participante
					p = insere_part(p,linhaArq+2);
					break;
				case 2:
					//Cadastro de voo
					v = insere_voo_a(v,linhaArq+2);
					break;
				case 3:
					printf("Opcao invalida\n");
					break;
			}
		}
	}

	opcao = menu();

	while(opcao){
		switch (opcao){
			case 1:
				opcao1 = menu_voo();
				while(opcao1){
					switch (opcao1){
						case 1:
							system("cls");
							v = insere_voo(v);
        					system("pause");
        					printf("\n");
							break;
						case 2:
							system("cls");
							opcao2 = menu_listar_v();
							switch (opcao2){
								case 1:
									if(vazia(v)){
										system("cls");
										printf("+------------------------------------+\n");
        								printf("|         Nao existe voos            |\n");
        								printf("+------------------------------------+\n");
        								system("pause");	
									}else{
										system("cls");
										printf("+------------------------------------+\n");
	        							printf("|                 Voos               |\n");
	        							printf("+------------------------------------+\n");		
										imprime_voo(v);
										system("pause");
									}
									break;
								case 2:
									if(vazia(v)){
										system("cls");
										printf("+------------------------------------+\n");
        								printf("|         Nao existe voos            |\n");
        								printf("+------------------------------------+\n");
        								system("pause");
        							}else{
										system("cls");
										printf("+------------------------------------+\n");
	        							printf("| Digite o prefixo do voo            |\n");
	        							printf("| Prefixo:                           |\n");
	        							printf("+------------------------------------+\n");
	        							gotoXY(11,2);
	        							fflush(stdin);
	        							scanf("%[^\n]%*c",prefixo);
	        							imprime_voo_pro(v,prefixo);
	        							system("pause");
	        						}
        							break;
        						case 0:
        							break;
        						default:
        							system("cls");
        							printf("+------------------------------------+\n");
        							printf("|        Operacao inexistente!       |\n");
        							printf("+------------------------------------+\n");
        							system("pause");
        							break;
							}
							break;
						case 3:
							printf("Teste\n");
							v = remover_voo(v);
							system("pause");
        					break;
        				default:
        					system("cls");
        					printf("+------------------------------------+\n");
        					printf("|        Operacao inexistente!       |\n");
        					printf("+------------------------------------+\n");
					}
					system("cls");
					opcao1 = menu_voo();
				}
				break;
			case 2:
				opcao1 = menu_p();
				while(opcao1){
					switch (opcao1){
						case 1:
							system("cls");
							p = insere_part1(p);
							printf("\n");
							system("pause");
							break;
						case 2:
							opcao2 = menu_listar_p();
							if(opcao2 == 1){
								if(vazia_p(p)){
									system("cls");
									printf("+------------------------------------+\n");
        							printf("|      Nao existe participantes      |\n");
        							printf("+------------------------------------+\n");
        							system("pause");
								}else{
									system("cls");
									listar_part(p);
									system("pause");
								}
							}
							else if(opcao2 == 2){
								if(vazia_p(p)){
									system("cls");
									printf("+------------------------------------+\n");
        							printf("|      Nao existe participantes      |\n");
        							printf("+------------------------------------+\n");
        							system("pause");
								}else{
									system("cls");
									printf("+------------------------------------+\n");
	        						printf("| Digite o CPF da pessoa             |\n");
	        						printf("| CPF:                               |\n");
	        						printf("+------------------------------------+\n");
	        						gotoXY(7,2);
	        						fflush(stdin);
	        						scanf("%[^\n]%*c",cpf_procurado);
									procurar_part(p,cpf_procurado);
									system("pause");
								}
							}
							else if(opcao2 == 0){
								break;
							}
							else{
								system("cls");
								printf("+------------------------------------+\n");
								printf("|        Operacao inexistente        |\n");
       							printf("+------------------------------------+\n");
       						}
       						break;
       					case 3:
       						system("cls");
       						printf("+------------------------------------+\n");
        					printf("| Digite o CPF da pessoa             |\n");
        					printf("| CPF:                               |\n");
        					printf("+------------------------------------+\n");
        					gotoXY(7,2);
        					fflush(stdin);
        					scanf("%[^\n]%*c",cpf_procurado);
        					p = excluir_part(p,cpf_procurado);
        					system("pause");	
       						break;
       					case 0:
       						break;
       					default:
       						system("cls");
        					printf("+------------------------------------+\n");
        					printf("|        Operacao inexistente!       |\n");
        					printf("+------------------------------------+\n");
        					break;
					}
					system("cls");
					opcao1 = menu_p();
				}
				break;
			default:
				system("cls");
				printf("+------------------------------------+\n");
				printf("|        Operacao inexistente        |\n");
       			printf("+------------------------------------+\n");
		}
		system("cls");
		opcao = menu();
	}
	
	fclose(f);
	system("cls");
	return 0;
}