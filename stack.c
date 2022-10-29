#include "stack.h"

typedef struct node {
    char data;
    struct node* next;
}stackNode;

typedef struct stack {
    stackNode* top;
}Stack;


STACK stack_init_default(void) {
    Stack* temp = NULL;
    temp = (Stack*)malloc(sizeof(Stack));

    if (temp == NULL)
    {
        printf("Failed to allocate stack\n");
        exit(1);
    }
    temp->top = NULL;
    return temp;
}


Status stack_pop(STACK hStack) {

    Stack* pStack = (Stack*)hStack;
    if (pStack == NULL) {
        return FAILURE;
    }
    else {
        stackNode* temp;
        temp = pStack->top;
        pStack->top = pStack->top->next;

        free(temp);
        return SUCCESS;
    }
}


Boolean isEmpty(STACK* hStack) {
    if (stack_top(hStack) == '\0') {
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void stack_push(STACK hStack, char data) {
    Stack* pStack = (Stack*)hStack;
    stackNode* new = (stackNode*)malloc(sizeof(stackNode));

    new->data = data;
    new->next = pStack->top;
    pStack->top = new;
}


void stack_destroy(STACK* phStack) {
    Stack* pStack = (Stack*)*phStack;
    stackNode* temp;
    while (pStack->top != NULL) {
        temp = pStack->top;
        pStack->top = pStack->top->next;
        free(temp);
    }
    free(pStack);
    *phStack = NULL;
}

char stack_top(STACK* hStack){
    char temp;
    Stack* pTemp = (Stack*)hStack;
    if (pTemp->top == NULL) {
        return '\0';
    }
    else{
        temp = pTemp->top->data;
        return temp;
    }
}
