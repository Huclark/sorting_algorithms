#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 * @array: An array of integers to sort
 * @size: Size of array to sort
*/
void bubble_sort(int *array, size_t size)
{
	int tmp, flag;
	size_t i, j;

	/* If array is empty there is nothing to sort */
	if (!array || size < 2)
		return;

	/* Iterate through array */
	i = 0;
	while (i < size - 1)
	{
		/* Set flag to break loop */
		flag = 1;

		/* Iterate through remaining unsorted numbers */
		j = 0;
		while (j < size - i - 1)
		{
			/* Compare two numbers */
			if (array[j] > array[j + 1])
			{
				/* Swap if unsorted */
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				/* Print the array */
				print_array(array, size);

				/* Set flag to continue loop */
				flag = 0;
			}
			j++;
		}

		/* Array is sorted if true, break loop */
		if (flag)
			break;
		i++;
	}
}
