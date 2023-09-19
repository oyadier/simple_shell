#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

#define  BUF_SIZE 128

void _exits();
char *_getline();
int _putchar(char c);
void prompt();
char *_strcpy(char *des, char *src);
int _strlen(char *str);
char **parse_tok(char *line_ptr);
char *valid_command(char *cmd);
char *dir_path(char *dir,char *cmd);
void _execve(char *argv[]);
int _environ();
int null_checker(char **ptr, size_t *n);
int  re_alloc(size_t chars_read,char **ptr,size_t bufsize, size_t *n);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
char *_strcat(char *dest, char *src);
void __exiting();
void handle_cd(char *arg[]);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
extern char **environ;
void free_memory(char *arg[]);
#endif
