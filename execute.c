#include "holberton.h"

/**
 *execute - fork the parent proccess to be able/
 *to call exceve to execute the command request in child proccess
 *@command: the array with the user's input
 *@path_name: the path of the executable file
 *
 *Return: 1 as success. 0 as fail
 */
int execute(char **command, char *path_name)
{
	pid_t id;

	id = fork();
	if (id == 0)
	{
		if (execve(path_name, command, environ) == -1)
		{
			perror(command[0]);
			return (0);
		}
	}
		if (id != 0)
		{
			while (wait(NULL) != -1) /*NULL OR A STATUS*/
			{}
		}
	return (1);
}
