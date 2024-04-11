//
// Created by saw_henry_min on 4/7/24.
//
#include "dataStructure.h"
#include "stdio.h"
#include "stdlib.h"

int main(){

    struct Queue *q = createQueue();


    EnQueue(q, 10);
    EnQueue(q,20);

    DeQueue(q);
    DeQueue(q);

    EnQueue(q,30);
    EnQueue(q,40);
    EnQueue(q,50);

    DeQueue(q);

    printf("Queue Front : %d\n",(q->front != NULL) ? (q->front)->key : -1);
    printf("Queue Rear : %d\n",(q->rear != NULL) ? (q->rear)->key : -1);

    free(q);

    struct QNode *Node = newNode(0);
    free(Node);

    return 0;
}