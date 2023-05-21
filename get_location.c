#include "main.h"

/**
 * get_location - function that gets the path of the command typed.
 * @cmd: the command to get its path
 *
 * Return: Return the path if exit or NULL upon failure
 */
char *get_location(char *cmd)
{
	char *path;
	struct stat buff;
	char *location;

	path = getenv("PATH");

	if (path)
	{
		location = path_help(path, cmd);

		/* testing to know if the command itself is a path */
		if (stat(cmd, &buff) == 0)
		{
			return (cmd);
		}
		/* check if the command is not a valid command */
		if (location != NULL && _strcmp(cmd, location) != 0)
		{
			return (location);
		}
	}

	return (NULL);
}
