/*.Escreva uma função que armazene n valores da sequência Fibonnaci em
uma pilha.*/


#include<stdio.h>
#include<stdlib.h>

typedef struct no No;

struct no {
    int valor;
    No *prox;
};

typedef struct pilha {
    No *topo;
}Pilha;


Pilha* criarPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;

    return p;
}

int isEmpty(Pilha *p) {
    return p->topo == NULL;
}

void push(Pilha *p, int valor) {
    No *novoNo = (No*)malloc(sizeof(No));

    novoNo->valor = valor;

    novoNo->prox = p->topo;

    p->topo = novoNo;
}

int pop(Pilha *p) {

    if(isEmpty(p)) {
        printf("Pilha Vazia\n");
        return NULL;
    }

    int valor = p->topo->valor;

    No *noAux = p->topo;

    p->topo = p->topo->prox;
    free(noAux);

    return valor;
}

void piFib(Pilha *p, int n){
    for(int i = 0; i < n; i++){
        if((i % 2 != 0) && (i % 3 != 0) && (i % 5 != 0) && (i % 7 != 0)){
            push(p, i);
        }
        if(i == 2 || i == 3 || i == 5 || i == 7){
            push(p, i);
        }
    }
}

int main() {

    Pilha *p = criarPilha();

    int n;
    printf("Digite o valor n: ");
    scanf("%d", &n);

    piFib(p, n);

//1, 2,3,5,7,9,11,13,17,19,23,
    while(!isEmpty(p)) {
        printf("Valor: %d\n", pop(p));
    }


    return 0;
}