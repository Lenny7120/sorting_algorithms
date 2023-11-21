#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j;
	int i, temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate initial gap using Knuth sequence */
	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		/* Print the array after each decrease in the gap */
		print_array(array, size);
		/* Update gap using Knuth sequence */
		gap = (gap - 1) / 3;
	}
}
