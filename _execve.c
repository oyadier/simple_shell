#include "main.h"
/**
 * _execve - prints the command in the shell
 * @arg: Array argument
 *
 * Return: Always 0
 */

void _execve(char *arg[])
{   
	int status = 0;
	pid_t child;
	char *pa;
	/*int  exit_status = 0;*/

	if (_strcmp(arg[0], "cd") == 0 || _strcmp(arg[0], "clear") == 0)
	{
		handle_cd(arg);
	}
	else
	{
		child = fork();
		if (child == -1)
		{
			exit(EXIT_FAILURE);
		}

		pa = valid_comand(arg[0]);

		if (pa != NULL)
		{ 
			if (child == 0)
		  	{
					if (execve(pa, arg, NULL) == -1)
					{
							if(pa != NULL)
							 	free(pa);
							printf("%s: No command found\n", arg[0]);
							exit(EXIT_FAILURE);
					}

			}
			else
			{
				if(pa)
					free(pa);
				waitpid(child, &status, 0);
			}
		
		}
	}

}  
