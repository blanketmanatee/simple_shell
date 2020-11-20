#include "simple.h"

/**
 * getline_failure - handles ctrl + D or getline read failure including EOF
 * @line: line read from getline
 * @n_characters: number of chars read from getline (-1 on failure or EOF)
 *
 * Return: none
 */
int getline_failure(int n_characters, int *ext)
{
	if (n_characters == -1)
	{
		if (errno)
			perror(NULL);
		_puts("\r");
		*ext = 1;
		return (1);
	}
	return (0);
}


/**
 * check_command - checks for existence of command and execution permissions
 * @cmd_args: arguments from user
 *
 * Return: command path or NULL on failure
 */
char *check_command(char **cmd_args)
{
	char *cmd;

	if (!_strstr(cmd_args[0], "/"))
		cmd = search_path(cmd_args[0]);
	else
		cmd = _strdup(cmd_args[0]);

	if (!cmd || access(cmd, F_OK) != 0)
	{
		_puts(cmd_args[0]);
		_puts(": command not found\n");
		if (cmd)
			free(cmd);
		return (NULL);
	}
	else if (access(cmd, X_OK) != 0)
	{
		_puts(cmd);
		_puts(": permission denied\n");
		free(cmd);
		return (NULL);
	}
	return (cmd);
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
	if (!result)
	{
		perror(NULL);
		exit(1);
	}
	return (result);
}

int env_name_errs(const char *name)
{
	int i = 0;

	if (!name || !_strlen(name))
	{
		errno = EINVAL;
		perror("Variable name required");
		return (-1);
	}
	for (i = 0; name[i]; ++i)
	{
		if (name[i] == '=')
		{
			errno = EINVAL;
			perror("Variable name cannot contain '='");
			return (-1);
		}
	}
	return (0);
}
