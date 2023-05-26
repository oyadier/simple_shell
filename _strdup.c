#include "main.h"

/**
 * _strdup - function that duplicate a string
 * @src: the string to be duplicated
 *
 * Return: a new duplicated string
 */

char *_strdup(char *src)
{
	char *dup;
	int i = 0;

	dup = malloc(sizeof(char) * (_strlen(src) + 1));

	if (dup == NULL)
	{
		exit(EXIT_FAILURE);
	}

	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);
}
