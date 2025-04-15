#include <stdio.h>

int* func1(int n){
	
	int *vetor=(int *)malloc(n*sizeof(int));
	
	for(int i; i<n; i++){
		printf("Digite o elemento %d do vetor: ", i+1);
		scanf("%d", &vetor[i]);
	}
	
	return vetor;
}

void func2(int *vetor, int n){
	int maior;
	int menor, soma;
	float media;
	
	maior=menor=vetor[0];
	
	for(int i=0; i<n; i++){
		if(vetor[i]>maior){
			maior=vetor[i];
		}
		if(vetor[i]<menor){
			menor=vetor[i];
		}
		soma+=vetor[i];
	}
			
		media+=soma/n;
	
		
		printf("Maior: %d\nMenor: %d\nMedia: %.2f\nSoma: %d\n", maior, menor, media,soma);
		
}


int main(){
		
		int tamanho;	
		printf("Digite o tamanho do vetor: ");
		scanf("%d", &tamanho);
		
		int *vetor=func1(tamanho);

		
		printf("Informacoes: \n");
		func2(vetor, tamanho);

    	free(vetor);
	
	
return 0;
}