#include "main.h"

/**
 * line_cmd - function that get command from the user
 *
 * Return: on success the function the command
 */
char *line_cmd(void)
{
	char *_line_ptr = NULL, *enter_key = "Enter";
	size_t n = 0;
	ssize_t nchars_read;
	int i = 0;

	nchars_read = getline(&_line_ptr, &n, stdin);
	/* check if getline function failed or CTRL +D was entered */
	if (nchars_read == -1)
	{
		/*perror("Exiting...\n");*/
		
		return (NULL);
	}
	if (nchars_read == 1)
	{
		/*perror("Exiting...");*/
		free(_line_ptr);
		return (enter_key);
	}

	/* Handling EOF */
	while (_line_ptr[i])
	{
		if (_line_ptr[i] == '\n')
			_line_ptr[i] = '\0';
		i++;
	}

	return (_line_ptr);
}
