#include "main.h"
/**
 * cust_getline - get user input from any stream
 * @lineptr: the string entered into the file stream
 * @n: a number use to reallocate buffer size
 * @stream: the source of the characters
 * Return: the number of characters read
 */
ssize_t cust_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buff[1024];
	static int pos;
	static int b_read;
	ssize_t line_len = 0, j;
	char *lin = NULL;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	while (1)
	{
		if (pos >= b_read)
		{
			b_read = fread(buff, 1, sizeof(buff), stream);
			if (b_read <= 0)
				return (-1);
			pos = 0;
		}
		while (pos < b_read)
		{
			if (buff[pos] == '\n')
			{
				lin = realloc(lin, line_len + 1);
				if (lin == NULL)
					return (-1);
				for (j = 0; j < line_len; j++)
					lin[j] = buff[j];
				lin[line_len] = '\0';
				*lineptr = lin;
				*n = line_len;
				pos++;

				return (line_len);
			}
			/* move buffer posion and increase line length */
			pos++;
			line_len++;
		}
	}
}
