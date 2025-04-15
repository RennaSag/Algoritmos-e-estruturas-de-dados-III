/*Implemente uma função para remover todos os elementos duplicados de
uma pilha estática, mantendo a ordem dos elementos.*/



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

bool push(Pilha *p, int dado) {
    if(isFull(p))
        return false;

    p->topo = p->topo+1;
    p->dados[p->topo] = dado;

    return true;
}

int pop(Pilha *p) {
    if(isEmpty(p) == false){
        int aux = p->dados[p->topo];
        p->topo = p->topo -1;
        return aux;
    }
}

void mostrar(Pilha *p) {
    printf("Valores armazenados na pilha: ");
    while(!isEmpty(p)) {
        printf("%d ", pop(p));
    }
    printf("\n");
}


/*Implemente uma função para remover todos os elementos duplicados de
uma pilha estática, mantendo a ordem dos elementos.
p1:
1
2
2
3
//
p2:
3
2
2
1
//
p1:
1
2
3
*/


void removerDuplicados(Pilha *p1){
    Pilha *p2 = criarPilha(p1->tam);
    int aux;

    while (!isEmpty(p1)){
        push(p2, pop(p1));
    }

    while (!isEmpty(p2)){
        aux = pop(p2);  
        if(aux != p2->dados[p2->topo]){
            push(p1, aux);
        }
    }

    mostrar(p1);
}



int main() {
    Pilha *p = criarPilha(10);


    push(p, 10);
    push(p, 5);
    push(p, 5);
    push(p, 5);
    push(p, 4);
    push(p, 1);


    
    removerDuplicados(p);


    return 0;
}