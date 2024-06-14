#include "stack.h"
#ifndef CALCULATOR_H
#define CALCULATOR_H

#define MAX_LENGTH 100

#define PI 3.1415
#define E 2.7182

void removeNewLine(char *str);
int isDigit(char character);
int isValidOperation(char character);
int isPI(char *str);
int isE(char *str);
int isIn(char *str);
int isLog(char *str);
double getResult(Stack *stack);

void enterExpression(char *expression);
int isValidExpression(char *expression);
void tokeniseExpression(char *expression, Stack *stack);

void add(Stack *stack);
void subtract(Stack *stack);
void multiply(Stack *stack);
void divide(Stack *stack);
void natural_log(Stack *stack);
void logarithm(Stack *stack);

#endif