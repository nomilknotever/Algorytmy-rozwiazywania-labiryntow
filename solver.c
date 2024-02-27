#include "functions.c"
#include "stack.c"
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

				}		
			}
		}
	
	}
	fclose(fp);
	free(maze);
	free(visited);
	return 0;}
