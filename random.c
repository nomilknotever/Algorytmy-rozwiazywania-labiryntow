#include "constants.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
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
    bool solved = false;
    int currentX = 1;
    int currentY = 1;
    Stack* directions;
    directions = createStack();
    maze = malloc(width * height * sizeof(char) + 5);
    visited = malloc(width * height * sizeof(bool));
    c = ' ';

    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
        if (c == '\n')
            continue;
        maze[i] = c;
        i++;
    }
    printf("\n **Solution**\n");

    if (true) {
        while (!solved) {
            randomDirection = 1 + rand() % 4;
            if (exitNear(width, currentX, currentY, maze) != 0) {
                switch (exitNear(width, currentX, currentY, maze)) {
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
                        break;
                }
                push(directions, FORWARD);
		solved = true;
                break;
            } else {
                if (canGoForward(width, height, randomDirection, currentX, currentY, maze)) {
                    switch (randomDirection) {
                        case NORTH:
                            switch (zwrot) {
                                case NORTH:
                                    push(directions, FORWARD);
                                    break;
                                case EAST:
                                    push(directions, TURNLEFT);
                                    push(directions, FORWARD);
                                    break;
                                case SOUTH:
                                    push(directions, BACK);
                                    break;
                                case WEST:
                                    push(directions, TURNLEFT);
                                    break;
                            }
                            currentY--;
                            zwrot = NORTH;
                            break;
                        case EAST:
                            switch (zwrot) {
                                case NORTH:
                                    push(directions, TURNRIGHT);
                                    push(directions, FORWARD);
                                    break;
                                case EAST:
                                    push(directions, FORWARD);
                                    break;
                                case SOUTH:
                                    push(directions, TURNLEFT);
                                    push(directions, FORWARD);
                                    break;
                                case WEST:
                                    push(directions, BACK);
                                    break;
                            }
                            currentX++;
                            zwrot = EAST;
                            break;
                        case SOUTH:
                            switch (zwrot) {
                                case NORTH:
                                    push(directions, BACK);
                                    break;
                                case EAST:
                                    push(directions, TURNRIGHT);
                                    push(directions, FORWARD);
                                    break;
                                case SOUTH:
                                    push(directions, FORWARD);
                                    break;
                                case WEST:
                                    push(directions, TURNLEFT);
                                    push(directions, FORWARD);
                                    zwrot = WEST;
                                    break;
                            }
                            currentY++;
                            zwrot = SOUTH;
                            break;
                        case WEST:
                            switch (zwrot) {
                                case NORTH:
                                    push(directions, TURNLEFT);
                                    push(directions, FORWARD);
                                    break;
                                case EAST:
                                    push(directions, BACK);
                                    break;
                                case SOUTH:
                                    push(directions, TURNRIGHT);
                                    push(directions, FORWARD);
                                    break;
                                case WEST:
                                    push(directions, FORWARD);
                                    break;
                            }
                            currentX--;
                            zwrot = WEST;
                            break;
                    }
                }
            }
        }
    }
	printf("gegeg");
    printStack(directions);
    fclose(fp);
    free(maze);
    free(visited);
    destroyStack(directions);
    return 0;
}

