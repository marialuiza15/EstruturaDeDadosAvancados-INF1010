#include <stdio.h>
#include <string.h>
 
int main() {
    int contador[27] = {0};      
    char letras[27] = {'\0'};    
    int totalLetras = 0; 

    char linha[256];
    FILE *arquivo = fopen("texto.txt", "r");
 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
 
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        for (int i = 0; i < strlen(linha); i++) {
            char c = linha[i];
 
            if (c == '\n' || c == '\r')
                continue;
 
            int encontrou = -1;
            for (int j = 0; j < totalLetras; j++) {
                if (letras[j] == c) {
                    encontrou = j;
                    break;
                }
            }
 
            if (encontrou != -1) {
                contador[encontrou]++;
            } else {
                letras[totalLetras] = c;
                contador[totalLetras] = 1;
                totalLetras++;
            }
        }
    }
 
    fclose(arquivo);
 
    printf("Letra | Frequencia\n");

    for (int i = 0; i < totalLetras; i++) {
        printf(" %c | %d\n", letras[i], contador[i]);
    }
 
    return 0;
}