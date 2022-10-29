
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int checkforsimilar(char first, char second);
void answer(void);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[]) {

    int i = 0;
    int string_amount = 0;

    printf("Number of strings:\n");
    scanf("%d", &string_amount);
    clear_keyboard_buffer();
    
    for (i = 0; i < string_amount; i++) {
      printf("Enter string number %d:\n", i + 1);
      answer();
    }

    return 0;
}

void answer() {
    char temp = '\0';
    STACK string = stack_init_default();
    
    while (scanf("%c", &temp) == 1 && temp != '\n') { //takes input and checks input
        if (checkforsimilar(stack_top(string), temp) == 1) {
            stack_pop(string);
        }
        else {
            stack_push(string, temp);
        }
    }
    if (isEmpty(string)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}

int checkforsimilar(char first, char second) {
    if (first == '(' && second == ')') {
        return 1;
    }
    else if (first == '{' && second == '}') {
        return 1;
    }
    else if (first == '[' && second == ']') {
        return 1;
    }
    return 0;
}


void clear_keyboard_buffer(void)
{
    char c;
    scanf("%c", &c);
    while (c != '\n'){
        scanf("%c", &c);
    }
}
