#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two sub-arrays into one sorted array
 * @array: The original array containing the sub-arrays
 * @size: The size of the array
 * @left: The starting index of the left sub-array
 * @mid: The middle index splitting the two sub-arrays
 * @right: The ending index of the right sub-array
 * @temp: Temporary array to store merged elements
 */
void merge(int *array, size_t size, int left, int mid, int right, int *temp)
{
	int i = left, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = left; i < mid; i++)
	{
		printf("%d", array[i]);
		if (i < mid - 1)
			printf(", ");
	}
	printf("\n[right]: ");
	for (i = mid; i < right; i++)
	{
		printf("%d", array[i]);
		if (i < right - 1)
			printf(", ");
	}
	printf("\n");

	i = left;
	j = mid;

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j < right)
		temp[k++] = array[j++];

	for (i = left, k = 0; i < right; i++)
		array[i] = temp[k++];
}

/**
 * ms_recursive - Recursively sorts the array using Merge Sort
 * @array: The array to be sorted
 * @size: The size of the array
 * @temp: Temporary array to store merged elements
 * @left: The starting index of the sub-array
 * @right: The ending index of the sub-array
 */
void ms_recursive(int *array, size_t size, int *temp, int left, int right)
{
	if (right - left <= 1)
		return;

	int mid = (left + right) / 2;

	ms_recursive(array, size, temp, left, mid);
	ms_recursive(array, size, temp, mid, right);
	merge(array, size, left, mid, right, temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int *temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	ms_recursive(array, size, temp, 0, size);

	free(temp);
}
