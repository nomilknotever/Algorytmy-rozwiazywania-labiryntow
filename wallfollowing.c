#include "constants.h"
#include "functions.c"
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
	  printf("\n **Solution**\n");
	 
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
				push(directions,FORWARD);
			       break;	
			}
			else{
				if(canTurnRight(width,height,zwrot, currentX, currentY, maze)){
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
					push(directions, FORWARD);}

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
				else if(canTurnLeft(width,height,zwrot,currentX,currentY,maze)){
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
