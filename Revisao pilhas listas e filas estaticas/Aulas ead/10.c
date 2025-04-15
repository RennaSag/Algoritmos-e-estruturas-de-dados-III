#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} FilaEncadeada;

void inicializarFila(FilaEncadeada *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(FilaEncadeada fila) {
    return (fila.inicio == NULL && fila.fim == NULL);
}

void enfileirar(FilaEncadeada *fila, int valor) {
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;

    if (filaVazia(*fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

int contarValor(FilaEncadeada fila, int valor) {
    int contador = 0;
    No *atual = fila.inicio;

    while (atual != NULL) {
        if (atual->valor == valor) {
            contador++;
        }
        atual = atual->prox;
    }

    return contador;
}

void exibirFila(FilaEncadeada fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Conteudo da fila:\n");
    No *atual = fila.inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    FilaEncadeada fila;
    inicializarFila(&fila);

    enfileirar(&fila, 1);
    enfileirar(&fila, 2);
    enfileirar(&fila, 3);
    enfileirar(&fila, 2);
    enfileirar(&fila, 4);
    enfileirar(&fila, 2);

    printf("Fila:\n");
    exibirFila(fila);

    int valor = 2;
    int vezes = contarValor(fila, valor);
    printf("O valor %d aparece %d vezes na fila.\n", valor, vezes);

    return 0;
}
