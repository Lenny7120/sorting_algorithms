#include "sort.h"

/**
 * get_max_custom - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max_custom(int *array, int size)
{
	int max_val, i;

	for (max_val = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}

	return (max_val);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                        using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count_custom, *sorted_custom, max_val_custom, i;

	if (array == NULL || size < 2)
		return;

	sorted_custom = malloc(sizeof(int) * size);
	if (sorted_custom == NULL)
		return;
	max_val_custom = get_max_custom(array, size);
	count_custom = malloc(sizeof(int) * (max_val_custom + 1));
	if (count_custom == NULL)
	{
		free(sorted_custom);
		return;
	}

	for (i = 0; i < (max_val_custom + 1); i++)
		count_custom[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_custom[array[i]] += 1;
	for (i = 0; i < (max_val_custom + 1); i++)
		count_custom[i] += count_custom[i - 1];
	print_array(count_custom, max_val_custom + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_custom[count_custom[array[i]] - 1] = array[i];
		count_custom[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_custom[i];

	free(sorted_custom);
	free(count_custom);
}
