/**
 * @class Queue
 * @brief A class that represents a queue data structure.
 *
 * Basic queue operations: enqueue, dequeue, and check if empty.
 */


#include <stdio.h>
#include "queue.h"

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL; 

    if (isEmpty(q)){
        q->front = temp;
        q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(Queue* q){
    if (isEmpty(q)){
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}