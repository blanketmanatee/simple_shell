#include "simple.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n_characters;
	char **array;

	while (1)
	{
		_puts("$ ");

		n_characters = getline(&line, &len, stdin);
		line[n_characters - 1] = '\0';
		if (n_characters > 1)
		{
			array = split_delim(line, " ");
			if (fork() == 0)
				execve(array[0], array, NULL);
			else
			{
				wait(NULL);
				free(line);
				line = NULL;
			}
			free_split(array);
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

	result = malloc(sizeof(char *) * (i + 2));

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
