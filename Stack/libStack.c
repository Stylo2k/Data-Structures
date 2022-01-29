/**
 * @file libStack.c
 * @author Mohammad Al Shakoush(mo.alshakoush@gmail.com)
 * @brief library for stack manipulation
 * @version 0.1
 * @date 2022-01-29
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "libStack.h"

#define EX_VAL 10

/**
 * @brief makes a new stack with the given size
 *
 * @param size the size of the stack
 * @return Stack the new stack
 */
Stack newStack(int size)
{
  Stack st;
  st.array = malloc(size * sizeof(int));
  assert(st.array != NULL);
  st.top = 0;
  st.size = size;
  return st;
}

/**
 * @brief doubles teh size of the stack
 *
 * @param stp pointer to the stack
 */
void doubleStackSize(Stack *stp)
{
  int newSize = 2 * stp->size;
  stp->array = realloc(stp->array, newSize * sizeof(int));
  assert(stp->array != NULL);
  stp->size = newSize;
}

/**
 * @brief extends the size of the stack with the `EX_VAL`
 *
 * @param stp
 */
void extendStackSize(Stack *stp)
{
  int newSize = EX_VAL + stp->size;
  stp->array = realloc(stp->array, newSize * sizeof(int));
  assert(stp->array != NULL);
  stp->size = newSize;
}

/**
 * @brief checks if the stack is empty
 *
 * @param st stack to check
 * @return bool, true if stack is empty
 */
bool isEmptyStack(Stack st)
{
  return (st.top == 0);
}

/**
 * @brief prints an error message
 *
 */
void stackEmptyError()
{
  printf("**stack is empty**\nAborting...");
  abort();
}

/**
 * @brief pushes an element on top of the stack
 *
 * @param value the value to push
 * @param stp stack pointer
 */
void push(int value, Stack *stp)
{
  if (stp->top == stp->size)
  {
    doubleStackSize(stp);
  }
  stp->array[stp->top] = value;
  stp->top++;
}

/**
 * @brief pushes an element on top of the stack
 *
 * @param value the value to push
 * @param stack the stack to push an element on top
 *
 * @return new stack with the pushed element
 */
Stack pushNoPointer(int value, Stack stack)
{
  if (stack.top == stack.size)
  {
    doubleStackSize(&stack);
  }
  stack.array[stack.top] = value;
  stack.top++;

  return stack;
}

/**
 * @brief pops an element from the stack
 *
 * @param stp Stack pointer
 * @return int the popped element
 */
int pop(Stack *stp)
{
  if (isEmptyStack(*stp))
  {
    stackEmptyError();
  }
  stp->top--;
  return stp->array[stp->top];
}

/**
 * @brief frees the stack
 *
 * @param st the stack to free
 */
void freeStack(Stack st)
{
  free(st.array);
}

/**
 * @brief prints the elements of the stack
 *
 * @param st the stack to print
 */
void printStack(Stack st)
{
  if (isEmptyStack(st))
  {
    stackEmptyError();
  }
  // st.top points to the top of the stack + 1 (so where a new insertion is possible) therefore, -1
  for (int i = st.top - 1; i >= 0; i--)
  {
    printf("%d\n", st.array[i]);
    printf("_\n");
  }
}