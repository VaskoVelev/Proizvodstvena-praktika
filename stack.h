#ifndef STACK_H
#define STACK_H

typedef enum {
    INT,
    CHAR
} Type;

typedef union {
    int intValue;
    char charValue;
} Value;

typedef struct {
    Type type;
    Value value;
} Element;

typedef struct {
    Element *arr;
    int top;
    int capacity;
} Stack;

Stack *init_stack(int capacity);
void freeStack(Stack *stack);

int isEmpty(Stack *stack);
int isFull(Stack *stack);

void pushNumber(Stack *stack, int number);
void pushSymbol(Stack *stack, char symbol);

Element pop(Stack *stack);

#endif