#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - function that sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: it's an array to be sorted
 * @size: it's the size of that array
 */
void counting_sort(int *array, size_t size)
{
	int *c, *o, maxi = 0;
	size_t x;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size; x++)
	{
		if (array[x] > maxi)
			maxi = array[x];
	}

	c = malloc((maxi + 1) * sizeof(int));
	o = malloc(size * sizeof(int));

	if (c == NULL || o == NULL)
		return;

	for (x = 0; x <= (size_t)maxi; x++)
		c[x] = 0;

	for (x = 0; x < size; x++)
		c[array[x]]++;

	for (x = 1; x <= (size_t)maxi; x++)
		c[x] += c[x - 1];

	print_array(c, maxi + 1);

	for (x = size - 1; (int)x >= 0; x--)
	{
		o[c[array[x]] - 1] = array[x];
		c[array[x]]--;
	}

	for (x = 0; x < size; x++)
		array[x] = o[x];

	free(c);
	free(o);
}
