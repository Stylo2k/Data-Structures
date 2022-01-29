/**
 * @file libStack.h
 * @author Mohammad Al Shakoush (mo.alshakoush@gmail.com)
 * @brief header file for stack
 * @version 0.1
 * @date 2022-01-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef LIBSTACK_H
#define LIBSTACK_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/**
 * @brief struct of the stack
 * Array to contain the elements
 * Top and size to indicate the top and size
 *
 */
typedef struct Stack
{
  int *array;
  int top;
  int size;
} Stack;

Stack newStack(int s);

void doubleStackSize(Stack *stp);
bool isEmptyStack(Stack st);
void printStack(Stack st);
void stackEmptyError();
void push(int value, Stack *stp);
Stack pushNoPointer(int value, Stack stack);
int pop(Stack *stp);
void freeStack(Stack st);

#endif
