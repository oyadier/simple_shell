#include "main.h"

/**
 * _environ - prints the environment
 *
 * Return: zero for success
 */

int _environ(void)
{
	unsigned int i;
	char **env = environ;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
