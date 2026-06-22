#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ── BitVector (do slide) ── */
typedef struct _bitvector {
    int max;
    int *vector;
} BitVector;

BitVector* bvInit(int max) {
    int size = sizeof(int);
    int num = ((max - 1) / size) + 1;
    BitVector* bv = (BitVector*)malloc(sizeof(BitVector));
    bv->max = max;
    bv->vector = (int*)calloc(num, sizeof(int));
    return bv;
}

int bvGet(BitVector* bv, int i) {
    return ((bv->vector[i / sizeof(int)]) & (1 << i % sizeof(int))) != 0;
}

void bvSet(BitVector* bv, int i) {
    bv->vector[i / sizeof(int)] |= 1 << i % sizeof(int);
}

BitVector* bvIntrsec(BitVector* a, BitVector* b) {
    int minab = (a->max < b->max) ? a->max : b->max;
    int num = (minab - 1) / sizeof(int) + 1;
    BitVector* bv = (BitVector*)malloc(sizeof(BitVector));
    bv->max = minab;
    bv->vector = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
        bv->vector[i] = a->vector[i] & b->vector[i];
    return bv;
}

void bvShow(BitVector* bv, char* title) {
    printf("%s (max=%d): [ ", title, bv->max);
    for (int i = 0; i < bv->max; i++)
        if (bvGet(bv, i)) printf("%d ", i);
    printf("]\n");
}

void bvFree(BitVector* bv) { free(bv->vector); free(bv); }

/* ── Exercício 1: complemento de BitVector ── */
BitVector* bvCompl(BitVector* a) {
    int num = ((a->max - 1) / sizeof(int)) + 1;
    BitVector* bv = (BitVector*)malloc(sizeof(BitVector));
    bv->max = a->max;
    bv->vector = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
        bv->vector[i] = ~a->vector[i];
    return bv;
}

/* ── Exercício 2: A contém B (Set com unsigned char) ── */
typedef struct {
    int n;              /* número de bytes */
    unsigned char* v;   /* vetor */
} Set;

Set* setCreate(int n) {
    Set* s = (Set*)malloc(sizeof(Set));
    s->n = n;
    s->v = (unsigned char*)calloc(n, 1);
    return s;
}

void setInsert(Set* s, int elem) {
    s->v[elem / 8] |= (1 << (elem % 8));
}

void setShow(Set* s, char* title) {
    printf("%s (n=%d bytes): [ ", title, s->n);
    for (int i = 0; i < s->n; i++)
        for (int b = 0; b < 8; b++)
            if (s->v[i] & (1 << b)) printf("%d ", i * 8 + b);
    printf("]\n");
}

void setFree(Set* s) { free(s->v); free(s); }

/*
 * A contem B  <=>  (A & B) == B
 * Se B tem mais bytes que A, os bytes extras de B devem ser 0.
 */
int contem(Set* A, Set* B) {
    int m = A->n, n = B->n;
    int lim = (n < m) ? n : m;

    for (int i = 0; i < lim; i++)
        if ((A->v[i] & B->v[i]) != B->v[i]) return 0;

    for (int i = m; i < n; i++)
        if (B->v[i] != 0) return 0;

    return 1;
}

/* ── main ── */
int main(void) {
    printf("=== Exercício 1: bvCompl ===\n");

    BitVector* a = bvInit(8);
    bvSet(a, 0); bvSet(a, 2); bvSet(a, 3); bvSet(a, 5);
    bvShow(a, "A");

    BitVector* ca = bvCompl(a);
    bvShow(ca, "~A");

    BitVector* inter = bvIntrsec(a, ca);
    bvShow(inter, "A & ~A");

    bvFree(a); bvFree(ca); bvFree(inter);

    printf("\n=== Exercício 2: contem ===\n");

    Set* A = setCreate(2);
    setInsert(A, 0); setInsert(A, 2); setInsert(A, 3);
    setInsert(A, 7); setInsert(A, 10);

    Set* B = setCreate(2);
    setInsert(B, 2); setInsert(B, 3);

    Set* C = setCreate(2);
    setInsert(C, 2); setInsert(C, 5);  /* 5 não está em A */

    setShow(A, "A");
    setShow(B, "B (subconjunto de A)");
    setShow(C, "C (tem elem 5, fora de A)");

    printf("contem(A,B) = %d  (esperado: 1)\n", contem(A, B));
    printf("contem(A,C) = %d  (esperado: 0)\n", contem(A, C));
    printf("contem(B,A) = %d  (esperado: 0)\n", contem(B, A));

    /* B menor que A em bytes */
    Set* D = setCreate(1);
    setInsert(D, 2); setInsert(D, 3);
    setShow(D, "D (1 byte, subconjunto de A)");
    printf("contem(A,D) = %d  (esperado: 1)\n", contem(A, D));

    /* B com bytes extras não-zero */
    Set* E = setCreate(3);
    setInsert(E, 2); setInsert(E, 16);  /* 16 fora do alcance de A */
    setShow(E, "E (3 bytes, tem elem 16)");
    printf("contem(A,E) = %d  (esperado: 0)\n", contem(A, E));

    setFree(A); setFree(B); setFree(C); setFree(D); setFree(E);
    return 0;
}
