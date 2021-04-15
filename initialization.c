#include "holberton.h"

/**
 * main - initilize the shell
 *
 * Return: Always 0 as success
 */
int main(void)
{
	int status = 1;

	if (isatty(STDIN_FILENO))
	{
		status = interactive_mode();
	}
	else
	{
		status = non_interactive();
	}
	if (status == 1)
	{
		return (0);
	}
	return (status);
}
