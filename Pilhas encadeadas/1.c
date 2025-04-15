/*Crie uma função size, com assinatura int size(Pilha *p), que receba um
ponteiro para uma pilha encadeada como parâmetro e retorne o seu
tamanho. Considere o retorno 0 (zero) para pilha vazia. */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct no_da_pilha{
	int dado;
	struct no_da_pilha *proximo_no;	
}NO;

typedef struct pilha{
	NO *topo_da_pilha;
}PILHA;


//


void empilhar(int dado, PILHA *minha_pilha){
	NO *no=(NO* )malloc(sizeof(NO));
	
	if(no==NULL){
		printf("Erro ao alocar");
	}
	else{
		no->dado=dado;
		no->proximo_no = minha_pilha->topo_da_pilha;
		minha_pilha->topo_da_pilha = no;
	}
}


int size(PILHA *minha_pilha){
	int tamanho=0;
	
	
	NO *p = minha_pilha->topo_da_pilha;
	
	if(p == NULL){
		return 0;
	}
	
	else{	
	while(p != NULL){
		tamanho++;
		p = p->proximo_no;
	}}
	
	
	return tamanho;
}

int main (){
	
	
	PILHA pilha;
    pilha.topo_da_pilha = NULL;
    
	int op, *dado;
	
	
	while (1) { 
        printf("1-Adicionar itens a pilha\n2-Contar quantos itens ha na pilha\n3-Sair\n");
        scanf("%d",&op);
        
        switch (op) {
            case 1:
            	system("cls");
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &dado);
                empilhar(dado, &pilha);
                break;
                
            case 2:
            	system("cls");
                printf("Tamanho da pilha: %d\n\n", size(&pilha));
                break;
                
            case 3:
                exit(0);
                break;
                
            default:
            	system("cls");
                printf("Opcao invalida\n");
                break;
        }
    }
		
		
		
	
	
	
	
	
return 0;
}