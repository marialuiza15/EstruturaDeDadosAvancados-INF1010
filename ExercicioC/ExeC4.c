// Faça um programa que:
// Leia 20 números inteiros entre 0 e 9.
// Conte quantas vezes cada número aparece.
// Mostre a frequência de cada número.

// Exemplo

// Entrada:
// 1 2 3 2 1 0 5 5 5 5 3 2 1 4 6 7 8 9 0 1

// Saída:
// 0 aparece 2 vezes
// 1 aparece 4 vezes
// 2 aparece 3 vezes
// 3 aparece 2 vezes
// 4 aparece 1 vezes
// 5 aparece 4 vezes
// 6 aparece 1 vezes
// 7 aparece 1 vezes
// 8 aparece 1 vezes
// 9 aparece 1 vezes

#include <stdio.h>
#include <stdbool.h>

void verFreq(int* v, int tam){
    int n[5] = {0,1,2,3,4};
    int f[5] = {0,0,0,0,0};
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            int* pos = &v[0]+i*sizeof(int);
            if(*pos == n[j]){
                f[j] += 1;
                printf("%d", f[j]);
            }
        }
    }
    for (int i=0; i<5; i++){
        printf("%d aparece %d vezes\n",n[i],f[i]);
    }
}

void montaVetor(int* v, int tam){
    int num=0;
    for(int i=0; i<tam; i++){
        scanf("%d", &num);
        int* pos = &v[0]+i*sizeof(int);
        *pos = num;
    }
}

int main() {
    int v[5];
    montaVetor(v, 5);
    verFreq(v, 5);
    
    return 0;
}