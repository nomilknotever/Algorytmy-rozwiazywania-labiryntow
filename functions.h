#ifndef FUNCTIONS_H // Header guard
#define FUNCTIONS_H
#include<stdbool.h>
bool canTurnRight(int width, int height, int zwr, int x, int y, char* maze);
bool canTurnLeft(int width, int height, int zwr, int x, int y, char* maze);
bool canGoForward(int width, int height, int zwr, int x, int y, char* maze);
bool canGoBack(int width, int height, int zwr, int x, int y, char* maze);
char exitNear(int width, int x, int y, char* maze);
#endif // FUNCTIONS_H
