#include "sort.h"
/**
 * bubble_sort - a fuction that sorts an array of ints in ascending order
 * using the bubble sort
 * @array: the sorted array
 * @size: Nb of items in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t m, n;
	int val;
	int swaps;

	for (m = 0; m < size - 1; m++)
	{
		swaps = 0;
		for (n = 0; n < size - m - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				val = array[n];
				array[n] = array[n + 1];
				array[n + 1] = val;
				swaps = 1;

				print_array(array, size);
			}
		}
		if (swaps == 0)
			break;
	}
}
