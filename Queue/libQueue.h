/**
 * @file libQueue.h
 * @author Mohammad Al Shakoush (mo.alshakoush@gmail.com)
 * @brief header file for the lib Queue
 * @version 0.1
 * @date 2022-01-29
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef LIBQUEUE_H
#define LIBQUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * @brief the struct for a queue. With an array to contain the elements. Indicators for back, front and the size of the array/queue.
 *
 */
typedef struct Queue
{
  int *array;
  int back;
  int front;
  int size;
} Queue;

Queue newQueue(int s);
int isEmptyQueue(Queue q);
void queueEmptyError();
void doubleQueueSize(Queue *qp);
void enqueue(int item, Queue *qp);
Queue enqueueNoPointer(int item, Queue queue);
int dequeueNoPointer(Queue queue);
int dequeue(Queue *qp);
void printQueue(Queue queue);
void freeQueue(Queue q);

#endif
