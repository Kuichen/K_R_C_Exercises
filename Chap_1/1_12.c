// Exercise 1-12. Write a program that prints its input one word per line.
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int c, len;
	len = 0;
	while ((c = getchar()) != EOF) {
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') 
			putchar(c);	
		
		else 
			printf("\n");
	}
	return 0;
}