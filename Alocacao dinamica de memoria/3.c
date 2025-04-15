#include <stdio.h>

double** preencher_matriz(int lin, int col) {
    double** matriz = (double**)malloc(lin * sizeof(double*));

    for (int i = 0; i < lin; i++) {
        matriz[i] = (double*)malloc(col * sizeof(double));

        for (int j = 0; j < col; j++) {
            printf("Digite o elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matriz[i][j]);
        }
    }

    return matriz;
}


int main() {
    int linhas, colunas;

    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    double** matriz1 = preencher_matriz(linhas, colunas);
    double** matriz2 = preencher_matriz(linhas, colunas);

    double** matriz_soma = (double**)malloc(linhas * sizeof(double*));
    
	for (int i = 0; i < linhas; i++) {
        matriz_soma[i] = (double*)malloc(colunas * sizeof(double));
        for (int j = 0; j < colunas; j++) {
            matriz_soma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }


    printf("\nMatriz 1:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.2lf\t", matriz1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz 2:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.2lf\t", matriz2[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz Soma:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.2lf\t", matriz_soma[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < linhas; i++) {
        free(matriz1[i]);
        free(matriz2[i]);
        free(matriz_soma[i]);
    }
    free(matriz1);
    free(matriz2);
    free(matriz_soma);

    return 0;
}