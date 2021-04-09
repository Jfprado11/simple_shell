#include  "holberton.h"

/**
 * read_line - read the line and kepp into a buffer
 *
 * Return: the string line on succes, and 0 on failure
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t readline;

	readline = getline(&line, &bufsize, stdin);
	if (readline == EOF)
	{
		free(line);
		write(1, "\n", 1);
		exit(0);/*CODIGO */
	}
	return (line);
}