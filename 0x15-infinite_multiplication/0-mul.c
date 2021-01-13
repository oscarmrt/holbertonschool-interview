#include "holberton.h"

/**
 * print_str - Function to print each string number
 * @s: pointer to the string
 * Return: void function
 */
void print_str(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		print_str(s + 1);
	}
}
/**
 * is_digit - Function to check if s is a number.
 * @s: pointer to the string.
 * Return: 0 if s is a number or 1 if not..
 */
int is_digit(char *s)
{
	int i, num = 0;

	for (i = 0; s[i] && !num; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			num++;
	}
	return (num);
}
