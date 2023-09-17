#include "main.h"

int  re_alloc(size_t chars_read,char **ptr,size_t bufsize, size_t *n)
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
}
