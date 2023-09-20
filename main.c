#include "shell.h"

/**
 * main - The main function
 *
 * Return: Always 0
 */
int main(void)
{
	char *line_ptr;
	char **arg;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt();
			fflush(stdout);
		}
		signal(SIGINT, __exiting);

		line_ptr = _getline();

		if (_strcmp(line_ptr, "Enter") == 0)
			continue;
		if (line_ptr == NULL)
			break;
		arg = parse_tok(line_ptr);
		if (arg == 0)
			continue;
		if (_strcmp(arg[0], "env") == 0)
		{
			_environ();
		}
		else if (_strcmp(arg[0], "exit") == 0)
		{
			free_memory(arg);
			free(line_ptr);
			__exiting(2);
		}
		else
		{
			_execve(arg);
		}
		free(line_ptr);
		free_memory(arg);
	}
	return (0);
}

