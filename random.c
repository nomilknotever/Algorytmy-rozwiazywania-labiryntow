#include "constants.h"
#include "functions.h"
int main(void){
	int randomDirection;
	srand(time(NULL));
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
	  printf("\n **Solution**\n");
	 
	if(true){ 
		while(true){
			randomDirection = 1 + rand() % 4;
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
				push(directions,FORWARD);
			       break;	
			}
			else{
				if(canGoForward(width,height,randomDirection,currentX,currentY,maze)){
						switch(randomDirection){
						 case NORTH:

						switch(zwrot){
							case NORTH:
							push(directions,FORWARD);
							break;
							case EAST:
                                                        push(directions,TURNLEFT);
							push(directions,FORWARD);
                                                        break;
							case SOUTH:
                                                        pop(directions);
                                                        break;
							case WEST:
                                                        push(directions,TURNLEFT);
                                                        break;
							}
						
                                                currentY--;
						zwrot = NORTH;
                                                break;
                                        case EAST:
						 switch(zwrot){
                                                        case NORTH:
							push(directions,TURNRIGHT);
                                                        push(directions,FORWARD);
                                                        break;
                                                        case EAST:
                                                        push(directions,FORWARD);
                                                        break;
                                                        case SOUTH:
                                                        push(directions,TURNLEFT);
							push(directions,FORWARD);
                                                        break;
                                                        case WEST:
                                                        pop(directions);
                                                        break;}
                                                currentX++;
						zwrot = EAST;
                                                break;
                                        case SOUTH:
						 switch(zwrot){
                                                        case NORTH:
                                                        pop(directions);
                                                        break;
                                                        case EAST:
                                                        push(directions,TURNRIGHT);
                                                        push(directions,FORWARD);
                                                        break;
                                                        case SOUTH:
                                                        push(directions,FORWARD);
                                                        break;
                                                        case WEST:
                                                        push(directions,TURNLEFT);
							push(directions,FORWARD);
                                                        zwrot = WEST;
                                                        break;}
                                                currentY++;
						zwrot=SOUTH;
                                                break;
                                        case WEST:
						 switch(zwrot){
                                                        case NORTH:
                                                        push(directions,TURNLEFT);
							push(directions,FORWARD);
                                                        break;
                                                        case EAST:
                                                      	pop(directions);
                                                        break;
                                                        case SOUTH:
                                                        push(directions,TURNRIGHT);
							push(directions,FORWARD);
                                                        break;
                                                        case WEST:
                                                        push(directions,FORWARD);
							break;}
                                                        break;}
                                                currentX--;
						zwrot=SOUTH;
                                                break;}
									
		

				}}	
			}	
		}
	
	printStack(directions);
	fclose(fp);
	free(maze);
	free(visited);
	destroyStack(directions);
	return 0;}
