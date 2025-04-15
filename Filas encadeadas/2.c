#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct no {
    char dado;
    struct no *prox;
} No;

typedef struct fila {
    No *inicio;
    No *fim;
} Fila;

Fila *criarFila() {
    Fila *fi = (Fila*)malloc(sizeof(Fila));
    fi->inicio = NULL;
    fi->fim = NULL;
    return fi;
}

bool verificarVazia(Fila *fi) {
    return (fi->inicio == NULL && fi->fim == NULL);
}

bool inserir(Fila *fi, char dado) {
    No *novoNo = (No*)malloc(sizeof(No));

    novoNo->dado = dado;
    novoNo->prox = NULL;

    if (verificarVazia(fi)) {
        fi->inicio = novoNo;
        fi->fim = novoNo; 
    } else {
        fi->fim->prox = novoNo;
        fi->fim = novoNo; 
    }

    return true;
}

int remover(Fila *fi) {
    if (verificarVazia(fi)) {
        printf("Fila Vazia\n");
        return -1;
    }

    int valorAux = fi->inicio->dado;

    No *noAux = fi->inicio;
    fi->inicio = fi->inicio->prox;

    if (fi->inicio == NULL) {
        fi->fim = NULL;
    }

    free(noAux);

    return valorAux;
}

int verificarTamanho(Fila *fi){
	int n=0;
	No *atual = fi->inicio;
	
	while(atual != NULL) {
		n++;
		atual = atual->prox;
	}
	return n;
}


void limparFila(Fila *fi){
	fi->fim = NULL;
	fi->inicio = NULL;
}


void mostrarFila(Fila *fi){
	No *noAtual = fi->inicio;
	
	while(noAtual != NULL){
		printf("%c ", noAtual->dado);
		noAtual=noAtual->prox;
	}	
}


void removerOrdemInversa(Fila *fi){
	while(fi->fim != NULL && fi->inicio != NULL){
		printf(" %c", remover(fi));
	}	
}

void inserirPalavra(Fila *fi, char *palavra){
	int tamanho = strlen(palavra);
	for(int i=0; i < tamanho; i++){
		inserir(fi, palavra[i]);
	}
}


//PILHA
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
        return NULL;
    }

    int dado = p->topo->dado;

    No *noAux = p->topo;

    p->topo = p->topo->prox;
    free(noAux);

    return dado;
}
//



void inverterNaPilha(Fila *fi, Pilha *p){
    while(!verificarVazia(fi)) {
        char dado = remover(fi);
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


int main() {
    
	Fila *f = criarFila();
	Pilha *p = criarPilha();
    
    char dado;
	int op;;
    
    	
    while (true) {
        printf("Escolha uma opcao:\n");
        printf("1-Inserir caractere na fila\n2-Remover valor da fila e mostrar na trla\n3-Mostrar a quantidade de elementos da fila\n");
        printf("4-Remover todos os elementos da fila\n5-Mostrar todos os elementos da fila\n6-Mostrar a quantidade de elementos na fila e remove-los\n");
        printf("7-Remover todos os elementos da fila e mostrar na ordem inversa\n");
        printf("8-Inverter elementos da fila\n9-Inserir uma palavra na fila\n10-Sair\n");
        scanf("%d", &op);
        while (getchar() != '\n');

        switch(op) {
            case 1:
            	system("cls");
                printf("Insira o valor: ");
                scanf(" %c", &dado);
                inserir(f, dado);   
				printf("\n\n");        
                break;
            case 2:
            	system("cls");
                printf("Valor %c removido\n\n", remover(f));
                printf("\n\n");  
                break;
                
            case 3:
            	system("cls");
				printf("Tamanho da fila: %d\n", verificarTamanho(f));
				printf("\n\n");  
				break;  
				
			case 4:
				system("cls");
				limparFila(f);
				printf("Fila limpa\n\n");
				break;
				
			case 5:
				system("cls");
				printf("A fila eh:\n");
				mostrarFila(f);
				printf("\n\n");  
				break; 
				
			case 6:
				system("cls");
				printf("A quantidade de elementos eh %d:\n", verificarTamanho(f));			
				limparFila(f);
				printf("\nFila limpa\n\n");
				printf("\n\n");
				break;
				
			case 7:
				system("cls");
				printf("Removendo e mostrando em ordem inversa:\n");
				removerOrdemInversa(f);
				printf("\n\n");
				break;
						
			case 8:
				system("cls");
				printf("Invertendo fila:\n");
				inverterNaPilha(f, p);
				printf("\n\n");
				break;
				
			case 9:
				system("cls");
				char palavra[20];
   				printf("Digite uma palavra: ");
    			scanf("%s", palavra);
				inserirPalavra(f, palavra);
				break;
				
            
            case 0:
            	printf("\nPrograma encerrado...\n");
            	return 0;
              	break;           
        }  
    }  	

    
    
    

return 0;
}


