#include "main.h"

/**
 * valid_command - Checks if a command is valid.
 * @cmd: The command to be checked.
 *
 * Return: A valid command or NULL.
 */
char *valid_command(char *cmd)
{
	char *path;
	char *valid_cmd;
	struct stat st;

	path = getenv("PATH");

	if (cmd == NULL)
	{
		return (NULL);
	}

	if (stat(cmd, &st) == 0)
	{
		valid_cmd = _strdup(cmd);
		return (valid_cmd);
	}
	valid_cmd = dir_path(path, cmd);
	if (valid_cmd != NULL && _strcmp(cmd, valid_cmd) != 0)
	{
		return (valid_cmd);
	}

	return (NULL);
}
