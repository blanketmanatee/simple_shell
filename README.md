# Simple Shell
A simple command line interpreter, built as a group project for Holberton's
C13.

## Description

## Used Functions and System Calls
* access - used to verify existence of files and permissions
    *search_path
    *check_command
* execve - used to execute and fork processes
  *run_cmd
* exit - exit the simple shell
  *search_builtins
  *my_exit
* fork - used to create child processes
  *run_cmd
* free - free memory
  *all functions
* getline - used to read line from input to store in a ptr
  *main
* isatty - tests if a fd refers to a terminal
  *main
  *sigint
  *getline_failure
* kill - kill child process
  *sigint
* malloc - allocates memory
  *all functions
* perror - prints system error message
  *run_cmd
  *getline_failure
  *malloc_or_exit
  *env_name_errs
* signal - used to check for ctrl c signal
  *main
* strtok - extracting tokens from strings
  *split_delim
  *strip_comments
* wait - wait status for children to finish their process
  *run_cmd
* write - write to stdout for _putchar
  *_putchar
## Usage
Simple Shell can be used in interactive and non-interactive modes. See example below.
Interactive Mode

>./hsh\
($) /bin/ls\
hsh main.c shell.c\
($)\
($) exit\
$

Non-interactive Mode
>$ echo "/bin/ls" | ./hsh\
hsh main.c shell.c test_ls_2\
$\
$ cat test_ls_2\
/bin/ls\
/bin/ls\
$\
$ cat test_ls_2 | ./hsh\
hsh main.c shell.c test_ls_2\
hsh main.c shell.c test_ls_2\
$


## Authors
Ashley Price @blanketmanatee and Maddi Laizure @mlaizure
