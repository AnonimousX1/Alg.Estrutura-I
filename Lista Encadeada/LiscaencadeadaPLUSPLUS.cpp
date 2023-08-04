#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int E;
	struct No *Prox;
}No;

void InserirInicio(No *&Lista, int valor){
	No *novo_no = (No *)malloc(sizeof(No));
	if(novo_no != NULL){
		novo_no->E = valor;
		novo_no->Prox = Lista;
		Lista= novo_no;
	}
}

void Imprimir(No *&Lista){
	No *prt_lista = Lista;
	if(prt_lista != NULL){
		while(prt_lista != NULL){
			printf("%d--> ",prt_lista->E);
			prt_lista = prt_lista->Prox;
		}
	}else{
		printf("Nao ha elementos na lista a ser impresso");
	}
}

void Busca(No *&Lista, int valor){
	No *prt_lista = Lista;
	while(prt_lista != NULL){
		if(prt_lista->E != valor){
			prt_lista = prt_lista->Prox;
		}
		else{
			printf("O elemento foi encontrado na lista");
			break;
		}
	}
	if(prt_lista == NULL){
			printf("O elemento nao existe na lista");
		}
}

void Remocao(No *&Lista, int valor){
	No *prt_lista = Lista;
	No *prt_ant = NULL;
	if(prt_lista != NULL){
		if(prt_ant == NULL && valor == prt_lista->E){ // Caso especial primeiro elemento;
			prt_ant = prt_lista->Prox;
			Lista = prt_ant;
			free(prt_lista);
			return;
		}else{
			while(prt_lista != NULL){
				if(valor == prt_lista->E){
					prt_ant->Prox = prt_lista->Prox;
					free(prt_lista);
					return;
				}else{
					prt_ant = prt_lista;
					prt_lista = prt_lista->Prox;
				}
			}
		}
		printf("Elemento nao esta na lista");
	}else{
		printf("A lista esta vazia");
	}
}

int UltimoEle(No *L){
	if(L== NULL){
		return -11;
	}
	else{
		if(L->Prox == NULL){
			return L->E;
		}
		return UltimoEle(L->Prox);
	}
	
}

int Auxkultimo(No *L,int k){
	//Retorna o k-ultimo elemento da lista
	//considera lista vazia
}

int main(){
	No *Lista = NULL;
	InserirInicio(Lista, 2);
	InserirInicio(Lista, 3);
	InserirInicio(Lista, 4);
	Imprimir(Lista);
	printf("O ultimo elemento da lista: %d", UltimoEle(Lista));
	printf("\nO K-ultimo elemento da lista: %d", Auxkultimo(Lista,3));
	return 0;
}
