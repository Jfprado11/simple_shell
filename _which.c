#include "holberton.h"

/**
 * _which - search the full path and concatenates whit the command.
 * @command: name of the command.
 * Return: The path with the executable command or NULL if doesn't exist.
 */
char *_which(char *command)
{
	char *pth = NULL, *temp = NULL;
	char **args_path = NULL;
	const char *env_var = "PATH";
	int i = 0, check_accsess;
	struct stat st;

	if (stat(command, &st) == 0)
	{
		return (command);
	}
	else
	{
		pth = _getenv(env_var);
		args_path = slpit_line(pth);
		while (args_path[i])
		{
			temp = str_concat_path(args_path[i], command);
			if (stat(temp, &st) == 0)
			{
				check_accsess = access(temp, X_OK);
				if (check_accsess == 0)
				{
					free(args_path);
					return (temp);
				}
			}
			else
			{
				free(temp);
			}
			i++;
		}
	}
	return (NULL);
}

/**
 * _getenv - obtain the env variable requested
 * @name: name of the env varible requested to get
 * Return: the exact env variable requested
 */
char *_getenv(const char *name)
{
	int result, i = 0;
	char *env;
	int len = (_strlenconst(name) + 1);

	while (environ[i])
	{
		result = _strcmp(environ[i], name);
		if (result == 0)
		{
			env = environ[i] + len;
			return (env);
		}
		i++;
	}
	return (NULL);
}

/**
 * str_concat_path - put together the path and the commad in a new variable
 * @str1: path
 * @str2: name of commad
 * Return: the new variable with the string of the patt, NULL  if fails.
 */
char *str_concat_path(char *str1, char *str2)
{
	int len1, len2, i, j;
	char *concat;

	if (str1 == NULL)
	{
		str1 = "";
	}
	if (str2 == NULL)
	{
		str2 == "";
	}
	len1 = _strlen(str1);
	len2 = _strlen(str2);

	concat = malloc(sizeof(char) * (len1 + len2 + 2));
	if (concat == NULL)
	{
		return (NULL);
	}
	for (i = 0; *(str1 + i) != '\0'; i++)
	{
		*(concat + i) = *(str1 + i);
	}
	*(concat + i) = '/';
	i++;
	for (j = 0; *(str2 + j) != '\0'; j++)
	{
		*(concat + i + j) = *(str2 + j);
	}
	*(concat + i + j) = '\0';
	return (concat);
}