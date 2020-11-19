#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

extern char **environ;
int _putchar(char c);
void _puts(const char *str);
char *_strdup(const char *str);
char *_strstr(const char *haystack, const char *needle);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
void run_cmd(char **cmd_args);
char **split_delim(char *, const char *);
void free_split(char **array);
void clean_up(char ***aray, char **line);
void getline_failure(char *line, int n_characters);
char *check_command(char **cmd_args);
void *malloc_or_exit(size_t n);
int search_builtins(char **cmd_args, int *ext);
void my_exit(char **cmd_args, int *ext);
void print_env(void);
int findenv(const char *name);
char *_getenv(const char *name);
char *search_path(char *command);

#endif
