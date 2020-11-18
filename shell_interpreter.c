#include "simple.h"

/**
 * main - displays shell prompt and executes command
 *
 * Return: always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n_characters;
	char **cmd_args, *cmd;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		errno = 0;
		n_characters = getline(&line, &len, stdin);
		getline_failure(line, n_characters);
		line[n_characters - 1] = '\0';
		if (n_characters > 1)
		{
			cmd_args = split_delim(line, " ");
			cmd = check_command(cmd, cmd_args);
			if (!cmd)
			{
				clean_up(&cmd_args, &line);
				continue;
			}
			free(cmd_args[0]);
			cmd_args[0] = cmd;
			if (fork() == 0)
			{
				execve(cmd_args[0], cmd_args, NULL);
				perror(NULL);
			}
			else
			{
				wait(NULL);
				clean_up(&cmd_args, &line);
			}
		}
	}
	return (0);
}


/**
 * split_delim - breaks a string into pieces based on a delimiter
 * @s: string to split
 * @delim: delimiter to split string up around
 *
 * Return: array of strings
 */
char **split_delim(char *s, const char *delim)
{
	char *s1, *piece, *ptr;
	int i = 0, j = 0;
	char **result;

	for (i = 0, ptr = s; (ptr = _strstr(ptr, delim)); ++i, ++ptr)
		;

	result = malloc_or_exit(sizeof(char *) * (i + 2));

	s1 = _strdup(s);

	piece = strtok(s1, delim);

	while (piece)
	{
		result[j++] = _strdup(piece);
		piece = strtok(NULL, delim);
	}
	result[j] = NULL;

	free(s1);
	return (result);
}


/**
 * free_split - frees arrays of strings
 * @array: array of strings to be freed
 *
 * Return: none
 */
void free_split(char **array)
{
	int i;

	if (array)
	{
		for (i = 0; array[i]; ++i)
			free(array[i]);
		free(array);
	}
}


/**
 * clean_up - frees arrays of strings and lines and sets them to null
 * @array: pointer to array of strings
 * @line: pointer to a string (line)
 *
 * Return: none
 */
void clean_up(char ***array, char **line)
{
	if (line)
		free(*line);

	if (array)
		free_split(*array);

	*line = NULL;
	*array = NULL;
}
