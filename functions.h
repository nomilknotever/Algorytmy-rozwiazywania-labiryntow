#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<stdbool.h>
typedef struct Stack Stack;
// Function declarations for maze solving
bool canTurnRight(int width, int height, int zwr, int x, int y, char* maze);
bool canTurnLeft(int width, int height, int zwr, int x, int y, char* maze);
bool canGoForward(int width, int height, int zwr, int x, int y, char* maze);
bool canGoBack(int width, int height, int zwr, int x, int y, char* maze);
char exitNear(int width, int x, int y, char* maze);

// Function declarations for the stack


Stack* createStack();
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
void printStack(Stack* stack);
void destroyStack(Stack* stack);

#endif // FUNCTIONS_H

