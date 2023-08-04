#include <stdio.h>
#include <stdlib.h>
typedef struct No {
	int elem;
	struct No * Prox;
} No;

typedef struct pointer {
	struct No * pont;
	int N;
} pointer;

void Insere (pointer * L, int x);

void Imprime (pointer L, int N);

int main (void){
	pointer L;
	L.pont=NULL;
	L.N=0;
	Insere (&L,1);
	Insere (&L,2);
	Insere (&L,3);
	Insere (&L,4);
	Imprime (L,L.N);
}

 void Insere (pointer * L, int x){
	No * Novo;
	No * P;
	No * pAnt;
	Novo= (No*) (malloc(sizeof(No)));
	Novo->elem = x;
	P = L->pont;
	pAnt=NULL;
	while ((P!=NULL) && (P->elem != x)){
		pAnt = P;
		P = P->Prox;
	}
	if (pAnt!=NULL) {
	pAnt->Prox = Novo;
	Novo->Prox = P;
	}
	else {
		L->pont=Novo;
		Novo->Prox=P;
	}
	L->N = L->N +1;
	}
	
void Imprime (pointer L, int N){
	int i=0;
	No * P;
	P = L.pont;
	while (P!=NULL){
		printf ("%d",P->elem);
		P=P->Prox;
	}
	}
