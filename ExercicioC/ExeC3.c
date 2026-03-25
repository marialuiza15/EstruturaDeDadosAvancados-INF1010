// Implemente um programa que:
// Leia N números inteiros (onde N é informado pelo usuário).
// Armazene em um vetor.
// Ordene os números usando Bubble Sort.
// Imprima o vetor ordenado.

// Exemplo

// Entrada:
// N = 5
// 8 3 1 9 4

// Saída:
// 1 3 4 8 9

#include <stdio.h>
#include <stdbool.h>

void ordenaVetor(int* v, int tam){
    bool swap;
    for(int i=0; i<tam; i++){
        swap = false;
        for(int j=0; j<tam-1; j++){
            int* posAtual = &v[0]+j*sizeof(int);
            int* posSeguinte = &v[0]+(j+1)*sizeof(int);
            printf("v[i]= %d v[i+1]= %d\n\n", *posAtual,*posSeguinte);
            if(*posAtual>*posSeguinte){
                int aux = *posAtual;
                *posAtual = *posSeguinte;
                *posSeguinte = aux;
                swap = true;
            }
        }
        if(!swap){
            break;
        }
    }
}

void montaVetor(int* v, int tam){
    int num=0;
    for( int i=0; i<tam; i++){
        printf("digite: ");
        scanf("%d", &num);
        int* pos = &v[0]+i*sizeof(int);
        *pos = num;
    }
}

int main() {
    int n = 0;
    int num = 0;
    printf("Quantos numeros deseja adicionar? ");
    scanf("%d", &n);
    int v[n];
    montaVetor(v,n);
    ordenaVetor(v,n);
    for (int i=0; i<n; i++){
        printf("DEPOIS de ordenar: %d\n",*(&v[0]+i*sizeof(int)));
    }
    return 0;
}