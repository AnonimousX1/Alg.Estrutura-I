#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int e;
	struct No *Prox;
}No;

typedef struct Fila{
	int qts;
	No *Inicio;
	No *Fim;
}Fila;


void Enfileira(Fila *fila, int x){
	No *novo = (No*)malloc(sizeof(No));
	if(novo != NULL){
		novo->e = x;
		novo->Prox = fila->Fim;
		if(fila->Inicio == NULL){
			fila->Fim = novo;
			fila->Inicio = novo;
		}else{
			fila->Fim->Prox = novo;
			fila->Fim = novo;
		}
		fila->qts++;
	}
	else{
	}
}

int Desenfileira(Fila *fila){
	//Remove e retorna o próximo de F
	if(fila->Inicio != NULL){
		No *aux = fila->Inicio;
		int auxvalor= aux->e;
		
		fila->Inicio = fila->Inicio->Prox;
		free(aux);
		if (fila->Inicio == NULL) {
            fila->Fim = NULL;
        }
        fila->qts--;
        return auxvalor;
	}else{
		return -1;
	}
}

No *Proximo(Fila *fila){
	if(fila->Inicio != NULL){
		return fila->Inicio;
	}
	return NULL;
	
}

int Tamanho(Fila *fila){
	if(fila->Inicio != NULL){
		return 0;
	}
	return fila->qts;
	
}
Fila *Criarfila(){
	Fila *pfila = (Fila*)malloc(sizeof(Fila));
	pfila->Inicio = NULL;
	pfila->Fim = NULL;
	pfila->qts = 0;
	return pfila;
}

int main(){
	Fila *fila = Criarfila();
	Enfileira(fila, 3);
	Enfileira(fila, 4);
	Enfileira(fila, 5);
	return 0;
}
