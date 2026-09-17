#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_MAX_SIZE 100

typedef enum {
    QUEUE_OK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_FAIL
} QueueResult;

typedef struct int_queue {
    int head;
    int tail;
    int *data;
} queue

QueueResult queue_push (Queue *queue, int *value);
QueueResult queue_pop (Queue *queue, int *value);
QueueResult queue_max (Queue *queue, int *value);
QueueResult queue_min (Queue *queue, int *value);
QueueResult queue_peek (Queue *queue, int *value);

QueueResult queue_init (Queue *queue);
QueueResult queue_is_empty (Queue *queue);
void queue_destroy (Queue *queue);
void queue_print (Queue *queue);

#endif
