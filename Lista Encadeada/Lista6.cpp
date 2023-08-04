#include <stdio.h>
#include <stdlib.h>



typedef struct No {
	int E;
	No * Prox;
} No;

int Maior(No * L) {
	/* insert your code here */
	No *aux = L;
	int maior = 0;
	while(aux != NULL){
		if((aux->E) >= maior){
			maior = aux->E;
		}
		aux = aux->Prox;
	}
	return maior;
}

void RemoveMaiores(int L[], int *n, int k) {
	/* insert your code here */
	int aux = 0; int i = 0; int j = 0;
	while(i < *n-1){
		if(L[i] > k){
			j = i;
			while(j < *n-1){
				L[j] = L[j+1];
				j = j + 1;
			}
			*n = *n-1;
		}else{
			i = i+1;
		}
	}
}

void imprimir(int L[],int n){
	int i= 0;
	while(i <= n){
		printf("%d\n",L[i]);
		i= i+1;
	}
}

int main() {
	int k=3;
	int n=5;
	int  L[n];
	L[0]= 3;
	L[1]= 4;
	L[2]= 5;
	L[3]= -5;
	L[4]= -115;
	RemoveMaiores(L,&n,k);
	printf("Valor de n depois de modificado: %d\n",n);
	imprimir(L,n);
	return 0;
}
