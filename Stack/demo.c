#include "libStack.h"

int main()
{
    int size = 3;
    Stack stack = newStack(size);
    push(3, &stack);
    stack = pushNoPointer(2, stack);
    push(1, &stack);

    printStack(stack);

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", pop(&stack));
        printf("_\n");
    }

    freeStack(stack);
    return 0;
}