#include "calculator.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeNewLine(char *str) {
    char *newLine = strchr(str, '\n');
    if (newLine != NULL) {
        *newLine = '\0';
    }
}

void enterExpression(char *expression) {
    printf("Enter the mathematical expression:\n");
    fgets(expression, MAX_LENGTH, stdin);
    removeNewLine(expression);
}

int isValid(char *expression) {

    return 1;
}

int isDigit(char *character) {
    if (character >= '0' && character <= '9') {
        return 1;
    }

    return 0;
}

void add(Stack *stack) {
    
}

void subtract(Stack *stack) {

}

void multiply(Stack *stack) {

}

void divide(Stack *stack) {

}

void tokeniseExpression(char *expression, Stack *stack) {
    char *current = expression;
    while (*current != '\0') {

        while (*current == ' ') {
            current++;
        }

        if (*current == '\0') {
            break;
        }

        if (isDigit(*current)) {
            char *remainingExpression;
            double number = strtod(current, remainingExpression);
            push(stack, number);

            current = remainingExpression;
        } else if (strncmp(current, "pi", 2) == 0) {
            push(stack, PI);
            current += 2;
        } else if (strncmp(current, "e", 1) == 0) {
            push(stack, E);
            current++;
        } else if (strncmp(current, "In", 2) == 0) {
            natural_log(stack);
            current += 2;
        } else if (strncmp(current, "log", 3) == 0) {
            log(stack);
            current += 3;
        } else {
            switch (*current) {
                case '+':
                    add(stack);
                    break;
                case '-':
                    subtract(stack);
                    break;
                case '*':
                    multiply(stack);
                    break;
                case '/':
                    divide(stack);
                    break;
                default:
                    printf("Invalid token!\n");
                    break;
            }

            current++;
        }
    }
}