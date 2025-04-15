#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *n;
	n=(int *) malloc(5*sizeof(int));
	
	for(int i=0; i<5; i++){
		printf("Digite o numero %d: ", i+1);
		scanf("%d", &n[i]);
	}
	
	for(int j=0; j<5; j++){
		printf("%d\n", n[j]);
	}
	
	
	free(n);
return 0;
}