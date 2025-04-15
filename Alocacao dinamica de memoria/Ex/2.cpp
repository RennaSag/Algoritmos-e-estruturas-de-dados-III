#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int qtd;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &qtd);
	
	int *me;
	me=(int *) malloc(qtd*sizeof(int));
	
	
	for(int i=0; i<qtd; i++){
		printf("Digite o numero %d: ", i+1);
		scanf("%d", &me[i]);
	}
	
	for(int j=0; j<qtd; j++){
		printf("%d\n", me[j]);
	}
	
	free(me);
return 0;
}