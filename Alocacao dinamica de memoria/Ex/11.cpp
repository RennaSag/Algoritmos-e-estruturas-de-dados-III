#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int matricula;
	char sobrenome[40];
	int anonascimento;
}Aluno;


void armazenaralunos(Aluno *alunos, int qtd){
	
	printf("\n\nPrencha os dados dos alunos.\n");
	for(int i=0; i<qtd; i++){
		printf("Dados do aluno %d\n", i+1);
		
		printf("Matricula: ");
		scanf("%d", &alunos->matricula);
		
		printf("Sobrenome: ");
		scanf("%s", &alunos->sobrenome);
		
		printf("Ano de nascimento: ");
		scanf("%d", &alunos->anonascimento);	
		
		system("cls");	
	}}

void mostraralunos(Aluno *alunos, int qtd){
	
	printf("Dados dos alunos: \n");
	for(int i=0; i<qtd; i++){
		printf("Aluno %d:\n", i+1);
		printf("Matricula: %d\n", alunos->matricula);
		
		printf("Sobrenome: %s\n", alunos->sobrenome);
		
		printf("Ano de nascimento: %d\n\n", alunos->anonascimento);		
	}	
}


int main(){
	
	
	int qtdalunos;
	printf("Digite quantos alunos deseja armazenar: ");
	scanf("%d", &qtdalunos);
	
	Aluno *alunos;
	alunos=(Aluno *)malloc(qtdalunos * sizeof(Aluno));
	
	armazenaralunos(alunos, qtdalunos);
	
	mostraralunos(alunos, qtdalunos);
	
free(alunos);
return 0;
}