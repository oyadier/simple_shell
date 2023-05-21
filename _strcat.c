#include "main.h"
/**
 * _strncat - concatenate a string nth length
 * @dest: the resulted string pointer
 * @src: the tobe concatenated string
 * @n: the nth byte from src
 * Return: string pointer
 */

char *_strncat(char *dest, char *src, int n)
{
	//change the method implimentation
	int _d_length = 0;
	int _s_length = 0;

	while (dest[_d_length] != '\0')
	{
		_d_length++;
	}
	while (_s_length < n && src[_s_length] != '\0')
	{
		dest[_d_length] = src[_s_length];
		_d_length++;
		_s_length++;
	}
	dest[_d_length] = '\0';
	return (dest);
}
