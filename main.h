#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
/*Prototypes of required functions*/
void start_prompt(void);
int _putchar(char c);
char *line_cmd(void);
char **tok_parsing(char *_line_ptr, char *_cp_ptr);
void _execmd(char **argv);
void free_mem(char **argv, char *_line_ptr, char *_cp_ptr);
char *_cp_funct(char *_line_ptr);
char *get_location(char *cmd);
char *path_help(char *path, char *cmd);
void handle_exit(void);
void handle_env(void);
int _strlen(char *_line_ptr);
char *_strdup(char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
