#include "sort.h"

/**
 * lomuto_partition - partition through an array of integers
 * @array: array of integers
 * @size: the size of the array
 * @l: first index of array
 * @h: last index of array
 * Return: new index position
 */
int lomuto_partition(int *array, size_t size, int l, int h)
{
	int pivot = array[h], i = l, j;
	int tmp;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		tmp = array[i];
		array[i] = array[h];
		array[h] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_sort - implement the quick sort algorithm using recursion
 * @array: the array
 * @size: the size of the array
 * @l: first index of the array
 * @h: the last index of the array
 */

void lomuto_sort(int *array, size_t size, int l, int h)
{
	int i;

	if (l < h)
	{
		i = lomuto_partition(array, size, l, h);
		lomuto_sort(array, size, l, i - 1);
		lomuto_sort(array, size, i + 1, h);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order
 * @array: the array
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
