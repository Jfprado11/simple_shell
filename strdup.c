#include "holberton.h"
/**
 *_strdup - returns a pointer to a newly allocated space in memory an copied
 *@str: the string that we copied
 *
 *Return: a pointer
 */
char *_strdup(char *str) /*creo que ya no se usa*/
{
	int len = 0, i = 0;
	char *dup = NULL;
	/*char *duppass = NULL;*/

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
	/*duppass = dup;*/
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		/*duppass++;*/
		i++;
	}
	dup[i] = '\0';
	return (dup);
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
	char *dup = NULL;

	if (str == NULL)
	{
		return (NULL);
	}
	/*obtain the lengt of the string*/
	while (str[len] != '\n' && str[len] != '\0')
	{
		len++;
	}
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	/*duplicate the string in the new pointer*/
	while (str[i] != '\n' && str[len] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/**
 *w_strdupp - returns a pointer to a newly allocated space in memory an copied
 *@str: the string that we copied
 *
 *Return: a pointer
 */
char *w_strdupp(char *str)
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
	while (str[i] != ':' && str[i] != '\0')
	{
		*duppass = str[i];
		duppass++;
		i++;
	}
	*duppass = '\0';
	return (dup);
}