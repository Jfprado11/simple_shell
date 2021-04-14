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


	while (status)
	{
		line = NULL;
		write(STDOUT_FILENO, "$ ", 2);
		readline = getline(&line, &bufsize, stdin);
		if (readline == EOF)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		arg = split_line(line); /*Convert the line to an array of arguments*/
		status = interpreter(arg); /*type_of_function(arg)*/

		free_matrix(arg);
	}
	return (0);
}
