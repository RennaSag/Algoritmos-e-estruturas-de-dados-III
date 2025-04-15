/*Crie uma função que receba duas pilhas P1 e P2 e retorne uma nova pilha
contendo a interseção dos elementos entre P1 e P2, ou seja, os
elementos que estão presentes em ambas as pilhas*/



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


void verificarPilhas(Pilha *p1, Pilha *p2){
   Pilha *p3 = criarPilha();
   Pilha *p4 = criarPilha();
   int aux1, aux2 = 0; 

    while (!isEmpty(p1)){
        aux1 = pop(p1);
       
        while (!isEmpty(p2)){
            aux2 = pop(p2);
            if(aux1 == aux2){
                push(p3, aux1);
            }
            else{
                push(p4, aux2);
            }
        }
        

        while (!isEmpty(p4)){
            push(p2, pop(p4)); 
        }         
    }

    printf("Valores comuns:\n");
    while (!isEmpty(p3)) {
        printf("%d\n", pop(p3));
    }
}    




int main() {

    Pilha *p1 = criarPilha();
    Pilha *p2 = criarPilha();

    push(p1, 4);
    push(p1, 5);
    push(p1, 0);
    push(p1, 2);


    push(p2, 4);
    push(p2, 5);
    push(p2, 8);
    push(p2, 2);
    push(p2, 0);



     verificarPilhas(p1, p2);

    

    return 0;
}