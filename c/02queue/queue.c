#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

QueueResult queue_init (Queue *queue) {

    queue->data = (*int)malloc(sizeof(int) * QUEUE_MAX_SIZE);
    queue->head = 0;
    queue->tail = 0;

}

QueueResult queue_is_empty (Queue *queue) {

    if(queue->tail == -1 ) return QUEUE_EMPTY;

    return QUEUE_OK;

}

QueueResult queue_push (Queue *queue, int *value) {
    
    if(queue_is_empty(queue) != QUEUE_OK) return QUEUE_EMPTY;

    if (queue-> taili + 1  >= QUEUE_MAX_SIZE) {
        return QUEUE_FAIL;
    }

    queue->data[++(queue->tail)] = *value;

    return QUEUE_OK;
}

QueueResult queue_pop (Queue *queue, int *value) {

    if(queue_is_empty(queue) != QUEUE_OK) return QUEUE_EMPTY;

    *value = queue->data[(queue->head)];

    for(int i = queue->head; i < tail; i++) {
        queue->data[i] = queue->data[i+1];
    }

    return QUEUE_OK;
}

QueueResult queue_max (Queue *queue, int *value){

    if(queue_is_empty != QUEUE_OK) return QUEUE_EMPTY;

    *value = queue->data[queue->start];

    for(int i = start; i <= tail; i++) {
        if(queue->data[i] >= *value) {
            *value = queue->data[i];
        }
    }

    return QUEUE_OK;
}

QueueResult queue_min (Queue *queue, int *value) {
    
    if(queue_is_empty != QUEUE_OK) return QUEUE_EMPTY;

    *value = queue->data[queue->start];

    for(int i = start; i <= tail; i++) {
        if(queue->data[i] <= *value) {
            *value = queue->data[i];
        }
    }

    return QUEUE_OK;

}

QueueResult queue_peek (Queue *queue, int *value) {

    *value = queue->data[queue->head];

    return QUEUE_OK;

}

void queue_destory (Queue *queue) {

    queue->head = 0;
    queue->tail = 0;
    free(queue->data);

    queue->data = NULL;
}

void queue_print (Queue *queue) {

    if (queue_is_empty (queue) != QUEUE_OK) return QUEUE_EMPTY;

    for(int i = queue->head; i >= queue->tail; i++) 
        printf("%d | ", queue->data[i];

}

