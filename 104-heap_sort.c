#include "sort.h"
/**
 * swapping - function that swaps 2 ints in an array
 * @i: it's Pointer to the first integer
 * @j: it's pointer to the second integer
 */
void swapping(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * sift_down - Performs the sift-down operation in the heap sort algorithm
 * @array: Array to be sorted
 * @size: it's the size of that array
 * @index: the index of the element to be sifted down
 * @heap_size: the size of the heap
 */
void sift_down(int *array, size_t size, size_t index, size_t heap_size)
{
	size_t large = index;
	size_t prev = 2 * index + 1;
	size_t nxt = 2 * index + 2;

	if (prev < heap_size && array[prev] > array[large])
		large = prev;

	if (nxt < heap_size && array[nxt] > array[large])
		large = nxt;

	if (large != index)
	{
		swapping(&array[index], &array[large]);
		print_array(array, size);
		sift_down(array, size, large, heap_size);
	}
}

/**
 * heap_sort - a function that sorts an array of ints in ascending order
 *  using the heap sort
 * @array: the sorted aray
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	size_t j;

	if (array == NULL || size < 2)
		return;

	for (j = size / 2; j > 0; --j)
		sift_down(array, size, j - 1, size);

	for (j = size - 1; j > 0; --j)
	{
		swapping(&array[0], &array[j]);
		print_array(array, size);
		sift_down(array, size, 0, j);
	}
}
