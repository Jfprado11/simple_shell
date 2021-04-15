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
	int len = 0, status = 0, aux_status = 0;
	char *aux = NULL;

	line = _read();
	if (line == NULL)
	{
		exit(0);
	}
	while (*(line + len))
	{
		aux_status = status;
		while (*(line + len) == '\n')
		{
			len += 1;
		}
		aux = _strdupp(line + len);
		len += _strlen(aux) + 1;
		arg = split_line(aux);
		if (arg)
		{
			status = interpreter(arg);
			free_matrix(arg);
		}
	}
	free(line);
	return (aux_status);
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

