#include "main.h"
/**
 * _strcat - concatenate a string
 * @dest: the resulted string pointer
 * @src: the string to be concatenated
 *
 * Return: String pointer
 */
char *_strcat(char *dest, char *src)
{
	int _d_length = 0;
	int _s_length = 0;

	/*
	 * computing the length of the dest string
	 */

	_d_length = _strlen(dest);
	while (src[_s_length] != '\0')
	{
		dest[_d_length] = src[_s_length];
		_d_length++;
		_s_length++;
	}
	dest[_d_length] = '\0';
	return (dest);
}
