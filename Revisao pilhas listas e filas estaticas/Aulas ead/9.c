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

int desenfileirar(FilaEncadeada *fila) {
    if (filaVazia(*fila)) {
        printf("Erro: Fila vazia.\n");
        return -1;
    }

    No *temp = fila->inicio;
    int valor = temp->valor;

    if (fila->inicio == fila->fim) {
        fila->inicio = fila->fim = NULL;
    } else {
        fila->inicio = fila->inicio->prox;
    }

    free(temp);
    return valor;
}

int removerUltimoElemento(FilaEncadeada *fila) {
    if (filaVazia(*fila)) {
        printf("Erro: Fila vazia.\n");
        return -1;
    }

    No *atual = fila->inicio;
    No *anterior = NULL;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    int valor = atual->valor;

    if (anterior == NULL) {
        fila->inicio = fila->fim = NULL;
    } else {
        anterior->prox = NULL;
        fila->fim = anterior;
    }

    free(atual);
    return valor;
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
    enfileirar(&fila, 4);

    printf("Fila antes da remocao:\n");
    exibirFila(fila);

    int valorRemovido = removerUltimoElemento(&fila);
    printf("Valor removido: %d\n", valorRemovido);

    printf("Fila depois da remocao:\n");
    exibirFila(fila);

    return 0;
}
