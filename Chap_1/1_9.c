/* Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a
single blank. */
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int c, lastC;	
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' && lastC == ' ')
		continue;
		putchar(c);
		lastC = c;
	}
	return 0;
}