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
bool inserirPosicao(Lista *l, int pos, char dado) {
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
	while(!estaVazia){
	remover(l);
	}
}


//PILHA
typedef struct no {
    char dado;
    struct no *prox;
} No;


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

void push(Pilha *p, int dado) {
    No *novoNo = (No*)malloc(sizeof(No));

    novoNo->dado = dado;

    novoNo->prox = p->topo;

    p->topo = novoNo;
}

int pop(Pilha *p) {

    if(isEmpty(p)) {
        printf("Pilha Vazia\n");
        return 0;
    }

    int dado = p->topo->dado;

    No *noAux = p->topo;

    p->topo = p->topo->prox;
    free(noAux);

    return dado;
}
//

void inverterNaPilha(Lista *l, Pilha *p){
    while(!estaVazia(l)) {
        char dado = remover(l);
        push(p, dado);
    }
}

void imprimirPilha(Pilha *p){
	No *noAux = p->topo;
	
	while(noAux != NULL){
		printf(" %c", noAux->dado);
		noAux = noAux->prox;
	}
	printf("\n");
	
	
}


void inserirPalavra(Lista *l, char *palavra){
	int tamanho = strlen(palavra);
	for(int i=0; i < tamanho; i++){
		inserir(l, palavra[i]);
	}
}

int main() {
    Lista *lista = criarLista(10);
    Pilha *p = criarPilha();
    
    char dado;
	int op;
	int aux;
    
    	
    while (true) {
        printf("Escolha uma opcao:\n");
        printf("1-Inserir caractere na lista informando a posicao\n");
        printf("2-Remover um caractere da posicao informada\n");
        printf("3-Mostrar a quantidade de elementos da lista\n");
        printf("4-Remover todos os elementos da lista\n");
        printf("5-Mostrar todos os elementos da lista sem remove-los\n");
        printf("6-Mostrar a quantidade de elementos e remove-los\n");
        printf("7-Remover os elementos e mostrar na ordem inversa\n");
        printf("8-Inserir palavra na fila\n");
        printf("9-Sair");
        scanf("%d", &op);
        while (getchar() != '\n');

        switch(op) {
            case 1:
				system("cls");
				printf("Insira a posicao que deseja: ");
				scanf("%d", &aux);
				
				printf("Insira o caractere que deseja adicionar: ");
				scanf("%c", dado);				
				inserirPosicao(lista, aux, dado);
				
				printf("\nEstado da lista\n");
				imprimeListaSemRemover(lista);
                break;
            case 2:
            	system("cls");
            	printf("Insira a posicao que deseja remover: ");
            	scanf("%d", &aux);
            	removerPosicao(lista,aux); 
            	printf("\nEstado da lista\n");
				imprimeListaSemRemover(lista);
                break;
                
            case 3:
            	system("cls");
				printf("O tamanho atual da lista eh: %d", tamanho(lista));
				break;  
				
			case 4:
				system("cls");
				printf("Limpando a lista inteira...");
				limpar(lista);
				break;
				
			case 5:
				system("cls");
				printf("\nMostrando a lista sem remover\n");
				imprimeListaSemRemover(lista);
				break; 
				
			case 6:
				system("cls");
				printf("\nMostrando a quantidade de elemento e removendo...");
				printf("O tamanho atual da lista eh: %d", tamanho(lista));
				limpar(lista);
				break;
				
			case 7:
				system("cls");
				printf("Removendo e mostrando em ordem inversa:\n");
				inverterNaPilha(lista, p);
				imprimirPilha(p);
				
				break;
						
			case 8:
				system("cls");
				char palavra[20];
   				printf("Digite uma palavra: ");
    			scanf("%s", palavra);
    			inserirPalavra(lista, palavra);
				break;
				          
            case 9:
            	printf("\nPrograma encerrado...\n");
            	return 0;
              	break;           
        }  
    }
    
    

    return 0;
}