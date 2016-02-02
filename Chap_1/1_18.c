// Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely
// blank lines.
#include <stdio.h>
#define LINEMAX 1000

int adjustLine(char line[], int upLim);
void copyArray(char to[], char from[], int len);
void revArray(char revA[], char srcA[], int len);
int countBlanks(char srcA[], int len);
int getLine(char a[], int lim);


int main(int argc, char const *argv[])
{
	int len, newLen;	
	char currentLine[LINEMAX], outLine[LINEMAX];
	while ((len = getLine(currentLine, LINEMAX)) > 0) {
		copyArray(outLine, currentLine, (newLen = countBlanks(currentLine, len)));
		for (int i = 0; i < newLen; ++i)		
			printf("%c",outLine[i]);
		//printf("\n%d %d", newLen, len);		
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

void copyArray(char to[], char from[], int len)
{
	for (int i = 0; i < len; ++i)
		to[i] = from[i]; 
}

void revArray(char revA[], char srcA[], int len) {
	int j;
	j = len-1;
	for (int i = 0; i < len; ++i) {
		revA[j] = srcA[i];
		j--;
	}
}

int countBlanks(char srcA[], int len) {
	int i;
	i = len -2;
	while (srcA[i] == ' ' || srcA[i] == '\t') 
		i--;
	return ++i;
}