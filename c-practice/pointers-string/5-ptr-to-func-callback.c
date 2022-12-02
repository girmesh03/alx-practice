#include <stdio.h>
#include <stdbool.h>

/**
 * Description: Pointer to function example.
 * 				In this example, we will see how to use
 * 				a callback function.
 * Author: 	Girmachew zewdie
 * Date: 	2020-12-29
 * Usage:	gcc -Wall -pedantic -std=gnu89 5-ptr-to-func-callback.c
 * 			./a.out
 */

/*prototyping*/
bool temperature_f(double fahrenheit);
bool temperature_c(double celsius);
bool is_freezing(double temperature, bool (*ptr_to_function)(double));

int main(void)
{
	/*variable to hold result*/
	bool result = false;

	/*variable to hold temperature*/
	double temperature = 0;

	/*select temperature unit*/
	/*bool (*ptr_to_function)(double) = NULL;*/
	/*bool (*ptr_to_function)(double) = temperature_f;*/
	bool (*ptr_to_function)(double) = temperature_f;

	/*get temperature*/
	printf("Enter temperature: ");
	scanf("%lf", &temperature);

	/*check if temperature is freezing*/
	result = is_freezing(temperature, ptr_to_function);

	/*print result*/
	if (result == true)
	{
		printf("It is freezing: %f\n", temperature);
	}
	else
	{
		printf("It is not freezing: %f\n", temperature);
	}

	return (0);
}

bool is_freezing(double temperature, bool (*ptr_to_function)(double))
{
	/*variable to hold result*/
	bool result = false;

	/*check if temperature is freezing*/
	result = ptr_to_function(temperature);

	return (result);
}

bool temperature_c(double celsius)
{
	/*variable to hold result*/
	bool result = false;

	/*check if temperature is freezing*/
	if (celsius <= 0)
	{
		result = true;
	}

	return (result);
}

bool temperature_f(double fahrenheit)
{
	/*variable to hold result*/
	bool result = false;

	/*check if temperature is freezing*/
	if (fahrenheit <= 32)
	{
		result = true;
	}

	return (result);
}
