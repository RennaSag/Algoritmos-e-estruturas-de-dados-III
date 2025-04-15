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

int segundoMaiorValor(Pilha *p) {
    if (p->topo < 1) {
        return -1; 
    }

    int maior = p->itens[0];
    int segundoMaior = -1;

    for (int i = 1; i <= p->topo; i++) {
        int atual = p->itens[i];
        if (atual > maior) {
            segundoMaior = maior;
            maior = atual;
        } else if (atual > segundoMaior && atual < maior) {
            segundoMaior = atual;
        } else if (segundoMaior == -1 && atual < maior) {
            segundoMaior = atual;
        }
    }

    return segundoMaior;
}

int main() {
    Pilha p;
    inicializa(&p, 100); 

    push(&p, 3);
    push(&p, 1);
    push(&p, 4);
    push(&p, 1);
    push(&p, 5);
    push(&p, 9);
    push(&p, 2);
    push(&p, 6);
    push(&p, 5);

    int segundoMaior = segundoMaiorValor(&p);
    if (segundoMaior == -1) {
        printf("Nao ha elementos suficientes na pilha.\n");
    } else {
        printf("O segundo maior valor na pilha eh: %d\n", segundoMaior);
    }

    return 0;
}
