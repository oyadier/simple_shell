#include "main.h"

/**
 * handle_exit - function that handles the 'exit' built-in command
 * @argv: parameter to be freed
 * @lineptr: parameter to be freed
 * @lineptr_copy: parameter to be freed
 *
 * Return: Nothing
 */
void handle_exit(char **argv, char *lineptr, char *lineptr_copy)
{
	/* send a SIGTERM to the current processs */
	free_mem(argv, lineptr, lineptr_copy);
	exit(0);
}
