#include "main.h"
/**
 * custom_getline - Custom getline function for reading lines from a stream.
 * @lineptr: Pointer to the buffer to hold the line.
 * @n: Pointer to the size of the buffer.
 * @stream: The stream where the input will be read from.
 *
 * Return: The total characters read, or -1 if it fails.
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 0;
	size_t chars_read = 0;
	/*int _spaces;*/

	/*checks if null return*/
	null_checker(lineptr, n);

	if (*lineptr == NULL || *n == 0)
        {
                bufsize =(size_t) BUF_SIZE; /* Initial buffer size (can be adjusted) */
                *lineptr = (char *)malloc(bufsize);
                if (*lineptr == NULL)
                {
                        return (-1); /* Memory allocation error */
                }
                *n = bufsize; /* Ownership of memory passed to the caller */
        }
	/* Read characters until a newline or EOF is encountered */
	while (1)
	{
		int c = fgetc(stream);

		if (c == EOF || c == '\n' || c == ' ')
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
		re_alloc(chars_read, lineptr, bufsize, n);
	}
	return (chars_read);
}

