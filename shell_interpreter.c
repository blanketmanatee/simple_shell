#include "simple.h"

/**
 * main - displays shell prompt and sends command  split executed calls cleanup
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
		if (isatty(STDIN_FILENO))/*checks for mode*/
			_puts("$ ");
		errno = 0;/*resets to check for failure*/
		n_characters = getline(&line, &len, stdin);
		if (getline_failure(n_characters, &ext)) /*error handling*/
			clean_up(&cmd_args, &line, &env_a, ext);
		line[n_characters - 1] = '\0';
		if (n_characters > 1)
		{
			cmd_args = split_delim(line, " ");/*if builtin runs w/o execve*/
			if (search_builtins(cmd_args, &ext, &env_a))
			{
				clean_up(&cmd_args, &line, &env_a, ext);
				continue;
			}
			cmd = check_command(cmd_args);/*check if PATH is input calls search path*/
			if (!cmd)/*checks for file and execute permissions*/
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

/**
 * run_cmd - execve
 * @cmd_args: commnd and args
 * @ext: exit code
 * Return: void
 */

void run_cmd(char **cmd_args, int *ext)
{
	pid_t pid = fork();

	if (pid < 0)
		perror(NULL);
	if (pid == 0)
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
 * @env_a: env alloc env memory
 * @ext: exit code
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
