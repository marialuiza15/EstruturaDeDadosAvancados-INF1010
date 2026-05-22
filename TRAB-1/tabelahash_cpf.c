/*
INF1010 - Estruturas de Dados Avançadas
Maria Luiza Lima Bastos - 2320468
Para compilar: gcc -O2 -o tabelahash_cpf tabelahash_cpf.c -lm
Para rodar: ./tabelahash_cpf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 4919 
#define N2 4903  
#define MAX_CHAVES 4096

#define CSV_SAIDA "colisoes.csv"

unsigned long long tabela[N];

const int pesos[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, };

int h1(unsigned long long cpf) {
    // double A = 0.6180339887;
    // double frac = (double)cpf*A;
    // frac = frac - floor(frac);
    // return (unsigned int)(N*frac);
    unsigned long long h = 0;
    for (int i=0; i<11; i++){
        h = h*31ULL + cpf;
    }

    h^=(h>>21);
    h*=2654435761ULL;
    h^=(h>>16);

    return (unsigned int)(h%N);

}
// tenbtar fazer por tentativa
int h2(unsigned long long cpf) {
    return (unsigned int)(N2-(cpf%N2));
}

int inseridaserir(unsigned long long cpf) {
    int idx   = h1(cpf);
    int passo = h2(cpf);
    int col   = 0;

    for (int k = 0; k < N; k++) {
        if (tabela[idx] == 0 || tabela[idx] == 1) {
            tabela[idx] = cpf;
            return col;
        }
        if (tabela[idx] == cpf) return col;
        col++;
        idx = (idx + passo) % N;
    }
    return col;
}

int main(void) {
    FILE *fp = fopen("CPFsValidos.txt", "r");
    if (!fp) { perror("Erro ao abrir CPFsValidos.txt"); return 1; }
 
    memset(tabela, 0, sizeof(tabela));
 
    unsigned long long  cpfs[MAX_CHAVES];
    int  total_lidos = 0;
    char linha[32];
 
    while (total_lidos < MAX_CHAVES && fgets(linha, sizeof(linha), fp)) {
        char digits[12] = {0};
        int  d = 0;
        for (int i = 0; linha[i] && d < 11; i++) {
            if (linha[i] >= '0' && linha[i] <= '9')
                digits[d++] = linha[i];
        }
        if (d < 11) continue;
        cpfs[total_lidos++] = (unsigned long long)atoll(digits);
    }
    fclose(fp);
 
    FILE *csv = fopen(CSV_SAIDA, "w");
    if (!csv) { perror("Erro ao criar " CSV_SAIDA); return 1; }
 
    fprintf(csv, "chaves,colisoes,fator_de_carga\n");
 
    printf("CPFs lidos: %d\n", total_lidos);
    printf("Tamanho da tabela: %d\n", N);
    printf("Fator de carga maximo: %.4f\n\n", (double)total_lidos / N);
 
    printf("%-10s  %-20s  %-12s\n","Chaves", "Colisões", "Fator de Carga");

    // metodo do quadrado e garanir que a qtd de colisoues nao ultrapasse log n

    int checkpoint = 100;
    int colisoes_bloco = 0; 
    int total_colisoes = 0; 
 
    for (int i = 0; i < total_lidos; i++) {
        int c = inseridaserir(cpfs[i]);
        colisoes_bloco += c;
        total_colisoes += c;
 
        int inseridas  = i + 1;
        double fator_carga = (double)inseridas / N;
 
        if (inseridas == checkpoint || inseridas == total_lidos) {
            fprintf(csv, "%d,%d,%.6f\n", inseridas, colisoes_bloco, fator_carga);
 
            printf("%-10d  %-20d  %-12.4f\n",inseridas, colisoes_bloco, fator_carga);
 
            colisoes_bloco = 0;  
            checkpoint    += 100;
        }
    }
 
    fclose(csv);
    printf("\nResumo final\n");
    printf("Colisoes totais: %d\n",   total_colisoes);
    printf("Media col/chaves: %.4f\n", (double)total_colisoes / total_lidos);
    printf("\nArquivo gerado: %s\n", CSV_SAIDA);
 
    return 0;
}
 