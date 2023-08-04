#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include "definicoes.h"

//Implementacao das Funcoes Para arvores

int SomarT(NoT *T){
	if(T == NULL){
		return 0;
	}else{
		return SomarT(T->esq)+SomarT(T->dir)+T->E;
	}
}


void AtualizaAltura(NoT *T, int contar){ 
	// Coloca o valor correto da altura do no, considere pode ser nula
	if(T == NULL){
		return;
	}
	if(T != NULL){
		contar = contar + 1;
		AtualizaAltura(T->esq, contar);
		AtualizaAltura(T->dir, contar);
		T->h = contar;
	}
}

int MaiorSubarvore(NoT * T) {
	//Assuma que a arvore pode ser vazia
	//retorna a soma dos valores da maior subarvore;
	int principal = SomarT(T);
	int esqueda = SomarT(T->esq);
	int direita = SomarT(T->dir);
	
	if(esqueda > principal){
		principal = esqueda;
	}
	if(direita > principal){
		principal = direita;
	}
	return principal;
}

int MaiorSubarvore2(NoT * T) {
	//Assuma que a arvore pode ser vazia
	//retorna a soma dos valores da maior subarvore;
	if(T == NULL){
		return 0;
	}
	int principal = SomarT(T);
	if(T->esq != NULL){
		int esqueda = SomarT(T->esq);
		if(esqueda > principal){
			principal = esqueda;
		}
	}
	if(T->dir !=NULL){
		int direita = SomarT(T->dir);
		if(direita > principal){
			principal = direita;
		}
	}
	return principal;
}

int AlturaT(NoT *T){
	//suponha que T pode ser Nulo
	//Retornar altura da arvore
	if(T == NULL){
		return 0;
	}
	int alturaesq = AlturaT(T->esq)+1;
	int alturadir = AlturaT(T->dir)+1;
	if(alturaesq > alturadir){
		return alturaesq;
	}else{
		return alturadir;
	}
}

int altura(NoT *T){
	//Retorna a altura de uma arvore
	if(T == NULL){
		return 0;
	}
	if(T != NULL){
		int tesq = altura(T->esq)+1;
		int tdir = altura(T->dir)+1;
		if(tesq>tdir){
			return tesq;
		}else{
			return tdir;
		}
	}
}

int SomaFolhas(NoT *T) {
	//Somar todas as folhas de T
	//Assuma que T pode ser nulo;
	if(T == NULL){
		return 0;
	}else{
		if(T->esq == NULL && T->dir == NULL){
			return T->E;
		}
		int soma1 = SomaFolhas(T->dir);
		int soma2 = SomaFolhas(T->esq);
		return soma1 + soma2;
	}
}

int MaiorT(NoT *T){
	//assumo que a arvore contém pelo menos 1 elemento;
	int maiorele = T->E;
	if(T->esq != NULL){
		int maioreleesq = MaiorT(T->esq);
		if(maioreleesq > maiorele){
			maiorele = maioreleesq;
		}
	}
	if(T->dir != NULL){
		int maioreledir = MaiorT(T->dir);
		if(maioreledir > maiorele){
			maiorele = maioreledir;
		}
	}
	return maiorele;
}


int QTS(NoT *T){
	if(T == NULL){
		return 0;
	}else{
		return QTS(T->esq)+QTS(T->dir)+1;
	}
}

NoT *BuscaT(NoT* T, int x){
	if(T == NULL){
		return NULL;
	}else{
		if(T->E == x){
			return T;
		}
		else if(x < T->E){
			return BuscaT(T->esq, x);
		}else{
			return BuscaT(T->dir, x);
		}
	}
}

NoT *CriarT(int x){
    NoT* novo = (NoT*)malloc(sizeof(NoT));
    novo->E = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void CriarTOrdem(NoT *&T, int x) {
    if (T == NULL) {
        T = CriarT(x);
    } else if (x > T->E) {
        CriarTOrdem(T->dir, x);
    } else if (x < T->E) {
        CriarTOrdem(T->esq, x);
    }
}

void ImprimirT(NoT *T){
	if(T == NULL){
		return;
	}else{
		printf("Valor em arvore: %d\n",T->E);
		ImprimirT(T->esq);
		ImprimirT(T->dir);
		
		
	}
}

void CadaAltura(NoT *T){
	if(T == NULL){
		return;
	}else{
		printf("Altura do NO: %d\n",T->h);
		CadaAltura(T->esq);
		CadaAltura(T->dir);	
	}
}

