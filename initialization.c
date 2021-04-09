#include "holberton.h"

/**
 * main - initilize the shell
 *
 * Return: Always 0 as success
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		interactive_mode();
	}
	else
	{
		non_interactive();
	}
	return (0);
}
