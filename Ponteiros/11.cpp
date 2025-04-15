#include <stdio.h>
#include <stdlib.h>

#define NUM_ALUNOS 10

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float media;
} Aluno;

void calcularMedia(Aluno *aluno) {
    aluno->media = (aluno->nota1 + aluno->nota2) / 2.0;
}

int main() {
    Aluno alunos[NUM_ALUNOS];
    Aluno *ptrAluno = alunos;  
    
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Informe o nome do aluno %d: ", i + 1);
        scanf("%s", ptrAluno->nome);

        printf("Informe a nota 1 do aluno %d: ", i + 1);
        scanf("%f", &ptrAluno->nota1);

        printf("Informe a nota 2 do aluno %d: ", i + 1);
        scanf("%f", &ptrAluno->nota2);

        
        calcularMedia(ptrAluno);

        
        ptrAluno++;
    }

   
    printf("\nResultados:\n");
    ptrAluno = alunos;  
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Aluno: %s, Nota 1: %.2f, Nota 2: %.2f, Média: %.2f\n",
               ptrAluno->nome, ptrAluno->nota1, ptrAluno->nota2, ptrAluno->media);

        ptrAluno++;
    }

    return 0;
}
