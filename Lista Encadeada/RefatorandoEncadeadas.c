#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int Dado;
	struct No *Prox;
	
}No;

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

void Remove(No **L, int valor){
	No *pAnt = NULL;
	No *ptrl = *L;
	if(ptrl!=NULL && ptrl->Dado==valor){ //Caso do primeiro elemento
		pAnt= ptrl->Prox;
		free(ptrl);
		*L = pAnt;
		return;
	}if(ptrl!=NULL && ptrl->Dado !=valor && ptrl!=NULL && ptrl->Prox!=NULL){
		while (ptrl !=NULL){
			if(ptrl->Dado!= valor){
				pAnt = ptrl;
				ptrl = ptrl->Prox;
			}else{
				pAnt->Prox = ptrl->Prox;
				//*L= pAnt;
				return;
			}
		}
		printf("Elemento nao pode ser removido da lista, pois nao esta na lista\n");
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

int media(No *L){
	No * p = L;
	int soma = 0; int contar = 0;
	while(p !=NULL){
		soma = soma + p->Dado;
		contar = contar + 1;
		p = p->Prox;
	}
	return soma/contar;
}


int main(){
	No * Lista = NULL;
	Insere(&Lista, 3);
	Insere(&Lista, 4);
	Insere(&Lista, 5);
	printf("Lista original\n");
	Imprimir(&Lista);
	printf("\n");
	printf("Lista apos remocao\n");
	Remove(&Lista, 1);
	Imprimir(&Lista);
	printf("Media %d:", media(Lista));
	//No * K = Busca(&Lista, 3);
	return 0;
}
