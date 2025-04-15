#include <stdio.h>

int verificar_progressao_aritmetica(int lista[], int tamanho) {
    if (tamanho <= 2)
        return 1;

    int diff = lista[1] - lista[0];

    for (int i = 2; i < tamanho; i++) {
        if (lista[i] - lista[i - 1] != diff)
            return 0;
    }

    return 1;
}

int main() {
    int lista1[] = {1, 3, 5, 7, 9}; 
    int tamanho1 = sizeof(lista1) / sizeof(lista1[0]);

    printf("Lista 1:\n");
    printf("eh pa %s\n", verificar_progressao_aritmetica(lista1, tamanho1) ? "Sim" : "Não");

    int lista2[] = {1, 2, 4, 8, 16}; 
    int tamanho2 = sizeof(lista2) / sizeof(lista2[0]);

    printf("\nLista 2:\n");
    printf("eh uma pa %s\n", verificar_progressao_aritmetica(lista2, tamanho2) ? "Sim" : "Não");

    return 0;
}
