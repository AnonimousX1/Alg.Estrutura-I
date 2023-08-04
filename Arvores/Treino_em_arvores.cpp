#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int x;
	struct No *Esq;
	struct No *Dir;
}No;

int SomaT(No *T){
	if(T == NULL){
		return 0;
	}
	int dir = SomaT(T->Esq);
	int esq = SomaT(T->Dir);
	return dir + esq + T->x;
}

void CriarOrdem(No *&T, int x){
	if(T == NULL){
		T = (No*)malloc(sizeof(No));
		T->x = x;
		T->Esq = NULL;
		T->Dir = NULL;
		
	}else{
		if(x > T->x){
			CriarOrdem(T->Dir,x);
		}
		else{
			CriarOrdem(T->Esq,x);
		}
	}
}

void ImprimirT(No *T){
	if(T != NULL){
		printf("Elemento: %d\n",T->x);
		ImprimirT(T->Esq);
		ImprimirT(T->Dir);
		
	}
}

int main(){
	No *T = NULL;
	CriarOrdem(T,5);
	CriarOrdem(T,-3);
	CriarOrdem(T,1);
	CriarOrdem(T,0);
	CriarOrdem(T,0);
	CriarOrdem(T,-4);
	CriarOrdem(T,0);
	CriarOrdem(T,0);
	CriarOrdem(T,10);
	CriarOrdem(T,-1);
	ImprimirT(T);
	printf("Soma da arvore: %d\n",SomaT(T));
	return 0;
}
