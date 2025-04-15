#include <stdio.h>
#include <stdlib.h>

int* intersecao_listas(int lista1[], int tamanho1, int lista2[], int tamanho2, int *tamanho3) {
    int *lista3 = (int*)malloc((tamanho1 < tamanho2 ? tamanho1 : tamanho2) * sizeof(int));
    if (lista3 == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(EXIT_FAILURE);
    }

    int k = 0;

    for (int i = 0; i < tamanho1; i++) {
        for (int j = 0; j < tamanho2; j++) {
            if (lista1[i] == lista2[j]) {
                int l;
                for (l = 0; l < k; l++) {
                    if (lista3[l] == lista1[i])
                        break;
                }
                if (l == k) {
                    lista3[k++] = lista1[i];
                }
            }
        }
    }

    *tamanho3 = k;
    lista3 = (int*)realloc(lista3, k * sizeof(int));

    return lista3;
}

int main() {
    int lista1[] = {1, 2, 3, 4, 5};
    int tamanho1 = sizeof(lista1) / sizeof(lista1[0]);

    int lista2[] = {3, 4, 5, 6, 7};
    int tamanho2 = sizeof(lista2) / sizeof(lista2[0]);

    int tamanho3;
    int *lista3 = intersecao_listas(lista1, tamanho1, lista2, tamanho2, &tamanho3);

    printf("Intersecao das listas:\n");
    for (int i = 0; i < tamanho3; i++) {
        printf("%d ", lista3[i]);
    }
    printf("\n");

    free(lista3);

    return 0;
}
