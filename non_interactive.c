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
	int len = 0;
	char *aux = NULL;

	line = _read();
	if (line == NULL)
	{
		exit(0);
	}
	while (*(line + len))
	{
		while (*(line + len)== '\n')
		{
			len += 1;
		}
		aux = _strdupp(line + len);
		len += _strlen(aux) + 1;
		arg = split_line(aux);
		if (arg == NULL)
		{
			free(arg);
			free(aux);
			free(line);
			return (0);
		}
		interpreter(arg);
		free_matrix(arg);
		arg = NULL;
		aux = NULL;
	}
	free(line);
	return (0);
}

/**
 * _read - read the user's input in non interactive mode
 *
 * Return: the line readed
 */
char *_read(void)
{
	char *line = NULL;
	ssize_t readline;

	line = _calloc(4056, sizeof(char));
	if (line == NULL)
	{
		exit(0);
	}
	readline = read(STDIN_FILENO, line, 4056);
	if (readline == 1 || readline == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

