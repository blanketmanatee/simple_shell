#include "simple.h"

/**
 * search_builtins - checks if matches builtins
 * @cmd_args: array of str from cmd line
 * @ext: exit code
 * @env_allocs: memory management for env to cleanup before exit
 * Return: 1 if finds builtin 0 if not
 */

int search_builtins(char **cmd_args, int *ext, char ***env_allocs)
{
	char *cmd = cmd_args[0];

	if (!_strcmp(cmd, "exit"))
	{
		my_exit(cmd_args, ext);
		return (1);
	}
	if (!_strcmp(cmd, "env"))
	{
		print_env();
		return (1);
	}
	if (!_strcmp(cmd, "setenv"))
	{
		if (split_len(cmd_args) < 2)
			_setenv(cmd_args[1], NULL, env_allocs);
		else
			_setenv(cmd_args[1], cmd_args[2], env_allocs);
		return (1);
	}
	if (!_strcmp(cmd, "unsetenv"))
	{
		_unsetenv(cmd_args[1], env_allocs);
		return (1);
	}
	return (0);
}

/**
 * my_exit - exits
 * @cmd_args: command line args
 * @ext: exit
 * Return: void
 */

void my_exit(char **cmd_args, int *ext)
{
	int i;
	char *raw_code = cmd_args[1];

	if (raw_code)
	{
		for (i = 0; raw_code[i]; ++i)
			if (raw_code[i] < '0' || raw_code[i] > '9')
			{
				_puts(cmd_args[0]);
				_puts(": ");
				_puts(raw_code);
				_puts(": numeric argument required\n");
				*ext = 1;
				return;
			}
		*ext = _atoi(raw_code);
		return;
	}
	*ext = 0;
}

/**
 * print_env - print environment
 * Return: void
 */

void print_env(void)
{
	int i;

	for (i = 0; environ[i]; ++i)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}

/**
 * _setenv - sets new env var or modify existing
 * @name: name variable
 * @value: value of variable
 * @env_allocs: memory that is set for variable
 * Return: -1 on error 0 on success
 */

int _setenv(const char *name, const char *value, char ***env_allocs)
{
	int idx = 0, len = 0;

	if (env_name_errs(name) == -1)
		return (-1);

	idx = findenv(name);
	if (!value)
		value = "";
	if (environ[idx])
	{
		char *var = environ[idx];

		split_remove(*env_allocs, var);
		free(var);
	}
	else
		environ[idx + 1] = NULL;

	len = _strlen(name) + 1 + _strlen(value) + 1;

	environ[idx] = malloc_or_exit(sizeof(char) * len);
	_strcpy(environ[idx], name);
	_strcat(environ[idx], "=");
	_strcat(environ[idx], value);
	*env_allocs = split_add(*env_allocs, environ[idx]);
	return (0);
}

/**
 * _unsetenv - deletes env variable
 * @name: name of variable
 * @env_allocs: tracks memory for variable
 * Return: -1 or 0
 */

int _unsetenv(const char *name, char ***env_allocs)
{
	int idx = 0;

	if (env_name_errs(name) == -1)
		return (-1);

	idx = findenv(name);
	if (environ[idx])
	{
		char *var = environ[idx];

		split_remove(environ, var);
		if (*env_allocs && split_remove(*env_allocs, var))
			free(var);
	}
	return (0);
}
