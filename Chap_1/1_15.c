//Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.

#include <stdio.h>
int fahr2cel (int fahrenheit) 
{
	return (5.0/9.0)*(fahrenheit-32.0);
}

int main(int argc, char const *argv[])
{
	float celsius;
	for (int fahrenheit = 0; fahrenheit <= 300; fahrenheit+=20)
	{
		if (fahrenheit == 0)
			printf("Fahrenheit\tCelsius\n");			
		celsius = fahr2cel(fahrenheit);
		printf("%i\t\t%f\n",fahrenheit,celsius);
	}
	return 0;
}