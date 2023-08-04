#include <stdio.h>
#include <stdlib.h>

int BuscaBinaria(int L[], int x, int n){
	int i,j,m;
	i = 0; j = n;
	while (i<=j){
		m = (i+j)/2;
		if(L[m] > x){
			j = m-1;
		}else if(L[m] < x){
			i = m+1;
		}else{
			return m;
		}
		
	}
	return -1;
}

int main(){
	int lista[7]={1,2,3,4,5,6,7};
	
	printf("%d",BuscaBinaria(lista, 1, 7));
	
	return 0;
}


