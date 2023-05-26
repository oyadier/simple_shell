#include "main.h"

/**
 * handle_exit - function that handles the 'exit' built-in command
 *
 * Return: Nothing
 */
void handle_exit(char **argv, char *lineptr, char *lineptr_copy)
{
	/* send a SIGTERM to the current processs */
	free_mem(argv, lineptr, lineptr_copy);
	exit(0);
}
