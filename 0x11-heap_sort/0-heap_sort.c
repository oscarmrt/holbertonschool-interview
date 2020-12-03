#include "sort.h"
/**
 * swap - swap the position of two elements
 * @array1: array1
 * @array2: array2
 * Return: is a void
 */

void swap(int *array1, int *array2)
{
	int tmp;

	tmp = *array1;
	*array1 = *array2;
	*array2 = tmp;
}
/**
 * heapify - heap the array
 * @array: pointer to the array
 * @size: size of array
 * @i: max point
 * @length: lenght of the array after heap sort
 * Return: is a void
 */

void heapify(int *array, int size, int i, int length)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && array[max] < array[left])
	{
		max = left;
	}

	if (right < size && array[max] < array[right])
	{
		max = right;
	}

	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, length);
		heapify(array, size, max, length);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!size || !array)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}
	for (i = size - 1; i > 0; i--)
	{
		if (array[0] >= array[i])
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
		}
		heapify(array, i, 0, size);
	}
}
