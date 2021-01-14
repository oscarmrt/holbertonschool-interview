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
		puts(s + 1);
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
/**
 * op_maker - Function that performs multiplication and addition
 * storing it in a string.
 * @num1: pointer to the first number.
 * @num2: pointer to the second number.
 * @len1: length of num1.
 * @len2: length of num2.
 * Return: result of multiply.
 */
char *op_maker(char *num1, char *num2, int len1, int len2)
{
	char *res = NULL;
	int i, j, aux;
	int total_len = len1 + len2;

	res = malloc(sizeof(char) * total_len);
	if (!res)
	{
		print_str("Error");
		exit(98);
	}
	for (i = 0; i < total_len; i++)
		res[i] = '0';
	for (i = len1 - 1; i >= 0; i--)
	{
		aux = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			aux += (num1[i] - '0') * (num2[j] - '0');
			aux += res[i + j + 1] - '0';
			res[i + j + 1] = (aux % 10) + '0';
			aux /= 10;
		}
		if (aux)
			res[i + j + 1] = (aux % 10) + '0';
	}
	return (res);
}
/**
 * main - Function that multiplies two positive numbers.
 * @nums: double pointer to num1, num2
 * @ct: counter for the numbers.
 * Return: 0 if success and status 98 if error..
 */
int main(int ct, char **nums)
{
	int len1 = 0, len2 = 0;
	char *num1 = nums[1], *num2 = nums[2], *res = NULL;

	if (ct != 3 || is_digit(num1) || is_digit(num2))
	{
		print_str("Error");
		exit(98);
	}
	if (nums[1][0] == 48 || nums[2][0] == 48)
	{
		print_str("0");
		exit(0);
	}
	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	res = op_maker(num1, num2, len1, len2);
	if (res[0] == '0')
		print_str(res + 1);
	else
		print_str(res);
	free(res);
	return (0);
}
