#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

int get_prio(char a) {
    switch (a) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1; // Handle invalid characters
    }
}

int main() {
    char stack[MAX_SIZE];
    char infixExp[MAX_SIZE];
    char postfix[MAX_SIZE];
    int i = 0;
    int stack_top = -1, post_top = 0;

    printf("Enter the Expression: ");
    scanf("%s", infixExp);

    while (infixExp[i] != '\0') {
        if (isalnum(infixExp[i])) {
            postfix[post_top++] = infixExp[i];
        } else if (infixExp[i] == '(') {
            stack[++stack_top] = '(';
        } else if (infixExp[i] == ')') {
            while (stack_top > -1 && stack[stack_top] != '(') {
                postfix[post_top++] = stack[stack_top--];
            }
            if (stack_top > -1) {
                stack_top--; 
            } else {
                printf("Invalid Expression\n");
                return 1;
            }
        } else {
            while (stack_top > -1 && get_prio(stack[stack_top]) >= get_prio(infixExp[i])) {
                postfix[post_top++] = stack[stack_top--];
            }
            stack[++stack_top] = infixExp[i];
        }
        i++;
    }

    while (stack_top > -1) {
        if (stack[stack_top] == '(') {
            printf("Invalid Expression\n");
            return 1;
        }
        postfix[post_top++] = stack[stack_top--];
    }

    postfix[post_top] = '\0';

    printf("The postfix Expression is %s\n", postfix);
    return 0;
}
