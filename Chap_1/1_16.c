// Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrary
// long input lines, and as much as possible of the text.
//to be solved !!! erro when inputing array longer than 24 !!! 

#include <stdio.h>
#include <stdlib.h>
int getLine(char *s)
{
	int i,c;
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')	{
		s[i] = c;
		i++;
		s = realloc(s, (i+1) * sizeof(char));
	}
	if (c == '\n') {
		s[i] = '\n';
		s = realloc(s, (i++) * sizeof(char));				
	}
	s[i] = '\0';
	return i;
}

void copyLine(char *to, char *from)
{
	int i;
	i = 0;
	while ((*(to + i) = *(from + i)) != '\0')
		++i;			
}

int main(int argc, char const *argv[])
{
	int len, maxLen, i;	
	char *line = malloc(1 * sizeof(char));
	char *longestLine = malloc(1 * sizeof(char));
	maxLen = 0;
	while ((len = getLine(line)) > 0) {
		
		if (len > maxLen) {
			maxLen = len;
			longestLine = realloc(longestLine, maxLen * sizeof(char));
			copyLine(longestLine, line);
		}		
	}
	if (maxLen > 0)
	{	
		printf("the longest line (%d) of the input text is: ", maxLen);
		for (int i = 0; i < maxLen; ++i)
	  		printf("%c",*(longestLine + i));	 	
		printf("\n");
	}
	return 0;
}