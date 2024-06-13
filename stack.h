#ifndef STACK_H
#define STACK_H

typedef struct {
    double *arr;
    int top;
    int capacity;
} Stack;

Stack *init_stack(int capacity);
void freeStack(Stack *stack);

int isEmpty(Stack *stack);
int isFull(Stack *stack);

void push(Stack *stack, double value);
double pop(Stack *stack);

#endif