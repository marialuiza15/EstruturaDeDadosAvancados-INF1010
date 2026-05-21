#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct smapa Mapa;
struct smapa{
    int chave;
    int dados;
    Mapa *esq;
    Mapa *dir;
};

Mapa* criaNo(int num){
    Mapa *novo = (Mapa*) malloc(sizeof(Mapa));
    if (novo==NULL){
        exit(1);
    }

    novo->chave = num;
    novo->dados = 0;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

Mapa* insere(Mapa *arv, int num){
    if (arv==NULL){
        return criaNo(num);
    }

    if (num<arv->chave){
        arv->esq = insere(arv->esq, num);
    }
    else if (num>arv->chave){
        arv->dir = insere(arv->dir, num);
    }

    return arv;
}

void preOrdem(Mapa *arv){
    if (arv==NULL) return;

    printf("%d ",arv->chave);
    preOrdem(arv->esq);
    preOrdem(arv->dir);
    
}

void simetrica(Mapa *arv){
    if (arv==NULL) return;

    preOrdem(arv->esq);
    printf("%d ",arv->chave);
    preOrdem(arv->dir);
    
}

void posOrdem(Mapa *arv){
    if (arv==NULL) return;

    preOrdem(arv->esq);
    preOrdem(arv->dir);
    printf("%d ",arv->chave);
    
}

























