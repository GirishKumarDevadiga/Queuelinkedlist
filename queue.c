#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../Headers/queue.h"

Queue queue_new() {
   Queue q1 = { NULL, NULL, 0 };
   return q1;
}

uint32_t queue_length(const Queue *queue) {
    assert(queue != NULL);
    return queue-> length;
}

static Node* _get_new_node_(int32_t val) {
     Node *newnode = (Node*)malloc(sizeof(Node));
     newnode->data = val;
     newnode->next = NULL;
     newnode->prev = NULL;
     
     return newnode;
}

 Queue* queue_addnode_rear(Queue *queue, int32_t val) {
    assert(queue != NULL);
    Node *newnode = _get_new_node_(val);
    
    
    if(queue->rear != NULL){
       newnode->next = queue->rear;
       queue->rear->prev = newnode;
    }
    
    queue->rear = newnode;
    
    if(queue->front == NULL){
       queue->front = newnode;
    }
    
    ++queue->length;
    
    assert((queue->length == 1 && queue->front == queue->rear) ||
           (queue->length > 1 && queue->front != queue->rear));
    
    return queue;
}

Queue* queue_delnode_front(Queue *queue) {
       assert(queue != NULL);
       Node *last, *cur;
       
       if(queue->front != NULL) {
          last = queue->front;
          if(queue->rear == queue->front){
             queue->rear = queue->front = NULL;
          } else {
             for(cur = queue->rear; cur->next != last; cur = cur->next);
             queue->front = cur;
             cur->next = NULL;
          }
          --queue->length;
          free(last);
       }
       
       return queue;
}

