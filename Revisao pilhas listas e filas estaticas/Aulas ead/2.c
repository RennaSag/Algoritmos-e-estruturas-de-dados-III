#include <stdio.h>

typedef struct {
    int topo;
    int itens[100];
    int capacidade;
} Pilha;

void inicializa(Pilha *p, int capacidade) {
    p->topo = -1;
    p->capacidade = capacidade;
}

int isEmpty(Pilha *p) {
    return p->topo == -1;
}

int isFull(Pilha *p) {
    return p->topo == p->capacidade - 1;
}

int push(Pilha *p, int valor) {
    if (isFull(p)) {
        return 0;
    }
    p->itens[++(p->topo)] = valor;
    return 1;
}

int pop(Pilha *p, int *valor) {
    if (isEmpty(p)) {
        return 0;
    }
    *valor = p->itens[(p->topo)--];
    return 1;
}

int estaEmOrdemCrescente(Pilha *p) {
    if (p->topo < 1) {
        return 1;
    }
    
    for (int i = 0; i < p->topo; i++) {
        if (p->itens[i] > p->itens[i + 1]) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    Pilha p;
    inicializa(&p, 100); 

    push(&p, 1);
    push(&p, 2);
    push(&p, 3);
    push(&p, 4);
    push(&p, 5);

    int ordem = estaEmOrdemCrescente(&p);
    if (ordem) {
        printf("Os elementos estao em ordem crescente.\n");
    } else {
        printf("Os elementos n estao em ordem crescente.\n");
    }

    return 0;
}
