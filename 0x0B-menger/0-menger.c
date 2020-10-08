#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 * Return: If level is lower than 0, your function must do nothing
 */
void menger(int level)
{
	int x;
	int y;
	int size = pow(3, level);

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < size; y++)
		{
			printf("%c", sChar(x, y));
		}
		printf("\n");
	}
}

/**
 * sChar - Function to print the # char
 * @x: the x value
 * @y: the y value
 * Return: the character to print
 */
char sChar(int x, int y)
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
