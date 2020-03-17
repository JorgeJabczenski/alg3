#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo{
    int chave;
    struct nodo *esq;
    struct nodo *dir;
    struct nodo *pai;
} nodo;


nodo *binary(nodo *n, int chave){
    if (n == NULL)
        return criaNodo(chave);

    else if (n->chave < chave)
        return binary(n->dir, chave);
    else if (n->chave < chave)
        return binary(n->esq, chave);

    return n;
}


void inOrder(nodo *n){
    if (n != NULL){
        inOrder(n->esq);
        printf("%d ", n->chave);
        inOrder(n->dir);
    }
}

int main(){

    srand(time(NULL));

    nodo *raiz = criaNodo(50);

    for (int i = 0; i < 10; i++)
        binary(raiz, rand()%100);

    inOrder(raiz);

    return 0;
}