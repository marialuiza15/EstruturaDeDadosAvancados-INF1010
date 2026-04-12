// Implemente uma pilha usando um vetor para armazenar inteiros. A pilha deve ter as operações push, pop e empty. 
// Crie um exemplo simples onde você empilha e desempilha alguns números.

#include <stdio.h>
#include <stdlib.h>

//1° criar uma estrutura para guardar as informações da pilha

typedef struct{
    int *vetor; //endereço inicial do vetor
    int tamanho; //tamanho da pilha atualmente
    int capacidade; // capacidade total do vetor (aumentaraá conforme a pilha cresce)
} Pilha;

void verificaAlocacaoVetor(Pilha *pilha){
    if(pilha->vetor==NULL){ // valida se a memoria foi alocada corretamente
        exit(1);
    }
}

void inicializaPilha(Pilha *pilha, int capacidadeInicial){
    // como aqui temos um ponteiro para a estrutura da pilha, 
    // acessamos o seu conteudo usando pilha-> e não pilha.

    pilha->capacidade = capacidadeInicial; // inicia a capacidade da pilha como o valor recebido para capacidade inicial
    pilha->tamanho = 0; // o tamnho da pilha começa vazio, pois não há nada ainda na pilha
    pilha->vetor = (int*)malloc(pilha->capacidade * sizeof(int)); //alocando memoria dinamicamente para o vetor da pilha

    verificaAlocacaoVetor(pilha);
}



void empilha(Pilha *pilha, int num){
    // recebe o ponteiro para a pilha e o numero que deve ser empilhado

    if (pilha->tamanho==pilha->capacidade){
        // se o tamanho da pilha for igual a capacidade, 
        // significa que ela esta cheia, entao precisamos 
        // aumentar o espaço disponivel na pilha antes de 
        // empilhar o novo numero

        pilha->capacidade += 2;
        pilha->vetor = (int*)realloc(pilha->vetor, pilha->capacidade * sizeof(int)); //redimenciona
        verificaAlocacaoVetor(pilha);
    }
    pilha->vetor[pilha->tamanho]=num;
    pilha->tamanho++;
}

void desempilha(Pilha *pilha){
    if(pilha->tamanho==0){// se pilha estiver vazia nao tem como desempilha
        exit(1);
    }
    pilha->tamanho--; //diminui tamanho ocupado da pilha
}

int main(void){
    Pilha pilha;
    inicializaPilha(&pilha, 1); // passo o endereço da pilha e a capacidade inicial é 1

    // como aqui na main temos a variavel direta para a pilha
    // acessamos ela usando pilha. , e não pilha->

    empilha(&pilha, 10);
    empilha(&pilha, 12);
    empilha(&pilha, 14);

    desempilha(&pilha);

    for(int i=0; i < pilha.tamanho; i++){
        printf("%d\n",pilha.vetor[i]);
    }

    return 0;
}