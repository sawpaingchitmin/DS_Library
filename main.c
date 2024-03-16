//
// Created by saw_henry_min on 3/14/24.
//

#include "stdio.h"
#include "dataStructure.h"




int main(){

    struct Node *head = NULL;

    singleInsert(&head,100);
    singleInsert(&head,200);
    singleInsert(&head,300);
    singleInsert(&head,400);
    singleShowData(head);
    singleDelete(&head,300);
    printf("\nAfter delete\n");
    singleShowData(head);




    return 0;
}