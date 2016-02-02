//Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.

#include <stdio.h>
#define LINEMAX 1000

int getLine(char line[], int upLim);
void copyArray(char to[], char from[]);


int main(int argc, char const *argv[])
{
	int len;	
	char currentLine[LINEMAX], outLine[LINEMAX];
	while ((len = getLine(currentLine, LINEMAX)) > 0) {
		if (len > 80) {			
			copyArray(outLine, currentLine);
			printf("this line: \"");
			for (int i = 0; i < len; ++i)
				printf("%c",outLine[i]);			
			printf("\" has length greater than 80 \n ...\nwaiting for new input...\n");
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
		a[i] == '\n';
		i++;
	}
	a[i] = '\0';
	return i;
}

void copyArray(char to[], char from[])
{
	for (int i = 0; (to[i] = from[i]) != '\0'; ++i)
		;
}