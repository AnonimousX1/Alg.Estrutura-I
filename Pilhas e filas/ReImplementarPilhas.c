#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int E;
	struct No *Prox;
}No;

typedef struct EPilha{
	No *Topo;
	int qtd;
}EPilha;

EPilha *Topo();
EPilha* criarPilha();
void Empilha(EPilha *pilha, int x);
EPilha *Desempilha(EPilha *pilha);
int Tamanho(EPilha *pilha);


int main(){
	EPilha *pilhaa = criarPilha();
	Empilha(pilhaa, 3);
	Empilha(pilhaa, 4);
	printf("%d ",Topo(pilhaa)->Topo);
	printf("%d ",pilhaa->qtd);
	Empilha(pilhaa, 6);
	
	//printf("%d ",pilhaa->Topo);
	//printf("%d ",Tamanho(pilhaa));
	return 0;
}


EPilha* criarPilha() {
    EPilha* pilha = (EPilha*)malloc(sizeof(EPilha));
    pilha->Topo = NULL;
    pilha->qtd = 0;
    return pilha;
}

void Empilha(EPilha *prt, int x){
	No *novo = (No*)malloc(sizeof(No));
	if(novo != NULL){
		novo->E = x;
		novo->Prox = prt->Topo;
		prt->Topo = novo;
		prt->qtd++;
	}
}

EPilha *Desempilha(EPilha *prt){
	if(prt->Topo != NULL){
		EPilha *aux;
		aux->Topo = prt->Topo->Prox;
		prt->Topo = aux->Topo;
		free(prt);
		prt->Topo = aux->Topo;
		prt->qtd--;
	}
}

EPilha *Topo(EPilha *prt){
	if(prt->Topo == NULL){
		return prt;
	}
}

int Tamanho(EPilha *prt){
	if(prt->Topo != NULL){
		return prt->qtd;
	}
}
