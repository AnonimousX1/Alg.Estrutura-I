#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int NumeroElementos(No * L) {
	int count = 0;
	No * aux;
	aux = L;
	while(aux != NULL){
		count = count + 1;
		aux = aux->Prox;
	}
	return count;
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
	printf("%d",NumeroElementos(L));
	return 0;
}
