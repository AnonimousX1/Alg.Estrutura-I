#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SomaDig(int vetor[],int n , int &k){
	//Retorna a soma dos digitos em n
	//assuma que n>=0;
	if(n < 0){
		return;
	}
	else{
		SomaDig(vetor, n-1, k);
		k = vetor[n]+k;
	}
}
void auxpalindromo(char P[], int &VE, int i, int j){
	if(j == 0){
		return;
	}
	if(j == i && VE == 1){
		return;
	}
	if(P[i] == P[j]){
		VE = 1;
	}
	else{
		VE = -1;
		return;
	}
	auxpalindromo(P, VE, i+1, j-1);
}

void palindromo(char P[], int &VE){
	int J = strlen(P)-1;
	auxpalindromo(P, VE, 0, J);
}

int main(){
	int VE = 1; 
	char v[] = "ar";
	palindromo(v,VE);
	printf("%d",VE);
	
	return 0;
}
