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
    if(novo == NULL){
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

    if (arv->chave<num){
        arv->dir = insere(arv->dir, num);
    } 
    else if (arv->chave>num){
        arv->esq = insere(arv->esq, num);
    } 
    return arv;
}

int main(){
    Mapa *arv = NULL;
    int num;
    int v[] = {1,5,4,1,65,2,5,4,8,5,2,6,5,98,8};

    srand(time(NULL)); //semente

    int tam = sizeof(v)/sizeof(v[0]);

    for(int i=0;i<tam;i++){
        num = v[i];
        arv = insere(arv, num);
    }


    return 0;
}