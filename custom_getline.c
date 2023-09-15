#include "main.h"
/**
 * custom_getline - my custome getline function
 * @lineptr: the buffer to hold the stream input
 * @n: the size of the buffer
 * @stream: the stream where the input will be made
 *
 * Return: the total characters read. -1 if it fails
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream) {

    size_t bufsize = 0;
    size_t chars_read;
    int errno;
    char *temp;

    if (lineptr == NULL || n == NULL) {
        errno = EINVAL;
        return -1;
    }

    /* Allocate memory for the line buffer if needed*/
    if (*lineptr == NULL || *n == 0) {
        bufsize = BUF_SIZE;  /*Initial buffer size (can be adjusted)*/
        *lineptr = (char *)malloc(bufsize);
        if (*lineptr == NULL) {
            return -1;
        }
        *n = bufsize;
    }

    /*Read characters until a newline or EOF is encountered*/
    chars_read = 0;
    while (1) {
        int c = fgetc(stream);

        if (c == EOF || c == '\n') {
            if (chars_read == 0 && c == EOF) {
                return -1; 
            }
            (*lineptr)[chars_read] = '\0';  /* Null-terminate the line*/
            break;
        }

        (*lineptr)[chars_read] = (char)c;
        chars_read++;

        /* Resize the buffer if needed*/
        if (chars_read >= bufsize - 1) {
            bufsize *= 2;
            temp = (char *)realloc(*lineptr, bufsize);
            if (temp == NULL) {
                return -1;
            }
            *lineptr = temp;
            *n = bufsize;
        }
    }

    return chars_read;
}

