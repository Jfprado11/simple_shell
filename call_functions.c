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
		exit(3);
    }
	return (line);
}
/**
 * slpit_line - tokenize the line into an array
 * @line: the line we got from user's input
 *
 * Return: an array of arrays or NULL if fails
 */
char **split_line(char *line)
{
	unsigned int bufsize = 64, buf_position = 0, new_bufsize = 0;
	char **array_tokens = NULL;
	char *single_token, *delimit = " \t\r\n\a:";
	char *aux_line = NULL;

	aux_line = _strdup(line);
	array_tokens = malloc(bufsize * sizeof(char *));
	if (!array_tokens)
	{
		return (NULL); /*MENSAJE DE ERROR???????*/
	}
	single_token = strtok(aux_line, delimit); /*MALLOC????*/
	while (single_token)
	{
		array_tokens[buf_position] = single_token;
		buf_position++;

		if (buf_position >= bufsize)
		{
			new_bufsize = bufsize + bufsize;
			array_tokens = _realloc(array_tokens, bufsize * sizeof(char *),
			new_bufsize * sizeof(char *));
			bufsize += bufsize;
			if (!array_tokens)
			{
				perror("hsh: allocation error\n");
				exit(0);
			}
		}
		single_token = strtok(NULL, delimit);
	}
	array_tokens[buf_position] = NULL;
	return (array_tokens);
}
/**
 * interpreter - interpet the command & proceed to execut it
 * @command: Is the array of arguments (command[0] is the name of the command)
 *
 * Return 1 to status in succes, 0 if command[0] is "exit".
 */

int interpreter(char **command)
{
	char *path_name;
	int buildint_result = 0, exec_result;

	if (command[0] == NULL)
	{
		return (1);
	}
	/*verificar si es build int*/
	/*buildint_result = buildint(command)*/
	if (buildint_result == 0)
	{
		path_name = _which(command[0]); /*recive the path of the executable command*/
		exec_result = execute(command, path_name);
		free(path_name);
		return (exec_result);
	}
	return (1);
}