#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *itens;
    int frente;
    int tras;
    int capacidade;
    int tamanho;
} FilaCircular;

void inicializaFila(FilaCircular *fila, int capacidade) {
    fila->itens = (int *)malloc(capacidade * sizeof(int));
    if (fila->itens == NULL) {
        printf("erro na alocacao de memoria\n");
        exit(1);
    }
    fila->frente = 0;
    fila->tras = -1;
    fila->capacidade = capacidade;
    fila->tamanho = 0;
}

int estaVazia(FilaCircular *fila) {
    return fila->tamanho == 0;
}

int estaCheia(FilaCircular *fila) {
    return fila->tamanho == fila->capacidade;
}

void enfileira(FilaCircular *fila, int valor) {
    if (!estaCheia(fila)) {
        fila->tras = (fila->tras + 1) % fila->capacidade;
        fila->itens[fila->tras] = valor;
        fila->tamanho++;
    } else {
        printf("fila cheia\n");
    }
}

int desenfileira(FilaCircular *fila) {
    if (!estaVazia(fila)) {
        int valor = fila->itens[fila->frente];
        fila->frente = (fila->frente + 1) % fila->capacidade;
        fila->tamanho--;
        return valor;
    } else {
        printf("fila vazia\n");
        return -1;
    }
}

void moverElementosParaOFinal(FilaCircular *fila, int N) {
    if (N <= 0) {
        printf("digite um impar.\n");
        return;
    }

    if (N > fila->tamanho) {
        N = fila->tamanho;
    }

    int *tempArray = (int *)malloc(N * sizeof(int));
    if (tempArray == NULL) {
        printf("erro na alocacao de memoria\n");
        return;
    }

    
    for (int i = 0; i < N; i++) {
        tempArray[i] = desenfileira(fila);
    }

    
    for (int i = 0; i < N; i++) {
        enfileira(fila, tempArray[i]);
    }

    free(tempArray);
}

void imprimeFila(FilaCircular *fila) {
    if (estaVazia(fila)) {
        printf("fila vazia\n");
        return;
    }

    printf("Fila: ");
    int i = fila->frente;
    int count = 0;
    while (count < fila->tamanho) {
        printf("%d ", fila->itens[i]);
        i = (i + 1) % fila->capacidade;
        count++;
    }
    printf("\n");
}

int main() {
    FilaCircular fila;
    int capacidade = 100;
    inicializaFila(&fila, capacidade);

   
    for (int i = 1; i <= 10; i++) {
        enfileira(&fila, i);
    }

    printf("Fila original: ");
    imprimeFila(&fila);

    int N = 4;
    moverElementosParaOFinal(&fila, N);

    printf("Fila com oos primeiros %d elementos no final: ", N);
    imprimeFila(&fila);

    return 0;
}
