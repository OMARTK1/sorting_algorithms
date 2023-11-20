#include "sort.h"
/**
 * insertion_sort_list - a function that sorts a D-linked list of ints
 * in ascending order using insertion sort
 * @list: double pointer to the D-linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp_n;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		tmp_n = curr;
		while (tmp_n->prev != NULL && tmp_n->n < tmp_n->prev->n)
		{
			tmp_n->prev->next = tmp_n->next;
			if (tmp_n->next != NULL)
				tmp_n->next->prev = tmp_n->prev;
			tmp_n->next = tmp_n->prev;
			tmp_n->prev = tmp_n->prev->prev;
			tmp_n->next->prev = tmp_n;

			if (tmp_n->prev != NULL)
				tmp_n->prev->next = tmp_n;
			else
				*list = tmp_n;

			print_list(*list);
		}
		curr = curr->next;
	}
}

