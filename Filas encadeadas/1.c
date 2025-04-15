#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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



int main() {
    
	Fila *f = criarFila();
    
    char dado;
	int op;;
    
    	
    while (true) {
        printf("Escolha uma opcao:\n");
        printf("1-Inserir valor na fila\n2-Remover valor da fila\n3-Mostrar tamanho atual\n");
        printf("4-Limpar fila\n5-Mostrar fila\n0-Sair\n\n");
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
            
            case 0:
            	printf("\nPrograma encerrado...\n");
            	return 0;
              	break;           
        }  
    }  	

    
    
    

return 0;
}
