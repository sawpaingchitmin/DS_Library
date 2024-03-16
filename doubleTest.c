//
// Created by saw_henry_min on 3/14/24.
//

#include "stdio.h"
#include "dataStructure.h"

int main() {

    struct Node *head = NULL;

    doubleInsert(&head, 10);
    doubleAppend(&head, 15);
    doubleInsert(&head, 20);
    doubleAppend(&head, 25);
    doubleInsert(&head, 30);
    doubleAppend(&head, 35);
    doubleInsert(&head, 40);

    doubleShowData(head);

    doubleDelete(&head, 20);
    printf("\nAfter delete\n");
    doubleDisplayForward(head);
    doubleDisplayBackward(head);

}