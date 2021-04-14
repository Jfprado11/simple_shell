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
#include <sys/stat.h>
#include <fcntl.h>

/*GLOBAL VARIABLE*/
extern char **environ;

/*STRUCTURES*/

/**
 *struct built_in - to know which builtin to use
 *@name: name of the builtin to compare
 *@func: the function of the builtin
 *@doc_name: name of the file whit the help of each function
 */
typedef struct built_in
{
	char *name;
	int (*func)(char **command);
	char *doc_name;
} ours_built_in;

/*MAIN PROTOTYPES*/
int interactive_mode(void);
int non_interactive(void);

char **split_line(char *line);
int interpreter(char **command);
char *_which(char *command, int *stat_path);
int execute(char **command, char *path_name);
char *_read(void);
void free_matrix(char **array);

ssize_t read_textfile(const char *filename, size_t letters);

/*OWN_PROTOTYPES_FUNCTIONS*/
char *_getenv(const char *name);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *s);
unsigned int _strlenconst(const char *p);
char *_strdup(char *str);
char *str_concat_path(char *str1, char *str2);
int strcmp_var(char *s1, const char *s2);
int _strcmp(char *s1, char *s2);
char *_strdupp(char *str);
void *_calloc(unsigned int nmemb, unsigned int size);
unsigned int counter_words(char *str);

/*BUILT IN FUNCTION*/
int bi_exit(char **command __attribute__((unused)));
int bi_env(char **command __attribute__((unused)));
int bi_help(char **command __attribute__((unused)));

#endif /**/
