#include "holberton.h"
char *_strdupp(char *str);

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
	char *aux;

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
		printf("aux = %s\n", aux);
		arg = split_line(aux);
		printf("arg = %s y %s\n", arg[0], arg [1]);
		interpreter(arg);
		free(arg);
		free(aux);
	}
	//arg = split_line(line);
	//interpreter(arg);/*VER COMO HACER PARA QUE LEA VARAIOS COMANDOS*/

	free(line);
	//free(arg);
	return (0);
}

/**
 * _read -
 *
 * return: vvv
 */
char *_read(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t readline;

	line = malloc(sizeof(char) * 1024);
	readline = read(STDIN_FILENO, line, 1024);
	if(readline == 1)
	{
		return (NULL);
	}
	return (line);
}
/**
 *_strdup - returns a pointer to a newly allocated space in memory an copied
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
