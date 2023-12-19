#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm (Hoare partition scheme)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive_hoare(array, 0, size - 1);
}

/**
 * quick_sort_recursive_hoare - Recursively sorts subarrays using Quick sort
 *                               with Hoare partition scheme
 * @array: The array to be sorted
 * @low: The low index of the subarray
 * @high: The high index of the subarray
 */
void quick_sort_recursive_hoare(int *array, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high);
		quick_sort_recursive_hoare(array, low, pivot - 1);
		quick_sort_recursive_hoare(array, pivot + 1, high);
	}
}

/**
 * hoare_partition - Partitions the array using Hoare's scheme
 * @array: The array to be partitioned
 * @low: The low index of the partition
 * @high: The high index of the partition
 * Return: The index of the pivot
 */
int hoare_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;
	int temp;

	do {
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, high + 1);
		}

	} while (i < j);

	return (j);
}
