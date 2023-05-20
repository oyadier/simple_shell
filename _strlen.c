#include "main.h"

/**
 * _strlen - count the number of string characters
 *@_line_ptr: the string to be countered
 *
 * Return: the lenght of a string
 */


int _strlen(char *_line_ptr)
{
	int len = 0;


	while (*_line_ptr++ != '\0')
	{
		len++;

	}

	return (len);

}
