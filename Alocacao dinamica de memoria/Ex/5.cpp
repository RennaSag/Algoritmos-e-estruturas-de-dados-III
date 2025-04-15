#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtd;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &qtd);

    int *me;
    me = (int *)malloc(qtd * sizeof(int));

    for (int i = 0; i < qtd; i++) {
        printf("\nDigite o numero %d: ", i + 1);
        scanf("%d", &me[i]);
    }

    int x, qtdmulti = 0;
    int *vetmulti = (int *)malloc(qtd * sizeof(int));

    printf("\nDigite o valor x: ");
    scanf("%d", &x);

    for (int j = 0; j < qtd; j++) {
        if (me[j] % x == 0) {
            vetmulti[qtdmulti] = me[j];
            qtdmulti++;
        }
    }

    printf("\n\nQuantidade de multiplos: %d\n", qtdmulti);
    for (int g = 0; g < qtdmulti; g++) {
        printf("Multiplo: %d, ", vetmulti[g]);
    }

    free(me);
    free(vetmulti);
    return 0;
}