#include <stdio.h>
#include <math.h>

struct Cidade {
    char nome[50];
    int x, y;
};

void calcularDistancias(struct Cidade cidades[], int N, double distancias[][10]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int deltaX = cidades[i].x - cidades[j].x;
            int deltaY = cidades[i].y - cidades[j].y;
            distancias[i][j] = sqrt(deltaX * deltaX + deltaY * deltaY);
        }
    }
}

void exibirMatrizDistancias(double distancias[][10], int N) {
    printf("\nMatriz de Distancias:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f\t", distancias[i][j]);
        }
        printf("\n");
    }
}

double obterDistanciaEntreCidades(int cidade1, int cidade2, double distancias[][10]) {
    return distancias[cidade1][cidade2];
}

int main() {
    int N;

    printf("Digite o numero de cidades (N): ");
    scanf("%d", &N);

    struct Cidade cidades[10];
    double distancias[10][10];

    for (int i = 0; i < N; i++) {
        printf("Digite o nome da cidade %d: ", i + 1);
        scanf("%s", cidades[i].nome);

        printf("Digite a coordenada X da cidade %d: ", i + 1);
        scanf("%d", &cidades[i].x);

        printf("Digite a coordenada Y da cidade %d: ", i + 1);
        scanf("%d", &cidades[i].y);
    }

    calcularDistancias(cidades, N, distancias);

    exibirMatrizDistancias(distancias, N);

    int cidade1, cidade2;
    printf("\nDigite o numero das duas cidades para obter a distancia entre elas: ");
    scanf("%d %d", &cidade1, &cidade2);

    if (cidade1 >= 0 && cidade1 < N && cidade2 >= 0 && cidade2 < N) {
        double distancia = obterDistanciaEntreCidades(cidade1, cidade2, distancias);
        printf("A distancia entre %s e %s eh %.2f\n", cidades[cidade1].nome, cidades[cidade2].nome, distancia);
    } else {
        printf("Numeros de cidades invalidos.\n");
    }

    return 0;
}
