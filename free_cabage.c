#include "main.h"
/**
 * free_memory - frees the memory
 * @arg: Array argument
 *
 * Return: Always 0
 */

void free_memory(char *arg[])
{
	int i;

	if (arg == NULL || arg[0] == NULL)
		return;
	for (i = 0; arg[i]; i++)
	{
		free(arg[i]);
	}

	if (arg)
	{
		free(arg);
	}
}
