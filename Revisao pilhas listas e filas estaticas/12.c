/*.Crie uma função que receba uma lista e retorne:
0 - Se não estiver ordenada.
1 - Se estiver ordenada de forma crescente.
2 - Se estiver ordenada de forma decrescente*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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




int crescenteDecrescente(Lista *l){
    
    int op1 = 1;
    int op2 = 2; 
    int aux = l->valores[0];

        for (int i = 1; i < l->fim; i++){
            if (l->valores[i] > aux){
                aux = l->valores[i];
            }    
            else{
                op1 = 0;
                break;
            }
        }

    aux = l->valores[0];
    for (int i = 1; i < l->fim; i++){
            if (l->valores[i] < aux){
                aux = l->valores[i];             
            }    
            else{
                op2 = 0;
                break;
            }
        }


        if(op1 == 1){
            printf("Lista eh crescente");
            return op1;
        }
        else if (op2 == 2){
            printf("Lista eh decrescente");
            return op2;
        }
        
        else if(op1 == 0 && op2 == 0){
            printf("Lista desordenada");
            return 0;
        }
}






int main() {

    Lista *lista = criarLista(10);

    inserir(lista, 1);
    inserir(lista, 5);
    inserir(lista, 25);
    inserir(lista, 177);


    crescenteDecrescente(lista);
    return 0;
}