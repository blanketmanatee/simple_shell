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

/* shell_interpreter (also includes main)*/
void run_cmd(char **cmd_args, int *ext, pid_t *child_pid);
void clean_up(char ***array, char **line, char ***env_a, int ext);
void sigint(int sig);
/* helpers */
char **split_delim(char *, const char *);
void free_split(char **array);
int split_len(char **cmd_args);
char **split_add(char **pieces, char *add);
int split_remove(char **pieces, char *remove);
/* error_handling */
int getline_failure(int n_characters, int *ext);
char *check_command(char **cmd_args);
void *malloc_or_exit(size_t n);
int env_name_errs(const char *name);
/* built_ins */
int search_builtins(char **cmd_args, int *ext, char ***env_allocs);
void my_exit(char **cmd_args, int *ext);
void print_env(void);
int _setenv(const char *name, const char *value, char ***env_allocs);
int _unsetenv(const char *name, char ***env_allocs);
/* environment_handling */
int findenv(const char *name);
char *_getenv(const char *name);
/* path_handling */
char *search_path(char *command);
/* utilities */
int _putchar(char c);
void _puts(const char *str);
char *_strdup(const char *str);
char *_strstr(const char *haystack, const char *needle);
size_t _strlen(const char *s);
/* utilities1 */
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _atoi(char *s);
void *_memcpy(void *dest, const void *src, size_t n);

#endif /* SIMPLE_H */
