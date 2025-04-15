/*Crie uma função que insira em uma lista estática todos os valores
armazenados de uma fila encadeada*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct no No;

struct no {
    int valor;
    No *prox;
};

//fila encadeada
typedef struct fila {
    No *inicio;
    int n;
    No *fim;
}FilaEncadeada;

//fila estatica
typedef struct{
    int inicio, fim, max;
    int *dados;
}FilaEstatica;


//Criar fila encadeada
FilaEncadeada* criarFilaEncadeada() {
    FilaEncadeada *f = malloc(sizeof(FilaEncadeada));
    f->n=0;
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

//Criar fila estatica
FilaEstatica* criarFilaEstatica(int max) {
    FilaEstatica *f = malloc(sizeof(FilaEstatica));

    f->inicio = 0;
    f->fim = -1;
    f->max = max;
    f->dados = malloc(max * sizeof(int));

    return f;
}


bool estaVazia(FilaEncadeada *f) {
    if(f->inicio == NULL && f->fim == NULL)
        return true;
    else
        return false;
}

bool inserir(FilaEncadeada *f, int dado) {

    No *novoNo = (No*)malloc(sizeof(No));

    novoNo->valor = dado;
    novoNo->prox = NULL;

    if(estaVazia(f))
        f->inicio = novoNo;
    else
        f->fim->prox = novoNo;

    f->fim = novoNo;
    f->n++;
    return true;
}


int remover(FilaEncadeada *f) {
    if(estaVazia(f)) {
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
    f->n--;
    return valorAux;
}


void imprimeFila(FilaEncadeada *f){
    while(!estaVazia(f)){
         printf("%d\n", remover(f));
    }
}




bool inserirFilaEstatica(FilaEstatica *fe, int dado) {
    fe->fim = fe->fim+1;
    fe->dados[fe->fim] = dado;
    return true;
}




int main() {

    FilaEncadeada *f = criarFilaEncadeada();
   
    FilaEstatica *fe = criarFilaEstatica(f->n);

   


    

    inserir(f, 10);
    inserir(f, 20);
    inserir(f, 50);
    inserir(f, 80);
    remover(f);

 

    //inserir valores da fila encadeada na fila estatica
    while(!estaVazia(f)){
        inserirFilaEstatica(fe, remover(f));
        
    }


    


    return 0;
}
