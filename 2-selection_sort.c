#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm
 * @array: Array to sort
 * @size: Size of array to sort
*/
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, k;

	if (!array || size < 2)
		return;

	i = 0;
	while (i < size - 1)
	{
		k = i;
		j = i + 1;

		while (j < size)
		{
			if (array[j] < array[k])
				k = j;
			j++;
		}
		if (k != i)
		{
			tmp = array[k];
			array[k] = array[i];
			array[i] = tmp;

			print_array(array, size);
		}
		i++;
	}
}
