#include <stdlib.h>
#include <stdio.h>

int main(){
	int n;
	printf("Escolha um valor para N: ");
	scanf("%d",&n);
	//printf("%d",calculasub(n));
	printf("%d",calculasoma(n));
	return 0;
}

int calculasub(int n){
	int r = n;
	printf("Calculo da operacao: %d \n",r*r);
	while(r*r > n){
		printf("Eh inclusivo\n");
		r = r - 1;
	}
	return r;
	
}

int calculasoma(int n){
	int r = 0;
	printf("Calculo da operacao: %d \n",(r+1)*(r+1));
	while((r+1)*(r+1) <= n){
		r = r + 1;
	}
	return r;
	
}
