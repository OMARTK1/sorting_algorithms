#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using Quick sort
 * @array: it's an array to be sorted
 * @size: Nb of elements in that array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_r(array, 0, size - 1, size);
}

/**
 * quick_sort_r - function that recursive for Quick sort
 * @array: it's an array to be sorted
 * @l: it's the lowest index of the partition
 * @h: it's the highest index of the partition
 * @size: Nb of elements in that array
 */
void quick_sort_r(int *array, int l, int h, size_t size)
{
	int p;

	if (l < h)
	{
		p = partition_arr(array, l, h, size);
		quick_sort_r(array, l, p - 1, size);
		quick_sort_r(array, p + 1, h, size);
	}
}

/**
 * partition_arr - function that partitions the array for Quick sort
 * @array: it's an array to be sorted
 * @l: it's the lowest index of the partition
 * @h: it's the highest index of the partition
 * @size: Nb of elements in that array
 * Return: the index of the pivot (p)
 */
int partition_arr(int *array, int l, int h, size_t size)
{
	int p = array[h];
	int n = l - 1;
	int m, tmp;

	for (m = l; m <= h - 1; m++)
	{
		if (array[m] < p)
		{
			n++;
			tmp = array[n];
			array[n] = array[m];
			array[m] = tmp;
			print_array(array, size);
		}
	}

	tmp = array[n + 1];
	array[n + 1] = array[h];
	array[h] = tmp;
	print_array(array, size);

	return (n + 1);
}
