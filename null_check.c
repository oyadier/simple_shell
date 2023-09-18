#include "main.h"

/**
 * null_checker - checks if lineptr and n are null
 * @lineptr: the string pointer (buffer)
 * @n: the size of the buffer
 *
 * Return: -1 if one of the params is null
 */
int null_checker(char **lineptr, size_t *n)
{
	int errno;

	/* Check for invalid arguments */
	if (lineptr == NULL || n == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	return (0);
}

