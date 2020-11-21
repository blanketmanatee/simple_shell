#include "simple.h"

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

	if (_strstr(s1, delim) == s1 && *delim != ' ')
		result[j++] = _strdup("");
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


int split_len(char **cmd_args)
{
	int i;

	for (i = 0; cmd_args[i]; ++i)
		;
	return (i);
}

char **split_add(char **pieces, char *add)
{
	int len = 0;
	char **new_pieces;

	if (!pieces)
		len = 0;
	else
		len = split_len(pieces);

	new_pieces = malloc_or_exit(sizeof(char *) * (len + 2));
	if (pieces)
	{
		_memcpy(new_pieces, pieces, sizeof(char *) * (len + 1));
		free(pieces);
	}
	new_pieces[len] = add;
	new_pieces[len + 1] = NULL;
	return (new_pieces);
}

int split_remove(char **pieces, char *remove)
{
	int ret = 0;

	for (; *pieces && *pieces != remove; ++pieces)
		;
	if (*pieces)
		ret = 1;

	for (; *pieces; pieces++)
		pieces[0] = pieces[1];

	return (ret);
}
