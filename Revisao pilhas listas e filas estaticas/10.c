/*Crie um programa que copie os dados de uma fila encadeada para uma
lista estática mantendo a ordem dos elementos*/



#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

//cogigos pra lista

typedef struct lista {
    int fim, qtd, max;
    int *valores;
}Lista;


Lista* criarLista(int max) {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->max = max;
    l->valores = (int*)malloc(max * sizeof(int));
    l->qtd = 0;
    l->fim = -1;
    return l;
}

bool VerificarListaEstaVazia(Lista *l) {
    return l->qtd == 0;
}
bool VerificarListaEsta(Lista *l) {
    return l->qtd == l->max;
}


bool inserirNaLista(Lista *l, int dado) {
    if (VerificarListaEsta(l))
        return false;

    l->fim++;
    l->valores[l->fim] = dado;
    l->qtd++;
    return true;
}

void imprimeListaSemRemover(Lista *l) {
    printf("\nElementos da lista:\n");
    for (int i = 0; i <= l->fim; i++) {
        printf("%d\n", l->valores[i]);
    }
}





//codigos pra fila

typedef struct no No;

struct no {
    int valor;
    No *prox;
};

typedef struct fila {
    No *inicio;
    No *fim;
    int tamanho;
}Fila;



Fila* criarFila() {
    Fila *f = malloc(sizeof(Fila));

    f->tamanho=0;
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

bool verificarFilaEstaVazia(Fila *f) {
    if(f->inicio == NULL && f->fim == NULL)
        return true;
    else
        return false;
}

bool inserirNaFila(Fila *f, int dado) {

    No *novoNo = (No*)malloc(sizeof(No));

    novoNo->valor = dado;
    novoNo->prox = NULL;

    if(verificarFilaEstaVazia(f))
        f->inicio = novoNo;
    else
        f->fim->prox = novoNo;

    f->fim = novoNo;
    f->tamanho++;
    return true;
}

int removerDaFila(Fila *f) {
    if(verificarFilaEstaVazia(f)) {
        printf("Fila Vazia\n");
        return -1; 
    }

    int valorAux = f->inicio->valor;

    No *noAux = f->inicio;
    f->inicio = f->inicio->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(noAux);
    f->tamanho--;
    return valorAux;
}

void imprimeFila(Fila *f){
    while(!verificarFilaEstaVazia(f)){
         printf("%d\n", removerDaFila(f));
    }
}



//funcao pra tirar os elementos da fila e colocar na lista
void filaLista(Lista *l, Fila *f){
     while (!verificarFilaEstaVazia(f)){
        inserirNaLista(l, removerDaFila(f));
    }
}





int main() {

    Fila *f = criarFila();

    inserirNaFila(f, 10);
    inserirNaFila(f, 20);
    inserirNaFila(f, 50);
    inserirNaFila(f, 80);
    inserirNaFila(f, 90);
    inserirNaFila(f, 200);
   

    Lista *l = criarLista(f->tamanho);


    filaLista(l, f);
    
    imprimeListaSemRemover(l);

    return 0;
}