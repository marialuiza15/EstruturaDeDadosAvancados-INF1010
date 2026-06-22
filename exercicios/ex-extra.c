#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// usado em ex 1
typedef struct _bitvector {
    int max;
    int *vector;
} BitVector;

// usado em ex 2
struct set {
    int n;            
    unsigned char* v;  
};
typedef struct set Set;

// dos slides
BitVector* bvInit(int max) {
    int i, size = sizeof(int);
    int num = ((max - 1) / size) + 1;
    BitVector* bv = (BitVector*)malloc(sizeof(BitVector));
    bv->max = max;
    bv->vector = (int*)malloc(num * sizeof(int));
    for (i = 0; i < num; i++)
        bv->vector[i] = 0;
    return bv;
}

// exercicio 1
BitVector* bvCompl(BitVector* a) {
    int i;
    int size = sizeof(int);
    int num = ((a->max - 1) / size) + 1;

    BitVector* bv = (BitVector*)malloc(sizeof(BitVector));
    bv->max = a->max;
    bv->vector = (int*)malloc(num * sizeof(int));

    for (i = 0; i < num; i++)
        bv->vector[i] = ~(a->vector[i]);

    return bv;
}

// exercicio 2
int contem(Set* A, Set* B) {
    int i;
    int m = A->n; 
    int n = B->n; 

    for (i = 0; i < n; i++) {
        unsigned char a_byte = (i < m) ? A->v[i] : 0;
        unsigned char b_byte = B->v[i];

        if ((a_byte & b_byte) != b_byte)
            return 0;
    }
    return 1;
}

// testes
int main(void) {
    // exercicio 1
    BitVector* a = bvInit(8);
    a->vector[0] = 0x2D;

    BitVector* comp = bvCompl(a);
    printf("A        = 0x%02X (esperado: 0x2D)\n", a->vector[0] & 0xFF);
    printf("~A       = 0x%02X (esperado: 0xD2)\n", comp->vector[0] & 0xFF);

    // exercicio 2
    Set A;
    A.n = 1;
    A.v = (unsigned char*)malloc(1);
    A.v[0] = 0x1F;

    Set B;
    B.n = 1;
    B.v = (unsigned char*)malloc(1);
    B.v[0] = 0x0D;

    Set C;
    C.n = 1;
    C.v = (unsigned char*)malloc(1);
    C.v[0] = 0x21;

    printf("\nA contem B? %d", contem(&A, &B));
    printf("\nA contem C? %d", contem(&A, &C));

    Set D;
    D.n = 2;
    D.v = (unsigned char*)malloc(2);
    D.v[0] = 0x0D;
    D.v[1] = 0x01; 

    printf("\nA contem D? %d", contem(&A, &D));

    return 0;
}