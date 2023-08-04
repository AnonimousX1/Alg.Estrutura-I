#include <stdio.h>
#include <stdlib.h>


typedef struct No{
	int Dado;
	No * Prox;
}No;


void InserirInicio(No **Lista, int Dado){
	No *prt_lista = *Lista;
	if(prt_lista->Prox !=NULL){
		No *novo_no = (No *)malloc(sizeof(No));
		novo_no->Dado = Dado;
		novo_no->Prox =NULL;
		prt_lista->Prox = novo_no;
	}
}

void Imprimir(No **Lista){
	No *prt_lista = *Lista;
	if(prt_lista->Prox != NULL){
		while(prt_lista->Prox != NULL){
			printf("%p--> ",prt_lista->Dado);
			prt_lista->Prox = prt_lista;
		}
	}else{
		printf("Nao ha elementos na lista a ser impresso");
	}
	
	
}

int main(){
	No *Lista = NULL;
	//No *prt_inicio = Lista;
	//InserirInicio(&Lista, 3);
	Imprimir(&Lista);
	return 0;
}
