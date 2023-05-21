#include "main.h"

/**
 * tok_parsing - function for tokenization and parsing.
 * @_line_ptr: comman gotten from the stdin
 * @_cp_ptr: a copy of lineptr
 *
 * Return: returns the array of string of the command
 */

char **tok_parsing(char *_line_ptr, char *_cp_ptr)
{
	char *token;
	const char *delim = " \n";
	char **argv;
	int n_tokens = 0, i;

	token = strtok(_line_ptr, delim);
	while (token != NULL)
	{
		n_tokens++;
		token = strtok(NULL, delim);
	}
	/* allocating space to hold the array of strings */
	argv = malloc(sizeof(char *) * n_tokens + 1);
	if (argv == NULL)
	{
		perror("tsh: memory allocation error");
		exit(0);
	}
	/* store each token in the argv array */
	token = strtok(_cp_ptr, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token) + 1);
		if (argv[i] == NULL)
		{
			perror("tsh: memory allocation error");
			exit(0);
		}
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}
