#include <stdio.h>
int main(int argc, char const *argv[])
{
	float celsius;
	for (int fahrenheit = 0; fahrenheit <= 300; fahrenheit+=20)
	{
		if (fahrenheit == 0)
			printf("Fahrenheit\tCelsius\n");			
		celsius = (5.0/9.0)*(fahrenheit-32.0);
		printf("%i\t\t%f\n",fahrenheit,celsius);
	}
	return 0;
}