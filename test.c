#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(void){
	srand(time(NULL));
	printf("%d\n",1 + rand() % 4);
	return 0;

}
