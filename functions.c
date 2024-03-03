#include "functions.h"
#include"constants.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
    int* array; // Dynamic array to store stack elements
    int top;    // Index of the top element in the stack
}Stack;

// initialize stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (int*)malloc(MAX_SIZE * sizeof(int));
    stack->top = -1; // initialize top as -1 to indicate an empty stack
    return stack;
}

// check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// push an element onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// get the top element of the stack without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}

// print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
   
    int i = 0;
    printf("%di\n",stack->top);
    printf("%d\n",6);
    while (i <= stack->top) {
	if(stack->array[i] == FORWARD){
		int j =1;
		while (i + j <= stack->top && stack->array[i + j] == FORWARD) {
                j++;
            }
            printf("Forward %d\n", j);
            i += j;
        }
	else if(stack->array[i] == TURNRIGHT){printf("Turn right\n");
	i++;}
	else if(stack->array[i] == TURNLEFT){printf("Turn left\n");
	i++;
	}
        
    }
    printf("\n");
}

// free memory allocated for the stack
void destroyStack(Stack* stack) {
    free(stack->array);
    free(stack);
}
bool canTurnRight(int width, int height, int zwr, int x, int y, char* maze){
	;
	switch(zwr){

		case NORTH:
			if(maze[y*width+x+1] == SPACE){
				return true;}
			return false;
			break;
		case EAST:
			
                        if(maze[width*(y+1) + x] == SPACE){
                                return true;}
                        return false;
                        break;
		case SOUTH:
                        if(maze[y*width+x-1] == SPACE){
                                return true;}
                        return false;
                        break;
		case WEST:
                        if(maze[width*(y-1) + x] == SPACE){
                                return true;}
                        return false;
                        break;
		

	}
}
bool canGoForward(int width, int height, int zwr, int x, int y, char* maze){
	 	switch(zwr){
		case NORTH:
                        if( maze[(y-1)*width+x] == SPACE){
                                return true;}
                        return false;
                        break;
                case EAST:
                        
                        if(maze[width*y + x + 1] == SPACE){
                                return true;}
                        return false;
                        break;
                case SOUTH:
                        if(maze[(y+1)*width+x] == SPACE){
                                return true;}
                        return false;
                        break;
                case WEST:
                        if(maze[width*y + x -1] == SPACE){
                                return true;}
                        return false;
                        break;
                
	
}}
bool canTurnLeft(int width, int height, int zwr, int x, int y, char* maze){
	 	
		switch(zwr){
		case NORTH:
                        if(maze[y*width+x-1] == SPACE){
                                return true;}
                        return false;
                        break;
                case EAST:
                       
                        if(maze[width*(y-1) + x] == SPACE){
                                return true;}
                        return false;
                        break;
                case SOUTH:
                        if(maze[y*width+x+1] == SPACE){
                                return true;}
                        return false;
                        break;
                case WEST:
                        if(maze[width*(y+1) + x] == SPACE){
                                return true;}
                        return false;
                        break;
		}}
char exitNear(int width, int x, int y, char* maze){
	if(maze[(y-1)*width + x] == 'K'){//up
		return NORTH;
	} 
	else if(maze[y*width+x+1] == 'K'){//right
		return EAST;
	}
	else if(maze[(y+1)*width+x] == 'K'){//down
		return SOUTH;
	}
	else if(maze[y*width+x-1] == 'K'){ // left
		return WEST;
	}else{return 0;}}


