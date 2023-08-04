#ifndef DEF_H
#define DEF_H

//Declaracao de prototipo de funcoes
//Declaracoes devem ser feitas entre as os codigos de processador

typedef struct NoT{
	int E;
	int h;
	struct NoT *esq;
	struct NoT *dir;
}NoT;

typedef struct NoL{
	int E;
	struct NoL *Prox;
}NoL;

NoL * CriaNo(int x);
NoL * ListaNosInternos(NoT *T);
void ImprimirL(NoL *L);
void CriarTOrdem(NoT * &T, int x);
NoT *CriarT(int x);
void ImprimirT(NoT *T);
NoT *BuscaT(NoT *T, int x);
int QTS(NoT *T);
int AlturaT(NoT *T);
int MaiorT(NoT *T);
int SomaFolhas(NoT *T);
int MaiorSubarvore(NoT * T);
int MaiorSubarvore2(NoT * T);
int SomarT(NoT *T);
void Insere(NoL *&L,int valor);
NoL * CriaNo(int x);
NoL * ListaNosInternos(NoT *T);
void AtualizaAltura(NoT *T, int contar);
void CadaAltura(NoT *T);

#endif //DEF_H
