#include <stdlib.h>
#include <stdio.h>

int BinariaMul(int L[][3],int n, int x);


int main(){
	int n = 3;
	int lista[][3] = {{1,2, 3}, {3, 4, 6}, {7, 8, 9}};
	int valor = BinariaMul(lista, 3, 1);
	printf("Valor: %d\n", valor);
	
	return 0;
}
/*
int BinariaMul(int *L[][2],int n, int x){
	int i, j, m, k;
	i= 0; j=n;
	m = (i+j)/2;
	while(i<=m){
		k=0;
		while(k <= n){
			if(*(L[m,k]) != x){
				k = k + 1;
			}else{
				return *(L[m,k]);
			}
		}
		m = (i+j)/2;
	}
	return -1;
}

*/

int BinariaMul(int L[][3], int n, int x) {
	int i, j, m, k;
	i = 0;
	j = n - 1;
	m = (i + j) / 2;
	while (i <= m) {
		k = 0;
		while (k <= n) {
			if (L[m][k] != x) {
				k = k + 1;
			} else {
				return L[m][k];
			}
		}
		m = (i + j) / 2;
	}
	return -1;
}

