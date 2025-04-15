#include <stdio.h>

void leituraMatriz(int matriz[10][10], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o elemento da posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void multiplicaMatrizes(int matA[10][10], int matB[10][10], int resultado[10][10], int linhasA, int colunasA, int colunasB) {
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunasA; k++) {
                resultado[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

void imprimeMatriz(int matriz[10][10], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a, b, c, d;

    printf("Digite as dimensoes das matrizes (a, b, c, d): ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (b != c) {
        printf("Operacao nao permitida. O numero de colunas da primeira matriz deve ser igual ao numero de linhas da segunda matriz.\n");
        return 1;
    }

    int matrizA[10][10], matrizB[10][10], resultado[10][10];

    printf("Digite os elementos da primeira matriz (%d x %d):\n", a, b);
    leituraMatriz(matrizA, a, b);

    printf("Digite os elementos da segunda matriz (%d x %d):\n", c, d);
    leituraMatriz(matrizB, c, d);

    multiplicaMatrizes(matrizA, matrizB, resultado, a, b, d);

    printf("\nMatriz A (%d x %d):\n", a, b);
    imprimeMatriz(matrizA, a, b);

    printf("\nMatriz B (%d x %d):\n", c, d);
    imprimeMatriz(matrizB, c, d);

    printf("\nProduto das matrizes A x B (%d x %d):\n", a, d);
    imprimeMatriz(resultado, a, d);

    return 0;
}
