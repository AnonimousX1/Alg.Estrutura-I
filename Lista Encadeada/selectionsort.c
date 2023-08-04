#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int dado;
	struct No *ptr_prox;
}No;

void Insere(No **L,int valor){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	if(novo!=NULL){
		novo->dado = valor;
		novo->ptr_prox = *L;
		*L = novo;
	}
}

void Imprimir(No **L){
	No *ptrl = *L;
	while(ptrl!= NULL){
		printf("%d->", ptrl->dado);
		ptrl = ptrl->ptr_prox;
	}
}

void SelectionSort(int vetor[], int tam) {
	int indice, indiceSeguinte, indiceMenor;
    for (indice = 0; indice < tam; ++indice) {
        indiceMenor = indice;
        for (indiceSeguinte = indice+1; indiceSeguinte < tam; ++indiceSeguinte) {
            if (vetor[indiceSeguinte] < vetor[indiceMenor]) {
                indiceMenor = indiceSeguinte;
            }
        }
        int aux = vetor[indice];
        vetor[indice] = vetor[indiceMenor];
        vetor[indiceMenor] = aux;
    }
}

void SelectionSortPointer(No **L) {
	No *pl1 = *L; No *pl2 = NULL; No *menor = NULL;
	int aux = 0;
	while(pl1 != NULL){
		menor = pl1;
		pl2 = pl1->ptr_prox;
		while(pl2 != NULL){
			if(pl2->dado < menor->dado){
				menor = pl2;
			}
			pl2 = pl2->ptr_prox;
		}
		
		aux = pl1->dado;
		pl1->dado = menor->dado;
		menor->dado = aux;
		pl1 = pl1->ptr_prox;
	}
}

int main(){
	
	No * Lista = NULL;
	Insere(&Lista, 3);
	Insere(&Lista, 0);
	Insere(&Lista, 2);
	Insere(&Lista, 4);
	Insere(&Lista, 54);
	Insere(&Lista, 5);
	Insere(&Lista, 9);
	Insere(&Lista, 18);
	printf("Lista original\n");
	Imprimir(&Lista);
	printf("\n");
	printf("Lista apos reordenacao\n");
	SelectionSortPointer(&Lista);
	//Remove(&Lista, 1);
	Imprimir(&Lista);
	//printf("Media %d:", media(Lista));
	//No * K = Busca(&Lista, 3);
	return 0;
}
