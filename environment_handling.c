#include "simple.h"
/**
 * findenv - gets index of environment variable from existing env
 * @name: name of variable
 * Return: index or index of NULL terminator of env
 */
int findenv(const char *name)
{
	int i = 0;
	char **n_v, *n;

	for (i = 0; environ[i]; ++i)
	{
		n_v = split_delim(environ[i], "=");
		n = n_v[0];
		if (!_strcmp(n, name))
		{
			free_split(n_v);
			return (i);
		}
		free_split(n_v);
	}
	return (i);
}

/**
 * _getenv - returns ptr to value of env variable
 * @name: name of variable
 * Return: ptr or NULL
 */

char *_getenv(const char *name)
{
	char *env;

	env = environ[findenv(name)];
	if (env)
		return (_strstr(env, "=") + 1);
	return (NULL);
}
