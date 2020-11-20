#include "simple.h"

/**
 * main - displays shell prompt and executes command
 *
 * Return: always 0
 */
int main(void)
{
	char **cmd_args = NULL, *cmd = NULL, **env_a = NULL, *line = NULL;
	size_t len = 0;
	ssize_t n_characters = 0;
	int ext = -1;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		errno = 0;
		n_characters = getline(&line, &len, stdin);
		if (getline_failure(n_characters, &ext))
			clean_up(&cmd_args, &line, &env_a, ext);
		line[n_characters - 1] = '\0';
		if (n_characters > 1)
		{
			cmd_args = split_delim(line, " ");
			if (search_builtins(cmd_args, &ext, &env_a))
			{
				clean_up(&cmd_args, &line, &env_a, ext);
				continue;
			}
			cmd = check_command(cmd_args);
			if (!cmd)
			{
				clean_up(&cmd_args, &line, &env_a, ext);
				continue;
			}
			free(cmd_args[0]);
			cmd_args[0] = cmd;
			run_cmd(cmd_args, &ext);
		}
		clean_up(&cmd_args, &line, &env_a, ext);
	}
	return (0);
}

void run_cmd(char **cmd_args, int *ext)
{
	if (fork() == 0)
	{
		execve(cmd_args[0], cmd_args, NULL);
		perror(NULL);
		*ext = 1;
	}
	else
		wait(NULL);
}


/**
 * clean_up - frees arrays of strings and lines and sets them to null
 * @array: pointer to array of strings
 * @line: pointer to a string (line)
 *
 * Return: none
 */
void clean_up(char ***array, char **line, char ***env_a, int ext)
{
	if (*line)
		free(*line);
	*line = NULL;
	if (*array)
		free_split(*array);
	*array = NULL;
	if (ext != -1)
	{
		if (*env_a)
			free_split(*env_a);
		exit(ext);
	}
}
