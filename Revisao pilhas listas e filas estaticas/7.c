/*Crie uma função recursiva que verifique se uma fila circular possui valores
pares.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila {
    int inicio, fim, max, tam;
    int *dados;
} Fila;

Fila* criarFila(int max) {
    Fila *f = malloc(sizeof(Fila));

    f->inicio = 0;
    f->fim = -1;
    f->tam = 0;
    f->max = max;
    f->dados = malloc(max * sizeof(int));

    return f;
}

bool estaVazia(Fila *f) {
    if(f->tam == 0)
        return true;
    else
        return false;
}

bool estaCheia(Fila *f) {
    if(f->max == f->tam){
        return true;
    }else{
        return false;
    }
}

bool inserir(Fila *f, int dado) {
    if(estaCheia(f))
        return false;

    f->fim = (f->fim+1) % f->max;
    f->dados[f->fim] = dado;
    f->tam++;

    return true;
}

int remover(Fila *f) {
    if(estaVazia(f) == false){
        int aux = f->dados[f->inicio];
        f->inicio = (f->inicio+1) % f->max;
        f->tam--;
        return aux;
    }
}

void imprimeFila(Fila *f){
    while(!estaVazia(f)){
        printf("%d\n", remover(f));
    }
}

int pares(Fila *f){
    if(estaVazia(f)){
        printf("Fila vazia");
        return 0;
    }
    int n = remover(f);
   
    if(n % 2 == 0){
        printf("Valor %d eh par", n); 
        return 0;
    }
    return pares(f);
}






int main() {

    Fila *f = criarFila(8);

    inserir(f, 11);
    inserir(f, 21);
    inserir(f, 51);
    inserir(f, 81);
    inserir(f, 91);
    inserir(f, 202);
    inserir(f, 40);
    inserir(f, 500);

    printf("\n\n");

    pares(f);

    printf("\n\n");

    printf("Inicio: %d\n", f->inicio);
    printf("Fim: %d\n", f->fim);
    printf("Max: %d\n", f->max);
    printf("Tam: %d\n", f->tam);
    printf("Esta vazia: %s\n", estaVazia(f) ? "sim" : "nao");
    printf("Esta cheia: %s\n", estaCheia(f) ? "sim" : "nao");


    return 0;
}