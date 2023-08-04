#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int Dado;
	struct No *Prox;
}No;

void RemoverK(No **L, int k);
void Insere(No **L,int valor);
void Imprimir(No **L);
No * Busca(No **L, int valor);

int main(){
	No * Lista = NULL;
	Insere(&Lista, 3);
	Insere(&Lista, 4);
	Insere(&Lista, 5);
	printf("Lista original\n");
	Imprimir(&Lista);
	printf("\n");
	//printf("Lista apos remocao\n");
	//Remove(&Lista, 1);
	printf("Lista apos remocao de elementos maiores que K\n");
	RemoverK(&Lista, 3);
	Imprimir(&Lista);
	return 0;
}


void Insere(No **L,int valor){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	if(novo!=NULL){
		novo->Dado = valor;
		novo->Prox = *L;
		*L = novo;
	}
}

void Imprimir(No **L){
	No *ptrl = *L;
	while(ptrl!= NULL){
		printf("%d->", ptrl->Dado);
		ptrl = ptrl->Prox;
	}
}

No * Busca(No **L, int valor){
	No *ptrl = *L;
	while(ptrl != NULL){
		if(ptrl->Dado != valor)	{
			ptrl = ptrl->Prox;
		}else
		 return(ptrl); // retorna o ponteiro para a estrutura onde se encontra o elemento
	}
	if(ptrl==NULL){
		return ptrl;
	}
	printf("Elemento nao esta na lista\n");
}

void RemoverK(No **L, int k){
	No *pL, *pantL;
	pL = *L; pantL = NULL;
	while (pL != NULL){
		if(pL->Dado <= k){
			pantL = pL;
			pL = pL->Prox;
		}else{
			if(pantL == NULL){
				*L = pL->Prox;
				free(pL);
				pL = *L;
			}else{
				pantL->Prox = pL->Prox;
				free(pL);
				pL = pantL->Prox;
			}
		}
	}
}


