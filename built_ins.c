#include "simple.h"

int search_builtins(char **cmd_args, int *ext)
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
	return (0);
}

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

void print_env(void)
{
	int i;

	for (i = 0; environ[i]; ++i)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}
