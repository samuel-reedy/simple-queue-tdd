#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @file queue.h
 * @brief Header file for the Queue data structure.
 *
 * Declarations for the Queue data structure
 */

// Node for each data value
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue();
void enqueue(Queue* q, int value);
void dequeue(Queue* q);
int isEmpty(Queue* q);

#endif // QUEUE_H