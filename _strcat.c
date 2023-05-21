#include "main.h"
/**
 * _strcat - concatenate a string nth length
 * @dest: the resulted string pointer
 * @src: the to be concatenated string
 * Return: string pointer
 */

char *_strcat(char *dest, char *src)
{
	/*change the method implimentation*/
	int _d_length = 0;
	int _s_length = 0;

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
