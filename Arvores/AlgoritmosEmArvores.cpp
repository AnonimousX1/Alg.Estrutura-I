// Online C++ compiler to run C++ program online
#include <stdio.h>
#include <stdlib.h>

#define MAIS_INF 999999999
#define MENOS_INF -999999999

int min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int max(int x, int y) {
    if (x < y) {
        return y;
    } else {
        return x;
    }
}

typedef struct NoLista {
    int e;
    NoLista * Prox;
} NoLista;

typedef struct No {
    int e;
    No * Esq;
    No * Dir;
} No;

void Insere(NoLista * &L, int x) {
    NoLista * n;
    n = (NoLista *) malloc(sizeof(NoLista));
    n->e = x;
    n->Prox = L;
    L = n;
}

void Escreve(NoLista * L) {
    if (L == NULL) {
        printf("(fim)\n");
    } else {
        printf("%d -> ", L->e);
        Escreve(L->Prox);
    }
}

int Soma(No * T) {
    if (T == NULL) {
        return 0;
    } else {
        return Soma(T->Esq) + Soma(T->Dir) 
                + T->e;
    }
}

No * CriarNo(int e, No * TEsq, No * TDir) {
    No * n;
    n = (No *) malloc(sizeof(No));
    n->e = e;
    n->Esq = TEsq;
    n->Dir = TDir;
    return n;
}

int Menor(No * T) {
    if (T == NULL) {
        return MAIS_INF;
    } else {
        int me = Menor(T->Esq);
        int md = Menor(T->Dir);
        return min(min(me, md), T->e);
    }
}

int Qte(No * T) {
    if (T == NULL) {
        return 0;
    } else {
        return Qte(T->Esq) + Qte(T->Dir) + 1;
    }
}

void MaxMin(No * T, int &m, int &M) {
    //escrever em m o menor elemento de T e 
    //         em M o maior elemento de T 
    if (T == NULL) {
        m = MAIS_INF; M = MENOS_INF;    
    } else {
        int me, md, Me, Md;
        MaxMin(T->Esq, me, Me);
        MaxMin(T->Dir, md, Md);
        m = min(min(me, md), T->e);
        M = max(max(Me, Md), T->e);
    }
}

void EscreveFolhas(No * T) {
    if (T != NULL) {
        if ((T->Esq == NULL) && (T->Dir == NULL)) {
            printf("Folha = %d\n", T->e);
        } else {
            EscreveFolhas(T->Esq);
            EscreveFolhas(T->Dir);
        }
    }
}

void DeterminarFolhas(No * T, NoLista * &Lfolhas) {
    if (T != NULL) {
        if ((T->Esq == NULL) && (T->Dir == NULL)) {
            Insere(Lfolhas, T->e);
        } else {
            DeterminarFolhas(T->Esq, Lfolhas);
            DeterminarFolhas(T->Dir, Lfolhas);
        }
    }
}

void EscreveInternos(No * T) {
    if (T != NULL) {
        if ((T->Esq != NULL) || (T->Dir != NULL)) {
            printf("Interno = %d\n", T->e);
        }
        EscreveInternos(T->Esq);
        EscreveInternos(T->Dir);
    }
}


int maiorcaminho(No *T){
	if(T == NULL){
		return 0;
	}
	if(T->Esq == NULL && T->Dir == NULL){
		return 1;
	}else{
		int maior;
		int maioresq = maiorcaminho(T->Esq);
		int maiordir = maiorcaminho(T->Dir);
		maior =  max(maioresq, maiordir)+1;
		return maior;
	}
}

int fabiano(No *T){
	if(T == NULL){
		return 0;
	}
	else{
		int hesq , hdir;
		hesq = fabiano(T->Esq);
		hdir = fabiano(T->Dir);
		return max(hesq, hdir)+1;
	}
}

int ProdutoT(No *T){
	if(T == NULL){
		return 1;
	}
	return ProdutoT(T->Esq)*ProdutoT(T->Dir)*T->e;
}

int main() {
    No * n9 = CriarNo(-2, NULL, NULL);
    No * n5 = CriarNo(5, NULL, n9);
    No * n6 = CriarNo(7, NULL, NULL);
    No * n3 = CriarNo(3, n5, n6);
    No * n8 = CriarNo(7, NULL, NULL);
    No * n7 = CriarNo(1, NULL, NULL);
    No * n4 = CriarNo(-4, n7, n8);
    No * n2 = CriarNo(-1, NULL, n4);
    No * T = CriarNo(2, n2, n3);
    
    //printf("Soma = %d\n", Soma(T));
    //printf("Menor = %d\n", Menor(T));
    //printf("Qte = %d\n", Qte(T));
    
    int m, M;
    //MaxMin(T, m, M);
    printf("Menor elemento = %d\n", m);
    printf("Maior elemento = %d\n", M);
    
    //EscreveFolhas(T);
    //EscreveInternos(T);
    
    NoLista * Lfolhas = NULL;
    //DeterminarFolhas(T, Lfolhas);
    //printf("Maior caminho: %d\n",fabiano(T));
    
    printf("Produto dos elementos na arvore: %d", ProdutoT(T));
    return 0;
}
