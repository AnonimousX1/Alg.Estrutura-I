#include <stdio.h>
#include <stdlib.h>
#define ENORME  -9848585

typedef struct NoLista {
    int e;
    NoLista * Prox;
} NoLista;

typedef struct No {
    int E;
    No * Esq;
    No * Dir;
} No;

int Maior(No *T) {
	/* insert your code here */
	//T != NULL;
	//Retorna o elemento com maior valor da arvore
	if(T == NULL){
		return ENORME;
	}if(T->E){
		return T->E;
	}
	else{
		int ElemD, ElemE;
		ElemE = Maior(T->Esq);
		ElemD = Maior(T->Dir);
	}
	
}

No *CriarNo(int x, No *Tesq, No *Tdir){
	No *Novo = (No *)malloc(sizeof(No));
	Novo->E = x;
	Novo->Esq = Tesq;
	Novo->Dir = Tdir;
	return Novo;
}

void ImprimirFolhar(){
	
}

int main() {
    No *n9 = CriarNo(-2, NULL, NULL);
    No *n5 = CriarNo(5, NULL, n9);
    No *n6 = CriarNo(7, NULL, NULL);
    No *n3 = CriarNo(3, n5, n6);
    No *n8 = CriarNo(7, NULL, NULL);
    No *n7 = CriarNo(1, NULL, NULL);
    No *n4 = CriarNo(-4, n7, n8);
    No *n2 = CriarNo(-1, NULL, n4);
    No *T = CriarNo(2, n2, n3);

    //EscreveFolhas(T);
    //EscreveInternos(T);
    
    //NoLista * Lfolhas = NULL;
    //DeterminarFolhas(T, Lfolhas);
    //Escreve(Lfolhas);
    
    return 0;
}
