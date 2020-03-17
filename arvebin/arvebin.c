#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo{
    int chave;
    struct nodo *esq;
    struct nodo *dir;
    struct nodo *pai;
} nodo;

void inOrder(nodo *n){
    if (n != NULL){
        inOrder(n->esq);
        printf("%d ", n->chave);
        inOrder(n->dir);
    }
}

nodo *maximo(nodo *x){
	while(x->dir != NULL)
		x = x->dir;
	return x;
}

nodo *minimo(nodo *x){
	while(x->esq != NULL)
		x = x->esq;
	return x;
}

nodo *buscaBin(nodo *x, int k){
	if (x == NULL || x->chave == k)
		return x;

	if (k < x->chave)
		return buscaBin(x->esq, k);
	return buscaBin(x->dir, k);	

}

nodo *inserir(nodo *raiz, nodo *z){
	
	nodo *y, *x;
	y = NULL;
	x = raiz;

	while(x != NULL){
		printf("z = %d -- x = %d\n", z->chave, x->chave);	
		y = x;
		if (z->chave < x->chave)
			x = x->esq;
		else
			x = x->dir;
	}
	z->pai = y;
	if (z->chave < y->chave)
		y->esq = z;
	else 
		y->dir = z;
	return z;
}

nodo *criaNodo(int k){
	nodo *n = malloc(sizeof(nodo));
	n->dir = NULL;
	n->esq = NULL;
	n->pai = NULL;
	n->chave = k;
	return n;
}

int main(){

    srand(time(NULL));

    nodo *raiz = criaNodo(50);

	nodo *n = criaNodo(20);
	inserir(raiz, n);
	for (int i = 0; i < 10; i++){
	}

    inOrder(raiz);
	nodo *m = minimo(raiz);
	printf("minimo = %d\n", m->chave);
	
    return 0;
}
