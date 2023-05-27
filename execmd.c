#include "main.h"

/**
 * _execmd - Function that handles the execution of commands
 * @argv: The array of string of the command
 * Return: Nothing.
 */
void _execmd(char **argv)
{
	char *command = NULL, *real_command = NULL;
	pid_t child_proc;
	int status;

	if (argv)
	{
		/* get the command */
		command = _strdup(argv[0]);

		/* generating the path to this command */
		real_command = get_location(command);

		if (real_command != NULL)
		{
			/* creating a child process to handle the execution of command separately */
			child_proc = fork();
			if (child_proc == -1)
			{
				exit(EXIT_FAILURE);
			}
			if (child_proc == 0)
			{
				/* execute the command with execve */
				status =  execve(real_command, argv, NULL);
				if (status == -1)
				{
					perror(real_command);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&status);
				free(real_command);
			}
		}
	}
}
