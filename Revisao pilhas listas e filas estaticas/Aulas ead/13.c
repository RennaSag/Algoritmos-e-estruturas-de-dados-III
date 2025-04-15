#include <stdio.h>
#include <stdlib.h>

int* inverter_lista(int lista[], int tamanho) {
    int *lista_invertida = (int*)malloc(tamanho * sizeof(int));
    if (lista_invertida == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < tamanho; i++) {
        lista_invertida[i] = lista[tamanho - 1 - i];
    }

    return lista_invertida;
}

int main() {
    int lista_original[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(lista_original) / sizeof(lista_original[0]);

    printf("Lista original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista_original[i]);
    }
    printf("\n");

    int *lista_invertida = inverter_lista(lista_original, tamanho);

    printf("Lista invertida: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista_invertida[i]);
    }
    printf("\n");

    free(lista_invertida);

    return 0;
}
