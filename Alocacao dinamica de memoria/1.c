#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[30];
	int quantidade;
	float valor;

}Produto;

int main(){
	
	int numero_produtos;
	Produto *produtos=(struct Produto *)malloc(numero_produtos*sizeof(Produto));
	
	for (int i=0; i<numero_produtos; i++){
		printf("Nome: ");
		scanf("%s", &produtos[i].nome);
		
		printf("Quantidade: ");
		scanf("%d", &produtos[i].quantidade);
		
		printf("Valor unitario: ");
		scanf("%f", &produtos[i].valor);
		
		printf("\n\n");
	}
	
	float valortotalvenda=0;
	for(int i=0; i<numero_produtos; i++){
		printf("Nome: %s", produtos[i].nome);
		printf("Valor unitario: %f", produtos[i].valor);
		valortotalvenda +=produtos[i].valor*produtos[i].quantidade;
	}
	
		printf("Valor total: %.2f", valortotalvenda);
		
		free(produtos);
return 0;
}