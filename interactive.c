#include "holberton.h"

/**
 * interactive_mode - it's a loop always attentive to the commands.
 *
 * Return: 0 on success.
 */

int interactive_mode(void)
{
	char *line = NULL; /*will be the text that user types*/
	char **arg= NULL; /*convert the line into arguments*/
	int status = 1; /*1 to continue in the loop, 0 to end loop*/

	while (status)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line = read_line(); /*Keeps the text recived in the standar input*/
		arg = split_line(line); /*Convert the line to an array of arguments*/
		status = interpreter(arg); /*type_of_function(arg)*/

		free(line);
		free(arg);
	}
	return (0);
}