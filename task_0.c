#include <stdio.h>

/**
 * main - function that prints the last digit of a num
 *	the number to find the last digit
 *@ac: the number of elements in av
 *@av: the string pointer argument passed
 * Return: Always return 0.
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	int r, num = 1024;

	if (num < 0)
		num = -num;

	r = num % 10;
	printf("%d\n", r);
	return (0);
}
