#include "shell.h"
/**
 * _getline - will get the new line
 *
 * Return: Always 0
 */

char *_getline()
{
	char *line_ptr = NULL;
	size_t line_no = 0;
	char *line_dp;
	ssize_t read_line;
	int i = 0;


	read_line = getline(&line_ptr, &line_no, stdin);

	if (read_line == -1)
	{
		free(line_ptr);
		exit(0);
	}

	line_dp = _strdup(line_ptr);
	if (read_line == 1)
	{
		free(line_dp);
		free(line_ptr);
		return ("Enter");
	}

	while (line_dp[i])
	{
		if (line_dp[i] == '\n')
			line_dp[i] = '\0';
		i++;
	}

	free(line_ptr);
	return (line_dp);
}

