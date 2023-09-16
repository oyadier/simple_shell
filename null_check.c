#include "main.h"
/**
 * null_checker - checks if lineptr and n are null
 * @lineptr: the string pointer (buffer)
 * @n: the size of the buffer
 *
 * Return: -1 if one of  the params is null
 */

int null_checker(char **lineptr, size_t *n, size_t *bufsize)
{
        int errno;

        /*Check for invalid arguments*/
        if (lineptr == NULL || n == NULL)
        {
                errno = EINVAL;
                return (-1);
        }

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
        return (0);
}
