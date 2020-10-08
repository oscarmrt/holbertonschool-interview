#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 * Return: If level is lower than 0, your function must do nothing
 */
void menger(int level)
{
	int x = 0;
    int y = 0;
    int size = pow(3, level);

	for (; x < size; x++)
	{
		for (; y < size; y++)
		{
			printf("%c", sponge_char(x, y));
		}
		printf("\n");
	}
}

/**
 * sponge_char - Function to print the # char
 * @x: the x value
 * @y: the y value
 * Return: the character to print
 */
char sponge_char(int x, int y)
{
	while (x && y)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (' ');

		x /= 3;
		y /= 3;
	}
	return ('#');
}
