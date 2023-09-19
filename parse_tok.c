#include "main.h"

/**
 * parse_tok - Parses the token.
 * @line_ptr: Line to be parsed.
 *
 * Return: Pointer to an array of strings (tokens).
 */
char **parse_tok(char *line_ptr)
{
	int array_len = 0, i;
	char **arg;
	char *token, *cpy_line;
	const char *delim = " \n";

	cpy_line = _strdup(line_ptr);
	token = strtok(line_ptr, delim);
	if (token == NULL)
	{
		return (NULL);
	}

	/* Counting the number of strings in the array */
	while (token)
	{
		array_len++;
		token = strtok(NULL, delim);
	}

	/* Allocating memory for the array of string (character pointer) */
	arg = malloc(sizeof(char *) * (array_len + 2));

	token = strtok(cpy_line, delim);
	for (i = 0; token != NULL; i++)
	{
		/* Allocating memory for each string in the array */
		arg[i] = malloc(sizeof(char) * _strlen(token) + 2);
		if (arg[i] == NULL)
		{
			perror("Error string memory");
			exit(EXIT_FAILURE);
		}
		else
		{
			_strcpy(arg[i], token);
			token = strtok(NULL, delim);
		}
	}

	arg[i] = NULL;	
	free(cpy_line);
	return (arg);
}
