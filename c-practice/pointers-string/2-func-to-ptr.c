#include <stdio.h>

/**
 * Description: Pointer to function example.
 * 				In this example, we have to type of functions,
 * 				one that returns void and another that returns double
 * 				and using pointer to function to access the functions.
 *
 * Author:      Girmachew zewdie
 * Date:        2020-12-29
 * Usage:		gcc -Wall -pedantic -std=gnu89 2-func-to-ptr.c
 * 				./a.out
 */

/*prototyping*/
void print_value(double x);
double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);

int main(void)
{
	/*variable to hold result*/
	double result = 0;

	/*pointer to function which takes 1 arg and returns void*/
	void (*ptr_to_function_1)(double);

	/*pointer to function which takes 2 args and returns double*/
	double (*ptr_to_function_2)(double, double);

	/*for ptr_to_function*/
	ptr_to_function_1 = &print_value;

	/*you can to it this way*/
	(*ptr_to_function_1)(10);

	/*or this way*/
	ptr_to_function_1(20);

	/*for ptr_to_function_2*/
	/*pointer to function which takes 2 args and returns double*/
	ptr_to_function_2 = &add;

	/*you can to it this way to get the result*/
	result = (*ptr_to_function_2)(10, 20);

	/*print the result*/
	printf("from ptr_to_function_2: result = %f\n", result);

	/*or this way*/
	result = ptr_to_function_2(10, 20);

	/*print the result*/
	printf("from ptr_to_function_2: result = %f\n", result);

	return (0);
}

void print_value(double x)
{
	printf("from ptr_to_function_1: The Value of x is %f\n", x);
}

double add(double x, double y)
{
	return (x + y);
}

double sub(double x, double y)
{
	return (x - y);
}

double mul(double x, double y)
{
	return (x * y);
}

double div(double x, double y)
{
	return (x / y);
}
