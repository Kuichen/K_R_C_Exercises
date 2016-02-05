/***********************************************
* Exercise 1-23. Write a program to remove all 
* comments from a C program. Don't forget to 
* handle quoted strings and character 
* constants properly. C comments don't nest.
***********************************************/

#include <stdio.h>
#define MAX 500
#define INCOMMENT 1
#define OUTCOMMENT 0

int getLine(char [], int);

int main(int argc, char const *argv[])
{
	int c, nextC, lim, len, state;
	state = OUTCOMMENT;	
	lim = MAX;
	char line[lim];
	while ((len = getLine(line,lim)) > 0) {
		for (int i = 0; i < len; ++i) {
			
			c = line[i];
			if (i < len-1)
				nextC = line[i+1];
			if (state == OUTCOMMENT && c == '/' && nextC == '*') {
				i++;
				state = INCOMMENT;
				continue;
			}
			if (state == INCOMMENT && c == '*' && nextC == '/') {
				i++;
				state = OUTCOMMENT;
				continue;
			}
			if (state == OUTCOMMENT) 
				putchar(c);			
		}
	} 	
	return 0;
}


int getLine(char a[], int lim)
{
	int c, i;
	for (i = 0; i < lim-1 && (c = getchar()) !=EOF && c != '\n'; ++i)
		a[i] = c;
	if (c == '\n') {
		a[i] = '\n';
		i++;
	}
	a[i] = '\0';
	return i;
}
