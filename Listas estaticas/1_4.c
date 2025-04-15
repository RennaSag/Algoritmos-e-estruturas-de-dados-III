#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Defini��o da estrutura da lista est�tica
typedef struct lista {
    int fim, qtd, max;
    char *valores;
} Lista;

//Fun��o para criar uma lista est�tica
Lista* criarLista(int max) {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->max = max;
    l->valores = (char*)malloc(max * sizeof(char));
    l->qtd = 0;
    l->fim = -1;
    return l;
}

//Fun��o para verificar se a lista est� vazia
bool estaVazia(Lista *l) {
    return l->qtd == 0;
}

//Fun��o para verificar se a lista est� cheia
bool estaCheia(Lista *l) {
    return l->qtd == l->max;
}

//Fun��o para inserir um elemento no fim da lista
bool inserir(Lista *l, int dado) {
    if (estaCheia(l))
        return false;

    l->fim++;
    l->valores[l->fim] = dado;
    l->qtd++;
    return true;
}

//Fun��o para inserir um elemento em uma posi��o espec�fica da lista
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

//Fun��o para remover um elemento do fim da lista
int remover(Lista *l) {
    if (estaVazia(l))
        return -1; // Lista vazia, retorna um valor inv�lido

    int valorRemovido = l->valores[l->fim];
    l->fim--;
    l->qtd--;
    return valorRemovido;
}

//Fun��o para remover um elemento de uma posi��o espec�fica da lista
int removerPosicao(Lista *l, int pos) {
    if (estaVazia(l) || pos < 0 || pos > l->fim)
        return -1; // Lista vazia ou posi��o inv�lida, retorna um valor inv�lido

    int valorRemovido = l->valores[pos];
    for (int i = pos; i < l->fim; i++) {
        l->valores[i] = l->valores[i + 1];
    }

    l->fim--;
    l->qtd--;
    return valorRemovido;
}

//Fun��o para consultar o elemento em uma posi��o espec�fica da lista
int consultar(Lista *l, int pos) {
    if (pos < 0 || pos > l->fim)
        return -1; // Posi��o inv�lida, retorna um valor inv�lido

    return l->valores[pos];
}

//Fun��o para imprimir todos os elementos da lista, removendo-os
void imprimeLista(Lista *l){
    while(!estaVazia(l)){
         printf("%c\n", removerPosicao(l, 0));
    }
}

//Fun��o para imprimir todos os elementos da lista, sem remov�-los
void imprimeListaSemRemover(Lista *l) {
    printf("\nElementos da lista:\n");
    for (int i = 0; i <= l->fim; i++) {
        printf("%c\n", l->valores[i]);
    }
}

//função de tamanho
int tamanho(Lista *l){
	return l->qtd;
}


void limpar(Lista *l){
	for(int i=0; i<l->qtd; i++){
		removerPosicao(l, i);
	}
}

int main() {
    Lista *lista = criarLista(10);

    //inserindo elementos na lista
    inserir(lista, 'a');
    inserir(lista, 'c');
    inserir(lista, 'b');
    inserir(lista, 's');
    inserir(lista, 'v');
    

    imprimeListaSemRemover(lista);

    //inserindo elemento 3 na posi��o 3
    inserirPosicao(lista, 3, 'o');

    //removendo elemento na �ltima posi��o da lista
    remover(lista);

    imprimeListaSemRemover(lista);

    //removendo elemento na posi��o 5 da lista
    removerPosicao(lista, 5);

    imprimeListaSemRemover(lista);
    
    printf("O tamanho da lista eh: %d ", tamanho(lista));
    
    limpar(lista);
    
    

    return 0;
}