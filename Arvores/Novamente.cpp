#include <stdio.h>
#include <stdlib.h>


typedef struct No{
	int E;
	int h;
	struct No *Esq;
	struct No *Dir;	
}No;

int Soma(No *T){
	//retorna a soma dos elementos em uma arvore t-1;
	//assuma que ha o resultado da soma do primeiro elemento da arvore
	if(T == NULL){
		return 0;
	}else{
		//int direita = Soma(T->Dir);
		//int esquerda = Soma(T->Esq);
		return Soma(T->Esq) + Soma(T->Dir)+ T->E;
	}
}

int Comparar(int a, int b){
	if(a > b){
		return a;
	}
	if(a > b){
		return a;
	}
}

int MaiorSub(No *T){
	//Retonar a maior soma das subarvores;
	//Assuma que T pode ser nulo ou Unico;
	if(T == NULL){
		return 0;
	}
	else{
		int esq = MaiorSub(T->Esq);
		int dir = MaiorSub(T->Dir);
		int p = esq + dir + T->E;
		if(T->Esq != NULL){
			int max = Comparar(esq,dir);
			if(max > p){
				p = max;
			}
		}else{
			if(T->Esq == NULL && T->Dir == NULL){
				p = T->E;
			}
		}
		return p;
	}
}

void AtualizarH(No *T){
	//assuma que a arvore pode ser vazia
	//assuma que você sabe a altura de uma arvore com apenas 1 no
	if(T == NULL){
		return;
	}
	if(T != NULL){
		T->h = 1;
		AtualizarH(T->Esq);
		AtualizarH(T->Dir);
		if(T->Esq != NULL){
			T->h = T->Esq->h+1;
		}
		if(T->Dir != NULL){
			T->h = Comparar(T->h,T->Dir->h+1);
		}
	}
}

void CriarOrdem(No *&T, int x){
	if(T == NULL){
		T = (No*)malloc(sizeof(No));
		T->E = x;
		T->h = 0;
		T->Esq = NULL;
		T->Dir = NULL;
	
	}else{
		if(x > T->E){
			CriarOrdem(T->Dir, x);
		}
		else{
			CriarOrdem(T->Esq, x);
		}
	}
}

void CriarT(No *&T, int x, No *esq, No *dir){
	
}


void ImprimirT(No *T){
	if(T!=NULL){
		printf("%d\n",T->E);
		ImprimirT(T->Esq);
		ImprimirT(T->Dir);
	}
}

void ImprimirTNivel(No *T){
	if(T!=NULL){
		printf("Altura de cada no: %d\n",T->h);
		ImprimirTNivel(T->Esq);
		ImprimirTNivel(T->Dir);
	}
}

int fibonnaci(int n){
	//returna o fibonnaci para o valor atribuido em N
	// se n=1 retorna 1, se n= 2 retorna 1;
	// caso geral f(n-1) +f(n-2)
	if(n == 1 || n == 2){
		return 1;
	}else{
		return fibonnaci(n-1)+fibonnaci(n-2);
	}
	
}

int Extrair(int n, int valor1, int valor2) {
    if (valor2 <= 0) {
        return valor1;
    }
    
    int r1 = Extrair(n, valor1 + 1, valor2 - 1);
    
    if ((r1 * r1) <= n) {
        return r1;
    } else {
        return valor1;
    }
}



int main(){
	No *T= NULL;
	//CriarOrdem(T,-10);
	//CriarOrdem(T,-10);
	//CriarOrdem(T,1);
	//CriarOrdem(T,-1000);
	//CriarOrdem(T,0);
	//CriarOrdem(T,-2);
	//CriarOrdem(T,7);
	//CriarOrdem(T,-15);
	//CriarOrdem(T,5);
	//CriarOrdem(T,10);
	//CriarOrdem(T,12);
	CriarOrdem(T,5);
	CriarOrdem(T,-3);
	CriarOrdem(T,1);
	CriarOrdem(T,0);
	CriarOrdem(T,0);
	CriarOrdem(T,-4);
	CriarOrdem(T,0);
	CriarOrdem(T,0);
	CriarOrdem(T,-10);
	CriarOrdem(T,0);
	CriarOrdem(T,0);
	CriarOrdem(T,-5);
	
	ImprimirT(T);
	printf("Soma de todos os elementos na arvore: %d\n", Soma(T));
	AtualizarH(T);
	ImprimirTNivel(T);
	//printf("Maior sub-arvore em T: %d\n",MaiorSub(T));
	int n = 0;
	printf("raiz: %d", Extrair(n,0,n));
	return 0;
}
