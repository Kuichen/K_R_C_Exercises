#include <stdio.h>
int main(int argc, char const *argv[])
{
	int c;

	while ((c = getchar()) != EOF)
	{
		putchar(c);	
		printf("\nthe statement 'c == EOF' returns 0\n");
	}
		printf("the statement 'c == EOF' returns 1\n");
	return 0;		
}