#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pilha {
    int tam, topo, *dados;
}Pilha;

Pilha* criarPilha(int tam) {
    Pilha *p = malloc(sizeof(Pilha));

    p->topo = -1;
    p->tam = tam;
    p->dados = malloc(tam * sizeof(int));

    return p;
}

bool isEmpty(Pilha *p) {
    if(p->topo == -1)
        return true;
    else
        return false;
}

bool isFull(Pilha *p) {
    if(p->topo == p->tam - 1){
        return true;
    }else{
        return false;
    }
}

bool empilhar(Pilha *p, int dado) {
    if(isFull(p))
        return false;

    p->topo = p->topo+1;
    p->dados[p->topo] = dado;

    return true;
}

int desempilhar(Pilha *p) {
    if(isEmpty(p) == false){
        int aux = p->dados[p->topo];
        p->topo = p->topo -1;
        return aux;
    }
}

void mostrar(Pilha *p) {
    printf("Valores armazenados na pilha: ");
    while(!isEmpty(p)) {
        printf("%d ", desempilhar(p));
    }
    printf("\n");
}


int metadePilha(Pilha *p){
	int meio;
	
	if(p->tam % 2 != 0){
	meio = (p->tam / 2);
	return p->dados[meio];
	}	
	else{
	return p->dados[meio+1];
	}
	
}


int main() {
    Pilha *p = criarPilha(5);

    empilhar(p, 10);
    empilhar(p, 5);
    empilhar(p, 4);
    empilhar(p, 2);
    empilhar(p, 1);

    mostrar(p);
    
    printf("\n%d", metadePilha(p));

    return 0;
}