#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct no{
	char dados[50];
	struct no *proximo_no;	
}NO;


typedef struct pilha{
	NO *topo;
}PILHA;


void push(char dados[50], PILHA *pilha){
	
	NO* no_atual=(NO *)malloc(sizeof(NO));
	
	no_atual->dados[50]=dados[50];
	no_atual->proximo_no=pilha->topo;
	pilha->topo=no_atual;
}



void inserir_dados(PILHA *pilha){
	char dados[50];
	
	
	printf("Insira dados na pilha\n*: Para encerrar\n");
	while (1){
		
		scanf("%s", &dados);
		if(dados[0] == '*'){
			system("cls");
			printf("Encerrando...");
		}
		push(dados, pilha);
	}
	
	
}




int main (){  
	
	PILHA pi;
	pi.topo=NULL;
	
	inserir_dados(&pi);
	
	//não consegui fazer o resto
	
return 0;
}


