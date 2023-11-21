include "sort.h"

/**
 * swap - swaps two elements in an array
 * @array: the array
 * @i: the index of the first element
 * @j: the index of the second element
 * @size: the size of the array
 */
void swap(int *array, int i, int j, size_t size)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * sift_down - repairs the heap whose root element is at index start
 * @array: the array
 * @start: the root index
 * @end: the last index of the heap
 * @size: the size of the array
 */
void sift_down(int *array, int start, int end, size_t size)
{
	int root, left, right, swaps;

	root = start;
	while (root * 2 + 1 <= end)
	{
		left = root * 2 + 1;
		right = root * 2 + 2;
		swaps = root;

		if (array[swaps] < array[left])
			swaps = left;
		if (right <= end && array[swaps] < array[right])
			swaps = right;
		if (swaps == root)
			return;
		else
		{
			swap(array, root, swaps, size);
			root = swaps;
		}
	}
}

/**
 * heapify - creates a max heap from an array
 * @array: the array
 * @size: the size of the array
 */
void heapify(int *array, size_t size)
{
	int start;

	start = (size - 2) / 2;
	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	int end;

	if (array == NULL || size < 2)
		return;

	/* Create a max heap from the array */
	heapify(array, size);

	/* Extract the elements from the heap one by one */
	end = size - 1;
	while (end > 0)
	{
		/* Swap the root (maximum) with the last element */
		swap(array, 0, end, size);

		/* Reduce the heap size by one */
		end--;

		/* Restore the max heap property */
		sift_down(array, 0, end, size);
	}
}
