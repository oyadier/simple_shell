#include "main.h"

/**
 * path_help - function that help in finding the path of command
 * @path: the path of the command
 * @cmd: the command being typed
 *
 * Return: return the file path
 */
char *path_help(char *path, char *cmd)
{
	char *path_copy = NULL, *path_token = NULL, *file_path;
	int command_len, dir_len;
	struct stat buff;

	/* Duplicating the path string */
	path_copy = _strdup(path);
	/* getting the length of command */
	command_len = _strlen(cmd);

	/* breaking down the path variable to get all the dir */
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		/* getting the len of the dir */
		dir_len = _strlen(path_token);
		/* allocating enough memory to store the command with the file path */
		file_path = malloc(command_len + dir_len + 2);
		_strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, cmd);
		file_path[dir_len + 1] = '\0';

		/* check if the path exist, free the memory and return the path */
		if (stat(file_path, &buff) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			/* free the file_path and check again */
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}
	free(path_token);
	free(path_copy);
	return (NULL);
}
