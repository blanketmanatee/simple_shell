#include "simple.h"

/**
 * _strcmp - compares two strings
 * @s1: a pointer to a string to compare
 * @s2: a pointer to another string to compare
 *
 * Return: an int less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match or be greater than s2.
 */

int _strcmp(const char *s1, const char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}

/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * null byte, to the buffer pointed to by dest
 * @dest: pointer to desination buffer
 * @src: pointer to the source string
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i, l = 0;

	while (src[l] != '\0')
		l++;

	for (i = 0; i <= l; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strcat - appends the src string to the dest string
 * @dest: string to be appended to
 * @src: string appended to dest
 *
 * Return: pointer to dest
 */

char *_strcat(char *dest, const char *src)
{
	int i, dl = 0, sl = 0;

	while (dest[dl] != '\0')
		dl++;

	while (src[sl] != '\0')
		sl++;

	for (i = 0; i < sl; i++)
		dest[dl + i] = src[i];

	dest[dl + i] = '\0';

	return (dest);
}

/**
 * _atoi - converts a string to an int
 * @s: pointer to a string
 *
 * Return: int from string (0 if string contains no ints)
 */

int _atoi(char *s)
{
	int i = 0, j = 0, sign = 1;

	while ((s[i] < '0' || s[i] > '9') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		j = j * 10 + sign * (s[i] - '0');
		i++;
	}

	return (j);
}

/**
 * _memcpy - copies memory area
 * @dest: area to be copied to
 * @src: area that is copied
 * @n: number of bytes copied from src
 *
 * Return: pointer to dest
 */

void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int i;
	unsigned char *d = dest;
	const unsigned char *s = src;

	for (i = 0; i < n; ++i)
		d[i] = s[i];

	return (d);
}
