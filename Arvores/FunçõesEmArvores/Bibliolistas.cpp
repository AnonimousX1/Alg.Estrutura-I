#include <stdlib.h>
#include <stdio.h>
#include "definicoes.h"

//Implementacao das Funcoes Para listas
void Insere(NoL *&L,int valor){
	NoL *novo;
	novo = (NoL *)malloc(sizeof(NoL));
	if(novo!=NULL){
		novo->E = valor;
		novo->Prox = L;
		L = novo;
	}
}


NoL * CriaNo(int x){
	NoL * novo = (NoL *)malloc(sizeof(NoL));
	novo->E= x;
	novo->Prox = NULL;
	return novo;
}

void ImprimirL(NoL *L){
	if(L == NULL){
		return;
	}else{
		printf("Valor na lista: %d\n",L->E);
		ImprimirL(L->Prox);
	}
}

NoL *Lista = NULL;
NoL * ListaNosInternos(NoT *T) {
	/* insert your code here */
	// Assuma que a lista pode ser vazia
	// Retorna a lista de todos os elementos que nao pertencem as folhas
	if(T == NULL){
		return NULL;
	}else{
		NoL *arvesq = ListaNosInternos(T->esq);
		NoL *arvdir = ListaNosInternos(T->dir);
		if(T->esq != NULL || T->dir != NULL){ 
			Insere(Lista,T->E);
		}
		return Lista;
	}
}
