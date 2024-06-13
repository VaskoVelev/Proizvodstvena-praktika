#ifndef CALCULATOR_H
#define CALCULATOR_H

#define MAX_LENGTH 100

#define PI 3.1415
#define E 2.7182

void removeNewLine(char *str);
void enterExpression(char *expression);
int isValid(char *expression);
int isDigit(char *character);
void tokeniseExpression(char *expression, Stack *stack);

void add(Stack *stack);
void subtract(Stack *stack);
void multiply(Stack *stack);
void divide(Stack *stack);

#endif