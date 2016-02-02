#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 10

int getLine(char a[], int lim);
void copyArray(char to[], char from[]);

int main(int argc, char const *argv[])
{
	char temp[MAXLINE], currentLine[MAXLINE];
	char *longestLine = malloc(1 * sizeof(char));
	int gotWholeLine, currentLen, maxLen, getLineLim;
	gotWholeLine = currentLen = maxLen = 0;
	getLineLim = MAXLINE;
	while ((currentLen = getLine(currentLine, getLineLim)) == getLineLim) {
    	
    	// if 
    	if (currentLine[getLineLim - 1] == '\n') {

    	} 
	}

	return 0;
}

int getLine(char a[], int lim)
{
	int c;
	len = 0;
	for (int i=0; i < lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i) {
		a[i] = c;
		++i;	
	}
	if (c == '\n'){
		a[i] == c;
		++i;
	}
	else if (c == EOF)
	{
		a[i] == '\n';
		++i;
	}
	return i;
}

void copyArray(to[], from[]) {
	for (int i=0; (to[i]=from[i]) !='\0'; ++i) 
		;	
}