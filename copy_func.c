#include "main.h"

/**
 * _cp_funct - this function will copy a source string
 *		to a new char pointer
 *@_line_ptr: the pointer to copy from
 *
 * Return: pointer to the copied content
 */
char *_cp_funct(char *_line_ptr)
{
	char *_cp_ptr;

	/*allocate memmory for the _line_ptr*/

	_cp_ptr = malloc(sizeof(char *) * _strlen(_line_ptr) + 1);

	if (_cp_ptr == NULL)
	{
		perror("tsh: memory allocation error");
		exit(0);
	}

	_strcopy(_cp_ptr, _line_ptr);

	return (_cp_ptr);
}
