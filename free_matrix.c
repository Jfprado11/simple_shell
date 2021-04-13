#include "holberton.h"

/**
 *free_matrix - free memory of a double pointer
 *@array: the double pointer to be liberate
 *
 */
void free_matrix(char **array)
{
	int i = 0;

	while (*(array + i))
	{
		free(*(array + i));
		i++;
	}
	free(array);
}
