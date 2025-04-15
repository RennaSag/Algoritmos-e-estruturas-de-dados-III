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


void verificarListas(Lista *l1, Lista *l2){

	int aux = 0;
	for(int i=0; i<l1->qtd; i++){
		for(int j=0; j<l1->qtd; j++){
			if(l1->valores[i] == l2->valores[j]){	
				printf("\nValor %d comum aas duas listas", l1->valores[i]);
				aux = 1;
			}
			
		}
	}
	if (!aux) {
        printf("Listas diferentes");
    }	
}





int main() {
    Lista *lista = criarLista(5);
    Lista *lista2 = criarLista(5);
    
   
    inserir(lista, 1);
    inserir(lista, 2);
    inserir(lista, 7);
    inserir(lista, 99);
    inserir(lista, 5);
    
	inserir(lista2, 4);
    inserir(lista2, 3);
    inserir(lista2, 8);
    inserir(lista2, 1);
    inserir(lista2, 16);
	
	printf("Lista 1:");
    imprimeListaSemRemover(lista);
    
    printf("\nLista 2:");
    imprimeListaSemRemover(lista2);

	verificarListas(lista, lista2);
    
    


    return 0;
}