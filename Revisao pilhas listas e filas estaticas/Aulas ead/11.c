#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

bool eh_primo(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int* primos(int lista[], int tamanho, int *qtd_primos) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (eh_primo(lista[i]))
            contador++;
    }
    *qtd_primos = contador;
    int *primos = (int*)malloc(contador * sizeof(int));
    if (!primos)
        return NULL;
    contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (eh_primo(lista[i]))
            primos[contador++] = lista[i];
    }
    return primos;
}

int main() {
    int lista[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    int qtd_primos;
    int *primos_lista = primos(lista, tamanho, &qtd_primos);

    printf("Numeros primos na lista: ");
    for (int i = 0; i < qtd_primos; i++) {
        printf("%d ", primos_lista[i]);
    }
    printf("\n");


    free(primos_lista);

    return 0;
}
