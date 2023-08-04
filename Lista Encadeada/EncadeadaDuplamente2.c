#include <stdio.h>
#include <stdlib.h>
//Lista duplamente encadeada

typedef struct No{
	int Dado;
	struct No *Ant;
	struct No *Prox;
	
}No;
/*
void insereInicio(No **L, int valor){
	No *prt = *L;
	No *novo = (No *) malloc(sizeof(No));
	if(novo ==NULL){
		printf("Falha em alocar memoria");
		return;
	}
	novo->Dado = valor;
	novo->Ant = NULL;
	novo->Prox = *L;
	*L = novo;
	return;
}
*/
void insereInicio(No **L, int valor){
	No *prt = *L;
	No *novo = (No *) malloc(sizeof(No));
	novo->Dado = valor;
	novo->Ant = NULL;
	if (prt == NULL) { // caso especial lista vazia
		novo->Prox = NULL;
	} else {
		novo->Prox = *L;
		prt->Ant = novo;
	}
	*L = novo;
	return;
}


void remover(No **L, int valor){
	No *prt = *L;
	if(prt != NULL && prt->Dado == valor){ // Caso especial Primeiro elemento
		prt->Ant = NULL;;
		*L = prt->Prox;
		free(prt);
	}else if(prt != NULL && prt->Dado != valor){ // caso genérico
		while(prt->Dado != valor){
			prt = prt->Prox;
		}
		if(prt->Dado == valor){
			if(prt->Prox == NULL){//Caso especial Ultimo elemento
				prt->Ant->Prox = prt->Prox;
				free(prt);
			}else{
				prt->Ant->Prox = prt->Prox;
				prt->Prox->Ant = prt->Ant;
				free(prt);
			}
		}else{
			printf("Elemento não está na lista");
		}
	}else if(prt == NULL){
		printf("Lista Vazia");
	}else{
		printf("Elemento não está na lista");
	}
}

void imprimir(No **L){
	No * prt = *L;
	while(prt != NULL){
		printf("%d -->",prt->Dado);
		prt = prt->Prox;
	}
}

int main(){
	No * L = NULL;
	insereInicio(&L, 2);
	insereInicio(&L, 3);
	insereInicio(&L, 4);
	printf("Lista antes de remocao\n");
	imprimir(&L);
	printf("\nLista apos remocao\n");
	remover(&L,4);
	imprimir(&L);
	
	return 0;
}
