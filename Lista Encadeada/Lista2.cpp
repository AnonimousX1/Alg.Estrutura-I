#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int Maior(No * L) {
	/* insert your code here */
	No *aux = L;
	int maior = 0;
	while(aux != NULL){
		if((aux->E) >= maior){
			maior = aux->E;
		}
		aux = aux->Prox;
	}
	return maior;
}

void Insere(No * &L, int e) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e;
	novo->Prox = L;
	L = novo;
}

int main() {
	No * L = NULL;
	
	Insere(L, 3);
	Insere(L, 4);
	Insere(L, 5);
	Insere(L, -5);
	Insere(L, -115);
	printf("%d",Maior(L));
	return 0;
}
