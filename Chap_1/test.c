#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	char line[1];
	line[0] = 'a';
	line[1] = 'b';
	char *p = line;
	printf("%c %c\n", *p, *(p+1));
	return 0;
}