#include "holberton.h"

/**
 * non_interactive - execute the command that recive and finish
 *
 * Return: 0 on succes
 */
int non_interactive(void)
{
	char *line = NULL;
	char **arg = NULL;

	line = read_line();
	arg = split_line(line);
	interpreter(arg);/*VER COMO HACER PARA QUE LEA VARAIOS COMANDOS*/

	free(line);
	free(arg);
	return (0);
}