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
char *line_command(void);
char **tok_parsing(char *_line_ptr, char *_cp_ptr);
void _execmd(char **argv);

#endif
