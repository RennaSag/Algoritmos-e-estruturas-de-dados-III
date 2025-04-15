#include <stdio.h>
#include <stdlib.h>


int *alocarmemoria(int tamanho){
	int *memoria=(int *)malloc(tamanho*sizeof(int));
	
	for(int i=0; i<tamanho; i++){
		memoria[i]=0;
	}
		
	return memoria;
}

//
void preenchervalor(int *memoria, int posicao, int valor) {
    memoria[posicao] = valor;
    printf("Valor %d inserido na posição %d.\n", valor, posicao);
}

//
void consulta(int *memoria, int posicao){
	printf("Valor na posição %d: %d\n", posicao, memoria[posicao]);
}


int main() {
   
   int tamanhomemoria, op, posicao, valor;
   
   printf("Digite o tamanho da memoria: ");
   scanf("%d", &tamanhomemoria);
   
   if(tamanhomemoria % sizeof(int) != 0){
   	printf("Digite um valor valido para a memoria.");
   	return 0;
   }
   
   int *memoria = alocarmemoria(tamanhomemoria);
   
   
   
   do{
   	printf("0 - Sair\n");
	printf("1 - Inserir valor\n");
   	printf("2 - Consultar valor\n");
   	scanf("%d", &op);
   	
   	switch(op){
   		
   		case 0:
   			free(memoria);
   			break;
   		
		case 1:
			printf("\nDigite a posicao: "); scanf("%d", &posicao);	
			printf("\nDigite o valor: "); scanf("%d", &valor);	
   			
			   preenchervalor(memoria, posicao, valor);
   			break;
   		
   		case 2:
   			printf("\nDigite a posicao: "); scanf("%d", &posicao);
   			
			   consulta(memoria, posicao);
   			break;		
	   }  	
   }while(op!=0);

return 0;
}
