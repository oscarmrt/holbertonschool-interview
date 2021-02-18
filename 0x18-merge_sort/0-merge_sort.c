#include "sort.h"
/**
 * merge_aux - merges left and right arrays
 * @array: pointer to array
 * @size: size of the array
 * @left: pointer to left array
 * @right: pointer to right array
 **/
void merge_aux(int *array, int *left, int *right, size_t size)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int left_size;
	int right_size;

	left_size = size / 2;
	right_size = size - left_size;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	while (i < left_size && j < right_size)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < left_size)
		array[k++] = left[i++];
	while (j < right_size)
		array[k++] = right[j++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - Function that sorts an array of integers in ascending
 * order using the Merge Sort algorithm
 * @array: pointer to array to sort
 * @size: size of the array to sort
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i;
	int left[MAX];
	int right[MAX];

	if (array == NULL || size < 2)
		return;
	mid = size / 2;
	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge_aux(array, left, right, size);
}
