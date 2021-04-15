#include  "holberton.h"

/**
 *split_line - tokenize the line into an array
 *@line: the line we got from user's input
 *
 *Return: an array of arrays or NULL if fails
 */
char **split_line(char *line)
{
	unsigned int bufsize, buf_position = 0, new_bufsize = 0;
	char **array_tokens = NULL;
	char *single_token = NULL, *delimit = " \t\r\n\a";
	int i = 0, check = 0;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] != ' ' && line[i] != '\n')
			check = 1;
	}
	if (check == 0)
	{
		free(line);
		return (array_tokens);
	}
	bufsize = counter_words(line);
	array_tokens = malloc(bufsize * sizeof(char *) + 1);
	if (!array_tokens)
		return (NULL); /*MENSAJE DE ERROR???????*/
	single_token = strtok(line, delimit); /*MALLOC????*/
	while (single_token)
	{
		array_tokens[buf_position] = _strdup(single_token);
		buf_position++;
		if (buf_position >= bufsize)
		{
			new_bufsize = bufsize + bufsize;
			array_tokens = _realloc(array_tokens, bufsize * sizeof(char *),
			new_bufsize * sizeof(char *));
			bufsize += bufsize;
			if (!array_tokens)
				exit(0);
		}
		single_token = strtok(NULL, delimit);
	}
	array_tokens[buf_position] = NULL;
	free(line);
	return (array_tokens);
}
/**
 * counter_words - counter of words in a string
 * @str: the string
 * Return: a unsigned int number
 */
unsigned int counter_words(char *str)
{
	int state = 0;
	unsigned int counter = 0;

	while (*str != '\0')
	{
		if (*str == 32 || *str == 10 || *str == 9)
		{
			state = 0;
		}
		else if (state == 0)
		{
			state = 1;
			++counter;
		}
		++str;
	}
	return (counter);
}

/**
 *interpreter - interpet the command & proceed to execut it
 *@command: Is the array of arguments (command[0] is the name of the command)
 *
 *Return: 1 to status in succes, 0 if command[0] is "exit".
 */

int interpreter(char **command)
{
	char *path_name = NULL;
	int i = 0, exec_result, stat_path = 0;
	ours_built_in built_cmp[] = {
		{"exit", bi_exit, "exit_help"},
		{"env", bi_env, "env_help"},
		{"help", bi_help, "help_help"},
		{NULL, NULL, NULL}
	};

	if (command[0] == NULL)
	{
		return (1);
	}
	/*verificar si es build int*/
	while (built_cmp[i].name != NULL)
	{
		if (_strcmp(command[0], built_cmp[i].name) == 0)
		{
			return (built_cmp[i].func(command));
		}
		i++;
	}
	/*recive the path of the executable command*/
	path_name = _which(command[0], &stat_path);
	if (path_name == NULL)
	{
		perror(command[0]);
		return (127);/*return 127*/
	}
	exec_result = execute(command, path_name);
	if (stat_path == 0)
	{
		free(path_name);
	}
	return (exec_result);
}
