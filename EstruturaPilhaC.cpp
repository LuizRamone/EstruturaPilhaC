#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int num;
	struct no *prox;
}T_no;

typedef struct cabeca{
	struct no *topo;
}T_cabeca;

T_cabeca *pcabeca;

//prototipos
T_cabeca *inicializa_pilha();
void push(int val,T_cabeca *pcabeca);
void pop(T_cabeca *pcabeca);
void mostra_dados(T_cabeca *pcabeca);
void libera (T_cabeca *pcabeca);


int main(){
		
	int n,val;
	T_cabeca *pcabeca;

pcabeca = inicializa_pilha();
	
		do{

		printf("\n0 - Encerrar programa\n");
		printf("1 - Para inserir na pilha (PUSH)\n");
		printf("2 - Remover do topo da pilha (POP)\n");
		printf("3 - Imprimir Pilha\n");
		printf("4 - Remove TUDO\n");
		printf ("Opcao: ");
			scanf("%d",&n);
		printf("\n");

			if(n==1){
				printf("Valor: ");
			scanf("%d",&val);
				push(val,pcabeca);
			} else if(n==2){
				printf("Um elemento foi removido do topo\n");
				pop(pcabeca);
			}else if (n==3){
			printf("Valores da pilha \n");
			mostra_dados(pcabeca);
			}
			else if(n==4){
				printf("TODOS elemntos foram removidos!");
				libera(pcabeca);
			}
			
			
		}while (n != 0);
	
	
	
	return 0;
}


T_cabeca *inicializa_pilha(){
T_cabeca *novo;
	novo = (T_cabeca*)malloc(sizeof(T_cabeca));
	if(novo==NULL){
		exit(0);
	}
	novo->topo=NULL;
	return(novo);
	}
	
	
	void push(int val,T_cabeca *pcabeca){
		T_no *novo;
		novo = (T_no*)malloc(sizeof(T_no));
		if (novo==NULL){
			exit(0);
		}
		if(pcabeca->topo==NULL){//PRIMEIRO ELEM
		pcabeca->topo=novo;
		novo->num=val;
		novo->prox=NULL;
	
	}
		
		else {	
		novo->num=val;	
		novo->prox=pcabeca->topo;
		pcabeca->topo=novo;
		
		}
	}
	void pop(T_cabeca *pcabeca){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
	
		T_no *aux;
		aux = pcabeca->topo;
		
		pcabeca->topo = aux->prox;
		//free(aux);
	}
	
	
	void libera(T_cabeca *pcabeca){
		T_no *no1;
		T_no *aux;
		no1=pcabeca->topo;
		
		while(no1!=NULL){
			aux = no1;
			no1 = no1->prox;
			free(aux);
		}pcabeca=NULL;
	}
	
	
	void mostra_dados(T_cabeca *pcabeca){
		T_no *aux;
		aux = pcabeca->topo;
		while(aux!=NULL){
				printf("\t%d",aux->num);
				aux = aux->prox;	
		}
	}
		
		
		
		
	
	
	
	
