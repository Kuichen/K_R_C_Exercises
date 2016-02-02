// Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to write a program that
// reverses its input a line at a time.

#include <stdio.h>
#define LINEMAX 1000

int getLine(char line[], int upLim);
void copyArray(char to[], char from[]);
void revArray(char revA[], char srcA[], int len);


int main(int argc, char const *argv[])
{
	int len;	
	char currentLine[LINEMAX], outLine[LINEMAX];
	while ((len = getLine(currentLine, LINEMAX)) > 0) {
		revArray(outLine, currentLine, len);
		for (int i = 0; i < len-1; ++i)
			printf("%c",outLine[i]);	
						
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

void revArray(char revA[], char srcA[], int len) {
	int j;
	j = len-2;
	for (int i = 0; i < len-1; ++i) {
		revA[j] = srcA[i];
		--j;
	}
}
