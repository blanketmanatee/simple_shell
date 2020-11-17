#include "simple.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n_characters;
	char **cmd_args;

	while (1)
	{
		_puts("$ ");
		errno = 0;
		n_characters = getline(&line, &len, stdin);
		getline_failure(line, n_characters);
		line[n_characters - 1] = '\0';
		if (n_characters > 1)
		{
			cmd_args = split_delim(line, " ");
			if (check_command(cmd_args[0]))
			{
				clean_up(&cmd_args, &line);
				continue;
			}
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

void free_split(char **array)
{
	int i;

	for (i = 0; array[i]; ++i)
		free(array[i]);
	free(array);
}

void clean_up(char ***array, char **line)
{
	if (line)
		free(*line);

	if (array)
		free_split(*array);

	*line = NULL;
	*array = NULL;
}
