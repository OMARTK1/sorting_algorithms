#include "sort.h"
/**
 * swapping - a function that swaps 2 items in an array
 * @x: Points to the 1st item
 * @y: Points to the 2nd item
 */
void swapping(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

/* 
 * print_array_alternative - a function that prints items of
 * an array
 * @array: Points to the 1st item
 * @size: Nb of items in the array
 */
void print_array_alternative(const int *array, size_t size)
{
    size_t y;

    y = 0;

    while (y < size)
    {
        if (y > 0)
            printf(", ");
        printf("%d", *(array + y));
        ++y;
    }
    printf("\n");
}
/**
 * quick_sort_hoare - function that initiates the quick sort
 *  using Hoare scheme
 * @array: sorted array
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    quick_sort_recursive_hoare(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive_hoare - function for quicksort using Hoare scheme (recursively)
 * @array: sorted array 
 * @low: Start idx of the partition
 * @high: End idx of the partition
 * @size: array size
 */
void quick_sort_recursive_hoare(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int index = partition_hoare_arr(array, low, high, size);
        
        if (low < index)
            quick_sort_recursive_hoare(array, low, index - 1, size);
        
        if (index < high)
            quick_sort_recursive_hoare(array, index + 1, high, size);
    }
}

/**
 * partition_hoare_arr - Partitions the array using the Hoare scheme
 * @array: the partitioned array
 * @low: Start idx of the partition
 * @high: End idx of the partition
 * @size: array size 
 * Return: Idx after partitioning
 */
int partition_hoare_arr(int *array, int low, int high, size_t size)
{
    int idx = array[high];
    int a = low - 1;
    int b = high + 1;

    while (1)
    {
        do
        {
            a++;
        } while (a < (int)size && array[a] < idx);

        do
        {
            b--;
        }
		while (b >= 0 && array[b] > idx);

        if (a >= b)
            return (b);

        swapping(&array[a], &array[b]);
        print_array(array, size);
    }
}
