#include <stdlib.h>
#include <stdio.h>

typedef struct No{
	int e;
	struct No *prox;
}No;

typedef struct Lista{
	struct No *inicio;
	int contar;
}Lista;

void InsercaoInicio(No *Lista, int x);

int main(){
	No *cabeca = (No *) malloc(sizeof(No));
	cabeca->prox = NULL;
	Lista *lista = (Lista *) malloc(sizeof(Lista));
	lista->inicio = cabeca;
	lista->contar = 0;
	
	return 0;
}

void InsercaoInicio(No * lista, int x){
	lista->inicio
	
}
