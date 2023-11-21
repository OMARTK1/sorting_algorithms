#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge_array - function that merge two subarrays
 *                  of the given array in the specified order
 * @array: it's the array to be merged
 * @down: it's the starting index of that first subarray
 * @c: the Nb of elements to be merged
 * @top: 1 if merging in ascending order, 0 if merging in descending order
 */
void bitonic_merge_array(int *array, size_t down, size_t c, int top)
{
	if (c > 1)
	{
		size_t k = c / 2;
		size_t n;

		printf("Merging [%lu/%lu] (%s):\n", c, c, (top ? "UP" : "DOWN"));
		print_array(array + down, c);

		for (n = down; n < down + k; ++n)
		{
			if ((array[n] > array[n + k]) == top)
			{
				int temp = array[n];

				array[n] = array[n + k];
				array[n + k] = temp;

				printf("Result [%lu/%lu] (%s):\n", c, c, (top ? "UP" : "DOWN"));
				print_array(array + down, c);
			}
		}

		bitonic_merge(array, down, k, top);
		bitonic_merge(array, down + k, k, top);
	}
}

/**
 * bitonic_sort_r - funtion that recursively sorts a bitonic sequence
 *                          in ascending order
 * @array: it's the array to be sorted
 * @down: it's the starting index of the sequence
 * @c: the Nb of elements in the sequence
 * @top: 1 if sorting in ascending order, 0 if sorting in descending order
 */
void bitonic_sort_r(int *array, size_t down, size_t c, int top)
{
	if (c > 1)
	{
		size_t k = c / 2;

		bitonic_sort_recursive(array, down, k, 1);

		bitonic_sort_recursive(array, down + k, k, 0);

		bitonic_merge(array, down, c, top);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                  using Bitonic sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	printf("Merging [%lu/%lu] (UP):\n", size, size);
	print_array(array, size);

	bitonic_sort_recursive(array, 0, size, 1);
}
