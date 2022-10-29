/**********************************************************************
Program: Daily 7 Parenthesis
Author: Aryan Puttur
Date: 2/28/22
Time spent: 3 hours
Purpose: The purpose of this program is to take an input from keyboard as a series of string consisting of parenthesis style characters and
returns if the string is valid or not depending on if it is an empty string, ff string A is correct and string B is correct then string AB is
correct, If A is correct then (A), [A] and {A} are all correct.
***********************************************************************/

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
