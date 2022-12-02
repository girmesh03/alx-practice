#include <stdio.h>

/**
 * Description: Array of pointer to functions example.
 *
 * Author:      Girmachew zewdie
 * Date:        2020-12-29
 * Usage:		gcc -Wall -pedantic -std=gnu89 3-ptr-to-func.c
 * 				./a.out
 * version:		1.0
 */

/*prototyping*/
double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);

int main(void)
{
	/*variable to hold result*/
	double result = 0;

	/*loop index*/
	int i = 0;

	/*array of pointer to a functions*/
	double (*array_of_pointers[4])(double, double) = {&add, &sub, &mul, &div};

	/*you can to it this way to get the result*/
	/*and print the result*/
	result = (*array_of_pointers[0])(10, 20);
	printf("the result of add function = %f\n\n", result);

	/*or this way*/
	/*loop through the array of pointer to functions*/
	for (i = 0; i < 4; i++)
	{
		/*get the result*/
		result = array_of_pointers[i](10, 20);

		/*print the result*/
		printf("array_of_pointers[%d]: result = %f\n", i, result);
	}

	return (0);
}

/*function to add two numbers*/
double add(double x, double y)
{
	return (x + y);
}

/*function to subtract two numbers*/
double sub(double x, double y)
{
	return (x - y);
}

/*function to multiply two numbers*/
double mul(double x, double y)
{
	return (x * y);
}

/*function to divide two numbers*/
double div(double x, double y)
{
	return (x / y);
}
