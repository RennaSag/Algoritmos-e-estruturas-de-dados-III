#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct celula {
    int dado_da_celula;
    struct celula *proxima_celula;
} Celula;

typedef struct pilha {
    Celula *topo_da_pilha;
} Pilha;

void iniciarPilha(Pilha *minhapilha) {
    minhapilha->topo_da_pilha = NULL;
}

void empilhar(int dado_da_celula, Pilha *minhapilha) {
    Celula *no = (Celula*)malloc(sizeof(Celula));
    
    if (no == NULL) {
        printf("Erro de alocação de nó\n");
    } else {
        no->dado_da_celula = dado_da_celula;
        no->proxima_celula = minhapilha->topo_da_pilha;
        minhapilha->topo_da_pilha = no;
    }
}

int desempilha(Pilha *minhapilha) {
    Celula *no = minhapilha->topo_da_pilha;
    int dado_da_celula;
    
    if (no == NULL) {
        printf("Pilha vazia\n");
        exit(1);
    } else {
        minhapilha->topo_da_pilha = no->proxima_celula;
        dado_da_celula = no->dado_da_celula;
        free(no);
        return dado_da_celula;
    }
}

void imprimePilha(Pilha *minhapilha) {
    Celula *atual = minhapilha->topo_da_pilha;
    
    if (atual == NULL) {
        printf("Pilha vazia\n");
        return;
    }

    printf("Elementos da pilha:\n");
    while (atual != NULL) {
        printf("%d\n", atual->dado_da_celula);
        atual = atual->proxima_celula;
    }
}




