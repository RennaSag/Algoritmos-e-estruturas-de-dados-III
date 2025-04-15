#include <stdio.h>
#include <string.h>

#define MAX_NOMES 5
#define TAM_NOME 31

void gravarNome(char matrizNomes[MAX_NOMES][TAM_NOME]);
void apagarNome(char matrizNomes[MAX_NOMES][TAM_NOME]);
void substituirNome(char matrizNomes[MAX_NOMES][TAM_NOME]);
void apagarPorNome(char matrizNomes[MAX_NOMES][TAM_NOME]);
void recuperarNome(char matrizNomes[MAX_NOMES][TAM_NOME]);

int main() {
    char matrizNomes[MAX_NOMES][TAM_NOME];
    char opcao;

    for (int i = 0; i < MAX_NOMES; i++) {
        matrizNomes[i][0] = '\0';
    }

    do {
        printf("\nOpcoes:\n");
        printf("(a) Gravar um nome\n(b) Apagar um nome\n(c) Substituir um nome\n(d) Apagar por nome\n(e) Recuperar um nome\n(s) Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'a':
                gravarNome(matrizNomes);
                break;
            case 'b':
                apagarNome(matrizNomes);
                break;
            case 'c':
                substituirNome(matrizNomes);
                break;
            case 'd':
                apagarPorNome(matrizNomes);
                break;
            case 'e':
                recuperarNome(matrizNomes);
                break;
            case 's':
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 's');

    return 0;
}

void gravarNome(char matrizNomes[MAX_NOMES][TAM_NOME]) {
    int linha;
    char nome[TAM_NOME];

    printf("Digite o nome a ser gravado: ");
    scanf("%s", nome);

    printf("Digite a linha para gravar o nome (0 a %d): ", MAX_NOMES - 1);
    scanf("%d", &linha);

    if (linha >= 0 && linha < MAX_NOMES) {
        strcpy(matrizNomes[linha], nome);
        printf("Nome gravado com sucesso!\n");
    } else {
        printf("Linha invalida.\n");
    }
}

void apagarNome(char matrizNomes[MAX_NOMES][TAM_NOME]) {
    int linha;

    printf("Digite a linha para apagar o nome (0 a %d): ", MAX_NOMES - 1);
    scanf("%d", &linha);

    if (linha >= 0 && linha < MAX_NOMES) {
        matrizNomes[linha][0] = '\0';
        printf("Nome apagado com sucesso!\n");
    } else {
        printf("Linha invalida.\n");
    }
}

void substituirNome(char matrizNomes[MAX_NOMES][TAM_NOME]) {
    int linha;
    char nome[TAM_NOME];

    printf("Digite o nome para substituir: ");
    scanf("%s", nome);

    printf("Digite a linha para substituir o nome (0 a %d): ", MAX_NOMES - 1);
    scanf("%d", &linha);

    if (linha >= 0 && linha < MAX_NOMES) {
        strcpy(matrizNomes[linha], nome);
        printf("Nome substituido com sucesso!\n");
    } else {
        printf("Linha invalida.\n");
    }
}

void apagarPorNome(char matrizNomes[MAX_NOMES][TAM_NOME]) {
    char nome[TAM_NOME];

    printf("Digite o nome a ser apagado: ");
    scanf("%s", nome);

    for (int i = 0; i < MAX_NOMES; i++) {
        if (strcmp(matrizNomes[i], nome) == 0) {
            matrizNomes[i][0] = '\0';
            printf("Nome apagado com sucesso!\n");
            return;
        }
    }

    printf("Nome nao encontrado.\n");
}

void recuperarNome(char matrizNomes[MAX_NOMES][TAM_NOME]) {
    int linha;

    printf("Digite a linha para recuperar o nome (0 a %d): ", MAX_NOMES - 1);
    scanf("%d", &linha);

    if (linha >= 0 && linha < MAX_NOMES) {
        if (matrizNomes[linha][0] != '\0') {
            printf("Nome na linha %d: %s\n", linha, matrizNomes[linha]);
        } else {
            printf("Nao ha nome na linha %d.\n", linha);
        }
    } else {
        printf("Linha invalida.\n");
    }
}
