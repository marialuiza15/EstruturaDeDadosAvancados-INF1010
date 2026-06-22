#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int chaves[4];        
    int numChaves;                  
    struct nodo *filhos[5];
} Nodo;

void intervalo(Nodo *arv, int lim_inf, int lim_sup) {
    if (arv == NULL)
        return;

    for (int i = 0; i < arv->numChaves; i++) {

        intervalo(arv->filhos[i], lim_inf, lim_sup);

        if (arv->chaves[i] > lim_inf &&
            arv->chaves[i] < lim_sup) {

            printf("%d ", arv->chaves[i]);
        }
    }

    intervalo(arv->filhos[arv->numChaves], lim_inf, lim_sup);
}

int main(void) {
    Nodo *folha1 = malloc(sizeof(Nodo));
    folha1->numChaves = 2;
    folha1->chaves[0] = 10;
    folha1->chaves[1] = 40;
    folha1->filhos[0] = NULL;
    folha1->filhos[1] = NULL;
    folha1->filhos[2] = NULL;

    Nodo *folha2 = malloc(sizeof(Nodo));
    folha2->numChaves = 2;
    folha2->chaves[0] = 60;
    folha2->chaves[1] = 70;
    folha2->filhos[0] = NULL;
    folha2->filhos[1] = NULL;
    folha2->filhos[2] = NULL;

    Nodo *folha3 = malloc(sizeof(Nodo));
    folha3->numChaves = 2;
    folha3->chaves[0] = 80;
    folha3->chaves[1] = 90;
    folha3->filhos[0] = NULL;
    folha3->filhos[1] = NULL;
    folha3->filhos[2] = NULL;

    Nodo *folha4 = malloc(sizeof(Nodo));
    folha4->numChaves = 2;
    folha4->chaves[0] = 110;
    folha4->chaves[1] = 115;
    folha4->filhos[0] = NULL;
    folha4->filhos[1] = NULL;
    folha4->filhos[2] = NULL;

    Nodo *folha5 = malloc(sizeof(Nodo));
    folha5->numChaves = 4;
    folha5->chaves[0] = 130;
    folha5->chaves[1] = 135;
    folha5->chaves[2] = 140;
    folha5->chaves[3] = 170;
    folha5->filhos[0] = NULL;
    folha5->filhos[1] = NULL;
    folha5->filhos[2] = NULL;
    folha5->filhos[3] = NULL;
    folha5->filhos[4] = NULL;

    Nodo *folha6 = malloc(sizeof(Nodo));
    folha6->numChaves = 4;
    folha6->chaves[0] = 220;
    folha6->chaves[1] = 230;
    folha6->chaves[2] = 240;
    folha6->chaves[3] = 250;
    folha6->filhos[0] = NULL;
    folha6->filhos[1] = NULL;
    folha6->filhos[2] = NULL;
    folha6->filhos[3] = NULL;
    folha6->filhos[4] = NULL;

    Nodo *folha7 = malloc(sizeof(Nodo));
    folha7->numChaves = 2;
    folha7->chaves[0] = 50;
    folha7->chaves[1] = 75;
    folha7->filhos[0] = folha1;
    folha7->filhos[1] = folha2;
    folha7->filhos[2] = folha3;

    Nodo *folha8 = malloc(sizeof(Nodo));
    folha8->numChaves = 2;
    folha8->chaves[0] = 120;
    folha8->chaves[1] = 200;
    folha8->filhos[0] = folha4;
    folha8->filhos[1] = folha5;
    folha8->filhos[2] = folha6;

    Nodo *raiz = malloc(sizeof(Nodo));
    raiz->numChaves = 1;
    raiz->chaves[0] = 100;
    raiz->filhos[0] = folha7;
    raiz->filhos[1] = folha8;

    printf("\nValores entre 5 e 300:");
    intervalo(raiz, 5, 300);
    printf("\n");

    printf("\nValores entre 50 e 100:");
    intervalo(raiz, 50, 100);
    printf("\n");

    printf("\nValores entre 70 e 135:");
    intervalo(raiz, 70, 135);
    printf("\n");

}

