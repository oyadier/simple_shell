#include "shell.h"
/**
 * _strcat - the function that concatenate string
 * @dest: the final or resulted string pointer
 * @src: the other string pointer
 *
 * Return: nothing
 */
char *_strcat(char *dest, char *src)
{
	int _d_length = 0;
	int _s_length = 0;

	while (dest[_d_length] != '\0')
	{
		_d_length++;
	}

	while (src[_s_length] != '\0')
	{
		dest[_d_length] = src[_s_length];
		_d_length++;
		_s_length++;
	}
	dest[_d_length] = '\0';
	return (dest);
}

