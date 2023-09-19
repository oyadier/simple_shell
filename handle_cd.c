#include "main.h"
/**
 * handle_cd - func changes the direct
 * @arg: the strig cd command
 *
 * Return: nothing
 */
void handle_cd(char *arg[])
{
	/* Change directory using chdir() system call*/
	if (chdir(arg[1]) != 0)
	{
		printf("%s: %s: No such file or directory\n", arg[0], arg[1]);
	}
	if (_strcmp(arg[0], "clear") == 0)
	{
		/* Clear the screen using ANSI escape codes*/
		printf("\033[H\033[J");
	}

}

