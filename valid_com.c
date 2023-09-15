#include "main.h"
/**
 * valid_comand - checks the valid command
 * @cmd: command to be inputed
 *
 * Return: NULL
 */
char *valid_comand(char *cmd)
{
	char *path;
	char *valid_cmd;
	struct stat st;

	path = getenv("PATH");

	if (cmd  == NULL)
	{
		return NULL;
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
