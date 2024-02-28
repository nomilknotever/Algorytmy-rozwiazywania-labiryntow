#include "constants.h"


#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1000 // Maximum size of the stack


typedef struct {
    int* array; // Dynamic array to store stack elements
    int top;    // Index of the top element in the stack
} Stack;

// Function to initialize a stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (int*)malloc(MAX_SIZE * sizeof(int));
    stack->top = -1; // Initialize top as -1 to indicate an empty stack
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to get the top element of the stack without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}

// Function to print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to free memory allocated for the stack
void destroyStack(Stack* stack) {
    free(stack->array);
    free(stack);
}
bool canTurnRight(int width, int height, int zwr, int x, int y, char* maze){
	printf("sprawdzam czy moge skrecic w prawo\n");
	switch(zwr){

		case NORTH:
			if(maze[y*width+x+1] == SPACE){
				return true;}
			return false;
			break;
		case EAST:
			printf("zaczynam sprawdzac co jak zwrot to wschod\n");
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
                        printf("zaczynam sprawdzac co jak zwrot to wschod\n");
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
                        printf("zaczynam sprawdzac co jak zwrot to wschod\n");
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
	if(maze[(y-1)*width + x] == 'K'){//gora
		return NORTH;
	} 
	else if(maze[y*width+x+1] == 'K'){//prawo
		return EAST;
	}
	else if(maze[(y+1)*width+x] == 'K'){//dol
		return SOUTH;
	}
	else if(maze[y*width+x-1] == 'K'){ // lewp
		return WEST;
	}
	

}
int main(int argc, char* argv[]){
	printf("help");
	int width = 7;
	int height = 7;
	char* maze;
	bool* visited;
	FILE* fp;
        fp = fopen("maze.txt","r");
        char c;
	int i = 0;
	int zwrot = EAST;
	int currentX = 0;//X wynosi 0 w lewym gornym rogu i rosnie idac w prawa strone
	int currentY = 1; //Y wynosi 0 w lewym gornym rogu i rosnie idac w dol ! idziemy po pojedynczych 
			  //znakach typu X P K
	Stack* directions;
        directions = createStack();

	maze = malloc(width*height*sizeof(char)+5);
	visited = malloc(width*height*sizeof(bool));
	c = ' ';
	 while (c != EOF){
                c = fgetc(fp);
                if (c == '\n')
                        {continue;}
		maze[i] = c;
		i++;

                }
	
	printf("%d",canTurnRight(width,height, EAST ,3 , 1,maze));

	if(true){ 
		while(true){
			if(exitNear(width,currentX,currentY,maze) != 0){
				switch(exitNear(width,currentX,currentY,maze)){
					case NORTH:
						currentY--;
						break;
					case EAST:
						currentX++;
						break;
					case SOUTH:
						currentY++;
						break;
					case WEST:
						currentX--;
						break;}
			}
			else{
				if(canTurnRight(width,height,zwrot, currentX, currentY, maze)){
					zwrot++;
					push(directions,TURNRIGHT);}
				else if(canGoForward(width,height,zwrot,currentX,currentY,maze)){
					switch(zwrot){
						 case NORTH:
                                                currentY--;
                                                break;
                                        case EAST:
                                                currentX++;
                                                break;
                                        case SOUTH:
                                                currentY++;
                                                break;
                                        case WEST:
                                                currentX--;
                                                break;}
					push(directions,FORWARD);
					
					}
				//else if(canTurnLeft(width,height,zwrot,currentX,currentY,maze)){
				//	zwrot--;
				//	push(directions,TURNLEFT);
				//}
				else{
					 switch(zwrot){
                                                 case NORTH:
                                                currentY++;
                                                break;
                                        case EAST:
                                                currentX--;
                                                break;
                                        case SOUTH:
                                                currentY--;
                                                break;
                                        case WEST:
                                                currentX++;
                                                break;}
                                        pop(directions);
				}
				}
					
			
		}
	
	}
	fclose(fp);
	free(maze);
	free(visited);
	destroyStack(directions);
}		

