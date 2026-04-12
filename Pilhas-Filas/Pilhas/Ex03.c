// Implemente uma pilha utilizando uma lista encadeada simples. 
// A pilha deve suportar operações básicas como push, pop e top, 
// sendo os itens armazenados em nós da lista. Crie um exemplo 
// simples para testar a inserção e remoção de elementos.

#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista encadeada
typedef struct No {
    int valor;          // O valor armazenado no nó
    struct No *prox;   // Ponteiro para o próximo nó (próximo item na pilha)
} No;

// Função para inicializar a pilha (inicialmente vazia)
void inicializaPilha(No **topo) {
    *topo = NULL;  // Pilha vazia significa que o topo é NULL
}

// Função para verificar se a pilha está vazia
int pilhaVazia(No *topo) {
    return topo == NULL;  // Se o topo for NULL, a pilha está vazia
}

// Função para empilhar um novo valor na pilha
void push(No **topo, int valor) {
    // Aloca um novo nó
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {  // Verifica se a alocação falhou
        printf("Erro ao alocar memória.\n");
        exit(1);  // Sai do programa em caso de erro na alocação
    }
    
    novoNo->valor = valor;  // Atribui o valor ao nó
    novoNo->prox = *topo;   // O próximo nó será o atual topo da pilha
    *topo = novoNo;         // O topo agora é o novo nó
}

// Função para desempilhar (remover o valor do topo da pilha)
int pop(No **topo) {
    if (pilhaVazia(*topo)) {  // Verifica se a pilha está vazia
        printf("Pilha vazia! Não é possível desempilhar.\n");
        return -1;  // Retorna um valor de erro
    }

    No *removerNo = *topo;     // O nó a ser removido é o topo
    int valor = removerNo->valor;  // Salva o valor que será retornado

    *topo = removerNo->prox;   // O novo topo será o próximo nó
    free(removerNo);           // Libera a memória do nó removido

    return valor;  // Retorna o valor desempilhado
}

// Função para ver o valor no topo da pilha (sem remover)
int top(No *topo) {
    if (pilhaVazia(topo)) {  // Verifica se a pilha está vazia
        printf("Pilha vazia! Não é possível ver o topo.\n");
        return -1;  // Retorna um valor de erro
    }
    
    return topo->valor;  // Retorna o valor no topo
}

// Função para liberar toda a memória alocada pela pilha
void liberarPilha(No *topo) {
    No *atual = topo;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;  // Avança para o próximo nó
        free(temp);  // Libera a memória do nó atual
    }
}

int main(void) {
    No *topo;  // Ponteiro para o topo da pilha
    inicializaPilha(&topo);  // Inicializa a pilha

    // Testando a inserção de elementos
    printf("Empilhando 10\n");
    push(&topo, 10);  // Empilha 10
    printf("Topo: %d\n", top(topo));  // Exibe o topo da pilha

    printf("Empilhando 20\n");
    push(&topo, 20);  // Empilha 20
    printf("Topo: %d\n", top(topo));  // Exibe o topo da pilha

    printf("Empilhando 30\n");
    push(&topo, 30);  // Empilha 30
    printf("Topo: %d\n", top(topo));  // Exibe o topo da pilha

    // Testando a remoção de elementos
    printf("Desempilhando\n");
    int valor = pop(&topo);  // Desempilha o valor
    printf("Valor desempilhado: %d\n", valor);
    printf("Novo topo: %d\n", top(topo));  // Exibe o novo topo após desempilhar

    printf("Desempilhando\n");
    valor = pop(&topo);  // Desempilha o valor
    printf("Valor desempilhado: %d\n", valor);
    printf("Novo topo: %d\n", top(topo));  // Exibe o novo topo após desempilhar

    printf("Desempilhando\n");
    valor = pop(&topo);  // Desempilha o valor
    printf("Valor desempilhado: %d\n", valor);
    
    // Tentando desempilhar de uma pilha vazia
    valor = pop(&topo);  // Tenta desempilhar, mas a pilha está vazia

    // Liberando a memória alocada
    liberarPilha(topo);
    
    return 0;
}