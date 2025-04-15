#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    struct Node* next;
} Node;

Node* createNode(float data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: memoria insuficiente!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, float data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

float pop(Node** top) {
    if (*top == NULL) {
        printf("pilha esta vazia!\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *top;
    float data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

float evaluatePostfixExpression(char* expression) {
    Node* stack = NULL;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (!isOperator(expression[i])) {
            push(&stack, (float)(expression[i] - '0'));
        } else {
            float operand2 = pop(&stack);
            float operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char expression[100];
    printf("Digite a expressao pos-fixa: ");
    scanf("%s", expression);

    float result = evaluatePostfixExpression(expression);
    printf(": %.2f\n", result);

    return 0;
}
