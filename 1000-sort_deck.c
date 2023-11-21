#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * compare_cards - function that compare two cards for qsort
 * @x: it's pointer to the first card
 * @y: it's pointer to the second card
 *
 * Return: Integer less than, equal to, or greater than zero if a is found,
 * respectively, to be less than, to match, or be greater than b.
 */
int compare_cards(const void *x, const void *y)
{
	return (strcmp(((deck_node_t *)x)->card->value,
				((deck_node_t *)y)->card->value));
}

/**
 * sort_deck - function that sorts a deck of cards
 * @deck: it's pointer to a doubly-linked list representing a deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	size_t n = 52;
	deck_node_t *arr[52];
	deck_node_t *tmp = *deck;
	size_t m;

	if (deck == NULL || *deck == NULL)
		return;

	for (m = 0; m < n; ++m)
	{
		arr[m] = tmp;
		tmp = tmp->next;
	}

	qsort(arr, n, sizeof(deck_node_t *), compare_cards);

	for (m = 0; m < n - 1; ++m)
	{
		arr[m]->next = arr[m + 1];
		arr[m + 1]->prev = arr[m];
	}

	arr[n - 1]->next = NULL;
	*deck = arr[0];
}
