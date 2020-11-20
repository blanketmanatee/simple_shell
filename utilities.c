#include "simple.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to be printed
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}


/**
 * _puts - prints a string to stdout
 * @str: pointer to string to be printed
 *
 * Return: none
 */
void _puts(const char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}


/**
 * _strdup - returns a pointer to a newly allocated space in memory which
 * contains a copy of the string given as a parameter
 * @str: string to make copy of
 *
 * Return: pointer to memory space containing string or NULL if str = NULL or
 * if insufficient memory was available
 */
char *_strdup(const char *str)
{
	char *strcopy;
	int l = 0;
	int i;

	if (str == 0)
		return (NULL);

	while (str[l] != '\0')
		l++;

	strcopy = malloc_or_exit(sizeof(char) * (l + 1));

	for (i = 0; i <= l; ++i)
		strcopy[i] = str[i];

	return (strcopy);
}


/**
 * _strstr - locates a substring
 * @haystack: string
 * @needle: substring to locate within haystack
 *
 * Return: pointer to the beginning of the located substring or NULL if the
 * substring is not found
 */
char *_strstr(const char *haystack, const char *needle)
{
	const char *needleCtr, *haystackCtr;

	while (*haystack)
	{
		needleCtr = needle;
		haystackCtr = haystack;
		while (*needleCtr == *haystackCtr && *needleCtr && *haystackCtr)
		{
			++needleCtr;
			++haystackCtr;
		}
		if (*needleCtr == '\0')
			return ((char *)haystack);
		++haystack;
	}
	return (0);
}


/**
 * _strlen - returns the length of a string
 * @s: pointer to a char array
 *
 * Return: length of string
 */

size_t _strlen(const char *s)
{
	size_t l = 0;

	while (s[l] != '\0')
		l++;

	return (l);
}
