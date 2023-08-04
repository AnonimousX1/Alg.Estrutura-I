#include <stdio.h>
#include <stdlib.h>
void selecao(int vet[], int tam);
void RemoveMaiores(int L[], int &n, int k);

int main(){
	int lista[8]={1,2,65,3,45,7,4,5};
	int n = 8;
	int k = 3;
	selecao(lista, n);
	RemoveMaiores(lista, n, k);
	for(int i = 0; i<n ; i++){
		printf("%d\n", lista[i]);
	}
	return 0;
}

void selecao(int vet[], int tam) {
    int i, j, min, x;
    for (i = 0; i < tam - 1; i++) {
        min = i;
        for (j = i + 1; j < tam; j++) {
            if (vet[j] < vet[min])
                min = j;
        }
        x = vet[min];
        vet[min] = vet[i];
        vet[i] = x;
    }
}


void RemoveMaiores(int L[], int &n, int k) {
	/* insert your code here */
	selecao(L,n);
	int aux = 0; int i = 0;
	while(L[i]!= k){
		i= i+1;
	}if(L[i] == k){
		n = i;
		/*
		while(i <= n && i+1 < n){
			//aux = L[i];
			L[i] = L[i+1];
			//L[i+1]= aux;
			i= i+1;
			n = n-1;
		}*/
	}
}
