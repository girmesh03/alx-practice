#include <stdio.h>
#include <stdlib.h>

/**
 * Description: Pointer to function example.
 * 				In this example, we will see how to use
 * 				a function that returns a pointer to a function.
 *
 * Author:      Girmachew zewdie
 * Date:        2020-12-29
 * Usage:		gcc -Wall -pedantic -std=gnu89 4-ptr-to-func.c
 * 				./a.out
 */

/*prototyping*/
double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double devide(double x, double y);

/*a function that returns a pointer to a function*/
double (*selector_1(char *operator))(double, double);

int main(void)
{
	/*variable to hold result*/
	double result = 0;

	/*index for looping*/
	int i = 0;

	/*array of operators*/
	char array_operator[] = {'+', '-', '*', '/'};

	/*select operator to use other options*/
	/*char *operator= NULL;*/
	char *operator= "*";

	/*pointer to function which takes 2 args and returns double*/
	double (*ptr_to_function)(double, double) = NULL;

	/*check the operator is NULL and if yes exit*/
	if (operator== NULL)
	{
		printf("Error\n");
		exit(1);
	}

	/*CASE 1:*/
	/*loop through operators*/
	for (i = 0; array_operator[i] != '\0'; i++)
	{
		/*select function*/
		ptr_to_function = selector_1(&array_operator[i]);

		/*call function*/
		result = ptr_to_function(10, 5);

		/*print result*/
		printf("result: %f\n", result);
	}

	/*add a new line */
	printf("\n");

	/*CASE 2:*/
	/*send operator and get the function*/
	ptr_to_function = selector_1(&operator[0]);

	/*based on the operator get the result*/
	result = ptr_to_function(20.0, 20.0);

	/*and now print the result*/
	printf("from ptr_to_function: result = %f\n", result);

	/*CASE 3:*/
	/*send operator, values and get functions result*/
	result = selector_1(&operator[0])(50.0, 20.0);

	/*and now print the result*/
	printf("from ptr_to_function: result = %f\n", result);

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

/*function to devide two numbers*/
double devide(double x, double y)
{
	return (x / y);
}

double (*selector_1(char *operator))(double, double)
{

	switch (*operator)
	{
	case '+':
		return &add;
	case '-':
		return &sub;
	case '*':
		return &mul;
	case '/':
		return &devide;
	default:
		return (0);
	}
}
