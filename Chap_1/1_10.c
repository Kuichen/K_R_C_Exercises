// Exercise 1-10. Write a program to copy its input to its output, 
// replacing each tab by \t, each backspace by \b,
// and each backslash by \\. This makes tabs and 
// backspaces visible in an unambiguous way.
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int c;
	while ((c = getchar()) != EOF) 
	{
		switch(c) 
		{
			case ' ' :
				printf(" \\b ");
				break;
			case '\t' :
				printf(" \\t ");
				break;
			case '\\' :
				printf(" \\""\\ ");
				break;
		}
		if (c != ' ' && c!= '\t' && c!= '\\')
			putchar(c);
	}
	return 0;
}