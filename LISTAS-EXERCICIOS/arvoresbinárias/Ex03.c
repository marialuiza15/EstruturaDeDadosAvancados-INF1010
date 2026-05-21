#include <stdio.h>
#include <stdlib.h>

typedef struct smapa Mapa;
struct smapa{
    int chave;
    int dados;
    Mapa *esq;
    Mapa *dir;
};

Mapa* criaNo(int num){
    Mapa *novo = (Mapa*)malloc(sizeof(Mapa));
    if(novo==NULL){
        exit(1);
    }
    novo->chave = num;
    novo->dados = 0;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

Mapa* insere(Mapa *arv, int num){
    if(arv==NULL){
        arv = criaNo(num);
    }

    if(num>arv->chave){
        arv->dir = insere(arv->dir, num);
    }

    if(num<arv->chave){
        arv->esq = insere(arv->esq, num);
    }

    return arv;
}

Mapa* busca(Mapa *arv, int num){
    if (arv==NULL) return NULL;

    if (num == arv->chave) return arv; // se fosse uma busca padrao, retornaria o dado e o tipo da funcaos eria int

    if (num < arv->chave) return busca(arv->esq, num);

    if (num > arv->chave) return busca(arv->dir, num);
}