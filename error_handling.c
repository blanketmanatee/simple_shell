#include "simple.h"

/**
 * getline_failure - handles ctrl + D or getline read failure including EOF
 * @line: line read from getline
 * @n_characters: number of chars read from getline (-1 on failure or EOF)
 *
 * Return: none
 */
void getline_failure(char *line, int n_characters)
{
	if (n_characters == -1)
	{
		if (errno)
			perror(NULL);
		free(line);
		_puts("\r");
		exit(1);
	}
}


/**
 * check_command - checks for existence of command and execution permissions
 * @command: command to check
 *
 * Return: 0 on success, 1 if file doesn't exist, 2 if permission denied
 */
int check_command(char *command)
{
	if (access(command, F_OK) != 0)
	{
		_puts(command);
		_puts(": command not found\n");
		return (1);
	}
	else if (access(command, X_OK) != 0)
	{
		_puts(command);
		_puts(": permission denied\n");
		return (2);
	}
	return (0);
}


/**
 * malloc_or_exit - returns malloc'd pointer or exits with error on failure
 * @n: number of bytes to malloc
 *
 * Return: malloc'd pointer or exits with error on failure
 */

void *malloc_or_exit(size_t n)
{
	void *result;

	result = malloc(n);
	if (result)
		return (result);
	else
	{
		perror(NULL);
		exit(1);
	}
}
