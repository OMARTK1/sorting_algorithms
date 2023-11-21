#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes_l - function that swaps two nodes in a doubly linked list
 * @l: it's pointer to the head of the list
 * @x: the first node to be swapped
 * @y: the second node to be swapped
 */
void swap_nodes_l(listint_t **l, listint_t *x, listint_t *y)
{
	if (!x || !y)
		return;

	if (x->prev)
		x->prev->next = y;
	else
		*l = y;

	if (y->next)
		y->next->prev = x;

	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list
 *                      using Cocktail shaker sort
 * @l: it's pointer to the head of the list
 */
void cocktail_sort_list(listint_t **l)
{
	int swapt;
	listint_t *act;

	if (!l || !(*l) || !(*l)->next)
		return;

	do {
		swapt = 0;
		for (act = *l; act && act->next; act = act->next)
		{
			if (act->n > act->next->n)
			{
				swap_nodes_l(l, act, act->next);
				swapt = 1;
			}
		}

		if (swapt)
			print_list(*l);

		if (!swapt)
			break;

		swapt = 0;
		for (act = act ? act->prev : *l; act && act->prev; act = act->prev)
		{
			if (act->n < act->prev->n)
			{
				swap_nodes_l(l, act->prev, act);
				swapt = 1;
			}
		}

		if (swapt)
			print_list(*l);

	} while (swapt);
}
