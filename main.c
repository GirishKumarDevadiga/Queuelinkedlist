#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Headers/queue.h"

void test_addnode_rear(){
    Queue q = queue_new();
    Queue *queue = &q;
    
    queue = queue_addnode_rear(queue, 10);
    queue = queue_addnode_rear(queue, 20);
    queue = queue_addnode_rear(queue, 30);
    queue = queue_addnode_rear(queue, 40);
    
    assert(queue_length(queue) == 4);

}

void test_addnode_front(){
    Queue q = queue_new();
    Queue *queue = &q;
    
    queue = queue_addnode_rear(queue, 10);
    queue = queue_addnode_rear(queue, 20);
    queue = queue_addnode_rear(queue, 30);
    queue = queue_addnode_rear(queue, 40);
    assert(queue_length(queue) == 4);
    
    queue = queue_delnode_front(queue);
    assert(queue_length(queue) == 3);
    
    queue = queue_delnode_front(queue);
    assert(queue_length(queue) == 2);
}

int main() {
   test_addnode_rear();
   test_addnode_front();
   return 0;
}
