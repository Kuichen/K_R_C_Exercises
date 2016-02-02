// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to
// the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic
// parameter?
#include <stdio.h>
#define TAB 8
#define MAX 100
int toNextTab(int charGot, int tabStep);
int getLine(char a[], int lim);
int main(int argc, char const *argv[])
 {
 	int len;
 	char outLine[MAX];
 	while ((len = getLine(outLine, MAX)) >0) {

	 	for (int i = 0; i < len; ++i)
			printf("%c", outLine[i]); 		
 	}
 	return 0;
 }

int toNextTab(int gots, int step) {
	return step - (gots % step);
}

int getLine(char a[], int lim) {

	int c,i,j,counter,blanks,tabStep;
	counter = j = 0;
	tabStep = TAB;
 	for (i = 0; i<lim-1 && (c = getchar()) != '\n' && c != EOF; ++i) {

		if (c != '\t') {
			a[i] = c;
			counter++;
			continue;
		}

		blanks = toNextTab(counter, tabStep);
		counter = 0;		
		printf("blanks is %d\n", blanks);
		for (int j = 0; j < blanks; ++j) {
			a[i] = ' ';
			if (j == blanks -1) // no increment at last time, cuz it'll be increment in the upper loop.
				continue;
			++i;
		}
	}

	if (c == '\n') {
		a[i] = c;
		++i;
	}

	a[i] = '\0';
	return i;
}