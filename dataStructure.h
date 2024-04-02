//
// Created by saw_henry_min on 3/14/24.
//

#ifndef C_ASSIGNMENT_DATASTRUCTURE_H
#define C_ASSIGNMENT_DATASTRUCTURE_H
#define MAX_SIZE 10


//For Linked List Data Structure
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

//For Stack DS(Array Implement)
struct Stack{
    int top;
    int item[MAX_SIZE];
};

// For Stack DS(Linked List Implement)
struct StackLL{
    struct Node* top;
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

//For Stack with Array
void initializing(struct Stack *stack);
int isFull(struct Stack *stack);
void push(struct Stack *stack,int value);
int isEmpty(struct Stack *stack);
int pop(struct Stack *stack);
int peek(struct Stack *stack);
void showStack(struct Stack *stack);


//For Stack with Linked List
void initializeStack(struct StackLL* stack);
int emptyStack(struct StackLL* stack);
void pushStack(struct StackLL* stack,int data);
int popStack(struct StackLL* stack);
int peekStack(struct StackLL* stack);
void displayStack(struct StackLL* stack);

#endif //C_ASSIGNMENT_DATASTRUCTURE_H
