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

	aux = malloc(sizeof(char) * 1024);
	line = _read();
	if (line == NULL)
	{
		exit(0);
	}
	while (*(line + len))
	{
		aux = _strdupp(line + len);
		len += _strlen(aux) + 1;
		arg = split_line(aux);
		interpreter(arg);
		free(arg);
		free(aux);
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

	line = malloc(sizeof(char) * 1024);
	if (line == NULL)
	{
		return (NULL);
	}
	readline = read(STDIN_FILENO, line, 1024);
	if (readline == 1)
	{
		return (NULL);
	}
	return (line);
}
/**
 *_strdupp - returns a pointer to a newly allocated space in memory an copied
 *@str: the string that we copied
 *
 *Return: a pointer
 */
char *_strdupp(char *str)
{
	int len = 0, i = 0;
	char *dup;
	char *duppass;

	if (str == NULL)
	{
		return (NULL);
	}
	len = _strlen(str);
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	duppass = dup;
	while (str[i] != '\n')
	{
		*duppass = str[i];
		duppass++;
		i++;
	}
	*duppass = '\0';
	return (dup);
}
