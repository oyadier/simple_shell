#include "main.h"

/**
 * _putchar - a function to print characters
 * @c: the charater argument
 *
 * Return: integer of the character
 */


int _putchar(char c)
{
	return (write(1, &c, 1));
}

