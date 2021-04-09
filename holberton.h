#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

/*LIBRARIES*/
#include <stdio.h> /*getline, perror*/
#include <unistd.h> /*fork, stat, write, access, execve, isatty*/
#include <stdlib.h> /*exit, malloc, */
#include <string.h> /*strtok*/
#include <sys/types.h> /*stat, wait*/
#include <sys/wait.h> /*wait*/
#include <sys/stat.h> /*stat, */

/*GLOBAL VARIABLE*/
extern char **environ;

/*MAIN PROTOTYPES*/
int interactive_mode(void);
int non_interactive(void);

char *read_line(void);

/*OWN_PROTOTYPES_FUNCTIONS*/
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *s);

#endif /*_HOLBERTON_H_*/
