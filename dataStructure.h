//
// Created by saw_henry_min on 3/14/24.
//

#ifndef TEST_DATASTRUCTURE_H
#define TEST_DATASTRUCTURE_H
#define MAX_SIZE 10


//For Linked List Data Structure
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

//For Stack Data Structure
struct Stack{
    int top;
    int item[MAX_SIZE];
};

//For Single Linked List
struct Node *createSingle(int newData);
void singleInsert(struct Node **head,int Data);
void singleAppend(struct Node **head,int Data);
void singleShowData(struct Node *head);
void singleDelete(struct Node **head,int key);


//For Double Liked Lit
struct Node *createDouble(int newData);
void doubleInsert(struct Node **head,int Data);
void doubleAppend(struct Node **head,int Data);
void doubleShowData(struct Node *head);
void doubleDelete(struct Node **head,int key);
void doubleDisplayForward(struct Node *head);
void doubleDisplayBackward(struct Node *head);

//For Stack
void initializing(struct Stack *stack);
int isFull(struct Stack *stack);
void push(struct Stack *stack,int value);
int isEmpty(struct Stack *stack);
int pop(struct Stack *stack);
int peek(struct Stack *stack);
void showStack(struct Stack *stack);


#endif //TEST_DATASTRUCTURE_H
