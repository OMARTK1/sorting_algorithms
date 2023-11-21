#include "sort.h"
/**
 * selection_sort - function that sorts an array of ints in ascending order
 *  using the selection sort
 * @array: The sorted array
 * @size: Nb of items in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t m, n, idx;
	int tmp_var;

	for (m = 0; m < size - 1; m++)
	{
		idx = m;
		for (n = m + 1; n < size; n++)
		{
			if (array[n] < array[idx])
				idx = n;
		}

		if (idx != m)
		{
			tmp_var = array[m];
			array[m] = array[idx];
			array[idx] = tmp_var;
			print_array(array, size);
		}
	}
}
