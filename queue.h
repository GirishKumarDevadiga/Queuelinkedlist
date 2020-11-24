#include <stdint.h>
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED


typedef struct _node_ Node;

struct _node_{
    int32_t data;
    Node *prev;
    Node *next;
};


typedef struct _queue_ Queue;


struct _queue_ {
    Node *front;
    Node *rear;
    uint32_t length;
};

Queue queue_new();
uint32_t queue_length(const Queue *queue);
Queue* queue_addnode_rear(Queue *queue, int32_t val);
Queue* queue_delnode_front(Queue *queue);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
#endif
