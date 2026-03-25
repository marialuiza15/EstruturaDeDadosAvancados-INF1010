
// Escreva um programa em C que:
// Leia 5 números inteiros digitados pelo usuário.
// Armazene esses números em um vetor.
// Calcule e imprima:
// a soma dos números
// a média dos números.

// Exemplo

// Entrada:
// 2 4 6 8 10

// Saída:
// Soma: 30
// Media: 6

#include <stdio.h>

void multVetor(int* v, int tam){
    int mult=1;
    for(int i=0; i<tam; i++){
        int* aI = &v[0]+i*sizeof(int);
        mult *= *aI;
    }
    printf("Multiplicação dos 5 valores: %d",mult);
}

void somaVetor(int* v, int tam){
    int soma=0;
    for(int i=0; i<tam; i++){
        int* aI = &v[0]+i*sizeof(int);
        soma += *aI;
    }
    printf("Soma dos 5 valores: %d\n",soma);
}

void montaVetor(int* v, int tam){
    int val = 0;
    for( int i; i<tam; i++){
        printf("Digite o %d° número inteiro: ",i+1);
        scanf("%d", &val);
        int* aI = &v[0]+i*sizeof(int);
        *aI = val;
    }
}

int main() {
    int v[5];
    montaVetor(v, 5);
    somaVetor(v, 5);
    multVetor(v, 5);
    
    return 0;
}