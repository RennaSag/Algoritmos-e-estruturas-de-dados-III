#include <stdio.h>
#include <stdlib.h>

int* remover_repetidos(int* vetor, int tamanho, int* novo_tamanho) {
    int* novo_vetor = (int*)malloc(tamanho * sizeof(int));
    int i, j = 0;

    for (i = 0; i < tamanho - 1; i++) {
        if (vetor[i] != vetor[i + 1]) {
            novo_vetor[j++] = vetor[i];
        }
    }

    novo_vetor[j++] = vetor[tamanho - 1];
    *novo_tamanho = j;

    novo_vetor = (int*)realloc(novo_vetor, j * sizeof(int));

    return novo_vetor;
}

int main() {
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int* vetor = (int*)malloc(tamanho * sizeof(int));

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    int novo_tamanho;
    int* novo_vetor = remover_repetidos(vetor, tamanho, &novo_tamanho);

    printf("\nVetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n\nVetor atualizado:\n");
    for (int i = 0; i < novo_tamanho; i++) {
        printf("%d ", novo_vetor[i]);
    }

    free(vetor);
    free(novo_vetor);

    return 0;
}
