#include "solver.h"
int main(int argc, char** argv){
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

      printf("problem z alokacja pamieci"); 
	maze = malloc(width*height*sizeof(char)+5);
	visited = malloc(width*height*sizeof(bool));
	 while (c != EOF){
                c = fgetc(fp);
                if (c == '\n')
                        {continue;}
		maze[i] = c;
		i++;

                }
	if(strcmp(argv[1],"righth") == 0){
		//WALL FOLLOWING
		/*Czy w jakims kierunku Jest K? jak tam to idz tam
		 * Czy można ruszyć sie w prawo? Jak tak to rusz sie ... prosto .. w lewo .... do tylu
		 */

		
	}printf(" w solver.c zzaraz aktywuje funckje canTurnRight");
	printf("%d",canTurnRight(width,height, EAST ,3 , 1,maze));
	fclose(fp);
	free(maze);
	free(visited);
	return 0;}
