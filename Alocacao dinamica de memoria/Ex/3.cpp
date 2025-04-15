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
	
	int qtdpar=0, qtdimpar=0;
	
	for(int j=0; j<qtd; j++){
		if(me[j]%2==0){
			qtdpar++;
		}
		else{
			qtdimpar++;
		}	
	}
	
	printf("Quantidade de pares: %d\nQuantidade de impares: %d.", qtdpar, qtdimpar);
	
	free(me);
return 0;
}