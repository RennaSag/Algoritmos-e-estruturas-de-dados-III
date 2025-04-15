#include <stdio.h>
#include <stdlib.h>

struct Node {
    double data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(double data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, double data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void menorChave(struct Node* root) {
    if (root == NULL) {
        printf("A arvore esta vazia.\n");
        return;
    }

    if (root->left != NULL) {
        menorChave(root->left);
    } else {
        printf("O menor valor e: %.2f\n", root->data);
    }
}

void maiorChave(struct Node* root) {
    if (root == NULL) {
        printf("A arvore esta vazia.\n");
        return;
    }

    if (root->right != NULL) {
        maiorChave(root->right);
    } else {
        printf("O maior valor e: %.2f\n", root->data);
    }
}

void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%f \n", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%f \n", root->data);
        inorderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%f \n", root->data);
    }
}

struct Node* search(struct Node* root, double key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

struct Node* deleteNode(struct Node* root, double key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int op;
    double value;

    while (1) {
        system("cls");
        printf("Escolha uma opcao:\n");
        printf("1- Inserir valor\n");
        printf("2- Consultar a menor chave\n");
        printf("3- Consultar a maior chave\n");
        printf("4- Exibir as chaves com percurso pre-ordem\n");
        printf("5- Exibir as chaves com percurso em-ordem\n");
        printf("6- Exibir as chaves com percurso pos-ordem\n");
        printf("7- Procurar uma chave\n");
        printf("8- Excluir uma chave\n");
        printf("9- Sair\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Digite o valor: ");
                scanf("%lf", &value);
                root = insert(root, value);
                break;

            case 2:
                menorChave(root);
                system("pause");
                break;

            case 3:
                maiorChave(root);
                system("pause");
                break;

            case 4:
                preOrderTraversal(root);
                system("pause");
                break;

            case 5:
                inorderTraversal(root);
                system("pause");
                break;

            case 6:
                postOrderTraversal(root);
                system("pause");
                break;

            case 7:
                printf("Digite o valor para procurar: ");
                scanf("%lf", &value);
                struct Node* foundNode = search(root, value);
                if (foundNode != NULL) {
                    printf("Valor %.2f encontrado na arvore.\n", foundNode->data);
                } else {
                    printf("Valor %.2f nao encontrado na arvore.\n", value);
                }
                system("pause");
                break;

            case 8:
                printf("Digite o valor para excluir: ");
                scanf("%lf", &value);
                root = deleteNode(root, value);
                break;

            case 9:
                exit(0);

            default:
                printf("Opcao invalida.\n");
                system("pause");
        }
    }

    return 0;
}
