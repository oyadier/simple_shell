#include "main.h"

/**
 * _strcmp - function that compare two string
 * @dest: first string
 * @src: second string
 *
 * Return: Return the difference between the string
 */
int _strcmp(char *dest, char *src)
{
	int index = 0;

	for (index = 0; dest[index] && src[index]; index++)
	{
		if (dest[index] != src[index])
		{
			return ((dest[index] - src[index]));
		}
	}
	return (dest[index] - src[index]);
}
