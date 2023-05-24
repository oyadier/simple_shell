#include "main.h"

ssize_t cust_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buff[1024];
	static int pos = 0;
	static int b_read = 0;
	ssize_t line_len = 0, j;
	char *lin = NULL;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	while (1)
	{
		/* check if buffer needs to be refilled */
		if (pos >= b_read)
		{
			b_read = fread(buff, 1, sizeof(buff), stream);
			if (b_read <= 0)
				/* end of file or error */
				return (-1);
			pos = 0;
		}
		/* check for newline character in buffer */
		while (pos < b_read)
		{
			if (buff[pos] == '\n')
			{
				/* allocate memory for the line */
				lin = realloc(lin, line_len + 1);
				if (lin == NULL)
					return (-1);
				/* copy the line from buffer to allocated memory */
				for (j = 0; j < line_len; j++)
					lin[j] = buff[j];
				lin[line_len] = '\0';
				/* update lineptr and n */
				*lineptr = lin;
				*n = line_len;
				/* move buffer position to next character */
				pos++;
	
				return (line_len);
			}
			/* move buffer posion and increase line length */
			pos++;
			line_len++;
		}
	}
}
