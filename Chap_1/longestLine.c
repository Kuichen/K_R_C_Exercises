// while (there's another line)
// if (it's longer than the previous longest)
// (save it)
// (save its length)
// print longest line

#include <stdio.h>
#define LINEMAX 1000

int getLine(char line[], int upLim);
void copyArray(char to[], char from[]);


int main(int argc, char const *argv[])
{
	int currentLen, maxLen;
	maxLen = 0;
	char currentLine[LINEMAX], maxLine[LINEMAX];
	while ((currentLen = getLine(currentLine, LINEMAX)) > 0) {
		if (currentLen > maxLen) {
			maxLen = currentLen;
			copyArray(maxLine, currentLine);
		}
	}
	if (maxLen > 0)
			printf("the following Line: \"");
			for (int i = 0; i < maxLen; ++i)
				printf("%c", maxLine[i]);
			printf("\" is with its %d length the longest line fetched from the input \n", maxLen);
		
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

void copyArray(char to[], char from[])
{
	for (int i = 0; (to[i] = from[i]) != '\0'; ++i)
		;
}