#ifndef SOLVER_H
#define SOLVER_H
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
			if(x + 1 < width - 1 && maze[y*width+x+1] == SPACE){
				return true;}
			return false;
			break;
		case EAST:
			printf("zaczynam sprawdzac co jak zwrot to wschod\n");
                        if(y + 1 < height - 1 && maze[width*(y+1) + x] == SPACE){
                                return true;}
                        return false;
                        break;
		case SOUTH:
                        if(x - 1 >= 0 && maze[y*width+x-1] == SPACE){
                                return true;}
                        return false;
                        break;
		case WEST:
                        if(y - 1 >= 0 && maze[width*(y-1) + x] == SPACE){
                                return true;}
                        return false;
                        break;
		fprintf(stderr,"Błąd - nie można się ruszyć w zadna strone");

	}
}
bool canMoveForward(int zwr, int X, int Y){
}
bool canTurnLeft(int zwr, int X, int Y){
}
bool canGoBack(int zwr, int X, int Y){
}




#endif
