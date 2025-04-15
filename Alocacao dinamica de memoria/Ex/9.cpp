#include <stdio.h>
#include <stdlib.h>


int main(){
	
	int n, tamanho=0, *vetor;
	
	do{
		printf("Digite um numero: ");
		scanf("%d", &n);
				
		if(n>=0){
		tamanho++;
		vetor=(int *)realloc(vetor, tamanho*sizeof(int));
		vetor[tamanho-1]=n;
		}
		
	}
	while(n>=0);
	
	printf("Os numeros digitados sao: \n");
	for(int i=0; i<tamanho; i++){
		printf("%d, ", vetor[i]);
	}
	
	free(vetor);
	
return 0;	
}