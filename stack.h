#ifndef stack_h
#define stack_h

#include <stdlib.h>
#include <stdio.h>
#include "status.h"

typedef void* STACK;
STACK stack_init_default(void);
void stack_push(STACK hStack, char data);
Status stack_pop(STACK top);
char stack_top(STACK* hStack);
void stack_destroy(STACK* stack);
void clear_keyboard_buffer(void);
Boolean isEmpty(STACK* hStack);

#endif 
