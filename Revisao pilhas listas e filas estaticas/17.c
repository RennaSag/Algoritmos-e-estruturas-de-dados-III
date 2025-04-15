/*.Escreva um programa que receba como entrada duas listas estáticas L1
e L2 e crie uma terceira lista L3 com a união dos elementos das duas
listas, mantendo a ordem original dos elementos. Assim, na lista L3 devem
estar todos os elementos da lista L1, seguidos dos elementos de L2.*/

/*
    l1: 1, 2, 3;
    l2: 4, 5, 6;

    l3: 1, 2, 3, 4, 5, 6;
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<locale.h>


typedef struct lista {
    int fim, qtd, max;
    int *valores;
} Lista;


Lista* criarLista(int max) {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->max = max;
    l->valores = (int*)malloc(max * sizeof(int));
    l->qtd = 0;
    l->fim = -1;
    return l;
}


bool estaVazia(Lista *l) {
    return l->qtd == 0;
}


bool estaCheia(Lista *l) {
    return l->qtd == l->max;
}


bool inserir(Lista *l, int dado) {
    if (estaCheia(l))
        return false;

    l->fim++;
    l->valores[l->fim] = dado;
    l->qtd++;
    return true;
}


bool inserirPosicao(Lista *l, int pos, int dado) {
    if (estaCheia(l) || pos < 0 || pos > l->fim + 1)
        return false;

    for (int i = l->fim; i >= pos; i--) {
        l->valores[i + 1] = l->valores[i];
    }

    l->valores[pos] = dado;
    l->fim++;
    l->qtd++;
    return true;
}


int remover(Lista *l) {
    if (estaVazia(l))
        return -1; 

    int valorRemovido = l->valores[l->fim];
    l->fim--;
    l->qtd--;
    return valorRemovido;
}


int removerPosicao(Lista *l, int pos) {
    if (estaVazia(l) || pos < 0 || pos > l->fim)
        return -1; 

    int valorRemovido = l->valores[pos];
    for (int i = pos; i < l->fim; i++) {
        l->valores[i] = l->valores[i + 1];
    }

    l->fim--;
    l->qtd--;
    return valorRemovido;
}


int consultar(Lista *l, int pos) {
    if (pos < 0 || pos > l->fim)
        return -1; 

    return l->valores[pos];
}


void imprimeLista(Lista *l){
    while(!estaVazia(l)){
         printf("%d\n", removerPosicao(l, 0));
    }
}


void imprimeListaSemRemover(Lista *l) {
    printf("\nElementos da lista:\n");
    for (int i = 0; i <= l->fim; i++) {
        printf("%d\n", l->valores[i]);
    }
}


void concatenar(Lista *l1, Lista *l2){
    Lista *l3 = criarLista(10);
    int aux;

    for(int i = 0; i < l1->qtd; i++){
        aux = l1->valores[i];
        inserir(l3, aux);
    }

    for(int i = 0; i < l2->qtd; i++){
        aux = l2->valores[i];
        inserir(l3, aux);
    }
    
    imprimeListaSemRemover(l3);
}




int main() {
    Lista *l1 = criarLista(10);
    Lista *l2 = criarLista(10);

  
    inserir(l1, 1);
    inserir(l1, 2);
    inserir(l1, 3);
    
    inserir(l2, 4);
    inserir(l2, 5);
    inserir(l2, 6);

    printf("Lista1:");
    imprimeListaSemRemover(l1);

    printf("Lista2:");
    imprimeListaSemRemover(l2);

    printf("Lista Concatenada:");
    concatenar(l1, l2);
    return 0;
}