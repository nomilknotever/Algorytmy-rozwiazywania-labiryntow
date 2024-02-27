#include <stdio.h>
#include <string.h>
int main(){

	FILE* fp;
	fp = fopen("maze.txt","r");
	char c;
	
	 while (c != EOF){
    	c = fgetc(fp); 
	if (c == '\n') {continue;}

        printf ("%c", c); 
         
    } 
return 0;
}
