/***********************************************
* Exercise 1-23. Write a program to remove all 
* comments from a C program. Don't forget to 
* handle quoted strings and character 
* constants properly. C comments don't nest.
***********************************************/

#include <stdio.h>

int main(void)
{
  int c,prevc;
	int code = 1;
	int slash = 0;
	int prevcomment = 0;
	int quote = 0;

	while ((c=getchar()) != EOF) {
		if ((c == '\'' || c == '"') && code) {
			quote = !quote;
			/* make sure we dont output prevc coming out
			of a quote */
			prevcomment = 1;
		}
		if (!quote) {
			if (prevc == '/' && c == '*') { /* comment found */
				code = 0;
			}
			if (prevc == '*' && c == '/') { /* out of comment */
				code = 1;
				prevcomment = 1;
			}
		}
		if (prevc == '/' && c != '*' && !prevcomment)
			putchar(prevc);
		if (code && !((c == '/') && !quote)) {
			prevcomment = 0;
			putchar(c);						
		}
		prevc = c;
	}
	
	return 0;
}