//
// Created by saw_henry_min on 3/16/24.
//

#include "stdio.h"
#include "stdlib.h"
#include "dataStructure.h"


//For Single Linked List
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

void singleAppend(struct Node **head,int Data){
    struct Node *newNode = createSingle(Data);
    struct Node *last = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = newNode;

}

void singleShowData(struct Node *head){
    int i = 0;
    while (head != NULL){
        printf("Index %d data : %d\n",i,head->data);
        head = head->next;
        i++;
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



//For Double Linked List
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

    int i = 0;
    while(head != NULL){
        printf("index %d data : %d\n",i,head->data);
        head = head->next;
        i++;
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

    int i = 0;
    while (head != NULL){
        printf("Index %d data : %d\n",i,head->data);
        head = head->next;
        i++;
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
    printf("\nDisplaying Backward\n");

    int i = 0;
    while (tail != NULL){
        printf("Index %d data : %d\n",i,tail->data);
        tail = tail->prev;
        i++;
    }
}


// For Stack Data Structure
void initializing(struct Stack *stack){
    stack->top = -1;
}

int isFull(struct Stack *stack){
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack,int value){
    if(isFull(stack)){
        printf("Stack overflow\n");
        exit(1);
    }else{
        stack->item[++stack->top] = value;
        printf("Date %d is insert at index %d\n",value,stack->top);
    }
}

int isEmpty(struct Stack *stack){
    return stack->top == -1;
}

int pop(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack underflow\n");
        exit(1);
    }else{
        return stack->item[stack->top--];
    }
}

int peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty!\n");
        return 1;
    }else{
        return stack->item[stack->top];
    }
}

void showStack(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty!\n");
        return;
    }

    printf("===Stack Data===\n");
    for(int i = 0; i <= stack->top; i++){
        printf("Index %d => %d\n",i,stack->item[i]);
    }
}

