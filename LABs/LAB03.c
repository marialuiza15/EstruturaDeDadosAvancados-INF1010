#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int chave;
    int numnos; 
    struct nodo *esq;
    struct nodo *dir;
} Nodo;

Nodo *criaNo(int chave) {
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo));

    if (novo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }

    novo->chave = chave;
    novo->numnos = 0;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

Nodo *insere(Nodo *r, Nodo *novo) {
    if (r == NULL) {
        return novo;
    }

    if (r->chave > novo->chave) {
        r->esq = insere(r->esq, novo);
    } else {
        r->dir = insere(r->dir, novo);
    }

    return r;
}

int calculaNumNos(Nodo *r) {
    if (r == NULL) {
        return 0;
    }

    int qtdEsq = calculaNumNos(r->esq);
    int qtdDir = calculaNumNos(r->dir);

    r->numnos = 1 + qtdEsq + qtdDir;
    return r->numnos;
}

void preOrdem(Nodo *r) {
    if (r == NULL){
        return;
    }   
    printf("%d(%d) ", r->chave, r->numnos);

    if (r->esq != NULL){
        preOrdem(r->esq);
    }
        
    if (r->dir != NULL){
        preOrdem(r->dir);
    }
}

void emOrdem(Nodo *r) {
    if (r == NULL){
        return;
    }
    
    if (r->esq != NULL){
        emOrdem(r->esq);
    }
    printf("%d(%d) ", r->chave, r->numnos);

    if (r->dir != NULL){
        emOrdem(r->dir);
    }
}

void porNivel(Nodo *raiz) {
    if (raiz == NULL) {
        return;
    }

    Nodo *fila[100];
    int inicio = 0;
    int fim = 0;

    fila[fim] = raiz;
    fim++;

    while (inicio < fim) {
        Nodo *atual = fila[inicio];
        inicio++;

        printf("%d(%d) ", atual->chave, atual->numnos);

        if (atual->esq != NULL) {
            fila[fim] = atual->esq;
            fim++;
        }

        if (atual->dir != NULL) {
            fila[fim] = atual->dir;
            fim++;
        }
    }
}

int main() {
    FILE *f;
    int valor;
    Nodo *raiz = NULL;

    f = fopen("entrada.txt", "r");

    if (f == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    while (fscanf(f, "%d", &valor) == 1) {
        Nodo *novo = criaNo(valor);
        raiz = insere(raiz, novo);
    }

    fclose(f);

    calculaNumNos(raiz);

    printf("Pre-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Ordem Simetrica: ");
    emOrdem(raiz);
    printf("\n");

    printf("Por nivel: ");
    porNivel(raiz);
    printf("\n");

    return 0;
}