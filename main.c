#include "stack.h"
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Stack *stack = init_stack(MAX_CAPACITY);

    char *expression = (char *) malloc(MAX_LENGTH * sizeof(char));
    if (expression == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    enterExpression(expression);

    if (isValid(expression)) {
        tokeniseExpression(expression, stack);
    }

    double result = getResult(stack);
    printf("%.4f\n", result);

    freeStack(stack);
    free(expression);

    return 0;
}