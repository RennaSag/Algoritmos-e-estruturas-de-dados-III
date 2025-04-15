#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
    int qtdestoque;
    float preco;
} Produto;

void armazenarprodutos(Produto *produtos, int nu) {
    printf("\n\nPrencha os dados dos produtos.\n");
    for (int i = 0; i < nu; i++) {
        printf("Dados do produto %d\n", i + 1);

        printf("Id: ");
        scanf("%d", &produtos[i].id);

        printf("Nome: ");
        scanf("%s", produtos[i].nome);

        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[i].qtdestoque);

        printf("Preco: ");
        scanf("%f", &produtos[i].preco);

        system("cls");
    }
}

void maiorpreco(Produto *produtos, int nu) {
    Produto promaiorpreco = produtos[0];

    for (int k = 1; k < nu; k++) {
        if (produtos[k].preco > promaiorpreco.preco) {
            promaiorpreco = produtos[k];
        }
    }

    printf("Produto com maior preco: \n");
    printf("Id: %d\n", promaiorpreco.id);
    printf("Nome: %s\n", promaiorpreco.nome);
    printf("Quantidade em estoque: %d\n", promaiorpreco.qtdestoque);
    printf("Preco: %.2f\n", promaiorpreco.preco);
}

void maiorqtd(Produto *produtos, int nu) {
    Produto promaiorqtd = produtos[0];

    for (int e = 1; e < nu; e++) {
        if (produtos[e].qtdestoque > promaiorqtd.qtdestoque) {
            promaiorqtd = produtos[e];
        }
    }

    printf("Produto com maior Quantidade: \n");
    printf("Id: %d\n", promaiorqtd.id);
    printf("Nome: %s\n", promaiorqtd.nome);
    printf("Quantidade em estoque: %d\n", promaiorqtd.qtdestoque);
    printf("Preco: %.2f\n", promaiorqtd.preco);
}

int main() {
    int n = 0;

    printf("Digite quantos produtos quer armazenar: ");
    scanf("%d", &n);

    Produto *produtos;
    produtos = (Produto *)malloc(n * sizeof(Produto));

    armazenarprodutos(produtos, n);
    maiorpreco(produtos, n);
    maiorqtd(produtos, n);

    free(produtos);
return 0;
}
