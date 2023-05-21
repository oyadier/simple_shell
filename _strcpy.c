#include "main.h"

/**
 * _cp_funct - copy string from src to dest
 * @dest: the new copied string
 * @src: the string to be copied
 *
 * Return: a pointer to the characters in the string
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr_start = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}

	*dest = '\0';

	return (ptr_start);
}

