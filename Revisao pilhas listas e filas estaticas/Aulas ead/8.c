#include <stdio.h>
#include <stdlib.h>

int MAX = 100;

typedef struct {
    int *itens;
    int frente;
    int tras;
} FilaCircular;

void inicializaFila(FilaCircular *fila) {
    fila->frente = -1;
    fila->tras = -1;
    fila->itens = (int*) malloc(MAX * sizeof(int));
}

int filaVazia(FilaCircular fila) {
    return (fila.frente == -1 && fila.tras == -1);
}

int filaCheia(FilaCircular fila) {
    return ((fila.tras + 1) % MAX == fila.frente);
}

void enfileirar(FilaCircular *fila, int valor) {
    if (filaCheia(*fila)) {
        printf("Erro: Fila cheia.\n");
        return;
    }
    
    if (filaVazia(*fila))
        fila->frente = fila->tras = 0;
    else
        fila->tras = (fila->tras + 1) % MAX;
    
    fila->itens[fila->tras] = valor;
}

int desenfileirar(FilaCircular *fila) {
    int valor;
    if (filaVazia(*fila)) {
        printf("Erro: Fila vazia.\n");
        return -1;
    }
    
    valor = fila->itens[fila->frente];
    
    if (fila->frente == fila->tras)
        fila->frente = fila->tras = -1;
    else
        fila->frente = (fila->frente + 1) % MAX;
    
    return valor;
}

FilaCircular concatenarFilas(FilaCircular fila1, FilaCircular fila2) {
    FilaCircular filaConcatenada;
    inicializaFila(&filaConcatenada);
    
    while (!filaVazia(fila1))
        enfileirar(&filaConcatenada, desenfileirar(&fila1));
    
    while (!filaVazia(fila2))
        enfileirar(&filaConcatenada, desenfileirar(&fila2));
    
    return filaConcatenada;
}

void exibirFila(FilaCircular fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    
    printf("Conteudo da fila:\n");
    int i = fila.frente;
    do {
        printf("%d ", fila.itens[i]);
        i = (i + 1) % MAX;
    } while (i != (fila.tras + 1) % MAX);
    printf("\n");
}

int main() {
    FilaCircular fila1, fila2, filaConcatenada;
    inicializaFila(&fila1);
    inicializaFila(&fila2);
    
    enfileirar(&fila1, 1);
    enfileirar(&fila1, 2);
    enfileirar(&fila1, 3);
    
    enfileirar(&fila2, 4);
    enfileirar(&fila2, 5);
    enfileirar(&fila2, 6);
    
    printf("Fila 1:\n");
    exibirFila(fila1);
    
    printf("Fila 2:\n");
    exibirFila(fila2);
    
    filaConcatenada = concatenarFilas(fila1, fila2);
    
    printf("Fila concatenada:\n");
    exibirFila(filaConcatenada);
    
    free(fila1.itens);
    free(fila2.itens);
    free(filaConcatenada.itens);
    
    return 0;
}
