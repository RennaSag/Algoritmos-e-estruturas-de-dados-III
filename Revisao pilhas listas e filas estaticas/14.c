/*Crie uma função que receba duas pilhas P1 e P2 e retorne se são iguais
ou não. Ao final da execução as pilhas P1 e P2 devem ter seus elementos
preservados na ordem original.*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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


bool verificarPilhas(Pilha *p1, Pilha *p2){
   Pilha *p12 = criarPilha();
   Pilha *p22 = criarPilha();
   bool op = true;


   while (!isEmpty(p1) && !isEmpty(p2) && op)
   {
    int np1 = pop(p1);
    int np2 = pop(p2);

    push(p12, np1);
    push(p22, np2);

    if(np1 != np2){
        op = false;
    }
   }

   if(!isEmpty(p1) || !isEmpty(p2)){
       op = false;
   }


   while (!isEmpty(p12))
   {
    push(p1, pop(p12));
   }

   while (!isEmpty(p22))
   {
    push(p2, pop(p22));
   }
   
    return op;
}




int main() {

    Pilha *p1 = criarPilha();
    Pilha *p2 = criarPilha();

    push(p1, 4);
    push(p1, 5);
    push(p1, 5);

    push(p2, 4);
    push(p2, 5);
    push(p2, 8);


    if(verificarPilhas(p1, p2)){
        printf("Pilhas iguais");
    }
    else{
        printf("Pilhas diferentes");
    }

    return 0;
}