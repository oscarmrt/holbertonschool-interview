#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - Function that compares two strings s1 and s2
 * @s1: string to compare
 * @s2: string to compare can contain the special character *. The special
 * char * can replace any string (including an empty string)
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (!*s2);
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
