#include "shell.h"
/**
 * _strcmp - compare two string pointers
 * @s1: first string pointer
 * @s2: second string pointer
 *
 * Return: 0 success
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

