#include "shell.h"

/**
 * dir_path - displays the path directory
 * @path_dir: the directory of the path
 * @usr_command: Command entered by the user
 *
 * Return: NULL if the file is not found;
 * 		otherwise, the full path of the file
 */
char *dir_path(char *path_dir, char *usr_command)
{
	char *path_token, *delim, *command_cp;
	struct stat status;
	int com_len;
	char *file_path;

	delim = ":";
	com_len = _strlen(usr_command);

	/* Making a copy of the whole PATH */
	command_cp = _strdup(path_dir);
	path_token = strtok(command_cp, delim);

	if (path_token != NULL)
	{
		/* Allocate memory for the path */
		file_path = malloc(com_len + _strlen(path_token) + 2);
	}

	while (path_token != NULL)
	{
		_strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, usr_command);

		if (stat(file_path, &status) == 0)
		{
			free(command_cp);
			return (file_path);
		}
		else
		{
			path_token = strtok(NULL, delim);
		}
	}
	return (NULL);
}

