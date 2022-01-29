#include "libQueue.h"

int main()
{
    int size = 3;
    Queue queue = newQueue(size);

    queue = enqueueNoPointer(1, queue);

    enqueue(2, &queue);

    queue = enqueueNoPointer(3, queue);

    printQueue(queue);

    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("|%d| ", dequeue(&queue));
    }
    printf("]\n");

    freeQueue(queue);
    return 0;
}