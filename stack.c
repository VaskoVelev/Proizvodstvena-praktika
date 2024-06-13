#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *init_stack(int capacity) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    stack->arr = (Element *) malloc(capacity * sizeof(Element));
    if (stack == NULL) {
        printf("Error allocating memory!\n");
        free(stack);
        exit(1);
    }

    stack->top = -1;
    stack->capacity = capacity;

    return stack;
}

void freeStack(Stack *stack) {
    free(stack->arr);
    free(stack);
}

int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }

    return 0;
}

int isFull(Stack *stack) {
    if (stack->top == stack->capacity - 1) {
        return 1;
    }

    return 0;
}

void pushNumber(Stack *stack, int number) {
    if (isFull(stack)) {
        printf("Stack is full!\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top].type = INT;
    stack->arr[stack->top].value.intValue = number;
}

void pushSymbol(Stack *stack, char symbol) {
    if (isFull(stack)) {
        printf("Stack is full!\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top].type = CHAR;
    stack->arr[stack->top].value.charValue = symbol;
}

Element pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        exit(1);
    }

    return stack->arr[stack->top--];
}