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
		; /*checking string for num of delim to set up space in array*/

	result = malloc_or_exit(sizeof(char *) * (i + 2));
 /*malloc space for array inc delim and null*/

	s1 = _strdup(s); /*duplicates str before strtok to save orig*/

	if (_strstr(s1, delim) == s1 && *delim != ' ')
		result[j++] = _strdup("");
	piece = strtok(s1, delim);

	while (piece)
	{
		result[j++] = _strdup(piece); /*filling array with tokens from str*/
		piece = strtok(NULL, delim);
	}
	result[j] = NULL;

	free(s1); /*frees duplicate str*/
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
 * split_len - checks size of array of arrays
 * @array: array
 * Return: size of array
 */

int split_len(char **array)
{
	int i;

	for (i = 0; array[i]; ++i)
		;
	return (i);
}

/**
 * split_add - add elements to array of arrays
 * @pieces: array of array elemts added to
 * @add: pieces being added
 * Return: array w added element
 */

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

/**
 * split_remove - remove elements
 * @pieces: array
 * @remove: element being removed
 * Return: 0 if fail 1 if success
 */

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
