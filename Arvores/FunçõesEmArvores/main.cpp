#include <stdlib.h>
#include <stdio.h>
#include "definicoes.h"
#include "Biblioarvores.cpp"
#include "Bibliolistas.cpp"

int main(){
	//NoT *T = NULL;
	//CriarTOrdem(T,-10);
	//CriarTOrdem(T,-10);
	//CriarTOrdem(T,1);
	ImprimirT(T);
	//printf("\n\n");
	//NoL* internos = ListaNosInternos(T);
	//ImprimirL(internos);
	printf("Altura maxima da arvore: %d\n", altura(T));
	int contar = 0;
	AtualizaAltura(T,contar);
	printf("\n\n");
	CadaAltura(T);
	printf("Altura maxima da arvore: %d\n", MaiorSubarvore2(T));
	return 0;
}
