// Exercise 1-8. Write a program to count blanks, tabs, and newlines.
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int nb, nt, nn, c;
	nb = nt = nn = 0;
	while ((c = getchar()) != EOF) 
	{
		switch(c) 
		{
			case ' ' :
				++nb;
				break;
			case '\t' :
				++nt;
				break;
			case '\n' :
				++nn;
				break;
		}		
	}
	printf("there are %d blanks, %d tabs and %d newlines"
		 " in the aboveing input.\n",nb,nt,nn);		
	return 0;
}