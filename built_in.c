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
 *bi_help - display on the help of built-in functions
 *@command: an array with the user's command
 *Return: 1 as succes and keeps the loop alive
 */
int bi_help(char **command __attribute__((unused)))
{
	int i = 0, n_bytes = 0;
	ours_built_in built_cmp[] = {
		{"exit", bi_exit, "exit_help"},
		{"env", bi_env, "env_help"},
		{"help", bi_help, "help_help"},
		{NULL, NULL}
	};

	while (built_cmp[i].name != NULL)
	{
		if (_strcmp(command[1], built_cmp[i].name) == 0)
		{
			n_bytes = read_textfile(built_cmp[i].doc_name, 1024);
		}
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
	return (1);
}
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: file to be readed
 * @letters:is the number of letters it should read and print
 * Return: the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	char *buffer;
	ssize_t /*len_buffer,*/i, j;

	if (filename == NULL)
		return (0);

	/*open and read file*/
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
		return (0);
	j = read(file_descriptor, buffer, letters);
	if (j == -1)
		return (0);

	/*print buffer*/
	i = write(STDOUT_FILENO, buffer, j);
	if (i == -1)
		return (0);
	close(file_descriptor);
	free(buffer);

	return (i);
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
