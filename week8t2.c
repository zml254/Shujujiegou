#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef struct Stack{
    char string [STACK_SIZE];
    int top;

}Stack;

Stack initStack() {
    Stack *stack;
    stack = (Stack *) malloc(sizeof(Stack));
    stack->top = -1;
    return *stack;

}

char pop(Stack *stack){

    if (stack->top == -1) {//栈空判断
        return '\0';
    }
    return stack->string[stack->top--];

}

int push(Stack *stack, char out) {
    if (stack->top == STACK_SIZE - 1) {//栈满判断
        return 0;
    }
    stack->top++;
    stack->string[stack->top] = out;
    return 1;
}

int inputString(char * string){

    printf("input String:");
    scanf("%s", string);
    if ('@' == string[strlen(string) - 1]) {
        string[strlen(string) - 1] = '\0';
        return 1;
    }
    return 0;
}


int main() {

    int n,i;
    Stack stack1 = initStack();
    Stack stack2 = initStack();
    char *string = (char *)malloc(sizeof(char) * 100);
    while (!inputString(string)) {//控制输入的字符串必须是以@结尾
    }
    n = strlen(string);
    for (i = 0; i < n / 2; i++) {//从开头和末尾同时入栈
        push(&stack1, string[i]);
        push(&stack2, string[n - i - 1]);
    }
    while (stack1.top != -1) {
        if (pop(&stack1) != pop(&stack2)) {//从栈顶一一出栈并且比较是否相同
            printf("This string isn't");
            return 0;
        }
    }
    printf("This string is");
    return 0;

}
