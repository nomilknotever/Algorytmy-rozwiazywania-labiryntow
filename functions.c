
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#define WALL X
#define ENTER P
#define EXIT K
#define SPACE ' ' 
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

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
		fprintf(stderr,"Błąd - nie można się ruszyć w zadna strone");

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
                fprintf(stderr,"Błąd - nie można się ruszyć w zadna strone");
	
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
                fprintf(stderr,"Błąd - nie można się ruszyć w zadna strone");
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
	return 0;

}





