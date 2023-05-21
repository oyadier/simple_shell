#include "main.h"

/**
 * free_mem - function that frees the memories allocated
 * @argv: the arary of string
 * @_line_ptr: the line pointer
 * @_cp_ptr: the copy version of line pointer
 * Return: Nothing
 */
void free_mem(char **argv, char *_line_ptr, char *_cp_ptr)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
		free(argv[i]);
	}
	free(argv);
	free(_cp_ptr);
	free(_line_ptr);
}
