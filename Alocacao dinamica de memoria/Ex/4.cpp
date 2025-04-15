#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int tamanho;
	
	printf("Digite o tamanho da string: ");
	scanf("%d", &tamanho);
	
	char *string;
	string=(char *)malloc(tamanho+1*sizeof(char));
	
	printf("Digite o conteudo da string: ");
	scanf("%s", string);
	
	for(int i; i<tamanho; i++){
		if(string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u'){
			printf("%c", string[i]);
		}
		else{
			printf("_");
		}
	}
	
	
	free(string);
return 0;
}