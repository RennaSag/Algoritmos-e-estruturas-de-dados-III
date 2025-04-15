/*Crie um programa que copie os dados de uma pilha encadeada para uma
lista estática mantendo a ordem dos elementos.*/

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>





//Codigos pra pilha
typedef struct no No;

struct no {
    int valor;
    No *prox;
};

typedef struct pilha {
    No *topo;
    int tamanho;
}Pilha;


Pilha* criarPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;

    p->tamanho=0;
    return p;
}

int isEmpty(Pilha *p) {
    return p->topo == NULL;
}

//adicionar
void push(Pilha *p, int valor) {
    No *novoNo = (No*)malloc(sizeof(No));

    novoNo->valor = valor;

    novoNo->prox = p->topo;
    p->tamanho++;
    p->topo = novoNo;
}

//remover
int pop(Pilha *p) {

    if(isEmpty(p)) {
        printf("Pilha Vazia\n");
        return 0;
    }

    int valor = p->topo->valor;

    No *noAux = p->topo;

    p->topo = p->topo->prox;
    free(noAux);
    p->tamanho--;
    return valor;
}






//codigos pra lista
typedef struct fila {
    int inicio, fim, max;
    int *dados;
} Fila;

Fila* criarFila(int max) {
    Fila *f = malloc(sizeof(Fila));

    f->inicio = 0;
    f->fim = -1;
    f->max = max;
    f->dados = malloc(max * sizeof(int));

    return f;
}

bool verificarFilaEstaVazia(Fila *f) {
    if(f->fim < f->inicio)
        return true;
    else
        return false;
}

bool verificarFilaEstaCheia(Fila *f) {
    if(f->fim == f->max - 1){
        return true;
    }else{
        return false;
    }
}

bool inserirNaFila(Fila *f, int dado) {
    if(verificarFilaEstaCheia(f))
        return false;

    f->fim = f->fim+1;
    f->dados[f->fim] = dado;

    return true;
}

int removerDaFila(Fila *f){
    if(verificarFilaEstaVazia(f) == false){
        int aux = f->dados[f->inicio];
        f->inicio = f->inicio + 1;
        return aux;
    }
}

void imprimeFila(Fila *f){
    while(!verificarFilaEstaVazia(f)){
         printf("%d\n", removerDaFila(f));
    }
}


void inverterPilhas(Pilha *p1, Pilha *p2){
    while (!isEmpty(p1)){
        push(p2, pop(p1));
    }
    
    
}


void inserirPilhaFila(Fila *f, Pilha *p1, Pilha *p2){
    inverterPilhas(p1, p2);
    while (!isEmpty(p2)){
        inserirNaFila(f, pop(p2));
    }
}








int main() {

    Pilha *p1 = criarPilha();
    Pilha *p2 = criarPilha();
    


    push(p1, 4);
    push(p1, 5);
    push(p1, 10);
    push(p1, 8);

    Fila *f = criarFila(p1->tamanho);

    inserirPilhaFila(f, p1, p2);
    imprimeFila(f);


    
    return 0;
}