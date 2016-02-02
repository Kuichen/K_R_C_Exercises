/*********************************************************************
 
	 Exercise 1-21. Write a program entab that replaces strings 
	 of blanks by the minimum number of tabs and blanks to achieve 
	 the same spacing. Use the same tab stops as for detab. When 
	 either a tab or a single blank would suffice to reach a tab 
	 stop, which should be given preference?

**********************************************************************/

#include <stdio.h>
#define MAX 500
#define TAB 8

int getLine(char[],int);
int neededBlks (int index, int blks, int tabStop);

int main(int argc, char const *argv[])
{
	int len, lim, blksCounter, isFirstBls, tabStop;
	tabStop = TAB;
	char inputLine[MAX], lastC;
	lim = MAX;
	blksCounter = 0;
	while((len = getLine(inputLine, lim)) > 0) {
		lastC = 'o'; //can be any character but blank
		for (int i = 0; i < len; ++i) {
			if (inputLine[i] != ' ') {
				if (lastC == ' ') {
					int tabs, blks;
					blks = neededBlks(i-1, blksCounter, tabStop);
					tabs = (blksCounter - blks + 7) / tabStop; // 
					for (int j = 0; j < tabs; ++j)
						putchar('\t');
					for (int j = 0; j < blks; ++j)
						putchar(' ');				
					blksCounter = blks = tabs = 0;					
				}						
				putchar(inputLine[i]);
			}
			else blksCounter++;
			lastC = inputLine[i];
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
		a[i] = c;
		++i;
	}
	a[i] = '\0';
	return i;
}

// index is the index of the last blanks
int neededBlks (int index, int blks, int tabStop) {
	int n;
	n = index % tabStop;
	if (n >= blks) 
		return blks;	
	return (++n);
}