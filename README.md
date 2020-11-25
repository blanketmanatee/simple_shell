# Simple Shell
A simple command line interpreter, built as a group project for Holberton's
C13.

## Description

## Used Functions and System Calls
<ul><li> access - used to verify existence of files and permissions</li>
<ul><li>search_path</li>
<li>check_command</li>
</ul>
<li>execve - used to execute and fork processes</li>
<ul><li>run_cmd</li></ul>
<li>exit - exit the simple shell</li>
<ul><li>search_builtins</li>
<li>my_exit</li></ul>
<li>fork - used to create child processes</li>
<ul><li>run_cmd</li></ul>
<li>free - free memory</li>
<ul><li>all functions</li></ul>
<li>getline - used to read line from input to store in a ptr</li>
<ul><li>main</li></ul>
<li>isatty - tests if a fd refers to a terminal<li>
<ul><li>main</li>
<li>sigint</li>
<li>getline_failure</li></ul>
<li>kill - kill child process</li>
<ul><li>sigint</li></ul>
<li>malloc - allocates memory</li>
<ul><li>all functions</li></ul>
<li>perror - prints system error message</li>
<ul><li>run_cmd</li>
<li>getline_failure</li>
<li>malloc_or_exit</li>
<li>env_name_errs</li></ul>
<li>signal - used to check for ctrl c signal</li>
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
