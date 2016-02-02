// Clesius to Fahrenheit
#include <stdio.h>
int main(int argc, char const *argv[])
{
	float fahrenheit;
	for (int celsius = 0; celsius <= 100; celsius += 10 )
	{
		if (celsius == 0)
			printf("Celsius\t\tFahrenheit\n");
		fahrenheit = (9.0/5.0)*celsius+32.0;
		printf("%i\t\t%f\n",celsius,fahrenheit);
		
	}
	return 0;
}