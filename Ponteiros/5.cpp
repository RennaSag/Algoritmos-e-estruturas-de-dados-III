#include <stdio.h>

void vetormaiormenor(int *mai, int *men, int *vet){
	
	int n;
	
	*mai=*men=*vet;
	
	for (int i = 0; i < n; i++) {
    	if (vet[i] > *mai) {
        	*mai = vet[i];
    	}
    	if(vet[i]<*men){
    		*men=vet[i];
		}
	}
	
}

int main(){
	
	int n;
	
	printf("Digite o tamanho do vetor\n");
	scanf("%d", &n);
	
	int vetor[n];
	
	
	for(int i; i<n; i++){
		printf("Digite o valor para a posicao %d: ", i+1);
		scanf("%d", &vetor[i]);
	}
	
	int maior, menor;
	
	vetormaiormenor(&maior, &menor, vetor);
	
	printf("Maior: %d\nMenor: %d", maior, menor);
	
return 0;
}