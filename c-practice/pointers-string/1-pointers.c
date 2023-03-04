#include <stdio.h>

void swap(int *a, int *b);

/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	/*USE CASE 1:*/
	/*declear two int variables*/
	int a = 10;
	int b = 20;

	/*declear two pointers int*/
	int *pointer_1, *pointer_2;

	/*assign the address of a to pointer_1*/
	pointer_1 = &a;

	/*assign the address of b to pointer_2*/
	pointer_2 = &b;

	/*pointers hold the address of a variable*/
	printf("address of a: %p = address of pointer_1: %p\n", &a, pointer_1);
	printf("address of b: %p = address of pointer_2: %p\n", &b, pointer_2);

	/*print the values using pointers*/
	printf("a = %d and b = %d\n", *pointer_1, *pointer_2);

	/*change the value of the variable using pointers*/
	*pointer_1 = 100;
	*pointer_2 = 200;

	/*see changes on the two variable values*/
	printf("a = %d and b = %d\n", a, b);

	/*USE CASE 2:*/
	/*pass values by reference to a function*/
	/*this function swap the values of b to a*/
	swap(&a, &b);

	/*see changes on the two variable values*/
	printf("a = %d and b = %d\n", a, b);

	return (0);
}

/*function to print values by reference*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
