/**
 * @file libQueue.c
 * @author Mohammad Al Shakoush (mo.alshakoush@gmail.com)
 * @brief function to make queues and work with them
 * @version 0.1
 * @date 2022-01-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "libQueue.h"

/**
 * @brief Makes a new queue with a given size
 *
 * @param size the size of the queue
 * @return Queue with the new size
 */
Queue newQueue(int size)
{
  Queue queue;
  queue.array = malloc(size * sizeof(int));
  assert(queue.array != NULL);
  queue.back = 0;
  queue.front = 0;
  queue.size = size;
  return queue;
}

/**
 * @brief checks if the queue is empty
 *
 * @param queue the queue to check
 * @return int
 */
int isEmptyQueue(Queue queue)
{
  return (queue.back == queue.front);
}

/**
 * @brief prints an error message that the queue is empty
 *
 */
void queueEmptyError()
{
  printf("**Queue is empty**\nAborting...");
  abort();
}

/**
 * @brief doubles the size of the queue
 *
 * @param qp a pointer to the queue to double the size of
 */
void doubleQueueSize(Queue *qp)
{
  int i;
  int oldSize = qp->size;
  qp->size = 2 * oldSize;
  qp->array = realloc(qp->array, qp->size * sizeof(int));
  assert(qp->array != NULL);
  for (i = 0; i < qp->back; i++)
  {
    qp->array[oldSize + i] = qp->array[i];
  }
  qp->back = qp->back + oldSize;
}

/**
 * @brief adds an item at the back of the queue (with out a pointer)
 *
 * @param item the item to add
 * @param queue the queue to add the element to
 *
 * @return queue with the item added
 */
Queue enqueueNoPointer(int item, Queue queue)
{
  queue.array[queue.back] = item;
  queue.back = (queue.back + 1) % queue.size;
  if (queue.back == queue.front)
  {
    doubleQueueSize(&queue);
  }
  return queue;
}

/**
 * @brief removes the first element from the queue (FIFO)
 *  with out a pointer
 *
 * @param queue to dequeue an item from
 * @return int the dequeued item
 */
int dequeueNoPointer(Queue queue)
{
  int item;
  if (isEmptyQueue(queue))
  {
    queueEmptyError();
  }
  item = queue.array[queue.front];
  queue.front = (queue.front + 1) % queue.size;
  return item;
}

/**
 * @brief adds an item at the back of the queue
 *
 * @param item the item to add
 * @param qp pointer to the queue
 */
void enqueue(int item, Queue *qp)
{
  qp->array[qp->back] = item;
  qp->back = (qp->back + 1) % qp->size;
  if (qp->back == qp->front)
  {
    doubleQueueSize(qp);
  }
}

/**
 * @brief removes the first element from the queue (FIFO)
 *
 * @param qp a pointer to the queue
 * @return int the dequeued item
 */
int dequeue(Queue *qp)
{
  int item;
  if (isEmptyQueue(*qp))
  {
    queueEmptyError();
  }
  item = qp->array[qp->front];
  qp->front = (qp->front + 1) % qp->size;
  return item;
}

/**
 * @brief generally you dont need this function. This is for demo purposes
 *
 * @param queue the queue to print
 */
void printQueue(Queue queue)
{
  if (isEmptyQueue(queue))
  {
    queueEmptyError();
  }
  printf("[ ");
  for (int i = queue.front; i < queue.back; i++)
  {
    if (i > queue.size)
    {
      i = i % queue.size;
    }
    printf("|%d| ", queue.array[i]);
  }
  printf("]\n");
}

/**
 * @brief frees a queue
 *
 * @param queue the queue to free
 */
void freeQueue(Queue queue)
{
  free(queue.array);
}
