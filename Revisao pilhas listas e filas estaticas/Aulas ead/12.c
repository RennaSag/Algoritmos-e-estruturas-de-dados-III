#include <stdio.h>

void remover_duplicados(int lista[], int *tamanho) {
    int novo_tamanho = 0;
    for (int i = 0; i < *tamanho; i++) {
        int j;
        for (j = 0; j < novo_tamanho; j++) {
            if (lista[i] == lista[j])
                break;
        }
        if (j == novo_tamanho)
            lista[novo_tamanho++] = lista[i];
    }
    *tamanho = novo_tamanho;
}

int main() {
    int lista[] = {1, 2, 3, 4, 2, 3, 5, 6, 7, 7, 8, 9, 9};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    printf("Lista original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    remover_duplicados(lista, &tamanho);

    printf("Lista sem duplicatas: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}
