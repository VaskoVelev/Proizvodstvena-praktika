#include "stack.h"
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void removeNewLine(char *str) {
    char *newLine = strchr(str, '\n');
    if (newLine != NULL) {
        *newLine = '\0';
    }
}

int isDigit(char character) {
    if (character >= '0' && character <= '9') {
        return 1;
    }

    return 0;
}

double getResult(Stack *stack) {
    return stack->arr[stack->top];
}

void enterExpression(char *expression) {
    printf("Enter the mathematical expression:\n");
    fgets(expression, MAX_LENGTH, stdin);
    removeNewLine(expression);
}

int isExpressionValid(char *expression) {
    //tva e za teb
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
            double number = strtod(current, &remainingExpression);
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
            logarithm(stack);
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
            }

            current++;
        }
    }
}

void add(Stack *stack) {
    //tva e za teb
}

void subtract(Stack *stack) {
    //tva e za teb
}

void multiply(Stack *stack) {
    //tva e za teb
}

void divide(Stack *stack) {
    //tva e za teb
}

void natural_log(Stack *stack) {
    //tva e za teb
}

void logarithm(Stack *stack) {
    //tva e za teb
}