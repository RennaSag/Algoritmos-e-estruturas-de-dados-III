/*Crie uma função recursiva para verificar se uma pilha encadeada possui
valores ímpares*/

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
        return 0;
    }

    int valor = p->topo->valor;

    No *noAux = p->topo;

    p->topo = p->topo->prox;
    free(noAux);

    return valor;
}


int impares(Pilha *p){
    if(isEmpty(p)){
        return 0;
    }
    int n = pop(p);
    if(n % 2 != 0){
        printf("Valor %d eh impar", n); 
        return 0;
    }
    return impares(p);
}






int main() {

    Pilha *p = criarPilha();

    push(p, 4);
    push(p, 2);
    pop(p);
    push(p, 4);
    push(p, 1);
    push(p, 2);


    impares(p);
    

    

   

    return 0;
}