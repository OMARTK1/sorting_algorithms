#include "sort.h"

/**
 * quick_sort_hoare - function sorts an array of integers
 *                      in ascending order using the Quick sort algorithm
 *                      with Hoare partition scheme
 * @array: it's an array to be sorted
 * @size: it's the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_hoare(array, 0, size - 1, size);
}

/**
 * sort_hoare - function recursively sorts partitions of the array
 *              using the Quick sort algorithm with Hoare partition scheme
 * @array: it's ana array to be sorted
 * @l: it's the starting index of the partition to be sorted
 * @h: it's the ending index of the partition to be sorted
 * @size: it's the size of the array
 */
void sort_hoare(int *array, int l, int h, size_t size)
{
	if (l < h)
	{
		int pivot = partition_hoare(array, l, h, size);

		sort_hoare(array, l, pivot, size);
		sort_hoare(array, pivot + 1, h, size);
	}
}

/**
 * partition_hoare - function that partitions the array using the Hoare scheme
 * @array: it's an array to be partitioned
 * @l: it's the starting index of the partition
 * @h: it's the ending index of the partition
 * @size: it's the size of the array
 * Return: it's the index of the pivot element
 */
int partition_hoare(int *array, int l, int h, size_t size)
{
	int pivot = array[l];
	int n = l - 1;
	int m = h + 1;

	while (1)
	{
		do {
			n++;
		} while (array[n] < pivot);

		do {
			m--;
		} while (array[m] > pivot);

		if (n >= m)
			return (m);

		swap(&array[n], &array[m]);
		print_array(array, size);
	}
}

/**
 * swap - function that swaps two elements in an array
 * @x: it's pointer to the first element
 * @y: it's pointer to the second element
 */
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
