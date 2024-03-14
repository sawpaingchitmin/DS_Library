//
// Created by saw_henry_min on 3/14/24.
//

#ifndef TEST_DATASTRUCTURE_H
#define TEST_DATASTRUCTURE_H

#include "stdio.h"
#include "stdlib.h"

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};


struct Node *createSingle(int newData){
    struct Node *newNode = (struct Node*) malloc(sizeof (struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    return newNode;
}

void singleInsert(struct Node **head,int Data){
    struct Node *newNode = createSingle(Data);
    newNode->next = *head;
    *head = newNode;
}

void singleShowData(struct Node *head){
    while (head != NULL){
        printf("Data : %d\n",head->data);
        head = head->next;
    }
}

void singleDelete(struct Node **head,int key){
    struct Node *temp = *head, *prev;
    while (temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nDelete data %d is not exist in node!\n",key);
        exit(1);
    }
    prev->next = temp->next;

    free(temp);
}



struct Node *createDouble(int newData){
    struct Node *newNode = (struct Node*) malloc(sizeof (struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void doubleInsert(struct Node **head,int Data){
    struct Node *newNode = createDouble(Data);
    newNode->next = *head;
    if(*head != NULL){
        (*head)->prev = newNode;
    }

    *head = newNode;
}


void doubleAppend(struct Node **head,int Data){
    struct Node *newNode = createDouble(Data);
    struct Node *last = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }

    while (last->next != NULL){
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;

}

void doubleShowData(struct Node *head){
    if(head == NULL){
        return;
    }

    while(head != NULL){
        printf("Data : %d\n",head->data);
        head = head->next;
    }
}

void doubleDelete(struct Node **head,int key){

    struct Node *temp = *head, *last;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;

        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        last = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Delete node doesn't exist!\n");
        exit(1);
    }

    last->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = last;
    }
    free(temp);
}


void doubleDisplayForward(struct Node *head){
    if(head == NULL){
        printf("Node is empty\n");
        exit(1);
    }
    printf("Displaying Forward\n");

    while (head != NULL){
        printf("Data : %d\n",head->data);
        head = head->next;
    }
}

void doubleDisplayBackward(struct Node *head){
    struct Node *tail = head;
    if(head == NULL){
        printf("Node is empty\n");
        exit(1);
    }
    while (tail->next != NULL){
        tail = tail->next;
    }
    printf("Displaying Backward\n");

    while (tail != NULL){
        printf("Data : %d\n",tail->data);
        tail = tail->prev;
    }
}



#endif //TEST_DATASTRUCTURE_H
