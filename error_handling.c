#include "simple.h"

/**
 * getline_failure - handles ctrl + D or getline read failure including EOF
 * @line: line read from getline
 * @n_characters: number of chars read from getline (-1 on failure or EOF)
 *
 * Return: none
 */

void getline_failure(char *line, int n_characters)
{
	if (n_characters == -1)
	{
		if (errno)
			perror(NULL);
		free(line);
		_puts("\r");
		exit(1);
	}
}
