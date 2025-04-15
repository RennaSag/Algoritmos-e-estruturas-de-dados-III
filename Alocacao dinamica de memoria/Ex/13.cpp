#include <stdio.h>
#include <stdlib.h>

void preenchermatriz(int l, int c, int **matriz) {
    for (int i = 0; i < l; i++) {
        matriz[i] = (int *)malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) {
            printf("\nDigite o valor para o elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void verificarmatriz(int l, int c, int valor, int **matriz) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (matriz[i][j] == valor){return 1;}
            else{return 0;}
			}}}

int main() {
    int linha, coluna, v;

    printf("Digite a quantidade de linhas e colunas: ");
    scanf("%d%d", &linha, &coluna);

   
    int **matriz = (int **)malloc(linha * sizeof(int *));
    for (int i = 0; i < linha; i++) {
        matriz[i] = (int *)malloc(coluna * sizeof(int));
    }

    preenchermatriz(linha, coluna, matriz);

    printf("\nDigite um valor v: ");
    scanf("%d", &v);
    verificarmatriz(linha, coluna, v, matriz);

   
    for (int i = 0; i < linha; i++) {
    free(matriz[i]);
    }
    free(matriz);

return 0;
}
