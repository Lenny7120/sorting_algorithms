#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: The first element to be swapped
 * @b: The second element to be swapped
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions an array using Lomuto scheme
 * @array: The array to be partitioned
 * @size: The size of the array
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * Return: The final partition index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				/* Swap the elements */
				swap(&array[i], &array[j]);
				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > pivot)
	{
		/* Swap the pivot with the element at i + 1 */
		swap(&array[i + 1], &array[high]);
		/* Print the array after the swap */
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;

	if (array == NULL || size < 2)
		return;

	while (low < high)
	{
		int pi = lomuto_partition(array, size, low, high);

		if (pi - low < high - pi)
		{
			if (pi > low)
				quick_sort(array, pi - low);

			low = pi + 1;
		}
		else
		{
			if (pi < high)
				quick_sort(array + pi + 1, high - pi);

			high = pi - 1;
		}
	}
}
