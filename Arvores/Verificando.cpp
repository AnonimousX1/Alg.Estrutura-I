#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

typedef struct NoT{
	int E;
	int h;
	struct NoT *Esq;
	struct NoT *Dir;
}NoT;

int SomarT(NoT *T);
int MaiorSubarvoreFabiano(NoT * T, int &soma);
int MaiorSubarvore(NoT * T);
int MaiorSubarvore2(NoT * T);
int MaiorSubarvore3(NoT * T);
int ReMaiorSubarvore(NoT *T, int &principal);
NoT *CriarT(int x, NoT * esq, NoT * dir);
int ImprimirR(NoT * T);
NoT *AuxCriarT(int x);
void CriarTOrdem(NoT *&T, int x);
int AuxReMaiorSubarvore(NoT *T);

int main(){
	//NoT *T3 = CriarT(1, NULL, NULL);
	//NoT *T2 = CriarT(-10, T3, NULL);
	//NoT *T = CriarT(-10, T2, NULL);
	//T->Esq = T2;
	//T2->Esq = T3;
	NoT *T = NULL;
	CriarTOrdem(T, -10);
	CriarTOrdem(T, -10);
	CriarTOrdem(T, 1);
	ImprimirR(T);
	printf("\n");
	int total = SomarT(T);
	int salvar = ReMaiorSubarvore(T,total);
	printf("Maior valor da soma das subarvores: %d", salvar);
	return 0;
}

int SomarT(NoT *T){
	if(T == NULL){
		return 0;
	}else{
		return SomarT(T->Esq)+SomarT(T->Dir)+T->E;
	}
}

int ImprimirR(NoT * T){
	if(T != NULL){
		ImprimirR(T->Esq);
		ImprimirR(T->Dir);
		printf("Elemento na arvore: %d\n",T->E);
	}
	

}
NoT *CriarT(int x, NoT * Esq, NoT * Dir){
    NoT* novo = (NoT*)malloc(sizeof(NoT));
    novo->E = x;
    novo->Esq = Esq;
    novo->Dir = Dir;
    return novo;
}
NoT *AuxCriarT(int x){
    NoT* novo = (NoT*)malloc(sizeof(NoT));
    novo->E = x;
    novo->Esq = NULL;
    novo->Dir = NULL;
    return novo;
}

void CriarTOrdem(NoT *&T, int x) {
    if (T == NULL) {
        T = AuxCriarT(x);
    } else if (x > T->E) {
        CriarTOrdem(T->Dir, x);
    } else if (x <= T->E) {
        CriarTOrdem(T->Esq, x);
    }
}

int MaiorSubarvore(NoT * T) {
	int soma;
	return MaiorSubarvoreFabiano(T, soma);
}

int MaiorSubarvoreFabiano(NoT * T, int &soma) {
	if (T == NULL) {
		soma = 0;
		return 0;
	} else {
		int me, md, s, se, sd;
		me = MaiorSubarvoreFabiano(T->Esq, se);
		md = MaiorSubarvoreFabiano(T->Dir, sd);
		soma = se + sd + T->E;
		return std::max(std::max(me, md), soma);
	}
}


int MaiorSubarvore2(NoT * T) {
	//Assuma que a arvore pode ser vazia
	//retorna a soma dos valores da maior subarvore;
	int principal = SomarT(T);
	int esqueda = SomarT(T->Esq);
	int direita = SomarT(T->Dir);
	
	if(esqueda > principal){
		principal = esqueda;
	}
	if(direita > principal){
		principal = direita;
	}
	return principal;
}

int MaiorSubarvore3(NoT *T) {
	//Assuma que a arvore pode ser vazia
	//retorna a soma dos valores da maior subarvore;
	if(T == NULL){
		return 0;
	}
	int principal = SomarT(T);
	if(T->Esq != NULL){
		int esqueda = SomarT(T->Esq);
		if(esqueda > principal){
			principal = esqueda;
		}
	}
	if(T->Dir !=NULL){
		int direita = SomarT(T->Dir);
		if(direita > principal){
			principal = direita;
		}
	}
	return principal;
}


int ReMaiorSubarvore2(NoT *T){
	//Assuma você já tem a soma dos T-1
	//Assma que a arvore pode ser nula
	if(T == NULL){
		return 0;
	}
	int principal = T->E;
	if(T->Esq !=NULL){
		int esqueda = SomarT(T->Esq);
		if(esqueda > principal){
			principal = esqueda;
		}
	}if(T->Dir != NULL){
		int direita = SomarT(T->Dir);
		if(direita > principal){
			principal = direita;
		}
	}
	return principal;
}

int ReMaiorSubarvore(NoT *T, int &principal){
	//Assuma você já tem a soma dos T-1
	//Assma que a arvore pode ser nula
	//Necessita de uma funcao auxiliar para fazer comparativos
	if(T == NULL){
		return 0;
	}
	if(T->Esq !=NULL){
		int esqueda = SomarT(T->Esq);
		if(esqueda > principal){
			principal = esqueda;
		}
	}if(T->Dir != NULL){
		int direita = SomarT(T->Dir);
		if(direita > principal){
			principal = direita;
		}
	}
	return principal;
}
