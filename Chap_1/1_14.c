//Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
#include <stdio.h>
int main(int argc, char const *argv[])
 {
	int c, i;
	i = 0;
	int characters[52];
	for (int i = 0; i < 52; ++i)
		characters[i] = 0;
			

	while ((c = getchar()) != EOF) 
	{

		if (c >= 'A' && c <= 'Z') 		
			++characters[c-'A'];			
		

		else if (c >= 'a' && c <= 'z') 
		{
			i = (c - 'a');
			++characters[i+26];			
		}		
	}

	for (int i = 0; i < 26; ++i)
	{
		// printf("%d ", characters[i]);
		c = 'A' + i;
		printf ("%c ", c);
		if (characters[i] == 0)
		{
		 	printf("\n");
		 	continue;
		}
		for (int j = 0; j < characters[i]; ++j)
		{
			if ((characters[i] - j) == 1) 
				printf("-\n");



			else printf("-");
		}
	}

	for (int i = 26; i < 52; ++i)
	{
		c = 'a' + i -26;
		printf ("%c ", c);
		if (characters[i] == 0)
		{
		 	printf("\n");
		 	continue;
		}

		for (int j = 0; j < characters[i]; ++j)
		{
			if ((characters[i] - j) == 1) 
				printf("-\n");
			else printf("-");
		}
	}
	return 0;
 } 