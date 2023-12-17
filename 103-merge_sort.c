#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, size);
}

/**
 * merge_sort_recursive - Recursively divides and merges the array
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort_recursive(int *array, size_t size)
{
	size_t mid = size / 2;

	if (size < 2)
		return;

	merge_sort_recursive(array, mid);
	merge_sort_recursive(array + mid, size - mid);
	merge(array, mid, size);
}

/**
 * merge - Merges two subarrays into a sorted array
 * @array: The original array containing two sorted subarrays
 * @mid: The midpoint index
 * @size: The size of the array
 */
void merge(int *array, size_t mid, size_t size)
{
	size_t i, j, k;
	size_t left_size = mid;
	size_t right_size = size - mid;
	int *left = malloc(left_size * sizeof(int));
	int *right = malloc(right_size * sizeof(int));

	if (!left || !right)
	{
		free(left);
		free(right);
		return;
	}

	for (i = 0; i < left_size; i++)
		left[i] = array[i];

	for (j = 0; j < right_size; j++)
		right[j] = array[mid + j];

	i = j = 0;
	k = 0;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
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

	free(left);
	free(right);
}
