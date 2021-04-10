#include "holberton.h"

/**
 *bi_exit - built in that exit the program
 *@command: an array with the user's command
 *Return: 0 as success
 */
int bi_exit(char **command __attribute__((unused)))
{
	return (0);
}

/**
 *bi_env - print the enviroment variables
 *@command: an array with the user's command
 *Return: 1 as succes and keeps the loop alive
 */
int bi_env(char **command __attribute__((unused)))
{
	int i = 0, len = 0;

	while (environ[i])
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}
/**
 *_strcmp - a function that compares two strings
 *@s2: variable to compare one string
 *@s1: variable to compare other string
 *
 *Return: 0 if string are the same. 1 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int a;
	int cmp = 0;

	for (a = 0; s1[a] != '\0' && s2[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
		{
			cmp = 1;
			break;
		}
	}
	if (cmp == 0)
	{
		return (0);
	}
	else
	{
		return (s1[a] - s2[a]);
	}
}
