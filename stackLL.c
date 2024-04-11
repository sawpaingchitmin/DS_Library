//
// Created by saw_henry_min on 4/1/24.
//

#include "stdio.h"
#include "dataStructure.h"


int main(){

    struct StackLL* stack;
    initializeStack((struct StackLL*) &stack);
    pushStack((struct StackLL*) &stack,10);
    pushStack((struct StackLL*) &stack,40);
    pushStack((struct StackLL*) &stack,30);

    printf("Node %d popped from stack\n",popStack((struct StackLL*) &stack));

    printf("Top element is %d\n", peekStack((struct StackLL*) &stack));

    displayStack((struct StackLL *) &stack);



    return 0;
}
