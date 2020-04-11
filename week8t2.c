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

    if (stack->top == -1) {//ջ���ж�
        return '\0';
    }
    return stack->string[stack->top--];

}

int push(Stack *stack, char out) {
    if (stack->top == STACK_SIZE - 1) {//ջ���ж�
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
    while (!inputString(string)) {//����������ַ�����������@��β
    }
    n = strlen(string);
    for (i = 0; i < n / 2; i++) {//�ӿ�ͷ��ĩβͬʱ��ջ
        push(&stack1, string[i]);
        push(&stack2, string[n - i - 1]);
    }
    while (stack1.top != -1) {
        if (pop(&stack1) != pop(&stack2)) {//��ջ��һһ��ջ���ұȽ��Ƿ���ͬ
            printf("This string isn't");
            return 0;
        }
    }
    printf("This string is");
    return 0;

}
