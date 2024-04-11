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


// For Stack DS(Array Implement)
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



// For Stack DS(Linked List Implement)
void initializeStack(struct StackLL* stack){
    stack->top = NULL;
}

int emptyStack(struct StackLL* stack){
    return (stack->top == NULL);
}

void pushStack(struct StackLL* stack,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof (struct Node));
    if(newNode == NULL){
        printf("Memory Allocation is failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Node %d pushed to stack\n",data);
}

int popStack(struct StackLL* stack){
    if(emptyStack(stack)){
        printf("Stack underflow!\n");
        exit(1);

    }else {

        struct Node *temp = stack->top;
        int data = temp->data;
        stack->top = temp->next;
        free(temp);
        return data;
    }
}

int peekStack(struct StackLL* stack){
    if(emptyStack(stack)){
        printf("Stack underflow!\n");
        exit(1);
    }

    struct Node *temp = stack->top;
    int data = temp->data;
    return data;
}

void displayStack(struct StackLL* stack){
    printf("Elements present in stack : ");
    while (stack->top != NULL){
        printf("%d ",stack->top->data);
        stack->top = stack->top->next;
    }
    printf("\n");
}



// For Queue DS(Array Implement)
int queue[MAX_SIZE], front = -1, rear = -1;

void enQueue(int data){
    if(rear == 0) {
        printf("Queue is full!\n");
    }else{
        if(front == -1) {
            front = MAX_SIZE - 1;
            rear = MAX_SIZE;
        }

        queue[--rear] = data;
        printf("Enqueue Data : %d\n",data);
    }
}

int deQueue(){
    int data = -1;
    if(front == -1) {
        printf("Queue is empty!\n");
    }else{
        data = queue[front];
        printf("Dequeue Data : %d\n",data);
        front--;

        if(front < rear){
            front = rear = -1;
        }

    }
    return data;
}

void display(){
    if(rear == -1) {
        printf("Queue is empty!\n");
    }else{
        printf("\nFront -> %d\n",front);
        printf("Queue elements are : ");
        for(int i = rear; i <= front; i++){
            printf("%d ",queue[i]);
        }
        printf("\nRear -> %d\n",rear);
    }
    printf("\n");
}



// For Queue DS(Linked List Implement)
struct QNode* newNode(int key){
    struct QNode *Node = (struct QNode*)malloc(sizeof (struct QNode));
    Node->key = key;
    Node->next = NULL;
    return Node;

}

struct Queue* createQueue(){
    struct Queue *q = (struct Queue*)malloc(sizeof (struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void EnQueue(struct Queue *q,int key){

    struct QNode *Node = newNode(key);

    if(q->rear == NULL) {
        q->front = q->rear = Node;
        return;
    }

    q->rear->next = Node;
    q->rear = Node;

}

void DeQueue(struct Queue *q){

    if(q->front == NULL)
        return;


    struct QNode *temp = q->front;

    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;


    free(temp);
}