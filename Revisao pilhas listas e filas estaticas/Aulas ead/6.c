#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int itens[100];
    int frente;
    int tras;
    int capacidade;
    int tamanho;
} Fila;

typedef struct {
    int itens[100];
    int topo;
} Pilha;

void inicializaFila(Fila *f, int capacidade) {
    f->capacidade = capacidade;
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

int isEmptyFila(Fila *f) {
    return f->tamanho == 0;
}

int isFullFila(Fila *f) {
    return f->tamanho == f->capacidade;
}

int enfileira(Fila *f, int valor) {
    if (isFullFila(f)) {
        return 0;
    }
    f->tras = (f->tras + 1) % f->capacidade;
    f->itens[f->tras] = valor;
    f->tamanho++;
    return 1;
}

int desenfileira(Fila *f, int *valor) {
    if (isEmptyFila(f)) {
        return 0;
    }
    *valor = f->itens[f->frente];
    f->frente = (f->frente + 1) % f->capacidade;
    f->tamanho--;
    return 1;
}

void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

int isEmptyPilha(Pilha *p) {
    return p->topo == -1;
}

int isFullPilha(Pilha *p) {
    return p->topo == 99;
}

int push(Pilha *p, int valor) {
    if (isFullPilha(p)) {
        return 0;
    }
    p->itens[++(p->topo)] = valor;
    return 1;
}

int pop(Pilha *p, int *valor) {
    if (isEmptyPilha(p)) {
        return 0;
    }
    *valor = p->itens[(p->topo)--];
    return 1;
}

void inverteFila(Fila *f) {
    Pilha p;
    inicializaPilha(&p);
    int valor;

  
    while (!isEmptyFila(f)) {
        desenfileira(f, &valor);
        push(&p, valor);
    }

    
    while (!isEmptyPilha(&p)) {
        pop(&p, &valor);
        enfileira(f, valor);
    }
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

    printf("Fila original: ");
    imprimeFila(&f);

    inverteFila(&f);

    printf("Fila invertida: ");
    imprimeFila(&f);

    return 0;
}
