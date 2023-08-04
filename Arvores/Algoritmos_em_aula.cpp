#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int E;
	int h;
	struct No *Esq;
	struct No *Dir;	
}No;

typedef struct L{
	int E;
	struct L *Prox;
}L;

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

/* Algoritmos em aula do fabiano*/
//"Corr" significa correto
void incrementaNivel(No *T){
	if(T != NULL){
		incrementaNivel(T->Esq);
		incrementaNivel(T->Dir);
		T->h = T->h+1;
	}
}

void AtuNiv(No *T){ //Com erro de raciocineo (Complexidade O(n^2))
	//(Resolucao exercicio 1B PDF arvores)
	//atualiza cada no de T com seu nivel em T
	if(T!= NULL){
		AtuNiv(T->Esq);
		AtuNiv(T->Dir);
		T->h = 1;
		incrementaNivel(T->Esq);
		incrementaNivel(T->Dir);
	}
}
void AtuNivCorr(No *T, int incr){ //Correto, porem generalizado
	//(Resolucao exercicio 1B PDF arvores)
	//atualiza todos os nos de T com os respectivos nivel
	//acrescido de incr.
	if(T!= NULL){
		AtuNivCorr(T->Esq,incr+1);
		AtuNivCorr(T->Dir,incr+1);
		T->h = incr + 1;
	}
}

int contar(No *T){ //algoritmo que deve ser evitado, nao eh o ideal
	// algoritmo com variavel local que deve ser evitado
	if(T!= NULL){
		int n;
		n = n+1;
		contar(T->Esq);
		contar(T->Dir);
		return n;
	}
	else{
		return 0;
	}
}

int contaCorr(No *T){// algoritmo ideal
	
	if(T!= NULL){
		int n;
		n = contaCorr(T->Esq);
		n = contaCorr(T->Dir);
		n = n+1;
		return n;
	}
	else{
		return 0;
	}
}

//(Resolucao exercicio 8 PDF arvores)
int h(No *T){
	if(T != NULL){
		
		//acertar definicao da funcao max da biblioteca c++
		return std::max(h(T->Esq), h(T->Dir))+1;
	}
	else{
		return 0;
	}
}

void ObterNiv(No *T, int *niv[], int nivr){
	//considera o nivel da raiz igual a
	//nivr e insere-os em niv[]
	if(T != NULL){
		insere(niv[nivr],T->E);// insere de listas encadeadas nao ordenadas
		ObterNiv(T->Esq, niv, nivr+1);
		ObterNiv(T->Dir, niv, nivr+1);
	}
}

int Maior(No *T){
	if(T != NULL){
		return std::max(Maior(T->Esq), Maior(T->Dir),T->E);
	}
	else{
		return -11111111;
	}
}



int main(){
	
	No *T= NULL;
	No * niv[h(T)] = NULL;
	ObterNiv(T, niv, 0); // em pseudo codigo deve ser o parametro 1
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
	printf("Maior sub-arvore em T: %d\n",MaiorSub(T));
	return 0;
}
