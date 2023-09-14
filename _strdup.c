#include "main.h"
/**
 * _strdup - nction that returns a pointer to a
 * newly allocated space in memory,
 * @str: the array of string pointer argument
 *
 * Return: returns a pointer to a newly allocated space
 */


char *_strdup(char *str)
{
	int i;
	int len = 0;
	char *dup;


	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);

	dup = (char *)malloc(len + 1);

	if (dup == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		*(dup + i) = str[i];
	}

	dup[len] = '\0';

	return (dup);
}

