#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int itens[100];
    int frente;
    int tras;
    int capacidade;
    int tamanho;
} Fila;

void inicializaFila(Fila *f, int capacidade) {
    f->capacidade = capacidade;
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

int isEmpty(Fila *f) {
    return f->tamanho == 0;
}

int isFull(Fila *f) {
    return f->tamanho == f->capacidade;
}

int enfileira(Fila *f, int valor) {
    if (isFull(f)) {
        return 0;
    }
    f->tras = (f->tras + 1) % f->capacidade;
    f->itens[f->tras] = valor;
    f->tamanho++;
    return 1;
}

int desenfileira(Fila *f, int *valor) {
    if (isEmpty(f)) {
        return 0;
    }
    *valor = f->itens[f->frente];
    f->frente = (f->frente + 1) % f->capacidade;
    f->tamanho--;
    return 1;
}

Fila filtraImpares(Fila *f) {
    Fila novaFila;
    inicializaFila(&novaFila, f->capacidade);
    int valor;

    for (int i = 0; i < f->tamanho; i++) {
        valor = f->itens[(f->frente + i) % f->capacidade];
        if (valor % 2 != 0) {
            enfileira(&novaFila, valor);
        }
    }

    return novaFila;
}

void imprimeFila(Fila *f) {
    for (int i = 0; i < f->tamanho; i++) {
        int indice = (f->frente + i) % f->capacidade;
        printf("%d ", f->itens[indice]);
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializaFila(&f, 100);

    enfileira(&f, 1);
    enfileira(&f, 2);
    enfileira(&f, 3);
    enfileira(&f, 4);
    enfileira(&f, 5);
    enfileira(&f, 6);
    enfileira(&f, 7);
    enfileira(&f, 8);
    enfileira(&f, 9);

    printf("Fila original: ");
    imprimeFila(&f);

    Fila novaFila = filtraImpares(&f);

    printf("Impars: ");
    imprimeFila(&novaFila);

    return 0;
}
