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

char *_strcpy(char *dest, char *src)
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

char *_strcat(char *dest, char *src)
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
