// Implemente uma pilha genérica usando um vetor em C, onde o tipo de dados é especificado pelo usuário (usando void*). 
// A pilha deve ser capaz de armazenar diferentes tipos de dados (inteiros, floats, etc.) 
// e você deve implementar funções para alocar memória dinamicamente, sem limites fixos de tamanho para a pilha. 
// Além disso, implemente um mecanismo de verificação de estouro e de acesso seguro aos itens armazenados

//A TERMINAR

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *vetor;  // Pode apontar para qualquer tipo de dado
    int tamanho;
    int capacidade;
} Pilha;

void verificaAlocacaoVetor(Pilha *pilha){
    if(pilha->vetor==NULL){ // valida se a memoria foi alocada corretamente
        exit(1);
    }
}

void inicializaPilha(Pilha *pilha, int capacidadeInicial, char tipo){
    // como aqui temos um ponteiro para a estrutura da pilha, 
    // acessamos o seu conteudo usando pilha-> e não pilha.

    pilha->capacidade = capacidadeInicial; // inicia a capacidade da pilha como o valor recebido para capacidade inicial
    pilha->tamanho = 0; // o tamnho da pilha começa vazio, pois não há nada ainda na pilha

    if(tipo=='i'){
        pilha->vetor = (int*)malloc(pilha->capacidade * sizeof(int));
    }
    if(tipo=='f'){
        pilha->vetor = (float*)malloc(pilha->capacidade * sizeof(float));
    }
    if(tipo=='c'){
        pilha->vetor = (char*)malloc(pilha->capacidade * sizeof(char));
    }
    verificaAlocacaoVetor(pilha);
}

void empilhaInt(Pilha *pilha, int valor){
    if(pilha->tamanho==pilha->capacidade){
        
    }
}

int main(void) {
    Pilha pilha;

    char tipo;
    printf("Insira o tipo de dado para a pilha: ");
    scanf("%c", &tipo);

    inicializaPilha(&pilha, 5, tipo);
    

    for(int i=0; i < pilha.tamanho; i++){
        
        if(tipo=='i'){
            printf("%d\n", ((int*)pilha.vetor)[i]);  
        }
        if(tipo=='f'){
            printf("%f\n", ((float*)pilha.vetor)[i]); 
        }
        if(tipo=='c'){
            printf("%c\n", ((char*)pilha.vetor)[i]); 
        }
    }

    return 0;
}