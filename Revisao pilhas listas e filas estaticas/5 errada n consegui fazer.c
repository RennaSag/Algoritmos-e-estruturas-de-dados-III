#include<stdio.h>
#include<stdlib.h>

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


void inverterPilha(Pilha *p1, Pilha *p2){
    while(!isEmpty(p1)) {
        int dado = pop(p1);
        push(p2, dado);
    }
}


void imprimirPilha(Pilha *p) {
    No *atual = p->topo;
    while(atual != NULL) {
        printf("Valor: %d\n", atual->valor);
        atual = atual->prox;
    }
}


int verificarPalindromo(Pilha *p1, Pilha *p2) {
    No *atualp1 = p1->topo;
    No *atualp2 = p2->topo;

    while (atualp1 != NULL && atualp2 != NULL) {
        if (atualp1->valor != atualp2->valor) {
            printf("Nao eh palindromo\n");
            return 0;
        }
        atualp1 = atualp1->prox;
        atualp2 = atualp2->prox;
    }

    
    printf("Eh palindromo.\n");
    return 1;
}




int main() {

    Pilha *p1 = criarPilha();
    Pilha *p2 = criarPilha();

    push(p1, 1);
    push(p1, 2);
    push(p1, 3);
    

	printf("Pilha 1:\n");
	imprimirPilha(p1);
	inverterPilha(p1, p2);
	
	printf("\nPilha 2:\n");
	imprimirPilha(p2);

	verificarPalindromo(p1, p2);


    return 0;
}