/***********************************************************
* Exercise 1-22. Write a program to ``fold'' long input lines 
* into two or more shorter lines after the last non-blank
* character that occurs before the n-th column of input. 
* Make sure your program does something intelligent with
* very long lines, and if there are no blanks or tabs 
* before the specified column.
***********************************************************/

#include <stdio.h>
#define TAB 8
#define MAX 500
int getLine(char line[], int upLim);
int main(int argc, char const *argv[])
{
	int c, currentIndex, lim, len;
	char line[MAX];
	lim = MAX;	
	currentIndex = 0;
	while ((len = getLine(line, lim)) > 0) {
		for (int i = 0; i < len; ++i) {

			c = line[i];
			switch (c) {
				
				case '\n':
					putchar(c);
					currentIndex = 0;
				break;

				case '\t':
					currentIndex += TAB - currentIndex % TAB;
					if (currentIndex >= 18) {
						putchar('\n');
						currentIndex = 0;
					}
					else putchar(c);				
				break;

				case ' ':
					currentIndex++;
					if (currentIndex >= 18) {
						putchar('\n');
						currentIndex = 0;
					} 
					else putchar(c);
				break;

				default:
					currentIndex++;
					putchar(c);
			}
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
