#include "constants.h"


#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100000000 // Maximum size of the stack


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
   
    int i = 0;
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

// Function to free memory allocated for the stack
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
	//printf("sprawdzamy czy koniec blisko x %d y %d",x,y);
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
	}else{return 0;}}
	
int main(int argc, char* argv[]){
	int width = 11;
	int height = 11;
	char* maze;
	bool* visited;
	FILE* fp;
        fp = fopen("maze.txt","r");
        char c;
	int i = 0;
	int zwrot = EAST;
	int currentX = 1;//X wynosi 0 w lewym gornym rogu i rosnie idac w prawa strone
			 //
	int currentY = 1; //Y wynosi 0 w lewym gornym rogu i rosnie idac w dol ! idziemy po pojedynczych 
			  //znakach typu X P K
	Stack* directions;
        directions = createStack();
	maze = malloc(width*height*sizeof(char)+5);
	visited = malloc(width*height*sizeof(bool));
	c = ' ';
	
	 while (c != EOF){
                c = fgetc(fp);
		printf("%c",c);
                if (c == '\n')
                        {continue;}
		maze[i] = c;
		i++;

                }
	  printf("\n **Rozwiazanie**\n");
	  //printf("\n%c\n",maze[currentY*width+currentX]);
	//printf("%s\n",maze);
	//printf("%d\n",canTurnRight(width,height, EAST ,3 , 1,maze));

	if(true){ 
		while(true){
			//printf("poczatek iteracji\n");
			if(exitNear(width,currentX,currentY,maze) != 0){
			//	printf("exit near\n");
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
				push(directions,FORWARD);
			       break;	
			}
			else{
				if(canTurnRight(width,height,zwrot, currentX, currentY, maze)){
					//printf("mozna skrecic w prawo\n");
					zwrot++;
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
					push(directions,TURNRIGHT);
					push(directions, FORWARD);
					//printf("prawo\n");
					//printf("prosto\n");}
				else if(canGoForward(width,height,zwrot,currentX,currentY,maze)){
					//printf("mozna isc prosto\n");
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
					//printf("prosto\n");
					
				}
				else if(canTurnLeft(width,height,zwrot,currentX,currentY,maze)){
					//printf("mozna w lewp\n");
					zwrot--;
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
					push(directions,TURNLEFT);
					push(directions,FORWARD);
					//printf("lewo\n");
					//printf("prosto\n");
				}
				else{
					 switch(zwrot){
                                                 case NORTH:
						zwrot +=2;
                                                currentY++;
                                                break;
                                        case EAST:
						zwrot +=2;
                                                currentX--;
                                                break;
                                        case SOUTH:
						zwrot -=2;
                                                currentY--;
                                                break;
                                        case WEST:
						zwrot -=2;
                                                currentX++;
                                                break;}
                                        pop(directions);
					push(directions,BACK);
				}
				if(zwrot>4){
					zwrot %= 4;
				}	
			
			}
					
			
		}
	
	}
	printStack(directions);
	fclose(fp);
	free(maze);
	free(visited);
	destroyStack(directions);
}		

