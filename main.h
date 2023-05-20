#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stat.h>


/*Prototypes of required functions*/
void prompt(void);
int _putchar(char c);
char *line_cmd(void);
char **tok_parsing(char *_line_ptr, char *_cp_ptr);
void _execmd(char **argv);
void free_mem(char **argv, char *_line_ptr, char *_cp_ptr);
char *_cp_func(char *_line_ptr);
char *get_loc(char *cmd);
char *path_help(char *path, char *cmd);
void hdl_exit(void);
void hdl_env(void);
int _strlen(char *_line_ptr);
char *_str_cp(char *dest, char *src);;

#endif
