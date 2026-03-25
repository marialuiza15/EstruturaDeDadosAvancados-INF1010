// Crie um programa que:
// Leia 10 números inteiros.
// Armazene-os em um vetor.
// Encontre e imprima:
// o maior número
// a posição onde ele aparece no vetor.

// Exemplo

// Entrada:
// 3 5 9 1 8 2 7 4 6 0

// Saída:
// Maior numero: 9
// Posicao: 2

#include <stdio.h>

void buscaMaiorNum(int* v, int tam){
    int maior = 0;
    int posMaior = 0;
    for(int i=0; i<tam; i++){
        int* pos = &v[0]+i*sizeof(int);
        if(*pos > maior){
            maior = *pos;
            posMaior = i+1;
        }
    }
    printf("O maior numero encontrado foi: %d na posição: %d", maior, posMaior);
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
    int v[10];
    montaVetor(v,sizeof(v)/4);
    buscaMaiorNum(v,sizeof(v)/4);
    
    return 0;
}