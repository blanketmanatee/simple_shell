#include "simple.h"

static pid_t child_pid = -1;
#define REPROMPT \
{ \
	clean_up(&cmd_args, &line, &env_a, ext); \
	continue; \
}

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

	signal(SIGINT, sigint);
	while (1)
	{
		if (isatty(STDIN_FILENO))/*checks for mode*/
			_puts("$ ");
		errno = 0;/*resets to check for failure*/
		n_characters = getline(&line, &len, stdin);
		if (getline_failure(n_characters, &ext)) /*error handling*/
			clean_up(&cmd_args, &line, &env_a, ext);
		line[n_characters - 1] = '\0';
		if (strip_comments(line))
			REPROMPT
		if (n_characters > 1)
		{
			cmd_args = split_delim(line, " ");
			if (!cmd_args[0])
				REPROMPT
			if (search_builtins(cmd_args, &ext, &env_a))
				REPROMPT /*if builtin runs w/o execve*/
			/*check if absolute path, calls search PATH*/
			cmd = check_command(cmd_args);
			if (!cmd)/*checks for file and execute permissions*/
				REPROMPT
			free(cmd_args[0]);
			cmd_args[0] = cmd;
			run_cmd(cmd_args, &ext, &child_pid);
			child_pid = -1;
		}
		clean_up(&cmd_args, &line, &env_a, ext);
	}
	return (0);
}

/**
 * sigint - handles SIGINT (ctrl + c)
 * @sig: signal number
 *
 * Return: none
 */
void sigint(int sig)
{
	if (sig == SIGINT)
	{
		if (child_pid != -1)
		{
			kill(child_pid, SIGINT);
			if (isatty(STDIN_FILENO))
				_puts("\n");
		}
		else if (isatty(STDIN_FILENO))
			_puts("\n$ ");
	}
}

/**
 * strip_comments - takes out comments
 * @line: input from command line
 * Return: 1 if full line is comment, 0 otherwise
 */

int strip_comments(char *line)
{
	if (*line == '#')
		return (1);
	strtok(line, "#");
	return (0);
}

/**
 * run_cmd - execve
 * @cmd_args: commnd and args
 * @ext: exit code
 * @child_pid: pid of child process
 * Return: void
 */

void run_cmd(char **cmd_args, int *ext, pid_t *child_pid)
{
	*child_pid = fork();

	if (*child_pid < 0)
		perror(NULL);
	if (*child_pid == 0)
	{
		execve(cmd_args[0], cmd_args, environ);
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
