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

int _putchar(char c);
void _puts(const char *str);
char *_strdup(const char *str);
char *_strstr(const char *haystack, const char *needle);
char **split_delim(char *, const char *);
void free_split(char **array);

#endif
