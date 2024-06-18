#include "utils/stack.h"
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
    return (character >= '0' && character <= '9');
}

int isValidOperation(char character) {
    return (character == '+' || character == '-' || character == '*' || character == '/');
}

int isPI(char *str) {
    return strncmp(str, "pi", 2) == 0;
}

int isE(char *str) {
    return strncmp(str, "e", 1) == 0;
}

int isIn(char *str) {
    return strncmp(str, "In", 2) == 0;
}

int isLog(char *str) {
    return strncmp(str, "log", 3) == 0;
}

void enterExpression(char *expression) {
    printf("Enter the mathematical expression:\n");
    fgets(expression, MAX_LENGTH, stdin);
    removeNewLine(expression);
}

int isValidExpression(char *expression) {
    int numCount = 0;
 
    char *current = expression;
    while(*current != '\0') {

        if (*current == ' ') {
            current++;
            continue;
        }
 
        if (isDigit(*current) || isPI(current) || isE(current)) {
            numCount++;
            if (isPI(current) || isE(current)) {
                current += (isPI(current)) ? 2 : 1;
            } else {
                while (isDigit(*current)) {
                    current++;
                }
            }
        } else if (isValidOperation(*current) || isIn(current) || isLog(current)) {
            if (isIn(current)) {
                if (numCount < 1) {
                    printf("Error: not enough operands for ln operation!\n");
                    return 0;
                }
                current += 2;
            } else if (isLog(current)) {
                if (numCount < 2) {
                    printf("Error: not enough operands for log operation!\n");
                    return 0;
                }
                numCount--;
                current += 3;
            } else {
                if (numCount < 2) {
                    printf("Error: not enough operands for binary operation!\n");
                    return 0;
                }
                numCount--;
                current++;
            }
        } else {
            printf("Error: invalid character {%c}!\n", *current);
            return 0;
        }
    }
 
    if (numCount != 1) {
        printf("Error: Invalid expression, unable to reach final result!\n");
        return 0;
    }
    
    return 1;
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
        } else if (isPI(current)) {
            push(stack, PI);
            current += 2;
        } else if (isE(current)) {
            push(stack, E);
            current++;
        } else if (isIn(current)) {
            natural_log(stack);
            current += 2;
        } else if (isLog(current)) {
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
    double op2 = pop(stack);
    double op1 = pop(stack);
    double result = op1 + op2;
    push(stack, result);
}
 
void subtract(Stack *stack) {
    double op2 = pop(stack);
    double op1 = pop(stack);
    double result = op1 - op2;
    push(stack, result);
}
 
void multiply(Stack *stack) {
    double op2 = pop(stack);
    double op1 = pop(stack);
    double result = op1 * op2;
    push(stack, result);
}
 
void divide(Stack *stack) {
    double op2 = pop(stack);
    double op1 = pop(stack);
    if (op2 == 0) {
        printf("Error: cannot divide by zero!\n");
        exit(1);
    }
    double result = op1 / op2;
    push(stack, result);
}
 
void natural_log(Stack *stack) {
    double op1 = pop(stack);
    if (op1 <= 0) {
        printf("Error: natural logarithm is undefined for non-positive values!\n");
        exit(1);
    }
    double result = log(op1);
    push(stack, result);
}
 
void logarithm(Stack *stack) {
    double op2 = pop(stack);
    double op1 = pop(stack);
    if (op2 <= 0) {
        printf("Error: logarithm is undefined for non-positive base!\n");
        exit(1);
    }
    if (op1 <= 0) {
        printf("Error: logarithm is undefined for non-positive argument!\n");
        exit(1);
    }
    double result = log(op1) / log(op2);
    push(stack, result);
}

double getResult(Stack *stack) {
    return stack->arr[stack->top];
};