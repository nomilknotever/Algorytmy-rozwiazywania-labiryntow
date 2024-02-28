
#ifndef STACK_H
#define STACK_H
typedef struct Stack;
Stack* createStack();
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
void printStack(Stack* stack);
void destroyStack(Stack* stack);
#endif
