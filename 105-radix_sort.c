#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * get_max - function that get the maximum value in the array
 * @array: array input
 * @size: array size
 * Return:  max value in the array
 */
int get_max(int *array, size_t size)
{
	int high = array[0];
	size_t a;

	for (a = 1; a < size; a++)
	{
		if (array[a] > high)
		{
			high = array[a];
		}
	}
	return (high);
}

/**
 * sorting_count - function that assumes that the array contains
 *  only non-negative ints.
 * @array: The array input
 * @size: The array size
 * @exp: The digit to consider
 */
void sorting_count(int *array, size_t size, int exp)
{
	const int nb_digit = 10;
	int *outcome = malloc(size * sizeof(int));
	int *arr = malloc(nb_digit * sizeof(int));
	size_t a;

	if (outcome == NULL || arr == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	for (a = 0; a < (size_t)nb_digit; a++)
	{
		arr[a] = 0;
	}

	for (a = 0; a < size; a++)
	{
		arr[(array[a] / exp) % nb_digit]++;
	}

	for (a = 1; a < (size_t)nb_digit; a++)
	{
		arr[a] += arr[a - 1];
	}

	for (a = size - 1; (int)a >= 0; a--)
	{
		outcome[arr[(array[a] / exp) % nb_digit] - 1] = array[a];
		arr[(array[a] / exp) % nb_digit]--;
	}
	for (a = 0; a < size; a++)
	{
		array[a] = outcome[a];
	}

	print_array(array, size);

	free(outcome);
	free(arr);
}

/**
 * radix_sort - function that sorts an array of ints
 *  in ascending order using the Radix sort
 * @array: The sorted array
 * @size: The array size
 */
void radix_sort(int *array, size_t size)
{
	int highest;
	int curr;

	if (size < 2)
	{
		return;
	}

	highest = get_max(array, size);
	curr = 1;

	while ((highest / curr) > 0)
	{
		sorting_count(array, size, curr);
		curr *= 10;
	}
}
