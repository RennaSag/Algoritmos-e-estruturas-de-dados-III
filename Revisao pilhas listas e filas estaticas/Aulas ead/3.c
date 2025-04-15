#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dado;
    struct Nodo *proximo;
} Nodo;

typedef struct {
    Nodo *topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = NULL;
}

int isEmpty(Pilha *p) {
    return p->topo == NULL;
}

int push(Pilha *p, int valor) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        return 0;
    }
    novo->dado = valor;
    novo->proximo = p->topo;
    p->topo = novo;
    return 1;
}

int pop(Pilha *p, int *valor) {
    if (isEmpty(p)) {
        return 0;
    }
    Nodo *temp = p->topo;
    *valor = temp->dado;
    p->topo = p->topo->proximo;
    free(temp);
    return 1;
}

void removePares(Pilha *p) {
    Pilha temp;
    inicializa(&temp);
    int valor;

    while (!isEmpty(p)) {
        pop(p, &valor);
        if (valor % 2 != 0) {
            push(&temp, valor);
        }
    }

    while (!isEmpty(&temp)) {
        pop(&temp, &valor);
        push(p, valor);
    }
}

void imprime(Pilha *p) {
    Nodo *atual = p->topo;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializa(&p);

    push(&p, 1);
    push(&p, 2);
    push(&p, 3);
    push(&p, 4);
    push(&p, 5);
    push(&p, 6);
    push(&p, 7);
    push(&p, 8);

    printf("Pilha: ");
    imprime(&p);

    removePares(&p);

    printf("Pilha sem pares: ");
    imprime(&p);

    return 0;
}
