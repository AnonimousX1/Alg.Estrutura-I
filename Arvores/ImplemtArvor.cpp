#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int E;
	struct No *Dir;
	struct No *Esq;
}No;

No *CriarT(int x , No *Esqr, No* Dire){
	No *Novo = (No *)malloc(sizeof(No));
	Novo->E = x;
	Novo->Dir = Esqr;
	Novo->Esq = Dire;
	return Novo;
}

void ImprimirT(No *T){
	// Imprime todos os elementos da arvore
	//Assume que T pode ser vazio;
	if (T == NULL) {
        return;
	}
    if (T != NULL) {
        printf("Elemento a direita: %d\n", T->E);
    }
    ImprimirT(T->Esq);
    ImprimirT(T->Dir);
}

/*
int ContarT(No *T, int x){
	if (T == NULL) {
        return 0;
	}
    if (T != NULL) {
        x++;
    }
    return ContarT(T->Esq, x) + ContarT(T->Dir, x) + 1;
}
*/
int ContarT(No *T){
	if (T == NULL) {
        return 0;
	}
    return ContarT(T->Esq) + ContarT(T->Dir) + 1;
}

int AlturaT(No *T){
	
}

int main(){
	No *t6 = CriarT(1, NULL, NULL);
	No *t5 = CriarT(9, NULL, NULL);
	No *t4 = CriarT(0, NULL, t6);
	No *t3 = CriarT(8, NULL, t4);
	No *t2 = CriarT(4, t3, NULL);
	No *t1 = CriarT(2, NULL, t5);
	No *T = CriarT(3, t1, t2);
	ImprimirT(T);
	//int total = 0; Para a segunda versao do codigo necessita 
	printf("%d", ContarT(T));
    return 0;
}
