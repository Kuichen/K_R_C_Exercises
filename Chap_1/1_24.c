/**************************************************************
* Exercise 1-24. Write a program to check a C program 
* for rudimentary syntax errors like unmatched parentheses,
* brackets and braces. Don't forget about quotes, both single 
* and double, escape sequences, and comments. (This program is 
* hard if you do it in full generality.)
**************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX 500
#define NOERR 1
#define ERR 0

int getLine (char [], int);
int main(int argc, char const *argv[])
{
	char pStack[MAX/5], brackStack[MAX/5], braceStack[MAX/5], line[MAX];
	int c,len,lim,state;	
	lim = MAX;	
	while ((len = getLine(line, lim)) > 0) {
		state = NOERR;
		int pCounter, braceCounter, brackCounter, sqCounter, dqCounter;
		pCounter = braceCounter = brackCounter = sqCounter = dqCounter = 0;		
		for (int i = 0; i < len; ++i) {
			c = line[i];
			switch (c) {

				case '}':
					--braceCounter;
					if (braceCounter < 0) {
						state = ERR;					
						printf("*ERR*: found one unpaired right brace. reading next... \n");
					}					
				break;

				case ']':
					--brackCounter;
					if (brackCounter < 0) {
						state = ERR;					
						printf("*ERR*: found one unpaired right bracket. reading next... \n");
					}						

				break;

				case ')':
					--pCounter;
					if (pCounter < 0){
						state = ERR;					
						printf("*ERR*: found one unpaired right parentheses. reading next... \n");
					}					 					
				break;
			}

			switch (c) {

				case '{':
					braceCounter++;
				break;

				case '[':
					brackCounter++;
				break;

				case '(':
					pCounter++;
				break;

				case '\'':
					sqCounter++;
				break;

				case '\"':
					dqCounter++;
				break;
			}
		}

		if (braceCounter != 0) {
			state = ERR;
			if (braceCounter > 0) 
				printf("*ERR*: totally missing %d right brace. \n", braceCounter);				
			else 
				printf("*ERR*: totally missing %d left brace. \n", abs(braceCounter));
		}

		if (brackCounter != 0) {
			state = ERR;
			if (brackCounter > 0) 
				printf("*ERR*: totally missing %d right bracket. \n", brackCounter);				
			else 
				printf("*ERR*: totally missing %d left bractet. \n", abs(brackCounter));
		}
			
		if (pCounter != 0) {
			state = ERR;
			if (pCounter > 0) 
				printf("*ERR*: totally missing %d right parentheses. \n", pCounter);				
			else 
				printf("*ERR*: totally missing %d left parentheses. \n", abs(pCounter));
		}

		if (sqCounter % 2 != 0) {
			state = ERR;
			printf("*ERR*: existing unmatched single quote. \n");
		}
		if (dqCounter % 2 != 0) {
			state = ERR;
			printf("*ERR*: existing unmatched double quote. \n");
		}
		if (state == NOERR)
			printf("no error found, but I could be wrong cuz I\'m younge. \n");
	} 
	return 0;
}

int getLine(char a[], int lim)
{
	int c, i;
	for (i = 0; i < lim-1 && (c = getchar()) !=EOF && c != '\n'; ++i)
		a[i] = c;
	if (c == '\n') {
		a[i] = '\n';
		i++;
	}
	a[i] = '\0';
	return i;
}
