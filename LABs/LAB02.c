#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    char valor;
    struct No *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
}Fila;

void inicializaFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

void validaAlocacao(No *novo){
    if (novo == NULL) {
        exit(1);
    }
}

void armazena(Fila *fila, char caracter){
    No *no = (No*)malloc(sizeof(No));
    validaAlocacao(no);

    no->valor = caracter;
    no->prox = NULL;

    if(fila->fim==NULL){
        fila->inicio = no;
        fila->fim=no;
    }
    else{
        fila->fim->prox = no;
        fila->fim = no;
    }
}

char retira(Fila *fila){
    if(fila->inicio==NULL){
        return ' ';
    }

    char valor = fila->inicio->valor;

    fila->inicio = fila->inicio->prox;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    return valor;
}

void imprimeFila(Fila *fila){

    No *atual = fila->inicio;

    printf("[");
    while(atual != NULL){
        printf("%c", atual->valor);
        if(atual->prox != NULL){
            printf(", ");
        }
        atual = atual->prox;
    }
    printf("]\n");
}

int main(){
    FILE *arq;
    Fila fila;
    char comando;
    char valor;

    inicializaFila(&fila);

    arq = fopen("lista.txt", "r");

    if(arq ==NULL){
        return 1;
    }

    while((comando = fgetc(arq)) != EOF){
        if(comando == 'a'){
            fscanf(arq, "%c", &valor);
            armazena(&fila, valor);
            imprimeFila(&fila);
        }
        else if(comando == 'r'){
            retira(&fila);
            imprimeFila(&fila);
        }
    }
}