// Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the
// histogram with the bars horizontal; a vertical orientation is more challenging.
#include <stdio.h>
int main(int argc, char const *argv[])
 {
	int c, len;
	len = 0;
	while ((c = getchar()) != EOF) {
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
			//putchar(c);			
			++len;
		}
		else if (len == 0)				
			printf("\n");
		else {
			printf("length of the word: ");
			for (int i = 0; i <= len; ++i) {
				if (i < len)
					printf("-");
				else printf("\n");
			}
			len = 0;
		}	
	}
	return 0;
 } 