#include "holberton.h"

/**
 * interactive_mode - it's a loop always attentive to the commands.
 *
 * Return: 0 on success.
 */

int interactive_mode(void)
{
	char *line = NULL; /*will be the text that user types*/
	char **arg = NULL; /*convert the line into arguments*/
	size_t bufsize = 0;
	ssize_t readline;
	int status = 1; /*1 to continue in the loop, 0 to end loop*/
	int aux_status = 0;

	while (status == 1 || status == 127)
	{
		line = NULL;
		write(STDOUT_FILENO, "$ ", 2);
		readline = getline(&line, &bufsize, stdin);
		if (readline == EOF)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		arg = split_line(line); /*Convert the line to an array of arguments*/
		aux_status = status;
		if (arg)
		{
			status = interpreter(arg); /*type_of_function(arg)*/
			free_matrix(arg);
		}
	}
	return (aux_status);
}
