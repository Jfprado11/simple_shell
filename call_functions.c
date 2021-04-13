#include  "holberton.h"
unsigned countWords(char *str);

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

	bufsize = countWords(line);
	array_tokens = malloc(bufsize * sizeof(char *));
	if (!array_tokens)
	{
		return (NULL); /*MENSAJE DE ERROR???????*/
	}
	single_token = strtok(line, delimit); /*MALLOC????*/
	while (single_token)
	{
		array_tokens[buf_position] = single_token;
		buf_position++;
		/*este if puede morir*/
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
/* C program to count no of words from given input string. */
// returns number of words in str
unsigned countWords(char *str)
{
    int state = 0;
    unsigned wc = 0;  // word count
 
    // Scan all characters one by one
    while (*str)
    {
        // If next character is a separator, set the
        // state as OUT
        if (*str == ' ' || *str == '\n' || *str == '\t')
            state = 0;
 
        // If next character is not a word separator and
        // state is OUT, then set the state as IN and
        // increment word count
        else if (state == 0)
        {
            state = 1;
            ++wc;
        }
 
        // Move to next character
        ++str;
    }
 
    return wc;
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
		{"exit", bi_exit},
		{"env", bi_env},
		{NULL, NULL}
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
	path_name = _which(command[0], &stat_path); /*recive the path of the executable command*/
	if (path_name == NULL)
	{
		perror(command[0]);
		return (1);
	}
	exec_result = execute(command, path_name);
	if (stat_path == 0)
	{
		free(path_name);
	}
	return (exec_result);
}
