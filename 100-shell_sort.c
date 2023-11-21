#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - function sorts an array of integers in ascending order
 *               using the Shell sort algorithm with Knuth sequence
 * @array: it's an array to be sorted
 * @size: it's size of that array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, x, y;
	int tmp;

	while (gap < size)
		gap = gap * 3 + 1;

	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (x = gap; x < size; x++)
		{
			tmp = array[x];
			for (y = x; y >= gap && array[y - gap] > tmp; y -= gap)
			{
				array[y] = array[y - gap];
			}
			array[y] = tmp;
		}
		print_array(array, size);
	}
}
