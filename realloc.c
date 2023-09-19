#include "main.h"

/**
 * custom_realloc - Custom memory reallocation function.
 * @chars_read: Number of characters read.
 * @ptr: Pointer to the memory block to be reallocated.
 * @bufsize: Current buffer size.
 * @n: Pointer to the size of the buffer.
 *
 * Return: 0 on success, -1 on failure.
 */
int custom_realloc(size_t chars_read, char **ptr, size_t bufsize, size_t *n)
{
	char *temp;

	if (chars_read >= bufsize - 1)
	{
		bufsize *= 2;
		temp = (char *)realloc(*ptr, bufsize);
		if (temp == NULL)
		{
			/* Memory allocation error during realloc */
			free(*ptr); /* Clean up previously allocated memory */
			*ptr = NULL; /* Prevent dangling pointer */
			return (-1);
		}
		*ptr = temp;
		*n = bufsize;
	}
	return (0);
}}
