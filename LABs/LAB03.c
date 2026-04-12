#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int chave;
    int numnos;   /* número de nós da subárvore, incluindo a raiz */
    struct nodo *esq;
    struct nodo *dir;
} Nodo;

/* Cria um novo nó */
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

/* Insere um nó na árvore binária de busca */
Nodo *insere(Nodo *r, Nodo *novo) {
    if (r == NULL) {
        return novo;
    }

    if (novo->chave < r->chave) {
        r->esq = insere(r->esq, novo);
    } else {
        r->dir = insere(r->dir, novo);
    }

    return r;
}

/* Busca uma chave na árvore */
Nodo *busca(Nodo *r, int k) {
    while (r != NULL && r->chave != k) {
        if (k < r->chave) {
            r = r->esq;
        } else {
            r = r->dir;
        }
    }
    return r;
}

/* Calcula e preenche o campo numnos de cada nó */
int calculaNumNos(Nodo *r) {
    if (r == NULL) {
        return 0;
    }

    int qtdEsq = calculaNumNos(r->esq);
    int qtdDir = calculaNumNos(r->dir);

    r->numnos = 1 + qtdEsq + qtdDir;
    return r->numnos;
}

/* Percurso em pré-ordem: raiz, esquerda, direita */
void preOrdem(Nodo *r) {
    if (r != NULL) {
        printf("%d(%d) ", r->chave, r->numnos);
        preOrdem(r->esq);
        preOrdem(r->dir);
    }
}

/* Percurso em ordem simétrica: esquerda, raiz, direita */
void emOrdem(Nodo *r) {
    if (r != NULL) {
        emOrdem(r->esq);
        printf("%d(%d) ", r->chave, r->numnos);
        emOrdem(r->dir);
    }
}

/* Percurso por nível usando fila */
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

/* Libera a memória da árvore */
void liberaArvore(Nodo *r) {
    if (r != NULL) {
        liberaArvore(r->esq);
        liberaArvore(r->dir);
        free(r);
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

    /* Preenche o campo numnos em todos os nós */
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

    liberaArvore(raiz);

    return 0;
}