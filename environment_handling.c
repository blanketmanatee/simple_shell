#include "simple.h"

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

char *_getenv(const char *name)
{
	char *env;

	env = environ[findenv(name)];
	if (env)
		return (_strstr(env, "=") + 1);
	return (NULL);
}
