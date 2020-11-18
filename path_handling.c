#include "simple.h"

char *search_path(char *command)
{
	int i = 0, len = 0;
	char *PATH, *current_path, **whole_path;

	PATH = _getenv("PATH");
	if (!PATH)
	{
		_puts("$PATH not set.\n");
		return (NULL);
	}
	whole_path = split_delim(PATH, ":");

	for (i = 0; whole_path[i]; ++i)
	{
		len = _strlen(whole_path[i]) + 1 + _strlen(command) + 1;
		current_path = malloc_or_exit(sizeof(char) * len);
		_strcpy(current_path, whole_path[i]);
		_strcat(current_path, "/");
		_strcat(current_path, command);
		if (access(current_path, F_OK) == 0)
		{
			free_split(whole_path);
			return (current_path);
		}
		free(current_path);
	}
	free_split(whole_path);
	return (NULL);
}
