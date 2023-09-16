#include "main.h"
/**
 * custom_getline - Custom getline function for reading lines from a stream.
 * @lineptr: Pointer to the buffer to hold the line.
 * @n: Pointer to the size of the buffer.
 * @stream: The stream where the input will be read from.
 * Return: The total characters read, or -1 if it fails.
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 0;
	size_t chars_read = 0;
	char *temp;

	null_checker(lineptr,n, &bufsize);
	/* Read characters until a newline or EOF is encountered */
	while (1)
	{
		int c = fgetc(stream);

		if (c == EOF || c == '\n')
		{
			if (chars_read == 0 && c == EOF)
			{
				return (-1); /* No characters read, and EOF reached */
			}
			(*lineptr)[chars_read] = '\0'; /* Null-terminate the line */
			break;
		}
		(*lineptr)[chars_read] = (char)c;
		chars_read++;

		/* Resize the buffer if needed */
		if (chars_read >= bufsize - 1)
		{
			bufsize *= 2;
			temp = (char *)realloc(*lineptr, bufsize);
			if (temp == NULL)
			{
				/* Memory allocation error during realloc */
				free(*lineptr); /* Clean up previously allocated memory */
				*lineptr = NULL; /* Prevent dangling pointer */
				return (-1);
			}
			*lineptr = temp;
			*n = bufsize;
		}
	}
	return (chars_read);
}

