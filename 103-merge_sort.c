#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * merge - function that merges two subarrays into a single sorted array
 * @array: it's the main array
 * @l: it's pointer to that left subarray
 * @l_size: it's the size of that left subarray
 * @r: it's pointer to that right subarray
 * @r_size: it's thr size of that right subarray
 */
void merge(int *array, int *l, size_t l_size,
		int *r, size_t r_size)
{
	size_t n = 0, m = 0, k = 0;
	int *tmp;

	tmp = malloc((l_size + r_size) * sizeof(int));
	if (tmp == NULL)
		return;

	while (n < l_size && m < r_size)
	{
		if (l[n] <= r[m])
		{
			tmp[k] = l[n];
			n++;
		}
		else
		{
			tmp[k] = r[m];
			m++;
		}
		k++;
	}
	while (n < l_size)
	{
		tmp[k] = l[n];
		n++;
		k++;
	}
	while (m < r_size)
	{
		tmp[k] = r[m];
		m++;
		k++;
	}
	for (m = 0; n < l_size + r_size; n++)
	{
		array[n] = tmp[n];
	}
	free(tmp);
}
/**
 * split_array - function that splits an array into two subarrays
 * @array: it's an array to be split
 * @size: it's the size of the array
 * @l: it's pointer to the left subarray
 * @r: it's pointer to the right subarray
 */
void split_array(int *array, size_t size, int **l, int **r)
{
	size_t mid = size / 2;
	*l = array;
	*r = array + mid;
}

/**
 * merge_sort - function that sorts an array of integers in ascending order
 *              using the Merge sort algorithm
 * @array: it's an array to be sorted
 * @size: it's the size of the array
 */
void merge_sort(int *array, size_t size)
{
    size_t mid;
	int *l, *r;

	if (array == NULL || size < 2)
		return;

	mid = size / 2;
	split_array(array, mid, &l, &r);

	merge_sort(l, mid);
	merge_sort(r, size - mid);

	merge(array, l, mid, r, size - mid);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, mid);
	printf("[right]: ");
	print_array(r, size - mid);
	printf("[Done]: ");
	print_array(array, size);
}
