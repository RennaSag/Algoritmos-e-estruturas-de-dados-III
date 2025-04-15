#include <stdio.h>
#include <stdlib.h>

int main() {
    char* vetorBytes = (char*)malloc(1024 * sizeof(char));

    int** matrizInteiros = (int**)malloc(10 * sizeof(int*));
    for (int i = 0; i < 10; i++) {
        matrizInteiros[i] = (int*)malloc(10 * sizeof(int));
    }

    struct Registro {
        char nomeProduto[30];
        int codigoProduto;
        float preco;
    };
    struct Registro* vetorRegistros = (struct Registro*)malloc(50 * sizeof(struct Registro));

    char** textoLinhas = (char**)malloc(100 * sizeof(char*));
    for (int i = 0; i < 100; i++) {
        textoLinhas[i] = (char*)malloc(81 * sizeof(char));
    }

    free(vetorBytes);

    for (int i = 0; i < 10; i++) {
        free(matrizInteiros[i]);
    }
    free(matrizInteiros);

    free(vetorRegistros);

    for (int i = 0; i < 100; i++) {
        free(textoLinhas[i]);
    }
    free(textoLinhas);

    return 0;
}
