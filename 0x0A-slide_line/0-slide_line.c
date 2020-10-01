#include "slide_line.h"

/**
 * slide_line - Slide and merge an array
 * @line: Pointer to an array of integers containing size elements
 * @size: Size of the elements
 * @direction: Direction to slide and merge array
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t helper, crrnt = 0, pos1 = 0, pos2 = 1, x, y;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	pos1 = (direction == SLIDE_RIGHT) ? size - 1 : pos1;
	pos2 = (direction == SLIDE_RIGHT) ? size - 2 : pos2;

	for (x = 0; x < size; x++)
	{       helper = pos2;
		crrnt = 0;
		for (y = x + 1; y < size; y++)
		{
			if (line[pos1] != 0 && line[pos2] == line[pos1])
			{
				line[pos1] = line[pos1] * 2;
				line[pos2] = 0;
				break;
			}
			if (line[pos1] == 0 && line[pos2] != 0)
			{
				line[pos1] = line[pos2];
				line[pos2] = 0;
				crrnt = 1;
				pos2 = helper;
				x--;
				break;
			}
			if (line[pos2] != 0)
				break;
			direction == SLIDE_LEFT ? pos2++ : pos2--;
		}
		if (line[pos1] == 0)
			break;
		if (crrnt == 0)
		{	pos1 = (direction == SLIDE_LEFT) ? pos1 + 1 : pos1;
			pos1 = (direction == SLIDE_RIGHT) ? pos1 - 1 : pos1;
			pos2 = (direction == SLIDE_LEFT) ? pos1 + 1 : pos2;
			pos2 = (direction == SLIDE_RIGHT) ? pos1 - 1 : pos2; }
	}
	return (1);
}
