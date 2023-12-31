#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_r(int *array, int l, int h, size_t size);
int partition_arr(int *array, int l, int h, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes_l(listint_t **l, listint_t *x, listint_t *y);
void cocktail_sort_list(listint_t **l);
void counting_sort(int *array, size_t size);
void merge(int *array, int *l, size_t l_size, int *r, size_t r_size);
void split_array(int *array, size_t size, int **l, int **r);
void merge_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t index, size_t heap_size);
void swapping(int *i, int *j);
void heap_sort(int *array, size_t size);
void bitonic_merge_array(int *array, size_t down, size_t c, int top);
void bitonic_sort_r(int *array, size_t down, size_t c, int top);
void bitonic_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void sorting_count(int *array, size_t size, int exp);
int get_max(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /* SORT_H */
