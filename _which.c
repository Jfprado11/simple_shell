#include "holberton.h"

char *w_strdupp(char *str);

/**
 * _which - search the full path and concatenates whit the command.
 * @command: name of the command.
 * @stat_path: number to check user type the full path.
 * Return: The path with the executable command or NULL if doesn't exist.
 */
char *_which(char *command, int *stat_path)
{
	char *pth = NULL, *path_name = NULL;
	char *aux_line = NULL;
	const char *env_var = "PATH";
	int check_accsess = 0, len = 0;
	struct stat st;

	if (stat(command, &st) == 0)
	{
		*stat_path = 1;
		return (command);
	}
	else
	{
		pth = _getenv(env_var);
		while (pth[len - 1] != '\0')
		{
			aux_line = w_strdupp(pth + len);
			len += _strlen(aux_line) + 1;
			path_name = str_concat_path(aux_line, command);
			if (stat(path_name, &st) == 0)
			{
				check_accsess = access(path_name, X_OK);
				if (check_accsess == 0)
				{
					free(aux_line);
					return (path_name);
				}
			}
			else
			{
				free(aux_line);
				free(path_name);
			}
		}
	}
	/*HAY QUE BUSCAR EN DIRECTORIO ACTUAL? ESO NO LO HACE LA SHELL*/
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
	char *env = NULL;
	int len = (_strlenconst(name) + 1);

	while (environ[i])
	{
		result = strcmp_var(environ[i], name);
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
	char *concat = NULL;

	if (str1 == NULL)
	{
		str1 = "";
	}
	if (str2 == NULL)
	{
		str2 = "";
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
/**
 * strcmp_var - find the env variable wated
 *@s1: first string to be compare
 *@s2: the stting that matches with first one
 *
 *Return: 0 as matched. 1 as unmatched
 */
int strcmp_var(char *s1, const char *s2)
{
	int i = 0, j = 0;

	while (s1[j] != '=')
	{
		if (s1[j] != s2[j])
		{
			i = 1;
			break;
		}
		j++;
	}
	if (i == 0)
		return (0);
	else
		return (1);
}
