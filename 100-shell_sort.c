#include "sort.h"

/**
* shell_sort - Sorts an array of integers in ascending order
*              using the Shell sort algorithm with the Knuth sequence
* @array: The array to be sorted
* @size: The size of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	/* Calculate the initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Iterate over decreasing gaps */
	while (gap > 0)
	{
		/* Perform insertion sort for the current gap */
		i = gap;
		while (i < size)
		{
			temp = array[i];

			/* Shift elements to their correct position within the gap */
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			/* Place the current element in its correct position */
			array[j] = temp;
			i++;
		}
		/* Print the array after each iteration for visualization */
		print_array(array, size);

		/* Reduce the gap according to Knuth sequence */
		gap /= 3;
	}
}
