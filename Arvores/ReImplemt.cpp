#include <stdlib.h>
#include <stdio.h>

typedef struct NoT{
	int E;
	struct NoT *esq;
	struct NoT *dir;
}NoT;

typedef struct NoL{
	int E;
	struct NoL *Prox;
}NoL;

NoL * CriaNo(int x);
NoL * ListaNosInternos(NoT *T);
void ImprimirL(NoL *L);
void CriarTOrdem(NoT * &T, int x);
NoT *CriarT(int x);
void ImprimirT(NoT *T);
NoT *BuscaT(NoT *T, int x);
int QTS(NoT *T);
int AlturaT(NoT *T);
int MaiorT(NoT *T);
int SomaFolhas(NoT *T);
int MaiorSubarvore(NoT * T);
int MaiorSubarvore2(NoT * T);
int SomarT(NoT *T);
void Insere(NoL *&L,int valor);
NoL * CriaNo(int x);
NoL * ListaNosInternos(NoT *T);


int main(){
	//1 5 0 0 2 0 0 -1
	NoT *T = NULL;
	CriarTOrdem(T,1);
	CriarTOrdem(T,5);
	CriarTOrdem(T,0);
	CriarTOrdem(T,0);
	CriarTOrdem(T,2);
	CriarTOrdem(T,0);
	CriarTOrdem(T,0);
	CriarTOrdem(T,-1);
	ImprimirT(T);
	printf("\n\n");
	printf("Altura: %d\n",AlturaT(T));
	printf("Quantos: %d\n",QTS(T));
	//printf("Maior elemento: %d\n",MaiorT(T));
	printf("Soma dos elementos da arvore: %d\n", SomarT(T));
	printf("Subarvore com a maior soma de elementos: %d\n", MaiorSubarvore2(T));
	NoL *Listainter;
	Listainter = ListaNosInternos(T);
	printf("\n");
	ImprimirL(Listainter);
	
	return 0;
}

void Insere(NoL *&L,int valor){
	NoL *novo;
	novo = (NoL *)malloc(sizeof(NoL));
	if(novo!=NULL){
		novo->E = valor;
		novo->Prox = L;
		L = novo;
	}
}


NoL * CriaNo(int x){
	NoL * novo = (NoL *)malloc(sizeof(NoL));
	novo->E= x;
	novo->Prox = NULL;
	return novo;
}



void ImprimirL(NoL *L){
	if(L == NULL){
		return;
	}else{
		printf("Valor na lista: %d\n",L->E);
		ImprimirL(L->Prox);
	}
}


NoL * ListaNosInternos(NoT *T) {
	/* insert your code here */
	//Assuma que a lista pode ser vazia
	// Retorna a lista de todos os elementos que nao pertencem as folhas
	if(T == NULL){
		return NULL;
	}else{
		NoL *Lista = NULL;
		NoL *arvesq = ListaNosInternos(T->esq);
		NoL *arvdir = ListaNosInternos(T->dir);
		if(T->esq != NULL && T->dir != NULL){
			if(Lista == NULL){
				Insere(Lista,T->E);
			}else{
			Insere(Lista->Prox,T->E);
			}
		}
		return Lista;
	}
}

int SomarT(NoT *T){
	if(T == NULL){
		return 0;
	}else{
		return SomarT(T->esq)+SomarT(T->dir)+T->E;
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
		ImprimirT(T->esq);
		ImprimirT(T->dir);
		printf("Valor em arvore: %d\n",T->E);
	}
}

