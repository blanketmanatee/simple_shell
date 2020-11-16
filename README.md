# Simple Shell
A simple command line interpreter, built as a group project for Holberton's
C13.

## Description

## Allowed Functions and System Calls
* access
* chdir
* close
* closedir
* execve
* exit
* _exit
* fflush
* fork
* free
* getcwd
* getline
* isatty
* kill
* malloc
* open
* opendir
* perror
* read
* readdir
* signal
* stat
* lstat
* fstat
* strtok
* wait
* waitpid
* wait3
* wait4
* write

## Usage
Simple Shell can be used in interactive and non-interactive modes. See example below.
Interactive Mode
>
./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

Non-interactive Mode
>
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$


## Authors
Ashley Price @blanketmanatee and Maddi Laizure @mlaizure