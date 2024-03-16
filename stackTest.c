//
// Created by saw_henry_min on 3/15/24.
//

#include "stdio.h"
#include "dataStructure.h"

int main() {
    struct Stack stack;
    initializing(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printf("\nData %d is pop from index %d\n", pop(&stack), stack.top);
    printf("Now top data of stack is %d at index %d\n\n", peek(&stack), stack.top);

    push(&stack, 50);
    push(&stack, 60);
    push(&stack, 70);

    printf("\nData %d is pop from index %d\n", pop(&stack), stack.top);
    printf("Now top data of stack is %d at index %d\n\n", peek(&stack), stack.top);

    push(&stack, 80);
    printf("Now top data of stack is %d at index %d\n\n", peek(&stack), stack.top);


    return 0;

}

