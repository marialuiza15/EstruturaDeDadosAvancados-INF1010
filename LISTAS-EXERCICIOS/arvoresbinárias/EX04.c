#include <stdio.h>
#include <stdlib.h>

typedef struct smapa Mapa;
struct smapa{
    int chave;
    int dados;
    Mapa *esq;
    Mapa *dir;
    Mapa *pai;
};

Mapa* criaNo(Mapa* arv,int num){
    Mapa *novo = (Mapa*)malloc(sizeof(Mapa));

    if (novo==NULL){
        exit(1);
    }

    novo->chave = num;
    novo->dados = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = arv;

    return novo;

}

Mapa* insere(Mapa* arv, int num, Mapa* pai){
    if (arv==NULL){
        arv = criaNo(pai, num);
    }

    if (num>arv->chave){
        arv->dir = insere(arv->dir, num, arv);
    }
    else if (num<arv->chave){
        arv->esq = insere(arv->esq, num, arv);
    }

    return arv;
}